#include <stdio.h>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

#include "astree.h"
#include "emitter.h"

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

void emitCode(astree* root) {
   emitStructs(root);
} 
