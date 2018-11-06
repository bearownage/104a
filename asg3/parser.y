/* Vineet Ramareddi (vramared@ucsc.edu) */
/* Husain Adam Askari (haskari@ucsc.edu) */
%{

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <cassert>

#include "lyutils.h"
#include "astree.h"

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%destructor { destroy ($$); } <>
%printer { astree::dump (yyoutput, $$); } <>

%initial-action {
   parser::root = new astree (TOK_ROOT, {0, 0, 0}, "<<ROOT>>");
}

%token TOK_VOID TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_NULL TOK_NEW TOK_VARDECL TOK_ARRAY TOK_ARROW TOK_BR
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE TOK_NOT
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_ROOT TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD          /* any tokens which are still required? */

%token TOK_PARAM TOK_DECLID

%right  TOK_IF TOK_ELSE                                          /* ifelse? */
%right  TOK_VARDECL
%left   TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left   '+' '-'
%left   '*' '/' '%'
%right  TOK_POS TOK_NEG TOK_NOT TOK_NEW
%left   TOK_ARRAY TOK_ARROW                                      /* correct way to arrange this? */
%nonassoc '(' ')'

%start start
                                                /* correct? */
%%

start      : program                                      {  parser::root = $1; parser::root -> dump_tree(stdout, 0); }
           ;

program    : program structdef                            { $$ = $1 -> adopt ($2); }
           | program globaldecl                           { $$ = $1 -> adopt ($2); }
           | program function                             { $$ = $1 -> adopt ($2); }
           |                                              { $$ = parser::root; }
           ; 

structdef  : struc '}'                                    { destroy ($2); }
           ;

struc      : struc fielddecl ';'                          { destroy ($3); $$ = $1 -> adopt ($2); } 
           | TOK_STRUCT TOK_IDENT '{'                     { destroy ($3); $$ = $1 -> adopt ($2); $2 -> adopt_sym (NULL, TOK_TYPEID); }
           ;

fielddecl  : basetype TOK_IDENT                           { $$ = $1 ->  adopt_sym ($2, TOK_FIELD); } 
           | basetype TOK_ARRAY TOK_IDENT                 { $$ = $2 -> adopt ($1); $1 -> adopt_sym ($3, TOK_FIELD); } 
           ;

globaldecl : identdec TOK_VARDECL constant ';'            { destroy ($4); $$ = $2 -> adopt ($1, $3); }
           ;

function   : identdec TOK_PARAM identdeclist ')' fnbody    {destroy($4); $$ = $1 -> adopt ($2, $5); $2 -> adopt ($3); }
           | identdec '(' ')' fnbody                       {destroy($2); destroy($3); $$=$1 -> adopt ($4); }
           | identdec '(' ')' '{' '}'                      {destroy($2); destroy($3); destroy($4); destroy($5); $$ = $1; }
           ;                                              
                                                         

identdeclist   : identdeclist ',' identdec                 {destroy ($2); $$ = $1 -> adopt ($3); }
               | identdec                                  {$$ = $1;} 
               ;

identdec   : basetype TOK_ARRAY TOK_IDENT                 { $$ = $2 -> adopt ($1); $1 -> adopt ($3); $3 -> adopt_sym (NULL, TOK_DECLID); }
           | basetype TOK_IDENT                           { $$ = $1 -> adopt ($2); $2 -> adopt_sym (NULL, TOK_DECLID); }        
           ;

fnbody     : '{' localdecl statement                      {destroy($1); $$ = $2 -> adopt ($3); }
           | '}'                                          {destroy($1); }
           | ';'                                          {destroy($1); }
           ;

basetype   : TOK_VOID                                     { $$ = $1; }
           | TOK_INT                                      { $$ = $1; }
           | TOK_STRING                                   { $$ = $1; }
           | TOK_IDENT                                    { $$ = $1; }
           ;

localdecl  : identdec TOK_VARDECL expr ';'                { destroy ($4); $$ = $2 -> adopt ($1, $3); }
           ;

ifelse     : TOK_IF                                       { $$ = $1; }
           ;

expr       : TOK_NULL                                     { $$ = $1; }
           ;

statement  : block                                        { $$ = $1; }
           | while                                        { $$ = $1; }
           | ifelse                                       { $$ = $1; }
           | TOK_RETURN                                   { $$ = $1; }
           | expr ';'                                     { destroy ($2); $$ = $1; }
           | ';'                                          { destroy ($1); } 
           ;

block      : TOK_BLOCK stateList '}'                      { destroy ($3); $$ = $1 -> adopt ($2); }
           ;

stateList  : stateList statement                          { $$ = $1 -> adopt ($2); }
           | statement                                    { $$ = $1; }
           ;

while      : TOK_WHILE '(' expr ')' statement             { destroy ($2); destroy ($4); $$ = $1 -> adopt ($3, $5); }
           ;

allocation : TOK_IF                                       { $$ = $1; }
           ;
 
exprList   : exprList ',' expr                            { destroy ($2); $$ = $1 -> adopt ($3); }
           | expr                                         { $$ = $1; }
           ;
                
call       : TOK_IDENT '(' exprList ')'                   { destroy ($2); destroy ($4); $$ = $1 -> adopt ($3); }
           ;

variable   : TOK_IDENT                                    { $$ = $1; }
           | expr '[' expr ']'                            { destroy ($2); destroy ($4); $$ = $1 -> adopt ($3); }
           | expr TOK_ARROW TOK_IDENT                     { $$ = $1 -> adopt ($2) -> adopt_sym ($3, TOK_FIELD); }
           ;

constant   : TOK_INTCON                                   { $$ = $1; }
           | TOK_STRINGCON                                { $$ = $1; }
           | TOK_CHARCON                                  { $$ = $1; }
           | TOK_NULL                                     { $$ = $1; }
           ;


%%


const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}


