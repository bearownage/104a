/* Vineet Ramareddi (vramared@ucsc.edu)
   Husain Adam Askari (haskari@ucsc.edu) */
%{

#include "lyutils.h"
#include "astree.h"
#include "yyparse.h"
#define YY_USER_ACTION  { lexer::advance(); }

%}

%option 8bit
%option debug
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option warn
/*%option verbose*/

LETTER          [A-Za-z_]
DIGIT           [0-9]
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)
STRING          (\"([^\\"\n]|\\[\\'"0nt])*\")
BADSTRING       (\"([^\\"\n]|\\[\\'"0nt])*\n)
CHAR            ('([^\\'\n]|\\[\\'"0nt])')
BADCHAR         ('([^\\'\n]|\\[\\'"0nt]))


%%

"#".*           { lexer::include(); }
[ \t]+          { }
\n              { lexer::newline(); }

"if"            { return yylval_token (TOK_IF); }                                                                                                                    
"else"          { return yylval_token (TOK_ELSE); }                                                                                                                  
"while"         { return yylval_token (TOK_WHILE); }                                                                                                                 
"return"        { return yylval_token (TOK_RETURN); }                                                                                                                
"int"           { return yylval_token (TOK_INT); }                                                                                                                   
"string"        { return yylval_token (TOK_STRING); }                                                                                                                
"struct"        { return yylval_token (TOK_STRUCT); }                                                                                                                
"void"          { return yylval_token (TOK_VOID); }                                                                                                                  
"new"           { return yylval_token (TOK_NEW); }                                                                                                                   
"null"          { return yylval_token (TOK_NULL); }                                                                                                                  
"not"           { return yylval_token (TOK_NOT); }
 
{NUMBER}        { return yylval_token (TOK_INTCON); }
{STRING}        { return yylval_token (TOK_STRINGCON); }
{IDENT}         { return yylval_token (TOK_IDENT); }
{CHAR}          { return yylval_token (TOK_CHARCON); }

"="             { return yylval_token ('='); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"^"             { return yylval_token ('^'); }
"("             { return yylval_token (TOK_PARAM); }
")"             { return yylval_token (')'); }
";"             { return yylval_token (';'); }
"%"             { return yylval_token ('%'); }
"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<"             { return yylval_token (TOK_LT); }
"<="            { return yylval_token (TOK_LE); }
">"             { return yylval_token (TOK_GT); }
">="            { return yylval_token (TOK_GE); }
"->"            { return yylval_token (TOK_ARROW); }
","             { return yylval_token (','); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }
"[]"            { return yylval_token (TOK_ARRAY); }

{NOTNUMBER}     { lexer::badtoken (yytext);
                  return yylval_token (TOK_INTCON); }
{BADSTRING}     { lexer::badtoken (yytext);
                  return yylval_token (TOK_STRINGCON); }
{BADCHAR}       { lexer::badtoken (yytext);
                  return yylval_token (TOK_CHARCON);   } 
.               { lexer::badchar (*yytext); }

%%

