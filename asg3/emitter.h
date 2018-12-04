#ifndef __EMITTER_H__
#define __EMITTER_H__

#include <string>
#include <vector>

using namespace std;

#include "lyutils.h"
#include "astree.h"
#include "symtable.h"

void emitCode(astree* root);
void emitFunctions(astree* node, symbol_table* local_vars);
void emitBlock(astree* node, symbol_table* local_vars);

#endif
