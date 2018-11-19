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
       attrString += node->strucname -> c_str();
       attrString += " ";
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
       attrString += node->strucname -> c_str();
       attrString += " ";
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
    attrString = attrString.substr(0, attrString.size()-1);
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
        if (it->second->fields != nullptr) {
           for (auto field = it->second->fields->cbegin(); field != it->second->fields->cend(); field++) {
               printf("    %s (%lu.%lu.%lu) %s %lu\n", field->first->c_str(), field->second->lloc.filenr, 
               field->second->lloc.linenr, field->second->lloc.offset, 
               attrStringSym(field->second).c_str(), field->second->sequence);
           }
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
               if (fieldNode -> children.size() >= 1 && fieldNode -> children[0] -> symbol == TOK_FIELD) {
                 v.push_back(fieldNode);
                 counter++;
               }
              else if (fieldNode -> symbol == TOK_ARRAY) {
                 v.push_back(fieldNode -> children[0]);
                 counter++;
              }
            }
            counter -= 1;
            // Use vector to print in the right order 
	    while (!v.empty()) {
                astree* tmpNode = nullptr;
                tmpNode = v.back();
                v.pop_back();
                auto* fieldSym = newSym(tmpNode -> children[0]);
                fieldSym -> sequence = counter;
                sym -> fields -> insert(std::make_pair(tmpNode -> children[0] -> lexinfo, fieldSym));
                counter--;
	    }
            types -> insert(std::make_pair(childNode -> children[0] -> lexinfo, sym));
            for(astree* child : childNode -> children) {
               if(child -> symbol == TOK_TYPEID) {
                  
               } 
            } 
            break;
         }
         case TOK_TYPEID :
            //childNode -> attributes[unsigned(attr::TYPEID)] = 1;
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
            childNode -> children[0] -> strucname = childNode -> children[0] -> lexinfo;
            break;
         }
         case TOK_TYPEID : {
            if(childNode -> attributes[unsigned(attr::STRUCT)] == 0) { 
               childNode -> attributes[unsigned(attr::TYPEID)] = 1;
            }
            break;
         }
         case TOK_FIELD : {
            childNode -> attributes[unsigned(attr::FIELD)] = 1;
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
