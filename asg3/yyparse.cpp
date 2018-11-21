/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "parser.y" /* yacc.c:339  */


#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <cassert>

#include "lyutils.h"
#include "astree.h"

#line 78 "yyparse.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_VOID = 258,
    TOK_CHAR = 259,
    TOK_INT = 260,
    TOK_STRING = 261,
    TOK_IF = 262,
    TOK_ELSE = 263,
    TOK_WHILE = 264,
    TOK_RETURN = 265,
    TOK_STRUCT = 266,
    TOK_NULL = 267,
    TOK_NEW = 268,
    TOK_VARDECL = 269,
    TOK_ARRAY = 270,
    TOK_ARROW = 271,
    TOK_BR = 272,
    TOK_EQ = 273,
    TOK_NE = 274,
    TOK_LT = 275,
    TOK_LE = 276,
    TOK_GT = 277,
    TOK_GE = 278,
    TOK_NOT = 279,
    TOK_IDENT = 280,
    TOK_INTCON = 281,
    TOK_CHARCON = 282,
    TOK_STRINGCON = 283,
    TOK_ROOT = 284,
    TOK_BLOCK = 285,
    TOK_CALL = 286,
    TOK_IFELSE = 287,
    TOK_INITDECL = 288,
    TOK_POS = 289,
    TOK_NEG = 290,
    TOK_NEWARRAY = 291,
    TOK_TYPEID = 292,
    TOK_FIELD = 293,
    TOK_NEWSTR = 294,
    TOK_PARAM = 295,
    TOK_FUNCTION = 296,
    TOK_PROTOTYPE = 297,
    TOK_DECLID = 298,
    TOK_INDEX = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 174 "yyparse.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   608

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    50,     2,     2,
      53,    54,    48,    46,    58,    47,    52,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    55,    56,    57,    58,    59,    60,    61,
      64,    67,    69,    74,    76,    80,    83,    88,    90,    92,
      95,    98,   103,   104,   105,   109,   111,   112,   115,   118,
     123,   124,   125,   127,   132,   133,   134,   135,   139,   144,
     146,   149,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     173,   175,   177,   180,   181,   182,   183,   184,   185,   188,
     190,   194,   196,   201,   205,   207,   211,   213,   216,   219,
     222,   226,   228,   230,   233,   234,   236,   239,   243,   244,
     245,   246
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_CHAR", "TOK_INT",
  "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_NULL", "TOK_NEW", "TOK_VARDECL", "TOK_ARRAY",
  "TOK_ARROW", "TOK_BR", "TOK_EQ", "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT",
  "TOK_GE", "TOK_NOT", "TOK_IDENT", "TOK_INTCON", "TOK_CHARCON",
  "TOK_STRINGCON", "TOK_ROOT", "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE",
  "TOK_INITDECL", "TOK_POS", "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID",
  "TOK_FIELD", "TOK_NEWSTR", "TOK_PARAM", "TOK_FUNCTION", "TOK_PROTOTYPE",
  "TOK_DECLID", "TOK_INDEX", "'='", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'['", "'.'", "'('", "')'", "'{'", "';'", "'}'", "','", "']'", "$accept",
  "start", "program", "structdef", "struc", "fielddecl", "globaldecl",
  "function", "func", "param", "identdec", "fnbody", "basetype",
  "localdecl", "ifelse", "expr", "unop", "statement", "block", "blockHelp",
  "while", "return", "allocation", "call", "funCall", "variable",
  "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    61,    43,    45,    42,    47,
      37,    91,    46,    40,    41,   123,    59,   125,    44,    93
};
# endif

