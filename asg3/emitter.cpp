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

const string typeStringSym(symbol* temp) {
    string type = "";
    if(temp->attributes[unsigned(attr::INT)]) {
       type += "int";
    }
    else if (temp->attributes[unsigned(attr::STRING)]) {
         type += "char";
    }
    else if (temp->attributes[unsigned(attr::STRUCT)]) {
         type += "struct ";
         type += temp->strucname->c_str();
    }

    return type;
}

const string addPtrsSym(symbol* node) {
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

const string addReg(symbol* node) { 
	string reg = "";
        if (node->attributes[unsigned(attr::INT)]) {
	   reg += "i" + std::to_string(regCounter);
        }
        if (node->attributes[unsigned(attr::STRING)]) {
	   reg += "s" + std::to_string(regCounter);
	}
        if ( node->attributes[unsigned(attr::VREG)]) { 
           reg += "a" + std::to_string(regCounter);
        }
        if ( node->attributes[unsigned(attr::STRUCT)]) { 
           reg += "p" + std::to_string(regCounter);
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
     //printTable(local_vars);
     string reg = "";
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
                   fprintf(oilFile, "while_%zd_%zd_%zd:;\n",
                   block->lloc.filenr, 
                   block->lloc.linenr, 
                   block->lloc.offset);
                   emitCondition(block->children[0]);
                   fprintf(oilFile, "%sif (!b%lu) goto break_%zd_%zd_%zd;\n",
                   indent.c_str(),
                   block->block_nr, 
                   block->lloc.filenr, 
                   block->lloc.linenr,
                   block->lloc.offset);
                   emitBlock(block->children[1], local_vars);
                   fprintf(oilFile, "%sgoto while_%zd_%zd_%zd;\n", indent.c_str(),
                   block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                   fprintf(oilFile, "break_%zd_%zd_%zd:;\n",
                   block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                   break;
              }
              case TOK_RETURN : { 
   		   if ( &block->children[0] == nullptr ) {
                 	fprintf(oilFile, "%sreturn;", indent.c_str());
                        break;
                   }
                   else { 
			if ( block->children[0]->attributes[unsigned(attr::VARIABLE)] != 1 )  { 
                             fprintf(oilFile, "%sreturn %s;\n",indent.c_str(), block->children[0]->lexinfo->c_str());
                             break;
                        }
			else { 
			     fprintf(oilFile, "%sreturn _%lu_%s;\n", indent.c_str(), block->children[0]->block_nr, block->children[0]->lexinfo->c_str());
                             break;
                        }
                   }
              }
              case TOK_CALL : {
                   //fprintf(oilFile, "%scall\n", indent.c_str());
                   symbol* temp = findGlobal(block->children[0]->lexinfo);
                   if ( !temp->attributes[unsigned(attr::VOID)]) {
			
                   }
                   //fprintf(oilFile, "%s%s\n", indent.c_str(), temp->funcname->c_str());
                   if ( &block->children[1] != nullptr ) {
                      if ( block->children[1]->symbol == TOK_CALL ) {
                          emitBlock(block, local_vars); 
                          break;
                     }
                   }
                   else {
                        printf("how is it null"); 
                        break;
                   }
                   break;  
	      }
              case '=' : {
                   symbol* temp = local_vars->find(block->children[0]->lexinfo)->second;
                   if ( temp == nullptr ) {
                  	temp = findGlobal(block->children[0]->lexinfo);
                        reg = addReg(temp).c_str();
                        fprintf(oilFile, "%s%s%s %s = _%zu_%s %s _%zu_%s; \n",indent.c_str(), typeStringSym(temp).c_str(),
                        addPtrsSym(temp).c_str(), reg.c_str(), temp->block_nr, block->children[1]->children[0]->lexinfo->c_str(),
                        block->children[1]->lexinfo->c_str(), temp->block_nr, block->children[1]->children[1]->lexinfo->c_str());
                        fprintf(oilFile, "%s_%zu_%s = %s\n", indent.c_str(), temp->block_nr, block->children[0]->lexinfo->c_str(), reg.c_str());
                        break;
                   }
                   reg = addReg(temp).c_str();                  
                   fprintf(oilFile, "%s%s%s %s = _%zu_%s %s _%zu_%s; \n",indent.c_str(), typeStringSym(temp).c_str(), 
                   addPtrsSym(temp).c_str(), reg.c_str(), temp->block_nr, block->children[1]->children[0]->lexinfo->c_str(),
                   block->children[1]->lexinfo->c_str(), temp->block_nr, block->children[1]->children[1]->lexinfo->c_str());
                   fprintf(oilFile, "%s_%zu_%s = %s\n", indent.c_str(), temp->block_nr, block->children[0]->lexinfo->c_str(), reg.c_str());
		   break;	 
	      }
              case TOK_IF : {
                   if ( block->children.size() > 2 ) { 
			emitCondition(block->children[0]);
                        fprintf(oilFile, "%sif (!b%zu) goto else_%zd_%zd_%zd;\n", indent.c_str(), block->block_nr, block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                        emitBlock(block->children[1], local_vars);
			fprintf(oilFile, "%sgoto fi_%zd_%zd_%zd;\n", indent.c_str(), block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                        fprintf(oilFile, "else_%zd_%zd_%zd;\n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                        emitBlock(block->children[2], local_vars);
                        fprintf(oilFile, "fi_%zd_%zd_%zd;\n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);

                   } 
                   else { 
                   emitCondition(block->children[0]);
                   fprintf(oilFile, "%sif (!b%zu) goto fi_%zd_%zd_%zd;\n", indent.c_str(), block->block_nr, block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                   emitBlock(block->children[1], local_vars);
                   fprintf(oilFile, "fi_%zd_%zd_%zd;\n", block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                   }
		   break;
              }
          }
    }
}

void emitFunctions(astree* function, symbol_table* local_vars) { 
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
     emitBlock(block, local_vars);
     fprintf(oilFile, "}\n");
}

void emitCode(astree* root) {
   emitStructs(root);
   emitStrings(root);
   emitGlobalDecs(root);
}  
