// Vineet Raareddi (vramared@ucsc.edu)
// Husain Adam Askari (haskari@ucsc.edu)
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "auxlib.h"
#include "lyutils.h"
#include <algorithm>

bool lexer::interactive = true;
location lexer::lloc = {0, 1, 0};
size_t lexer::last_yyleng = 0;
vector<string> lexer::filenames;
extern FILE *tokFile;
//FILE *tokFile;
astree* parser::root = nullptr;

const string* lexer::filename (int filenr) {
   return &lexer::filenames.at(filenr);
}

void lexer::newfilename (const string& filename) {
    lexer::filenames.push_back(filename);
    vector<string> remDup;
    for (const auto & vec : lexer::filenames) {
        if (!(std::find(remDup.begin(), 
           remDup.end(), vec) != remDup.end())) {
           remDup.push_back(vec);
        }
    }
  
   lexer::lloc.filenr = remDup.size();
   
   int counter = 0;
   for (const auto & vec : remDup) {
       if (!vec.compare(filename)) {
          lexer::lloc.filenr = counter - 1;
          break;
       }
       counter++;
   }
    


}

void lexer::advance() {
   if (not interactive) {
      if (lexer::lloc.offset == 0) {
         printf (";%2zd.%3zd: ",
                 lexer::lloc.filenr, lexer::lloc.linenr);
      }
      printf ("%s", yytext);
   }
   lexer::lloc.offset += last_yyleng;
   last_yyleng = yyleng;
}

void lexer::newline() {
   ++lexer::lloc.linenr;
   lexer::lloc.offset = 0;
}

void lexer::badchar (unsigned char bad) {
   char buffer[16];
   snprintf (buffer, sizeof buffer,
             isgraph (bad) ? "%c" : "\\%03o", bad);
   errllocprintf (lexer::lloc, "invalid source character (%s)\n",
                  buffer);
}


void lexer::badtoken (char* lexeme) {
   errllocprintf (lexer::lloc, "invalid token (%s)\n", lexeme);
}

int yylval_token (int symbol) {
   yylval = new astree (symbol, lexer::lloc, yytext);
   int curr = symbol;
   fprintf(tokFile, "%lu %2lu.%03lu %3d %-13s %s\n", 
   lexer::lloc.filenr,lexer::lloc.linenr, lexer::lloc.offset, 
   curr, parser::get_tname(curr), yytext);
  // delete yylval;
   return symbol;
}

void lexer::include() {
   size_t linenr;
   static char filename[0x1000];
   assert (sizeof filename > strlen (yytext));
   int scan_rc = sscanf (yytext, "# %zd \"%[^\"]\"", &linenr, filename);
   if (scan_rc != 2) {
      errprintf ("%s: invalid directive, ignored\n", yytext);
   }else {
      fprintf(tokFile, "# %lu \"%s\"\n", linenr, filename); 
      if (yy_flex_debug) {
         fprintf (stderr, "--included # %zd \"%s\"\n",
                  linenr, filename);
      }
      lexer::lloc.linenr = linenr - 1;
      lexer::newfilename (filename);
   }
}

void yyerror (const char* message) {
   assert (not lexer::filenames.empty());
   errllocprintf (lexer::lloc, "%s\n", message);
}


