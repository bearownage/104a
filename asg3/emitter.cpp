#include <stdio.h>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

#include "astree.h"
#include "emitter.h"

int stringCounter = 1;

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
      type += "char*";
   }
   else if(node->attributes[unsigned(attr::STRUCT)]) {
      type += "struct ";
      type += node->strucname->c_str();
      type += "*";
   }

   if(node->attributes[unsigned(attr::ARRAY)]) {
      type += "*";
   }
   return type;
}

void printFields(astree* structNode, const string* name) {
   for(astree* field : structNode->children) {
      if(field->symbol == TOK_FIELD) {
         printf("        %s %s;\n", typeString(field).c_str(), field->lexinfo->c_str());
      }
      printFields(field, name);
   }
}

void emitStructs(astree* root) {
   for(astree* structNode : root->children) {
      if(structNode->symbol == TOK_STRUCT) {
         const string* name = structNode->children[0]->strucname;
         printf("struct %s {\n", name->c_str());
         printFields(structNode, name);
         printf("};\n");
      }
      
   }
}

void emitStrings(astree* root) {
   for(astree* stringcon : root->children ) {
       if(stringcon->symbol == TOK_STRINGCON) {
           printf("char* s%d = %s;\n", stringCounter,
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
            printf("%s %s;\n", typeString(dec).c_str(), 
                dec->lexinfo->c_str());
        }
    }
}

void emitParams(astree* paramNode) {
    for(astree* param : paramNode->children) {
        if(param->attributes[unsigned(attr::PARAM)]) {
           printf("        %s _%lu_%s,\n", typeString(param).c_str(), 
           param->block_nr, param->lexinfo->c_str());
        }
        emitParams(param);
    }
}

void emitBlock(astree* root) {
     for (astree* block : root->children) {
          switch(block->symbol) {
             case TOK_VARDECL : {
                  string type = "";
                  if (block->children[0]->symbol == TOK_INT ) {
                     type += "int";
                  }
                  else if (block->children[0]->symbol == TOK_STRING ) { 
                     type += "string";
                  }
                  else {
                      printf("add case here"); 
                  }

                 
                  printf("        %s _%lu_%s %s %s;\n", type.c_str(), block->block_nr,
                  block->children[0]->children[0]->lexinfo->c_str(), block->lexinfo->c_str(),
                  block->children[1]->lexinfo->c_str()); 
                  break;
              }
              case TOK_WHILE: {
                   printf("while_%zd_%zd_%zd:;\n",
                   block->lloc.filenr, block->lloc.linenr, block->lloc.offset);
                   break;
              }
          }
    }
}

void emitFunctions(astree* root) {
    for(astree* function : root->children) {
        if(function->symbol == TOK_FUNCTION) {
           astree* ident = function->children[0]->children[0];
           if(function->children[0]->symbol == TOK_ARRAY) {
               ident = function->children[0]->children[0]
               ->children[0];
           }
           else if ( &function->children[1]->children[0] == nullptr ) { 
               printf("%s %s (void)\n", typeString(ident).c_str(),
               ident->lexinfo->c_str());
               astree* block = function->children[2];
               emitBlock(block);
           }
           else {
           printf("%s %s (\n", typeString(ident).c_str(), 
              ident->lexinfo->c_str());
           astree* params = function->children[1];
           emitParams(params);
           astree* block = function->children[2];
           emitBlock(block);
           }
        }
    }

}

void emitCode(astree* root) {
   emitStructs(root);
   emitStrings(root);
   emitGlobalDecs(root);
   emitFunctions(root);
}  
