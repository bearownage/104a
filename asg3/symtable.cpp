#include <bitset>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

#include "astree.h"
#include "symtable.h"

int blocknr = 0;
int next_block = 1;

symbol_table* types = new symbol_table;
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

const string attrStringSym(symbol* node) {
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
   sym -> strucname = node -> strucname;
   return sym;    
}

// Print the symbols for .sym
void printTable(symbol_table* table) { 
    for ( auto it = table -> cbegin(); it != table -> cend(); it++ ) {                                                                                                                         
        printf("%s (%lu.%lu.%lu) {%lu} %s\n", it->first->c_str(), it->second->lloc.filenr, 
        it->second->lloc.linenr, it->second->lloc.offset, it->second->block_nr, 
        attrStringSym(it->second).c_str());
        if(it->second->fields != nullptr) {
           printTable(it->second->fields);
        } 
    }                                                                                                                                                                                        
}

void traversal(astree* root) {
  for (astree* childNode: root -> children) {
      printf("Token: %s\n", parser::get_tname(childNode -> symbol));
      switch(childNode -> symbol) {
         case TOK_STRUCT : {
            childNode -> strucname = childNode -> children[0] -> lexinfo;
            childNode -> block_nr = 0;
            auto* sym = newSym(childNode);
            sym -> lloc = childNode -> children[0] -> lloc;
            sym -> attributes = childNode -> children[0] -> attributes;
            int counter = 0;
            sym -> fields = new symbol_table();
            vector <astree*> v;
            for (astree* fieldNode: childNode -> children) { 
               if (fieldNode -> symbol == TOK_FIELD) {
                 v.push_back(fieldNode);
               }
            }
            // Use vector to print in the right order 
	    while (!v.empty()) {
                astree* tmpNode = nullptr;
                tmpNode = v.back();
                v.pop_back();
                auto* fieldSym = newSym(tmpNode -> children[0]);
                fieldSym -> sequence = counter;
                sym -> fields -> insert(std::make_pair(tmpNode -> children[0] -> lexinfo, fieldSym));
                counter++;
	    }
            types -> insert(std::make_pair(childNode -> children[0] -> lexinfo, sym));
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
         case TOK_ARRAY : 
            childNode -> children[0] -> children[0] -> attributes[unsigned(attr::ARRAY)] = 1;
            break;
         default : 
           printf("Press F to pay respect");
      }
      updateAttr(childNode);
   }   

}
/*
void printTable(symbol_table* table) {
    for ( auto it = table -> begin(); it != table -> end(); ++it ) {
        printf("%s\n", it->first -> c_str());
    }
}
*/










