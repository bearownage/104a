#include <stdio.h>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

#include "astree.h"
#include "emitter.h"
#include "symtable.h"

int stringCounter = 1;
string indent = "        ";
int regCounter = 1;

extern FILE* oilFile;

enum class attr : unsigned {
   VOID, INT, NULLX, STRING, STRUCT, ARRAY, FUNCTION, VARIABLE, FIELD,
   TYPEID, PARAM, LOCAL, LVAL, CONST, VREG, VADDR, 
};

const string typeString(astree* node) {
   string type = "";
   if(node->attributes[unsigned(attr::INT)]) {
      type += "int";
   }
   else if(node->attributes[unsigned(attr::STRING)]) {
      type += "char";
   }
   else if(node->attributes[unsigned(attr::STRUCT)]) {
      type += "struct ";
      type += node->strucname->c_str();
   }

   return type;
}

const string addReg(astree* node) { 
	string reg = "";
        if (node->attributes[unsigned(attr::INT)]) {
	   reg += "i" + std::to_string(regCounter);
        }
        if (node->attributes[unsigned(attr::STRING)]) {
	   reg += "s" + std::to_string(regCounter);
	}
        regCounter++;
        return reg;
}

const string addPtrs(astree* node) {
    string mangled = "";
    if(node->attributes[unsigned(attr::STRING)]) {
      mangled += "*";
    }
    else if(node->attributes[unsigned(attr::STRUCT)]) {
      mangled += "*";
    }

    if(node->attributes[unsigned(attr::ARRAY)]) {
      mangled += "*";
    }
    return mangled;
}

void printFields(astree* structNode, const string* name) {
   for(astree* field : structNode->children) {
      if(field->symbol == TOK_FIELD) {
         fprintf(oilFile, "%s%s %s%s;\n", indent.c_str(), 
         typeString(field).c_str(), addPtrs(field).c_str(),
         field->lexinfo->c_str());
      }
      printFields(field, name);
   }
}

void emitStructs(astree* root) {
   for(astree* structNode : root->children) {
      if(structNode->symbol == TOK_STRUCT) {
         const string* name = structNode->children[0]->strucname;
         fprintf(oilFile, "struct %s {\n", name->c_str());
         printFields(structNode, name);
         fprintf(oilFile, "};\n");
      }
      
   }
}

void emitStrings(astree* root) {
   for(astree* stringcon : root->children ) {
       if(stringcon->symbol == TOK_STRINGCON) {
           fprintf(oilFile, "char *s%d = %s;\n", 
           stringCounter,
           stringcon->lexinfo->c_str());
           stringCounter++;
       }
       emitStrings(stringcon);
   }
}

void emitGlobalDecs(astree* root) {
    for(astree* global : root->children) {
        if(global->symbol == TOK_VARDECL) {
            astree* dec = global->children[0]->children[0];
            if(global->children[0]->symbol == TOK_ARRAY) {
                dec = global->children[0]->children[0]->children[0];
            }
            fprintf(oilFile, "%s %s%s;\n", 
            typeString(dec).c_str(), 
            addPtrs(dec).c_str(),
            dec->lexinfo->c_str());
        }
    }
}

void emitParams(astree* paramNode) {
    for (size_t i = 0; i < paramNode->children.size()-1; ++i ) {
        fprintf(oilFile, "%s%s %s_%lu_%s,\n", indent.c_str(), typeString(paramNode->children[i]->children[0]).c_str(), addPtrs(paramNode->children[i]).c_str(),
        paramNode->children[i]->block_nr, paramNode->children[i]->children[0]->lexinfo->c_str());
    }
    fprintf(oilFile, "%s%s %s_%lu_%s)\n", indent.c_str(), typeString(paramNode->children[paramNode->children.size()-1]->children[0]).c_str(), addPtrs(paramNode->children[paramNode->children.size()-1]).c_str(),
    paramNode->children[paramNode->children.size()-1]->block_nr, paramNode->children[paramNode->children.size()-1]->children[0]->lexinfo->c_str());
    return;
}

