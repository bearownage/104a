// $Id: main.cpp,v 1.18 2017-10-19 16:02:14-07 - - $
// Vineet Ramareddi (vramared@ucsc.edu)
// Husain Adam Askari (haskari@ucsc.edu)
#include <string>
#include <vector>
using namespace std;

#include <assert.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "astree.h"
#include "auxlib.h"
#include "lyutils.h"
#include "string_set.h"

const string cpp_name = "/usr/bin/cpp";
string cpp_command;
FILE *tokFile;
FILE *astFile;
// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* yyin.
void cpp_popen (const char* filename) {
   cpp_command = cpp_name + " " +  filename;
   yyin = popen (cpp_command.c_str(), "r");

   if (yyin == nullptr) {
      syserrprintf (cpp_command.c_str());
      exit (exec::exit_status);
   }else {
      if (yy_flex_debug) {
         fprintf (stderr, "-- popen (%s), fileno(yyin) = %d\n",
                  cpp_command.c_str(), fileno (yyin));
      }
   
      lexer::newfilename (cpp_command);
   }
}

void cpp_pclose() {
   int pclose_rc = pclose (yyin);
   eprint_status (cpp_command.c_str(), pclose_rc);
   if (pclose_rc != 0) exec::exit_status = EXIT_FAILURE;
}

void scan_opts (int argc, char** argv) {
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   lexer::interactive = isatty (fileno (stdin))
                    and isatty (fileno (stdout));
   for(;;) {
      int opt = getopt (argc, argv, "@:ly");
      if (opt == EOF) break;
      switch (opt) {
         case '@': set_debugflags (optarg);   break;
         case 'l': yy_flex_debug = 1;         break;
         case 'y': yydebug = 1;               break;
         default:  errprintf ("bad option (%c)\n", optopt); break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n",
                 exec::execname.c_str());
      exit (exec::exit_status);
   }
   const char* filename = optind == argc ? "-" : argv[optind];
   cpp_popen (filename);
}

int main (int argc, char** argv) {
   exec::execname = basename (argv[0]);
   if (yydebug or yy_flex_debug) {
      fprintf (stderr, "Command:");
      for (char** arg = &argv[0]; arg < &argv[argc]; ++arg) {
            fprintf (stderr, " %s", *arg);
      }
      fprintf (stderr, "\n");
   }
   char* filename = argv[argc-1];
   std::string filein;
   filein += filename;
   std::string filenameStr (filein.begin(), filein.end()-3);
   std::string filenameTok (filein.begin(), filein.end()-3);
   std::string filenameAst (filein.begin(), filein.end()-3);
   filenameStr += ".str";
   filenameTok += ".tok";
   filenameAst += ".ast";
   const char* outFileTok = filenameTok.c_str();
   const char* outFileStr = filenameStr.c_str();
   const char* outFileAst = filenameAst.c_str();
   tokFile = fopen(outFileTok, "w+");
   scan_opts (argc, argv);
  
   int parse_rc = yyparse();
   cpp_pclose();
   yylex_destroy();
   fclose(tokFile);
   
   FILE* strFile;
   strFile = fopen(outFileStr, "w");
   string_set::dump(strFile);
   fclose(strFile);

   if(parser::root == nullptr) {
     printf("nullptr");
   }
    
   FILE* astFile;
   astFile = fopen(outFileAst, "w");
   parser::root -> dump_tree(astFile, 0);
   fclose(astFile);
   /*
   FILE* astFile;
   astFile = fopen("hello.ast", "w");
   parser::root -> dump_tree(astFile, 0);
   fclose(astFile);
*/
   if (yydebug or yy_flex_debug) {
      fprintf (stderr, "Dumping parser::root:\n");
      if (parser::root != nullptr) parser::root->dump_tree (stderr);
      fprintf (stderr, "Dumping string_set:\n");
      string_set::dump (stderr);
   }
   if (parse_rc) {
      errprintf ("parse failed (%d)\n", parse_rc);
   }else {
   
   }
   return exec::exit_status;
}