#define YYPACT_NINF -34

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-34)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,    18,    97,   -34,     9,   -34,   -34,   -34,   -28,    17,
       7,   252,     2,   -34,    28,   561,     5,   -34,   -34,   -34,
     561,   561,   561,   228,   -34,   -34,     0,   -34,   -34,   -33,
      11,     4,   -34,   341,   -34,   -34,   -34,   202,   -34,   -34,
     -34,    30,   -34,   -34,   -34,   -34,   561,    14,   561,    15,
     -34,   353,    26,    42,   -23,   -19,   -34,   -34,    -1,   561,
     443,    -1,    -1,   -34,   -34,   -34,    27,    21,    90,   -34,
     151,   -34,     8,   177,   561,    61,   -34,    64,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,    65,   -34,    38,   -34,   -34,   561,   453,   561,   463,
     -34,   -34,   561,   561,   520,   -34,   -34,    74,   -34,   -34,
      45,    66,   -34,   -34,    90,    56,   -34,   -34,   392,    57,
     -34,   -34,    -8,    -8,    -8,    -8,    -8,    -8,   520,    10,
      10,    -1,    -1,    -1,   284,   -34,   -34,   520,   228,   500,
     228,   510,   299,   -34,   -34,   561,   -34,   -34,   -34,   -34,
     -34,   106,   228,   -34,   -34,   -34,   404,   228,   -34,   -34,
     -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     0,     1,     0,    34,    35,    36,     0,     0,
       0,     0,     0,    91,     0,     0,    84,    88,    90,    89,
       0,     0,     0,     0,    68,     3,     0,     4,     5,     0,
      24,     0,    65,     0,    55,     6,    63,     0,    64,    66,
      56,     0,    58,    59,     7,     8,     0,     0,     0,    84,
      74,     0,     0,    36,    76,     0,    42,    79,    62,    83,
       0,    60,    61,    72,    37,    10,     0,     0,    27,    22,
       0,    21,    23,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    69,    71,    80,     0,     0,     0,     0,
      75,    12,     0,     0,    82,    57,    11,     0,    13,    26,
      19,     0,    33,    32,     0,    18,    31,    30,     0,    59,
      28,    86,    49,    50,    51,    52,    53,    54,    43,    44,
      45,    46,    47,    48,     0,    87,    70,    81,     0,     0,
       0,     0,     0,    14,    20,     0,    25,    17,    16,    15,
      85,    39,     0,    73,    77,    78,     0,     0,    41,    38,
      40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
      12,   -34,   -13,    43,   -34,   -11,   -34,   -21,   -34,   -34,
     -34,   -34,   -34,   104,   -34,   -34,    46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    25,    26,    66,    27,    28,    29,    72,
     111,    73,    31,   112,    32,    33,    34,    35,    36,    37,
      38,    39,    56,    40,    41,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    55,    63,     5,    58,     6,     7,    68,    77,    60,
      61,    62,    46,    67,    30,    77,    94,    59,     3,    75,
     -37,    69,    70,    71,    47,    64,    77,    52,   -37,    76,
     -37,     5,   103,     6,    53,    97,   107,    99,    85,    86,
      87,    88,    89,    90,    91,    59,   108,    48,   104,   113,
      90,    91,   117,    54,    98,    59,    74,    65,    87,    88,
      89,    90,    91,   118,    44,    45,   114,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     109,   101,   102,   106,    95,   137,   120,   139,    96,   121,
     135,   141,   142,     5,   136,     6,     7,    -2,     4,   143,
       5,   144,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   145,   147,   149,   157,    64,   116,   151,    57,   153,
     119,    15,    16,    17,    18,    19,   146,     0,     0,     0,
       0,   158,     0,     0,   156,     0,   160,    20,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,     0,    23,    24,     5,     0,     6,     7,     8,     9,
      10,    11,     0,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
       5,     0,     6,     7,     8,     9,    10,    11,     0,    13,
      14,    20,     0,     0,     0,     0,     0,    21,    22,     0,
       0,    15,    16,    17,    18,    19,    23,    24,   110,     8,
       9,    10,    11,     0,    13,    14,     0,    20,     0,     0,
       0,     0,     0,    21,    22,     0,    15,    49,    17,    18,
      19,     0,    23,    24,   115,     8,     9,    10,    11,     0,
      13,    14,    20,     0,     0,     0,     0,     0,    21,    22,
       0,     0,    15,    49,    17,    18,    19,    23,    24,    93,
       0,     0,     0,     0,    13,    14,     0,     0,    20,     0,
       0,     0,     0,     0,    21,    22,    15,    49,    17,    18,
      19,     0,     0,    23,    24,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,    21,    22,
      77,     0,    78,    79,    80,    81,    82,    83,    50,     0,
       0,     0,     0,     0,     0,    77,     0,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,   150,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,    77,   155,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,    77,
       0,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,    92,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,    77,   100,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
      77,     0,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,   148,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,    77,
     159,    78,    79,    80,    81,    82,    83,     0,     0,    77,
       0,    78,    79,    80,    81,    82,    83,     0,     0,    77,
       0,    78,    79,    80,    81,    82,    83,     0,    84,    85,
      86,    87,    88,    89,    90,    91,     0,   105,    84,    85,
      86,    87,    88,    89,    90,    91,     0,   138,    84,    85,
      86,    87,    88,    89,    90,    91,    77,   140,    78,    79,
      80,    81,    82,    83,     0,     0,    77,     0,    78,    79,
      80,    81,    82,    83,     0,     0,    77,     0,    78,    79,
      80,    81,    82,    83,     0,    84,    85,    86,    87,    88,
      89,    90,    91,     0,   152,    84,    85,    86,    87,    88,
      89,    90,    91,     0,   154,    84,    85,    86,    87,    88,
      89,    90,    91,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    49,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
      11,    14,    23,     3,    15,     5,     6,    40,    16,    20,
      21,    22,    40,    26,     2,    16,    37,    40,     0,    15,
      15,    54,    55,    56,     7,    25,    16,    25,    51,    25,
      25,     3,    51,     5,     6,    46,    15,    48,    46,    47,
      48,    49,    50,    51,    52,    40,    25,    40,    59,    70,
      51,    52,    73,    25,    40,    40,    45,    57,    48,    49,
      50,    51,    52,    74,    55,    56,    58,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      68,    55,    40,    56,    54,    96,    25,    98,    58,    25,
      25,   102,   103,     3,    56,     5,     6,     0,     1,    25,
       3,    56,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    45,    56,    56,     8,    25,    73,   138,    14,   140,
      74,    24,    25,    26,    27,    28,   114,    -1,    -1,    -1,
      -1,   152,    -1,    -1,   145,    -1,   157,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    24,    25,    26,    27,    28,    55,    56,    57,     7,
       8,     9,    10,    -1,    12,    13,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    24,    25,    26,    27,
      28,    -1,    55,    56,    57,     7,     8,     9,    10,    -1,
      12,    13,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    24,    25,    26,    27,    28,    55,    56,    57,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    47,    24,    25,    26,    27,
      28,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      16,    -1,    18,    19,    20,    21,    22,    23,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    16,    59,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    16,    56,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    56,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    16,
      56,    18,    19,    20,    21,    22,    23,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    45,    46,
      47,    48,    49,    50,    51,    52,    16,    54,    18,    19,
      20,    21,    22,    23,    -1,    -1,    16,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    16,    -1,    18,    19,
      20,    21,    22,    23,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    45,    46,    47,    48,    49,
      50,    51,    52,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     1,     3,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    24,    25,    26,    27,    28,
      40,    46,    47,    55,    56,    63,    64,    66,    67,    68,
      70,    72,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    84,    85,    86,    55,    56,    40,     7,    40,    25,
      56,    75,    25,     6,    25,    72,    82,    83,    75,    40,
      75,    75,    75,    77,    25,    57,    65,    72,    40,    54,
      55,    56,    69,    71,    45,    15,    25,    16,    18,    19,
      20,    21,    22,    23,    45,    46,    47,    48,    49,    50,
      51,    52,    56,    57,    77,    54,    58,    75,    40,    75,
      56,    55,    40,    51,    75,    54,    56,    15,    25,    70,
      57,    70,    73,    77,    58,    57,    73,    77,    75,    86,
      25,    25,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    25,    56,    75,    54,    75,
      54,    75,    75,    25,    56,    45,    70,    56,    56,    56,
      59,    77,    54,    77,    54,    59,    75,     8,    77,    56,
      77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    72,    72,    72,    72,    73,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    80,    81,    81,    82,    82,    82,    82,
      83,    84,    84,    84,    85,    85,    85,    85,    86,    86,
      86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     3,     3,     0,
       2,     3,     3,     2,     3,     4,     4,     4,     3,     3,
       4,     2,     2,     2,     1,     3,     2,     1,     3,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     4,     5,
       7,     6,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       3,     2,     2,     5,     2,     3,     1,     4,     4,     1,
       2,     3,     3,     2,     1,     4,     3,     3,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
          case 3: /* TOK_VOID  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 872 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 4: /* TOK_CHAR  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 878 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 5: /* TOK_INT  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 884 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 6: /* TOK_STRING  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 890 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 7: /* TOK_IF  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 896 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 8: /* TOK_ELSE  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 902 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 9: /* TOK_WHILE  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 908 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 10: /* TOK_RETURN  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 914 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 11: /* TOK_STRUCT  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 920 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 12: /* TOK_NULL  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 926 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 13: /* TOK_NEW  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 932 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 14: /* TOK_VARDECL  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 938 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 15: /* TOK_ARRAY  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 944 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 16: /* TOK_ARROW  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 950 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 17: /* TOK_BR  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 956 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 18: /* TOK_EQ  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 962 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 19: /* TOK_NE  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 968 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 20: /* TOK_LT  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 974 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 21: /* TOK_LE  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 980 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 22: /* TOK_GT  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 986 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 23: /* TOK_GE  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 992 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 24: /* TOK_NOT  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 998 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 25: /* TOK_IDENT  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1004 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 26: /* TOK_INTCON  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1010 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 27: /* TOK_CHARCON  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1016 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 28: /* TOK_STRINGCON  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1022 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 29: /* TOK_ROOT  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1028 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 30: /* TOK_BLOCK  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1034 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 31: /* TOK_CALL  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1040 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 32: /* TOK_IFELSE  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1046 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 33: /* TOK_INITDECL  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1052 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 34: /* TOK_POS  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1058 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 35: /* TOK_NEG  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1064 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 36: /* TOK_NEWARRAY  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1070 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 37: /* TOK_TYPEID  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1076 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 38: /* TOK_FIELD  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1082 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 39: /* TOK_NEWSTR  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1088 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 40: /* TOK_PARAM  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1094 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 41: /* TOK_FUNCTION  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1100 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 42: /* TOK_PROTOTYPE  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1106 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 43: /* TOK_DECLID  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1112 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 44: /* TOK_INDEX  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1118 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 45: /* '='  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1124 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 46: /* '+'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1130 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 47: /* '-'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1136 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 48: /* '*'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1142 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 49: /* '/'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1148 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 50: /* '%'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1154 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 51: /* '['  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1160 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 52: /* '.'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1166 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 53: /* '('  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1172 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 54: /* ')'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1178 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 55: /* '{'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1184 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 56: /* ';'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1190 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 57: /* '}'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1196 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 58: /* ','  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1202 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 59: /* ']'  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1208 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 61: /* start  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1214 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 62: /* program  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1220 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 63: /* structdef  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1226 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 64: /* struc  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1232 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 65: /* fielddecl  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1238 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 66: /* globaldecl  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1244 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 67: /* function  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1250 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 68: /* func  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1256 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 69: /* param  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1262 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 70: /* identdec  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1268 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 71: /* fnbody  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1274 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 72: /* basetype  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1280 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 73: /* localdecl  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1286 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 74: /* ifelse  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1292 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 75: /* expr  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1298 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 76: /* unop  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1304 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 77: /* statement  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1310 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 78: /* block  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1316 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 79: /* blockHelp  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1322 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 80: /* while  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1328 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 81: /* return  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1334 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 82: /* allocation  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1340 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 83: /* call  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1346 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 84: /* funCall  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1352 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 85: /* variable  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1358 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 86: /* constant  */
