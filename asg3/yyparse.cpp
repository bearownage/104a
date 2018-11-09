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


#line 79 "yyparse.cpp" /* yacc.c:339  */

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
    TOK_DECLID = 298
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
#define YYLAST   643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    48,     2,     2,
      49,    50,    46,    44,    54,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    56,    57,    58,    59,    60,    61,    62,
      65,    68,    69,    72,    73,    76,    79,    80,    83,    84,
      85,    93,    94,    95,   102,   103,   106,   107,   108,   109,
     110,   113,   114,   115,   116,   119,   122,   125,   126,   129,
     130,   131,   132,   133,   134,   135,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   152,
     153,   154,   155,   158,   159,   160,   161,   162,   163,   166,
     169,   170,   173,   176,   177,   180,   181,   182,   185,   188,
     189,   190,   193,   194,   195,   198,   199,   200,   201
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
  "TOK_DECLID", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'{'",
  "';'", "'}'", "','", "'='", "'['", "']'", "$accept", "start", "program",
  "structdef", "struc", "fielddecl", "globaldecl", "function", "func",
  "param", "identdec", "fnbody", "basetype", "localdecl", "ifelse", "expr",
  "binop", "unop", "statement", "block", "blockHelp", "while", "return",
  "allocation", "call", "funCall", "variable", "constant", YY_NULLPTR
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
     295,   296,   297,   298,    43,    45,    42,    47,    37,    40,
      41,   123,    59,   125,    44,    61,    91,    93
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -39,    13,   129,   -39,   -23,   -39,   -39,   -39,   -38,    17,
     -19,    72,     1,   -39,   243,   594,     0,   -39,   -39,   -39,
     594,   594,   594,   250,   -39,   -39,     2,   -39,   -39,    54,
      16,    42,   -39,   353,   -39,   -39,   -39,   -39,   192,   -39,
     -39,   -39,   284,   -39,   -39,   -39,   -39,   594,    -3,   594,
      18,   -39,   394,    -9,    19,   -34,     4,    -2,   -39,    -2,
     -39,    -2,    -2,   407,   -39,   -39,   -39,    34,    87,    14,
     -39,   183,   -39,     7,    38,     6,    31,   -39,    70,   594,
     594,   594,   594,   594,   594,   594,   594,   594,   594,   594,
     -39,   594,   594,   -39,   -39,   -39,   -39,   569,   448,   594,
     461,   -39,   -39,   594,   594,   -39,   -39,    76,   -39,   -39,
      89,   -39,   -39,    14,   -39,   -39,   -39,    55,   -39,   -39,
     115,   115,   115,   115,   115,   115,   166,   166,    -2,    -2,
      -2,   569,   297,   250,   502,   250,   515,   339,   -39,   594,
     -39,   -39,   -39,   100,   250,   -39,   -39,   -39,   556,   250,
     -39,   -39,   -39
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     0,     1,     0,    31,    32,    33,     0,     0,
       0,    46,     0,    88,    46,    46,    82,    85,    87,    86,
      46,    46,    46,    46,    68,     3,     0,     4,     5,     0,
      20,     0,    65,     0,    40,    41,     6,    63,    46,    64,
      66,    42,    46,    44,    45,     7,     8,    46,     0,    46,
      82,    73,     0,     0,    33,    75,     0,    61,    39,    62,
      81,    59,    60,     0,    71,    34,    10,     0,     0,    23,
      18,    30,    17,    19,    46,     0,     0,    25,     0,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      67,    46,    46,    69,    70,    78,    79,    80,     0,    46,
       0,    74,    12,    46,    46,    43,    11,     0,    13,    22,
       0,    29,    28,     0,    16,    27,    26,     0,    24,    84,
      53,    54,    55,    56,    57,    58,    48,    49,    50,    51,
      52,    47,     0,    46,     0,    46,     0,     0,    14,    46,
      21,    15,    83,    37,    46,    72,    76,    77,     0,    46,
      38,    35,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
      10,   -39,     9,    35,   -39,   -11,   -39,   -39,   -22,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,    39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    25,    26,    67,    27,    28,    29,    73,
     110,    74,    31,   111,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    58,    41,    42,    43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    64,    47,    57,    59,     5,    60,     6,     7,    61,
      62,    63,    30,     3,    78,   -34,    94,     5,    13,     6,
       7,    49,   -34,    56,    48,   -34,    53,    65,    45,    46,
      75,    97,    17,    18,    19,    68,    98,    99,   100,    65,
      60,     5,   102,     6,     7,     8,     9,    10,    11,   112,
      13,    14,   116,    91,    92,    66,   118,    76,    60,   103,
     104,   113,    15,    16,    17,    18,    19,    77,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   109,
     131,   132,    20,    21,    13,    14,   106,    22,   134,    23,
      24,   114,   136,   137,    69,   119,    15,    50,    17,    18,
      19,   138,   107,   139,    70,    71,    72,   141,   149,   115,
       0,   143,   108,   145,   117,     0,    20,    21,     0,     0,
       0,    22,   150,   140,    51,     0,     0,   152,   148,    -2,
       4,    78,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,   -46,     0,   -46,   -46,   -46,
     -46,   -46,   -46,    15,    16,    17,    18,    19,     0,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
      91,    92,     0,    20,    21,   -46,   -46,   -46,    22,     0,
      23,    24,    78,     0,   -46,   -46,     5,     0,     6,     7,
       8,     9,    10,    11,     0,    13,    14,     0,     0,     8,
       9,    10,    11,     0,    13,    14,     0,    15,    16,    17,
      18,    19,    87,    88,    89,     0,    15,    50,    17,    18,
      19,    91,    92,     0,     0,     0,     0,    20,    21,     0,
       0,     0,    22,     0,    23,    24,    20,    21,     0,     0,
       0,    22,     0,    23,    24,    93,     5,     0,     6,    54,
       0,     0,     0,     0,     0,    13,    14,     8,     9,    10,
      11,     0,    13,    14,     0,     0,     0,    15,    55,    17,
      18,    19,     0,     0,    15,    50,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
       0,     0,    22,     0,    20,    21,    13,    14,     0,    22,
       0,    23,    24,     0,     0,     0,     0,     0,    15,    50,
      17,    18,    19,    78,     0,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,    20,    21,
       0,     0,     0,    22,    95,     0,     0,     0,    96,     0,
       0,    85,    86,    87,    88,    89,     0,     0,     0,     0,
       0,     0,    91,    92,   142,    78,     0,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    78,
       0,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,    91,    92,   147,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,     0,    91,    92,
      78,     0,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,     0,     0,   101,     0,     0,    91,
      92,    85,    86,    87,    88,    89,     0,   105,     0,     0,
       0,     0,    91,    92,    78,     0,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,     0,   133,     0,
       0,     0,     0,    91,    92,    85,    86,    87,    88,    89,
       0,   135,     0,     0,     0,     0,    91,    92,    78,     0,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,     0,   144,     0,     0,     0,     0,    91,    92,    85,
      86,    87,    88,    89,     0,   146,     0,     0,     0,     0,
      91,    92,    78,     0,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,    78,     0,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,    13,    14,   151,     0,
       0,    91,    92,    85,    86,    87,    88,    89,    15,    50,
      17,    18,    19,     0,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    21,
       0,     0,     0,    22
};

