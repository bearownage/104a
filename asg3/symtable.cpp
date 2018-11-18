#include <bitset>
#include <string>
#include <vector>

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
   //sym -> structName = nullptr;
   return sym;    
}

void traversal(astree* root) {

  for (astree* childNode: root -> children) {
      printf("Token: %s\n", parser::get_tname(childNode -> symbol)); 
      switch(childNode -> symbol) {
         case TOK_STRUCT :
            childNode -> attributes[unsigned(attr::STRUCT)] = 1;
            const string* structName = childNode->children[0];
            printf("%s", structName.c_str());
            break;
         case TOK_TYPEID :
            childNode -> attributes[unsigned(attr::TYPEID)] = 1;
            break;
         case TOK_FIELD : 
            childNode -> attributes[unsigned(attr::FIELD)] = 1;
            break;
         case TOK_FUNCTION :
            childNode -> attributes[unsigned(attr::STRUCT)] = 1;
            childNode -> block_nr++;
            break;
      }
      traversal(childNode);
  }

}