#line 22 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1364 "yyparse.cpp" /* yacc.c:684  */
        break;


      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* TOK_VOID  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1710 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOK_CHAR  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1716 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOK_INT  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1722 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOK_STRING  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1728 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOK_IF  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1734 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 8: /* TOK_ELSE  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1740 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 9: /* TOK_WHILE  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1746 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 10: /* TOK_RETURN  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1752 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 11: /* TOK_STRUCT  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1758 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 12: /* TOK_NULL  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1764 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 13: /* TOK_NEW  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1770 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 14: /* TOK_VARDECL  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1776 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 15: /* TOK_ARRAY  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1782 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 16: /* TOK_ARROW  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1788 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 17: /* TOK_BR  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1794 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 18: /* TOK_EQ  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1800 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 19: /* TOK_NE  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1806 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 20: /* TOK_LT  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1812 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 21: /* TOK_LE  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1818 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 22: /* TOK_GT  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1824 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 23: /* TOK_GE  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1830 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 24: /* TOK_NOT  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1836 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 25: /* TOK_IDENT  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1842 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 26: /* TOK_INTCON  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1848 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 27: /* TOK_CHARCON  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1854 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 28: /* TOK_STRINGCON  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1860 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 29: /* TOK_ROOT  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1866 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 30: /* TOK_BLOCK  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1872 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 31: /* TOK_CALL  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1878 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 32: /* TOK_IFELSE  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1884 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 33: /* TOK_INITDECL  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1890 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 34: /* TOK_POS  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1896 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 35: /* TOK_NEG  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1902 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 36: /* TOK_NEWARRAY  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1908 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 37: /* TOK_TYPEID  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1914 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 38: /* TOK_FIELD  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1920 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 39: /* TOK_NEWSTR  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1926 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 40: /* TOK_PARAM  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1932 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 41: /* TOK_FUNCTION  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1938 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 42: /* TOK_PROTOTYPE  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1944 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 43: /* TOK_DECLID  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1950 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 44: /* TOK_INDEX  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1956 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 45: /* '='  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1962 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 46: /* '+'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1968 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 47: /* '-'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1974 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 48: /* '*'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1980 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 49: /* '/'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1986 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 50: /* '%'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1992 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 51: /* '['  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1998 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 52: /* '.'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2004 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 53: /* '('  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2010 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 54: /* ')'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2016 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 55: /* '{'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2022 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 56: /* ';'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2028 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 57: /* '}'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2034 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 58: /* ','  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2040 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 59: /* ']'  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2046 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 61: /* start  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2052 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 62: /* program  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2058 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 63: /* structdef  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2064 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 64: /* struc  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2070 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 65: /* fielddecl  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2076 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 66: /* globaldecl  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2082 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 67: /* function  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2088 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 68: /* func  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2094 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 69: /* param  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2100 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 70: /* identdec  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2106 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 71: /* fnbody  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2112 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 72: /* basetype  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2118 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 73: /* localdecl  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2124 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 74: /* ifelse  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2130 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 75: /* expr  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2136 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 76: /* unop  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2142 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 77: /* statement  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2148 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 78: /* block  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2154 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 79: /* blockHelp  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2160 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 80: /* while  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2166 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 81: /* return  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2172 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 82: /* allocation  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2178 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 83: /* call  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2184 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 84: /* funCall  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2190 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 85: /* variable  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2196 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 86: /* constant  */