static const yytype_int16 yycheck[] =
{
      11,    23,    40,    14,    15,     3,    40,     5,     6,    20,
      21,    22,     2,     0,    16,    15,    38,     3,    12,     5,
       6,    40,    56,    14,     7,    25,    25,    25,    51,    52,
      14,    42,    26,    27,    28,    26,    47,    40,    49,    25,
      40,     3,    51,     5,     6,     7,     8,     9,    10,    71,
      12,    13,    74,    55,    56,    53,    25,    15,    40,    40,
      56,    54,    24,    25,    26,    27,    28,    25,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    69,
      91,    92,    44,    45,    12,    13,    52,    49,    99,    51,
      52,    53,   103,   104,    40,    25,    24,    25,    26,    27,
      28,    25,    15,    14,    50,    51,    52,    52,     8,    74,
      -1,   133,    25,   135,    75,    -1,    44,    45,    -1,    -1,
      -1,    49,   144,   113,    52,    -1,    -1,   149,   139,     0,
       1,    16,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    -1,    44,    45,    46,    47,    48,    49,    -1,
      51,    52,    16,    -1,    55,    56,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,     7,
       8,     9,    10,    -1,    12,    13,    -1,    24,    25,    26,
      27,    28,    46,    47,    48,    -1,    24,    25,    26,    27,
      28,    55,    56,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    49,    -1,    51,    52,    44,    45,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,     3,    -1,     5,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    -1,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    49,    -1,    44,    45,    12,    13,    -1,    49,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      16,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    44,    45,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    55,    56,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    -1,    50,    -1,
      -1,    -1,    -1,    55,    56,    44,    45,    46,    47,    48,
      -1,    50,    -1,    -1,    -1,    -1,    55,    56,    16,    -1,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    -1,    55,    56,    44,
      45,    46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,
      55,    56,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    -1,    12,    13,    52,    -1,
      -1,    55,    56,    44,    45,    46,    47,    48,    24,    25,
      26,    27,    28,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,    60,     0,     1,     3,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    24,    25,    26,    27,    28,
      44,    45,    49,    51,    52,    61,    62,    64,    65,    66,
      68,    70,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    82,    83,    84,    85,    51,    52,    40,     7,    40,
      25,    52,    73,    25,     6,    25,    70,    73,    81,    73,
      40,    73,    73,    73,    76,    25,    53,    63,    70,    40,
      50,    51,    52,    67,    69,    14,    15,    25,    16,    18,
      19,    20,    21,    22,    23,    44,    45,    46,    47,    48,
      52,    55,    56,    53,    76,    50,    54,    73,    73,    40,
      73,    52,    51,    40,    56,    50,    52,    15,    25,    68,
      68,    71,    76,    54,    53,    71,    76,    85,    25,    25,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    50,    73,    50,    73,    73,    25,    14,
      68,    52,    57,    76,    50,    76,    50,    57,    73,     8,
      76,    52,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    60,    60,    60,
      61,    62,    62,    63,    63,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    77,
      78,    78,    79,    80,    80,    81,    81,    81,    82,    83,
      83,    83,    84,    84,    84,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     3,     3,     0,
       2,     3,     3,     2,     3,     4,     3,     2,     2,     2,
       1,     3,     2,     1,     3,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     4,     7,     5,     6,     2,
       1,     1,     1,     3,     1,     1,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       2,     2,     5,     2,     3,     1,     4,     4,     2,     2,
       2,     2,     1,     4,     3,     1,     1,     1,     1
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
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 873 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 4: /* TOK_CHAR  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 879 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 5: /* TOK_INT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 885 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 6: /* TOK_STRING  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 891 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 7: /* TOK_IF  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 897 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 8: /* TOK_ELSE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 903 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 9: /* TOK_WHILE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 909 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 10: /* TOK_RETURN  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 915 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 11: /* TOK_STRUCT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 921 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 12: /* TOK_NULL  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 927 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 13: /* TOK_NEW  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 933 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 14: /* TOK_VARDECL  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 939 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 15: /* TOK_ARRAY  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 945 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 16: /* TOK_ARROW  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 951 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 17: /* TOK_BR  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 957 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 18: /* TOK_EQ  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 963 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 19: /* TOK_NE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 969 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 20: /* TOK_LT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 975 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 21: /* TOK_LE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 981 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 22: /* TOK_GT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 987 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 23: /* TOK_GE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 993 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 24: /* TOK_NOT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 999 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 25: /* TOK_IDENT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1005 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 26: /* TOK_INTCON  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1011 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 27: /* TOK_CHARCON  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1017 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 28: /* TOK_STRINGCON  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1023 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 29: /* TOK_ROOT  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1029 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 30: /* TOK_BLOCK  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1035 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 31: /* TOK_CALL  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1041 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 32: /* TOK_IFELSE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1047 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 33: /* TOK_INITDECL  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1053 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 34: /* TOK_POS  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1059 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 35: /* TOK_NEG  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1065 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 36: /* TOK_NEWARRAY  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1071 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 37: /* TOK_TYPEID  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1077 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 38: /* TOK_FIELD  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1083 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 39: /* TOK_NEWSTR  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1089 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 40: /* TOK_PARAM  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1095 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 41: /* TOK_FUNCTION  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1101 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 42: /* TOK_PROTOTYPE  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1107 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 43: /* TOK_DECLID  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1113 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 44: /* '+'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1119 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 45: /* '-'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1125 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 46: /* '*'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1131 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 47: /* '/'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1137 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 48: /* '%'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1143 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 49: /* '('  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1149 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 50: /* ')'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1155 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 51: /* '{'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1161 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 52: /* ';'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1167 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 53: /* '}'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1173 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 54: /* ','  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1179 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 55: /* '='  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1185 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 56: /* '['  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1191 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 57: /* ']'  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1197 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 59: /* start  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1203 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 60: /* program  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1209 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 61: /* structdef  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1215 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 62: /* struc  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1221 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 63: /* fielddecl  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1227 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 64: /* globaldecl  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1233 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 65: /* function  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1239 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 66: /* func  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1245 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 67: /* param  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1251 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 68: /* identdec  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1257 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 69: /* fnbody  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1263 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 70: /* basetype  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1269 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 71: /* localdecl  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1275 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 72: /* ifelse  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1281 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 73: /* expr  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1287 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 74: /* binop  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1293 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 75: /* unop  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1299 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 76: /* statement  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1305 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 77: /* block  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1311 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 78: /* blockHelp  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1317 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 79: /* while  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1323 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 80: /* return  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1329 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 81: /* allocation  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1335 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 82: /* call  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1341 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 83: /* funCall  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1347 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 84: /* variable  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1353 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 85: /* constant  */
#line 23 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1359 "yyparse.cpp" /* yacc.c:684  */
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
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1705 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOK_CHAR  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1711 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOK_INT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1717 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOK_STRING  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1723 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOK_IF  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1729 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 8: /* TOK_ELSE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1735 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 9: /* TOK_WHILE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1741 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 10: /* TOK_RETURN  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1747 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 11: /* TOK_STRUCT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1753 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 12: /* TOK_NULL  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1759 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 13: /* TOK_NEW  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1765 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 14: /* TOK_VARDECL  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1771 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 15: /* TOK_ARRAY  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1777 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 16: /* TOK_ARROW  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1783 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 17: /* TOK_BR  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1789 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 18: /* TOK_EQ  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1795 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 19: /* TOK_NE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1801 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 20: /* TOK_LT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1807 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 21: /* TOK_LE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1813 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 22: /* TOK_GT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1819 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 23: /* TOK_GE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1825 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 24: /* TOK_NOT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1831 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 25: /* TOK_IDENT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1837 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 26: /* TOK_INTCON  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1843 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 27: /* TOK_CHARCON  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1849 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 28: /* TOK_STRINGCON  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1855 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 29: /* TOK_ROOT  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1861 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 30: /* TOK_BLOCK  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1867 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 31: /* TOK_CALL  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1873 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 32: /* TOK_IFELSE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1879 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 33: /* TOK_INITDECL  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1885 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 34: /* TOK_POS  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1891 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 35: /* TOK_NEG  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1897 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 36: /* TOK_NEWARRAY  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1903 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 37: /* TOK_TYPEID  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1909 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 38: /* TOK_FIELD  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1915 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 39: /* TOK_NEWSTR  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1921 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 40: /* TOK_PARAM  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1927 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 41: /* TOK_FUNCTION  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1933 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 42: /* TOK_PROTOTYPE  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1939 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 43: /* TOK_DECLID  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1945 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 44: /* '+'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1951 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 45: /* '-'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1957 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 46: /* '*'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1963 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 47: /* '/'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1969 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 48: /* '%'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1975 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 49: /* '('  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1981 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 50: /* ')'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1987 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 51: /* '{'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1993 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 52: /* ';'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1999 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 53: /* '}'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2005 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 54: /* ','  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2011 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 55: /* '='  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2017 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 56: /* '['  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2023 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 57: /* ']'  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2029 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 59: /* start  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2035 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 60: /* program  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2041 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 61: /* structdef  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2047 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 62: /* struc  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2053 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 63: /* fielddecl  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2059 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 64: /* globaldecl  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2065 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 65: /* function  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2071 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 66: /* func  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2077 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 67: /* param  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2083 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 68: /* identdec  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2089 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 69: /* fnbody  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2095 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 70: /* basetype  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2101 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 71: /* localdecl  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2107 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 72: /* ifelse  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2113 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 73: /* expr  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2119 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 74: /* binop  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2125 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 75: /* unop  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2131 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 76: /* statement  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2137 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 77: /* block  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2143 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 78: /* blockHelp  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2149 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 79: /* while  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2155 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 80: /* return  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2161 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 81: /* allocation  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2167 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 82: /* call  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2173 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 83: /* funCall  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2179 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 84: /* variable  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2185 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 85: /* constant  */
#line 22 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2191 "yyparse.cpp" /* yacc.c:1257  */
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
#line 25 "parser.y" /* yacc.c:1429  */
{
   parser::root = new astree (TOK_ROOT, {0, 0, 0}, "<<ROOT>>");
}

#line 2281 "yyparse.cpp" /* yacc.c:1429  */
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
#line 53 "parser.y" /* yacc.c:1646  */
    {  parser::root = (yyvsp[0]); parser::root -> dump_tree(stdout, 0); }
#line 2463 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2469 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2475 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2481 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2487 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 2493 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 2499 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "parser.y" /* yacc.c:1646  */
    { (yyval) = parser::root; }
#line 2505 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 65 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); }
#line 2511 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 68 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2517 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 69 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); (yyvsp[-1]) -> adopt_sym (NULL, TOK_TYPEID); }
#line 2523 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->  adopt_sym ((yyvsp[0]), TOK_FIELD); }
#line 2529 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 73 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2])); (yyvsp[-2]) -> adopt_sym ((yyvsp[0]), TOK_FIELD); }
#line 2535 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 76 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-3]), (yyvsp[-1])); }
#line 2541 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 79 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2547 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]) -> adopt_sym (NULL, TOK_PROTOTYPE);}
#line 2553 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); }
#line 2559 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2565 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval) = new astree(TOK_FUNCTION, (yyvsp[0]) -> lloc ,""); (yyval) -> adopt ((yyvsp[0])); }
#line 2571 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 93 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-1])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[0])); }
#line 2577 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2583 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2589 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2])); (yyvsp[-2]) -> adopt ((yyvsp[0])); (yyvsp[0]) -> adopt_sym (NULL, TOK_DECLID); }
#line 2595 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); (yyvsp[0]) -> adopt_sym (NULL, TOK_DECLID); }
#line 2601 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2607 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2613 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt_sym ((yyvsp[0]), TOK_BLOCK); }
#line 2619 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt_sym ((yyvsp[0]), TOK_BLOCK); }
#line 2625 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) -> adopt_sym (NULL, TOK_BLOCK); }
#line 2631 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2637 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2643 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2649 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2655 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 119 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-3]), (yyvsp[-1])); }
#line 2661 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 122 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-5]), (yyvsp[-3])); destroy ((yyvsp[-1]));
                                                                          (yyval) = (yyvsp[-6]) -> adopt_sym (NULL, TOK_IF);
                                                                          (yyvsp[-6]) -> adopt((yyvsp[-4]), (yyvsp[-2])); (yyvsp[-6])->adopt((yyvsp[0])); }
