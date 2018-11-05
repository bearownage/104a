// Vineet Ramareddi (vramared@ucsc.edu)
// Husain Adam Askari (haskari@ucsc.edu)
//
//
// Use cpp to scan a file and print line numbers.
// Print out each input line read in, then strtok it for
// tokens.

#include <string>
using namespace std;

#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <unistd.h>


#include "string_set.h"
#include "auxlib.h"

const string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;

/*
void scan_opts (int argc, char** argv) {
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   lexer::interactive = isatty (fileno (stdin))
                   // and isatty (fileno (stdout));
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
*/

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

// Print the meaning of a signal.
static void eprint_signal (const char* kind, int signal) {
   fprintf (stderr, ", %s %d", kind, signal);
   const char* sigstr = strsignal (signal);
   if (sigstr != nullptr) fprintf (stderr, " %s", sigstr);
}

// Print the status returned from a subprocess.
void eprint_status (const char* command, int status) {
   if (status == 0) return; 
   fprintf (stderr, "%s: status 0x%04X", command, status);
   if (WIFEXITED (status)) {
      fprintf (stderr, ", exit %d", WEXITSTATUS (status));
   }
   if (WIFSIGNALED (status)) {
      eprint_signal ("Terminated", WTERMSIG (status));
      #ifdef WCOREDUMP
      if (WCOREDUMP (status)) fprintf (stderr, ", core dumped");
      #endif
   }
   if (WIFSTOPPED (status)) {
      eprint_signal ("Stopped", WSTOPSIG (status));
   }
   if (WIFCONTINUED (status)) {
      fprintf (stderr, ", Continued");
   }
   fprintf (stderr, "\n");
}

// Run cpp against the lines of the file.
void cpplines (FILE* pipe, const char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == nullptr) break;
      chomp (buffer, '\n');
      // printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      //printf("Tokenized: %s", tokenize);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, inputname);
      if (sscanf_rc == 2) {
         // printf ("DIRECTIVE: line %d file \"%s\"\n", 
         //                     linenr, inputname);
         continue;
      }

      char* savepos = nullptr;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = nullptr;
         if (token == nullptr) break;
         // printf ("token %d.%d: [%s]\n",
         //        linenr, tokenct, token);
         const string* str = string_set::intern(token);
         const string* one = str;
         str = one;
         // printf ("intern (\"%s\") returned %p->\"%s\"\n",
        // //token, str, str->c_str()); 
      }
      ++linenr;
   }
}
int main (int argc, char** argv) {
   //scan_opts (argc, argv);
   FILE* pFile;
   const char* execname = basename (argv[0]);
   int exit_status = EXIT_SUCCESS;
   for (int argi = 1; argi < argc; ++argi) {
      char* filename = argv[argi];
      string command = CPP + " " + filename;
      // printf ("command=\"%s\"\n", command.c_str());
      FILE* pipe = popen (command.c_str(), "r");
      if (pipe == nullptr) {
         exit_status = EXIT_FAILURE;
         fprintf (stderr, "%s: %s: %s\n",
                  execname, command.c_str(), strerror (errno));
      }else {
         std::string fileOut;
         fileOut += filename;
         std::string fileOutCut (fileOut.begin(), fileOut.end()-3);
         fileOutCut += ".str";
         const char* outFile  = fileOutCut.c_str();
         //char* outFile = filename + ".";
         pFile = fopen(outFile, "w");
         cpplines (pipe, filename);
         string_set::dump(pFile);
         fclose(pFile);
         int pclose_rc = pclose (pipe);
         eprint_status (command.c_str(), pclose_rc);
         if (pclose_rc != 0) exit_status = EXIT_FAILURE;
      }
   }
   //string_set::dump (pFile);
   //fclose(pFile);
   return exit_status;
}

