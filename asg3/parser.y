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
   parser::root = new astree (TOK_ROOT, {0, 0, 0}, "");
}

%token TOK_VOID TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_NULL TOK_NEW TOK_VARDECL TOK_ARRAY TOK_ARROW TOK_BR
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE TOK_NOT
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_ROOT TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD TOK_NEWSTR

%token TOK_PARAM TOK_FUNCTION TOK_PROTOTYPE TOK_DECLID TOK_INDEX

%right  TOK_IF TOK_ELSE                     
%right  '='
%left   TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left   '+' '-'
%left   '*' '/' '%'
%right  TOK_POS TOK_NEG TOK_NOT TOK_NEW
%left   '[' TOK_ARRAY '.' TOK_ARROW
%nonassoc   '(' ')'

%start start
                                                /* correct? */
%%

start      : program                        { $$ = $1 = nullptr; }
           ;

program    : program structdef              { $$ = $1 -> adopt ($2); }
           | program globaldecl             { $$ = $1 -> adopt ($2); }
           | program function               { $$ = $1 -> adopt ($2); }
           | program statement              { $$ = $1 -> adopt ($2); }
           | program error '{'              { $$ = $1; destroy ($3);}
           | program error ';'              { $$ = $1; destroy ($3);}
           |                                { $$ = parser::root; }
           ; 

structdef  : struc '}'          { destroy ($2); $$ = $1;}
           ;

struc      : struc fielddecl ';'                          
             { destroy ($3); $$ = $1 -> adopt ($2); } 
           | TOK_STRUCT TOK_IDENT '{'                     
             { destroy ($3); $$ = $1 -> adopt ($2); 
               $2 -> adopt_sym (NULL, TOK_TYPEID); }
           ;

fielddecl  : basetype TOK_IDENT                           
             { $$ = $1 ->  adopt ($2); 
             $2 -> adopt_sym(NULL, TOK_FIELD); } 
           | basetype TOK_ARRAY TOK_IDENT                 
             { $$ = $2 -> adopt ($1); 
             $1 -> adopt ($3); $3 -> adopt_sym(NULL, TOK_FIELD);}
           ;

globaldecl : identdec '=' constant ';'               
             { destroy ($4); $$ = $2 -> adopt ($1, $3); 
               $2 -> adopt_sym (NULL, TOK_VARDECL); }
           | identdec '=' expr ';'                
             { destroy ($4); $$ = $2 -> adopt ($1, $3); 
               $2 -> adopt_sym (NULL, TOK_VARDECL); }
           ;

function   : func fnbody '}' ';'                           
             { destroy ($3, $4); $$ = $1 -> adopt ($2); } 
           | func fnbody '}'                             
             { destroy ($3); $$ = $1 -> adopt ($2); }  
           | func '{' '}'                                
             { destroy ($3); $$ = $1 -> adopt ($2); 
               $2 -> adopt_sym (NULL, TOK_BLOCK); } 
           | func '{' '}' ';'                            
             { destroy ($2, $3); destroy ($4); 
               $$ = $1 -> adopt_sym (NULL, TOK_PROTOTYPE); }
           | func ';'                                    
             { destroy ($2); $$ = 
               $1 -> adopt_sym (NULL, TOK_PROTOTYPE);}
           ;

func       : func ')'     { destroy ($2); $$ = $1; }
           | func param   { $$ = $1 -> adopt ($2); }
           | identdec  { $$ = new astree(TOK_FUNCTION, $1 -> lloc ,""); 
                         $$ -> adopt ($1); }
           ;

param      : param ',' identdec  { destroy ($2); 
                                   $$ = $1 -> adopt ($3); }
           | TOK_PARAM identdec  { $$ = $1 -> adopt ($2); }
           | TOK_PARAM           { $$ = $1; }
           ;

identdec   : basetype TOK_ARRAY TOK_IDENT                 
              { $$ = $2 -> adopt ($1); 
                $1 -> adopt ($3); $3 -> adopt_sym (NULL, TOK_DECLID); }
           | basetype TOK_IDENT                           
              { $$ = $1 -> adopt ($2); 
                $2 -> adopt_sym (NULL, TOK_DECLID); }
           ;

fnbody     : fnbody statement    { $$ = $1 -> adopt ($2); }
           | fnbody localdecl    { $$ = $1 -> adopt ($2); }
           | '{' statement       
              { $$ = $1 -> adopt_sym ($2, TOK_BLOCK); }
           | '{' localdecl       
              { $$ = $1 -> adopt_sym ($2, TOK_BLOCK); }
           ;


basetype   : TOK_VOID                                     { $$ = $1; }
           | TOK_INT                                      { $$ = $1; }
           | TOK_STRING                                   { $$ = $1; }
           | TOK_IDENT                                    
           { $$ = $1 -> adopt_sym (NULL, TOK_TYPEID); }
           ;

localdecl  : identdec '=' expr ';'                
            { destroy ($4); $$ = $2 -> adopt ($1, $3); 
              $2 -> adopt_sym(NULL, TOK_VARDECL); }
           ;