#line 2669 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 125 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-3]), (yyvsp[-1])); (yyval) = (yyvsp[-4]) -> adopt((yyvsp[-2]), (yyvsp[0])); }
#line 2675 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 126 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-5])); destroy ((yyvsp[-3]), (yyvsp[-1])); (yyval) = (yyvsp[-4]) -> adopt((yyvsp[-2]), (yyvsp[0])); }
#line 2681 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2687 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2693 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2699 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2705 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 133 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-2]), (yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2711 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2717 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2723 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2729 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2735 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2741 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2747 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2753 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2759 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2765 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2771 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2777 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2783 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2789 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2795 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), TOK_POS); }
#line 2801 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), TOK_NEG); }
#line 2807 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2813 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2819 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2825 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2831 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2837 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2843 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 162 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2849 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 163 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); }
#line 2855 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 166 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); }
#line 2861 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2867 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt_sym ((yyvsp[0]), TOK_BLOCK); }
#line 2873 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 173 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-3])); destroy ((yyvsp[-1])); (yyval) = (yyvsp[-4]) -> adopt ((yyvsp[-2]), (yyvsp[0])); }
#line 2879 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 176 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2885 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 177 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2891 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) -> adopt_sym (NULL, TOK_TYPEID); }
#line 2897 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 181 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-2]), (yyvsp[0])); (yyval) = (yyvsp[-3]) -> adopt_sym ((yyvsp[-1]), TOK_NEWSTR); }
#line 2903 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 182 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]) -> adopt_sym ((yyvsp[-3]), TOK_NEWARRAY); (yyvsp[-2]) -> adopt ((yyvsp[-1])); }
#line 2909 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 185 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2915 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 188 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); }
#line 2921 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[0])); }
#line 2927 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) -> adopt_sym ((yyvsp[-1]), TOK_CALL); }
#line 2933 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2939 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 194 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[-2]), (yyvsp[0])); (yyval) = (yyvsp[-3]) -> adopt ((yyvsp[-1])); }
#line 2945 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) -> adopt ((yyvsp[-2]), (yyvsp[0])); (yyvsp[0]) -> adopt_sym (NULL, TOK_FIELD); }
#line 2951 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2957 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2963 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2969 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2975 "yyparse.cpp" /* yacc.c:1646  */
    break;


#line 2979 "yyparse.cpp" /* yacc.c:1646  */
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
#line 205 "parser.y" /* yacc.c:1906  */



const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}