void emitCondition(astree* cond) {
        if ( cond->attributes[unsigned(attr::VARIABLE)] == 1 ) 
        {
           return;
        }
	fprintf(oilFile, "%schar b%lu = __%s %s %s\n", indent.c_str(), cond->block_nr, cond->children[0]->lexinfo->c_str(), cond->lexinfo->c_str(), cond->children[1]->lexinfo->c_str()); 
        return;
}

void printTable(symbol_table *table) {
  for (auto it = table->cbegin(); it != table->cend(); it++) {
    printf("%s (%lu.%lu.%lu) {%lu} \n", it->first->c_str(),
           it->second->lloc.filenr, it->second->lloc.linenr,
           it->second->lloc.offset, it->second->block_nr);
  }
}

void emitBlock(astree* root, symbol_table* local_vars) {
     printTable(local_vars);
     for (astree* block : root->children) {
          switch(block->symbol) {
             case TOK_VARDECL : {
                  astree* ident = block->children[0]->children[0];
                  fprintf(oilFile, "%s%s %s_%lu_%s %s %s;\n", 
                  indent.c_str(), 
                  typeString(ident).c_str(), addPtrs(ident).c_str(),
                  block->block_nr,
                  ident->lexinfo->c_str(), block->lexinfo->c_str(),
                  block->children[1]->lexinfo->c_str()); 
                  break;
              }
              case TOK_WHILE: {
                   printf("while_%zd_%zd_%zd:;\n",
                   block->lloc.filenr, 
                   block->lloc.linenr, 
                   block->lloc.offset);
                   emitCondition(block->children[0]);
                   printf("%sif (!b%lu) goto break_%zd_%zd_%zd;\n",
                   indent.c_str(),
                   block->block_nr, 
                   block->lloc.filenr, 
                   block->lloc.linenr,
                   block->lloc.offset);
                   emitBlock(block->children[1], local_vars);
                   printf("%sgoto while_%zd_%zd_%zd;\n", indent.c_str(),
                   block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                   printf("break_%zd_%zd_%zd:;\n",
                   block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                   break;
              }
              case TOK_RETURN : { 
   		   if ( &block->children[0] == nullptr ) {
                 	printf("%sreturn;", indent.c_str());
                        break;
                   }
                   else { 
			if ( block->children[0]->attributes[unsigned(attr::VARIABLE)] != 1 )  { 
                             printf("%sreturn %s;\n",indent.c_str(), block->children[0]->lexinfo->c_str());
                             break;
                        }
			else { 
			     printf("%sreturn _%lu_%s;\n", indent.c_str(), block->children[0]->block_nr, block->children[0]->lexinfo->c_str());
                             break;
                        }
                   }
              }
              case TOK_CALL : {
                   printf("%scall\n", indent.c_str()); 
  		   break;
	      }
              case '=' : {
                   printf("%s%s\n",indent.c_str(), addReg(block->children[1]).c_str());
		   break;	 
	      }
          }
    }
}

void emitFunctions(astree* function) {
     astree* ident = function->children[0]->children[0];
     if(function->children[0]->symbol == TOK_ARRAY) {
        ident = function->children[0]->children[0]
        ->children[0];
     }
     if ( &function->children[1]->children[0] == nullptr ) { 
        fprintf(oilFile, "%s %s%s (void)\n", 
        typeString(ident).c_str(), 
        addPtrs(ident).c_str(), 
        ident->lexinfo->c_str());
     }
     else {
        fprintf(oilFile, "%s %s%s (\n", 
        typeString(ident).c_str(), 
        addPtrs(ident).c_str(),
        ident->lexinfo->c_str());
        astree* params = function->children[1];
        emitParams(params);
     }
     fprintf(oilFile, "{\n");
     astree* block = function->children[2];
     fprintf(oilFile, "}\n");
}

void emitCode(astree* root) {
   emitStructs(root);
   emitStrings(root);
   emitGlobalDecs(root);
}  