#line 21 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2202 "yyparse.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 24 "parser.y" /* yacc.c:1429  */
{
   parser::root = new astree (TOK_ROOT, {0, 0, 0}, "");
}

#line 2292 "yyparse.cpp" /* yacc.c:1429  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) = nullptr; }
#line 2474 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2480 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2486 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2492 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2498 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); destroy ((yyvsp[0]));}
#line 2504 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); destroy ((yyvsp[0]));}
#line 2510 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = parser::root; }
#line 2516 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 64 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]);}
#line 2522 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 68 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2528 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 70 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); 
               (yyvsp[-1]) -> adopt_sym (NULL, TOK_TYPEID); }
#line 2535 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 75 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->  adopt ((yyvsp[0])); (yyvsp[0]) -> adopt_sym(NULL, TOK_FIELD); }
#line 2541 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2])); (yyvsp[-2]) -> adopt ((yyvsp[0])); (yyvsp[0]) -> adopt_sym(NULL, TOK_FIELD);}
#line 2547 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 81 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-3]), (yyvsp[-1])); 
               (yyvsp[-2]) -> adopt_sym (NULL, TOK_VARDECL); }
#line 2554 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 84 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-3]), (yyvsp[-1])); 
               (yyvsp[-2]) -> adopt_sym (NULL, TOK_VARDECL); }