ifelse     : TOK_IF TOK_PARAM expr ')' statement %prec TOK_IF           
             { destroy ($2, $4); $$ = $1 -> adopt ($3, $5); }
           | TOK_IF TOK_PARAM expr ')' statement TOK_ELSE statement     
             { destroy ($2, $4); destroy ($6); 
               $$ = $1 -> adopt ($3, $5); $1 -> adopt ($7); } 
           | TOK_ELSE TOK_IF TOK_PARAM expr ')' statement               
             { destroy ($1, $3); destroy ($5); 
               $$ = $2 -> adopt ($4, $6); } 
           ;

expr       : TOK_NEW allocation         { $$ = $1 -> adopt ($2); }
           | expr '=' expr              { $$ = $2 -> adopt ($1, $3); }
           | expr '+' expr              { $$ = $2 -> adopt ($1, $3); }
           | expr '-' expr              { $$ = $2 -> adopt ($1, $3); }
           | expr '*' expr              { $$ = $2 -> adopt ($1, $3); }
           | expr '/' expr              { $$ = $2 -> adopt ($1, $3); }
           | expr '%' expr              { $$ = $2 -> adopt ($1, $3); }
           | expr TOK_EQ expr           { $$ = $2 -> adopt ($1, $3); }
           | expr TOK_NE expr           { $$ = $2 -> adopt ($1, $3); }
           | expr TOK_LT expr           { $$ = $2 -> adopt ($1, $3); }
           | expr TOK_LE expr           { $$ = $2 -> adopt ($1, $3); }
           | expr TOK_GT expr           { $$ = $2 -> adopt ($1, $3); }
           | expr TOK_GE expr           { $$ = $2 -> adopt ($1, $3); }
           | unop                       { $$ = $1; }
           | call                       { $$ = $1; }
           | TOK_PARAM expr ')'         { destroy($1, $3); $$ = $2; }
           | variable                   { $$ = $1; } 
           | constant                   { $$ = $1; }

unop       : '+' expr %prec TOK_POS  
             { $$ = $1->adopt_sym ($2, TOK_POS); }
           | '-' expr %prec TOK_NEG  
             { $$ = $1->adopt_sym ($2, TOK_NEG); }
           | TOK_NOT expr             { $$ = $1->adopt($2); }
           ;

statement  : block                                        { $$ = $1; }
           | while                                        { $$ = $1; }
           | ifelse                                       { $$ = $1; }
           | return                                       { $$ = $1; } 
           | expr ';'                       { destroy ($2); $$ = $1; }
           | ';'                          { destroy ($1); $$ = NULL; } 
           ;

block      : blockHelp '}'                                
                  { destroy($2); $$ = $1; }
           | blockHelp '}' ';'                            
                  { destroy ($2, $3); $$ = $1; }
           ;

blockHelp  : blockHelp statement                          
                  { $$ = $1 -> adopt ($2); }
           | '{' statement                                
                  { $$ = $1 -> adopt_sym ($2, TOK_BLOCK); }
           ;


while      : TOK_WHILE TOK_PARAM expr ')' statement       
             { destroy ($2); destroy ($4); $$ = $1 -> adopt ($3, $5); }
           ;

return     : TOK_RETURN ';'                               
             { destroy ($2); $$ = $1; }
           | TOK_RETURN expr ';'                          
             { destroy ($3); $$ = $1 -> adopt ($2); }
           ;

allocation : TOK_IDENT                                    
             { $$ = $1 -> adopt_sym (NULL, TOK_TYPEID); }
           | TOK_STRING TOK_PARAM expr ')'                
             { destroy ($2, $4); 
               $$ = $1 -> adopt_sym ($3, TOK_NEWSTR); }
           | basetype '[' expr ']'                        
             { destroy ($4); $$ = $2 -> adopt_sym ($1, TOK_NEWARRAY); 
               $2 -> adopt ($3); } 
           ;

call       : funCall ')'                                  
                { destroy ($2); $$ = $1; }
           ;

funCall    : funCall ',' expr                             
             { destroy ($2); $$ = $1 -> adopt ($3); }
           | TOK_IDENT TOK_PARAM expr                     
             { $$ = $2 -> adopt_sym ($1, TOK_CALL); $2 -> adopt ($3); }
           | TOK_IDENT TOK_PARAM                          
             { $$ = $2 -> adopt_sym ($1, TOK_CALL); }

variable   : TOK_IDENT   { $$ = $1 -> adopt_sym (NULL, TOK_DECLID); }
           | expr '[' expr ']'                            
             { destroy ($4); 
             $$ = $2 -> adopt_sym ($1, TOK_INDEX); $2 -> adopt ($3);  }
           | expr TOK_ARROW TOK_IDENT                     
             { $$ = $2 -> adopt ($1, $3); 
               $3 -> adopt_sym (NULL, TOK_FIELD); }
           | expr '.' TOK_IDENT {$$ = $2; $2 -> adopt ($1, $3); 
                                 $3 -> adopt_sym(NULL, TOK_FIELD); }
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


