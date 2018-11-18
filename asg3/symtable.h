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
/*
enum class attr: unsigned {
       VOID, INT, NULLX, STRING, STRUCT, ARRAY, FUNCTION, VARIABLE,
       FIELD, TYPEID, PARAM, LVAL, CONST, VREG, VADDR, BITSET_SIZE,
};
*/
using attr_bitset = bitset<15>;

struct symbol {
   attr_bitset attributes;
   size_t sequence;
   using symbol_table = unordered_map<string*, symbol*>;
   symbol_table* fields;
   location lloc;
   size_t block_nr;
   vector<symbol*>* parameters;
};

using symbol_table = unordered_map<string*, symbol*>;
using symbol_entry = pair<const string*, symbol*>;

const string attrString(astree* node);
void traversal(astree* node);

#endif