#line 2561 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 89 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-1]), (yyvsp[0])); (yyval) = (yyvsp[-3]) -> adopt ((yyvsp[-2])); }
#line 2567 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2573 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 93 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); 
               (yyvsp[-1]) -> adopt_sym (NULL, TOK_BLOCK); }
#line 2580 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 96 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-2]), (yyvsp[-1])); destroy ((yyvsp[0])); 
               (yyval) = (yyvsp[-3]) -> adopt_sym (NULL, TOK_PROTOTYPE); }
#line 2587 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = 
               (yyvsp[-1]) -> adopt_sym (NULL, TOK_PROTOTYPE);}
#line 2594 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 103 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2600 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2606 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval) = new astree(TOK_FUNCTION, (yyvsp[0]) -> lloc ,""); 
                         (yyval) -> adopt ((yyvsp[0])); }
#line 2613 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 109 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-1])); 
                                   (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[0])); }
#line 2620 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2626 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2632 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2])); 
                (yyvsp[-2]) -> adopt ((yyvsp[0])); (yyvsp[0]) -> adopt_sym (NULL, TOK_DECLID); }
#line 2639 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); 
                (yyvsp[0]) -> adopt_sym (NULL, TOK_DECLID); }
#line 2646 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2652 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2658 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt_sym ((yyvsp[0]), TOK_BLOCK); }
#line 2664 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt_sym ((yyvsp[0]), TOK_BLOCK); }
#line 2670 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2676 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2682 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2688 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) -> adopt_sym (NULL, TOK_TYPEID); }
#line 2694 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 140 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-3]), (yyvsp[-1])); 
              (yyvsp[-2]) -> adopt_sym(NULL, TOK_VARDECL); }
