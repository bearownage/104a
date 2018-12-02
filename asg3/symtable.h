#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include <bitset>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

#include "lyutils.h"
#include "auxlib.h"
#include "astree.h"

using attr_bitset = bitset<16>;

struct symbol {
   attr_bitset attributes;
   size_t sequence;
   using symbol_table = unordered_map<const string*, symbol*>;
   symbol_table* fields;
   location lloc;
   size_t block_nr;
   vector<symbol*> parameters;
  
   const string* funcname; 
   const string* strucname;
   const string* param_name;
};

using symbol_table = unordered_map<const string*, symbol*>;
using symbol_entry = pair<const string*, symbol*>;

const string attrString(astree* node);
void traversal(astree* node);
void updateAttr(astree* root);
void printTable(symbol_table* table);
#endif
