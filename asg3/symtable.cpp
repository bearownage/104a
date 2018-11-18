#include <bitset>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

#include "astree.h"
#include "symtable.h"

int blocknr = 0;
int next_block = 1;

symbol_table types;
symbol_table variables;
symbol_table globaldecs;

enum class attr: unsigned {
       VOID, INT, NULLX, STRING, STRUCT, ARRAY, FUNCTION, VARIABLE,
       FIELD, TYPEID, PARAM, LVAL, CONST, VREG, VADDR, BITSET_SIZE,
};

const string attrString(astree* node) {
    string attrString = "";
    if(node->attributes[unsigned(attr::VOID)]) {
       attrString += "void ";
    }
    if(node->attributes[unsigned(attr::INT)]) {
       attrString += "int ";
    }
    if(node->attributes[unsigned(attr::NULLX)]) {
       attrString += "null ";
    }
    if(node->attributes[unsigned(attr::STRING)]) {
       attrString += "string ";
    }
    if(node->attributes[unsigned(attr::STRUCT)]) {
       attrString += "struct ";
    }
    if(node->attributes[unsigned(attr::ARRAY)]) {
       attrString += "array ";
    }
    if(node->attributes[unsigned(attr::FUNCTION)]) {
       attrString += "function ";
    }
    if(node->attributes[unsigned(attr::VARIABLE)]) {
       attrString += "variable ";
    }
    if(node->attributes[unsigned(attr::FIELD)]) {
       attrString += "field ";
    }
    if(node->attributes[unsigned(attr::TYPEID)]) {
       attrString += "typeid ";
    }
    if(node->attributes[unsigned(attr::PARAM)]) {
       attrString += "param ";
    }
    if(node->attributes[unsigned(attr::LVAL)]) {
       attrString += "lval ";
    }
    if(node->attributes[unsigned(attr::CONST)]) {
       attrString += "const ";
    }
    if(node->attributes[unsigned(attr::VREG)]) {
       attrString += "vreg ";
    }
    if(node->attributes[unsigned(attr::VADDR)]) {
       attrString += "vaddr ";
    }
    return attrString;
}

symbol* newSym(astree* node) {
   symbol* sym = new symbol();
   sym -> attributes = node -> attributes;
   sym -> sequence = 0;
   sym -> fields = nullptr;
   sym -> lloc = node -> lloc;
   sym -> block_nr = node -> block_nr;
   sym -> parameters = nullptr;
   return sym;    
}

void traversal(astree* root) {

  for (astree* childNode: root -> children) {
      printf("Token: %s\n", parser::get_tname(childNode -> symbol));
      switch(childNode -> symbol) {
         case TOK_STRUCT : {
            const string* name = childNode -> children[0] -> lexinfo;
            childNode -> strucname = name;
            childNode -> block_nr = 0;
            auto* sym = newSym(childNode);
            sym -> lloc = childNode -> children[0] -> lloc;
            
            int counter = 0;
            sym -> fields = new symbol_table();
            for (astree* fieldNode: childNode -> children) { 
               auto* fieldSym = newSym(fieldNode);
               fieldSym -> sequence = counter;
               sym -> fields -> insert(std::make_pair(name, fieldSym));
               counter++;
            }
            //types -> insert(name, sym);
            
            break;
         }
         case TOK_TYPEID :
            childNode -> attributes[unsigned(attr::TYPEID)] = 1;
            break;
         default :
            break;
      }
      traversal(childNode);
  }

}

void updateAttr(astree* root) {
   for (astree* childNode: root -> children) {
      switch(childNode -> symbol) {
         case TOK_ROOT : 
            break;
         case TOK_STRUCT : {
            childNode -> children[0] -> attributes[unsigned(attr::STRUCT)] = 1;
            break;
         }
         case TOK_TYPEID : 
            childNode -> attributes[unsigned(attr::TYPEID)] = 1;
            break;
         case TOK_FIELD : {
            childNode -> children[0] -> attributes[unsigned(attr::FIELD)] = 1;
            if ( childNode -> lexinfo -> compare("int") == 0 ) {
               childNode -> children[0] -> attributes[unsigned(attr::INT)] = 1;
            }
            if ( childNode -> lexinfo -> compare("string") == 0 ) {
               childNode -> children[0] -> attributes[unsigned(attr::STRING)] = 1;
            } 
            break;
         }
         case TOK_VOID :
            childNode -> children[0] -> attributes[unsigned(attr::VOID)] = 1; 
            break;
         case TOK_INT : 
            childNode -> children[0] -> attributes[unsigned(attr::INT)] = 1;
            break;
         case TOK_NULL : 
            childNode -> children[0] -> attributes[unsigned(attr::NULLX)] = 1;
            break;
         case TOK_STRING : 
            childNode -> children[0] -> attributes[unsigned(attr::STRING)] = 1;
            break;
         case TOK_IDENT : 
            break;
         default : 
           printf("Press F to pay respect");
      }
      updateAttr(childNode);
   }   

}