#line 2701 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 145 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-3]), (yyvsp[-1])); (yyval) = (yyvsp[-4]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2707 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 147 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-5]), (yyvsp[-3])); destroy ((yyvsp[-1])); 
               (yyval) = (yyvsp[-6]) -> adopt ((yyvsp[-4]), (yyvsp[-2])); (yyvsp[-6]) -> adopt ((yyvsp[0])); }
#line 2714 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 150 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-5]), (yyvsp[-3])); destroy ((yyvsp[-1])); 
               (yyval) = (yyvsp[-4]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2721 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2727 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2733 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2739 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2745 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2751 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2757 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2763 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2769 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2775 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2781 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2787 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2793 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2799 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2805 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2811 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 169 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-2]), (yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2817 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2823 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2829 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), TOK_POS); }
#line 2835 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), TOK_NEG); }
#line 2841 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2847 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2853 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2859 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2865 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2871 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 184 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2877 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 185 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = NULL; }
#line 2883 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 189 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2889 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 191 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-1]), (yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2895 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2901 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt_sym ((yyvsp[0]), TOK_BLOCK); }
#line 2907 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 202 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-3])); destroy ((yyvsp[-1])); (yyval) = (yyvsp[-4]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2913 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 206 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2919 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 208 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2925 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) -> adopt_sym (NULL, TOK_TYPEID); }
#line 2931 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 214 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-2]), (yyvsp[0])); 
               (yyval) = (yyvsp[-3]) -> adopt_sym ((yyvsp[-1]), TOK_NEWSTR); }
#line 2938 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 217 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt_sym ((yyvsp[-3]), TOK_NEWARRAY); 
               (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2945 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2951 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 223 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2957 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 227 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-1])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[0])); }
#line 2963 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt_sym ((yyvsp[-2]), TOK_CALL); (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2969 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) -> adopt_sym ((yyvsp[-1]), TOK_CALL); }
#line 2975 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) -> adopt_sym (NULL, TOK_DECLID); }
#line 2981 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 235 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt_sym ((yyvsp[-3]), TOK_INDEX); (yyvsp[-2]) -> adopt ((yyvsp[-1]));  }
#line 2987 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); 
               (yyvsp[0]) -> adopt_sym (NULL, TOK_FIELD); }
#line 2994 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]); (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); 
                                 (yyvsp[0]) -> adopt_sym(NULL, TOK_FIELD); }
#line 3001 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3007 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3013 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3019 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3025 "yyparse.cpp" /* yacc.c:1646  */
    break;


#line 3029 "yyparse.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 250 "parser.y" /* yacc.c:1906  */



const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}


