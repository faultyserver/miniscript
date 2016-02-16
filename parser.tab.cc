/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.yy"

  #include <stdio.h>
  #include <chrono>
  #include <iostream>
  #include "ast.h"

  #define SLOC(term) { (term).first_line, (term).last_line, (term).first_column, (term).last_column }

  extern FILE *yyin;
  extern void yyerror(const char *s);
  extern int yylex();

  Node *ast = NULL;

/* Line 371 of yacc.c  */
#line 83 "parser.tab.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hh".  */
#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     STR = 260,
     SEMICOL = 261,
     NEWLINE = 262,
     kVAR = 263,
     kSTART = 264,
     kEND = 265,
     kWRITE = 266,
     kASSERT = 267,
     kTRUE = 268,
     kFALSE = 269,
     kIF = 270,
     kELSE = 271,
     kDO = 272,
     kWHILE = 273,
     kBREAK = 274,
     kCONTINUE = 275,
     kFUNCTION = 276,
     kRETURN = 277,
     LE = 278,
     EE = 279,
     NE = 280,
     GE = 281,
     OR = 282,
     AND = 283
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "parser.yy"

  int num;
  char *str;
  Node *node;


/* Line 387 of yacc.c  */
#line 161 "parser.tab.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 202 "parser.tab.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,     2,     2,     2,
      29,    30,    42,    40,    34,    41,    45,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,     2,
      38,    31,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    16,    18,    21,    23,
      24,    27,    28,    31,    33,    35,    37,    39,    41,    43,
      45,    47,    52,    55,    58,    61,    64,    69,    72,    74,
      76,    78,    84,    87,    92,    94,    98,   104,   107,   112,
     114,   118,   123,   128,   130,   133,   143,   146,   152,   153,
     162,   173,   183,   187,   189,   190,   194,   196,   197,   199,
     201,   205,   207,   211,   213,   217,   221,   223,   227,   231,
     235,   239,   241,   245,   249,   251,   255,   259,   261,   264,
     266,   270,   275,   280,   284,   286,   288,   290,   292
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    52,    49,    -1,    51,     9,     7,
      -1,    10,    51,    -1,     6,    -1,     7,    -1,     6,     7,
      -1,     7,    -1,    -1,    52,    53,    -1,    -1,    54,    50,
      -1,    55,    -1,    56,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    19,    -1,    20,    -1,    82,    29,    73,
      30,    -1,    67,    51,    -1,    69,    51,    -1,    70,    50,
      -1,    71,    51,    -1,     8,     3,    31,    57,    -1,     8,
       3,    -1,    58,    -1,    61,    -1,    74,    -1,    32,    51,
      59,    51,    33,    -1,    32,    33,    -1,    59,    34,    51,
      60,    -1,    60,    -1,     3,    35,    74,    -1,    36,    51,
      62,    51,    37,    -1,    36,    37,    -1,    62,    34,    51,
      74,    -1,    74,    -1,    82,    31,    74,    -1,    11,    29,
      73,    30,    -1,    12,    29,    74,    30,    -1,    22,    -1,
      22,    74,    -1,    15,    29,    74,    30,    32,     7,    52,
      33,    68,    -1,    16,    67,    -1,    16,    32,     7,    52,
      33,    -1,    -1,    18,    29,    74,    30,    32,     7,    52,
      33,    -1,    17,    32,     7,    52,    33,    51,    18,    29,
      74,    30,    -1,    21,     3,    29,    72,    30,    32,     7,
      52,    33,    -1,    72,    34,     3,    -1,     3,    -1,    -1,
      73,    34,    74,    -1,    74,    -1,    -1,    75,    -1,    76,
      -1,    75,    27,    76,    -1,    77,    -1,    76,    28,    77,
      -1,    78,    -1,    77,    24,    78,    -1,    77,    25,    78,
      -1,    79,    -1,    78,    38,    79,    -1,    78,    39,    79,
      -1,    78,    26,    79,    -1,    78,    23,    79,    -1,    80,
      -1,    79,    40,    80,    -1,    79,    41,    80,    -1,    81,
      -1,    80,    42,    81,    -1,    80,    43,    81,    -1,    82,
      -1,    44,    82,    -1,    83,    -1,    82,    45,     3,    -1,
      82,    36,    74,    37,    -1,    82,    29,    73,    30,    -1,
      29,    74,    30,    -1,     3,    -1,     4,    -1,     5,    -1,
      13,    -1,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    57,    59,    61,    62,    63,    65,    66,
      69,    70,    73,    74,    77,    78,    79,    80,    81,    82,
      83,    84,    87,    88,    89,    90,    93,    94,    96,    97,
      98,   101,   102,   105,   106,   109,   112,   113,   116,   117,
     121,   124,   127,   130,   131,   134,   137,   138,   139,   142,
     145,   148,   150,   151,   152,   154,   155,   156,   159,   162,
     163,   166,   167,   170,   171,   172,   175,   176,   177,   178,
     179,   182,   183,   184,   187,   188,   189,   192,   193,   196,
     197,   198,   199,   202,   203,   204,   205,   206,   207
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "STR", "SEMICOL", "NEWLINE",
  "kVAR", "kSTART", "kEND", "kWRITE", "kASSERT", "kTRUE", "kFALSE", "kIF",
  "kELSE", "kDO", "kWHILE", "kBREAK", "kCONTINUE", "kFUNCTION", "kRETURN",
  "LE", "EE", "NE", "GE", "OR", "AND", "'('", "')'", "'='", "'{'", "'}'",
  "','", "':'", "'['", "']'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'!'", "'.'", "$accept", "script", "start", "end", "separator",
  "opt_line", "statement_list", "statement", "simple_statement",
  "complex_statement", "declaration", "declaration_value",
  "object_initializer", "field_init_list", "field_initializer",
  "array_initializer", "member_init_list", "assignment", "write", "assert",
  "return", "conditional", "optional_else", "while_loop", "do_while_loop",
  "function_def", "param_list", "expr_list", "expr", "logical_or_expr",
  "logical_and_expr", "equality_expr", "relational_expr", "additive_expr",
  "mult_expr", "unary_expr", "postfix_expr", "primary_expr", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    40,
      41,    61,   123,   125,    44,    58,    91,    93,    60,    62,
      43,    45,    42,    47,    33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    64,    65,    66,    66,    67,    68,    68,    68,    69,
      70,    71,    72,    72,    72,    73,    73,    73,    74,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     1,     1,     2,     1,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     2,     2,     2,     4,     2,     1,     1,
       1,     5,     2,     4,     1,     3,     5,     2,     4,     1,
       3,     4,     4,     1,     2,     9,     2,     5,     0,     8,
      10,     9,     3,     1,     0,     3,     1,     0,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     2,     1,
       3,     4,     4,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     8,     0,    11,     0,     1,     0,     0,    84,    85,
      86,     0,     9,     0,     0,    87,    88,     0,     0,     0,
      19,    20,     0,    43,     0,     2,    10,     0,    13,    14,
      15,    16,    17,    18,     9,     9,     0,     9,     0,    79,
       3,    27,     4,    57,     0,     0,     0,     0,     0,     0,
      44,    58,    59,    61,    63,    66,    71,    74,    77,     0,
       5,     6,    12,    22,    23,    24,    25,    57,     0,     0,
       0,     0,     0,    56,     0,     0,    11,     0,    54,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    83,     7,     0,    40,     0,    80,     9,
       9,    26,    28,    29,    30,    41,     0,    42,     0,     0,
       0,    53,     0,    60,    62,    64,    65,    70,    69,    67,
      68,    72,    73,    75,    76,     0,    82,    81,    32,     0,
      37,     0,    55,     0,     9,     0,     0,     0,    82,     0,
       9,    34,     9,    39,    11,     0,    11,     0,    52,     0,
       9,     0,     9,     0,     0,     0,     0,    11,    35,     0,
      31,     0,    36,    48,     0,    49,     0,    33,    38,     0,
      45,     0,    51,     0,    46,    50,    11,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    25,    62,     4,     6,    26,    27,    28,
      29,   101,   102,   140,   141,   103,   142,    30,    31,    32,
      33,    34,   170,    35,    36,    37,   112,    72,    73,    51,
      52,    53,    54,    55,    56,    57,    58,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
      -1,   -73,     8,   -73,     4,   -73,   257,     9,   -73,   -73,
     -73,    18,    -1,   -11,    16,   -73,   -73,    19,    -8,    27,
     -73,   -73,    70,    23,    23,   -73,   -73,    51,   -73,   -73,
     -73,   -73,   -73,   -73,    -1,    -1,    51,    -1,    30,   -73,
     -73,    60,   -73,    23,    23,    23,    74,    23,    64,    50,
     -73,    71,    77,    65,    39,    56,    57,   -73,    15,    80,
     112,   -73,   -73,   -73,   -73,   -73,   -73,    23,    23,    23,
     123,     6,    46,   -73,    98,   108,   -73,   110,   138,    15,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,   -73,   -73,    52,   -73,   106,   -73,    -2,
      -4,   -73,   -73,   -73,   -73,   -73,    23,   -73,   114,   103,
     117,   -73,    53,    77,    65,    39,    39,    56,    56,    56,
      56,    57,    57,   -73,   -73,    58,    95,   -73,   -73,   141,
     -73,    23,   -73,   144,    -1,   145,   121,   151,   -73,   120,
       5,   -73,     7,   -73,   -73,   139,   -73,   149,   -73,    23,
      -1,   125,    -1,   122,   161,   132,   184,   -73,   -73,   141,
     -73,    23,   -73,   146,    23,   -73,   207,   -73,   -73,     2,
     -73,   133,   -73,   160,   -73,   -73,   -73,   230,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -73,   134,    -5,   -72,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    25,   -73,   -73,   -73,   -73,   -73,
     -73,    17,   -73,   -73,   -73,   -73,   -73,   -52,   -22,   -73,
      88,    96,    48,   -16,    24,    43,    -6,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -22
static const yytype_int16 yytable[] =
{
      38,    50,    59,     1,   109,     1,     1,    42,     5,     8,
       9,    10,     1,     7,     1,    95,    40,    17,    43,    15,
      16,    41,    74,    75,    46,    77,     8,     9,    10,    63,
      64,   128,    66,   130,   173,    24,    15,    16,    99,   150,
     125,   152,   100,    79,    92,    44,    96,    97,    45,   104,
      49,    69,    24,     8,     9,    10,    47,    60,    61,    67,
      70,    68,    84,    15,    16,    85,    69,    49,   117,   118,
     119,   120,   154,    48,   156,    70,   105,    86,    87,    24,
     106,    76,   126,   136,   132,   166,   106,   137,   138,    82,
      83,    71,   106,    78,   129,   131,    88,    89,    80,    90,
      91,   -21,   -21,    38,   177,    81,     8,     9,    10,   143,
      93,    11,   121,   122,    13,    14,    15,    16,    17,    94,
      18,    19,    20,    21,    22,    23,    98,   158,   107,   145,
     115,   116,    24,   123,   124,   151,   134,   153,   108,   168,
     110,   111,   171,   127,   139,   159,   133,   161,    38,   135,
      38,   144,   146,   147,   148,   149,   157,   155,   160,   162,
      38,   164,   169,   175,     8,     9,    10,   176,   113,    11,
      65,    38,    13,    14,    15,    16,    17,   114,    18,    19,
      20,    21,    22,    23,   167,     0,   174,     8,     9,    10,
      24,     0,    11,     0,   163,    13,    14,    15,    16,    17,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       8,     9,    10,    24,     0,    11,     0,   165,    13,    14,
      15,    16,    17,     0,    18,    19,    20,    21,    22,    23,
       0,     0,     0,     8,     9,    10,    24,     0,    11,     0,
     172,    13,    14,    15,    16,    17,     0,    18,    19,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,    24,
       8,     9,    10,   178,     0,    11,     0,    12,    13,    14,
      15,    16,    17,     0,    18,    19,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,    24
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,    23,    24,     7,    76,     7,     7,    12,     0,     3,
       4,     5,     7,     9,     7,    67,     7,    15,    29,    13,
      14,     3,    44,    45,    32,    47,     3,     4,     5,    34,
      35,    33,    37,    37,    32,    29,    13,    14,    32,    34,
      92,    34,    36,    49,    29,    29,    68,    69,    29,    71,
      44,    36,    29,     3,     4,     5,    29,     6,     7,    29,
      45,    31,    23,    13,    14,    26,    36,    44,    84,    85,
      86,    87,   144,     3,   146,    45,    30,    38,    39,    29,
      34,     7,    30,    30,   106,   157,    34,    34,    30,    24,
      25,    31,    34,    29,    99,   100,    40,    41,    27,    42,
      43,     6,     7,   109,   176,    28,     3,     4,     5,   131,
      30,     8,    88,    89,    11,    12,    13,    14,    15,     7,
      17,    18,    19,    20,    21,    22,     3,   149,    30,   134,
      82,    83,    29,    90,    91,   140,    33,   142,    30,   161,
      30,     3,   164,    37,     3,   150,    32,   152,   154,    32,
     156,     7,     7,    32,     3,    35,     7,    18,    33,    37,
     166,    29,    16,    30,     3,     4,     5,     7,    80,     8,
      36,   177,    11,    12,    13,    14,    15,    81,    17,    18,
      19,    20,    21,    22,   159,    -1,   169,     3,     4,     5,
      29,    -1,     8,    -1,    33,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
       3,     4,     5,    29,    -1,     8,    -1,    33,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,     3,     4,     5,    29,    -1,     8,    -1,
      33,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       3,     4,     5,    33,    -1,     8,    -1,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    47,    48,    51,     0,    52,     9,     3,     4,
       5,     8,    10,    11,    12,    13,    14,    15,    17,    18,
      19,    20,    21,    22,    29,    49,    53,    54,    55,    56,
      63,    64,    65,    66,    67,    69,    70,    71,    82,    83,
       7,     3,    51,    29,    29,    29,    32,    29,     3,    44,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    74,
       6,     7,    50,    51,    51,    50,    51,    29,    31,    36,
      45,    31,    73,    74,    74,    74,     7,    74,    29,    82,
      27,    28,    24,    25,    23,    26,    38,    39,    40,    41,
      42,    43,    29,    30,     7,    73,    74,    74,     3,    32,
      36,    57,    58,    61,    74,    30,    34,    30,    30,    52,
      30,     3,    72,    76,    77,    78,    78,    79,    79,    79,
      79,    80,    80,    81,    81,    73,    30,    37,    33,    51,
      37,    51,    74,    32,    33,    32,    30,    34,    30,     3,
      59,    60,    62,    74,     7,    51,     7,    32,     3,    35,
      34,    51,    34,    51,    52,    18,    52,     7,    74,    51,
      33,    51,    37,    33,    29,    33,    52,    60,    74,    16,
      68,    74,    33,    32,    67,    30,     7,    52,    33
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 55 "parser.yy"
    { ast = (yyvsp[(2) - (3)].node); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 69 "parser.yy"
    { (yyvsp[(1) - (2)].node)->add_child((yyvsp[(2) - (2)].node)); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 70 "parser.yy"
    { (yyval.node) = new StatementList(SLOC((yyloc))); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 82 "parser.yy"
    { (yyval.node) = new BreakStatement(SLOC((yylsp[(1) - (1)]))); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 83 "parser.yy"
    { (yyval.node) = new ContinueStatement(SLOC((yylsp[(1) - (1)]))); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 84 "parser.yy"
    { (yyval.node) = new FunctionCall((yyvsp[(1) - (4)].node), (ExpressionList*) (yyvsp[(3) - (4)].node), SLOC((yylsp[(1) - (4)]))); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 93 "parser.yy"
    { (yyval.node) = new InitializationStatement((yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].node), SLOC((yylsp[(2) - (4)]))); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 94 "parser.yy"
    { (yyval.node) = new DeclarationStatement((yyvsp[(2) - (2)].str), SLOC((yylsp[(2) - (2)]))); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 101 "parser.yy"
    { (yyval.node) = (yyvsp[(3) - (5)].node); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 102 "parser.yy"
    { (yyval.node) = new FieldInitializerList(SLOC((yylsp[(1) - (2)]))); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 105 "parser.yy"
    { (yyvsp[(1) - (4)].node)->add_child((yyvsp[(4) - (4)].node)); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 106 "parser.yy"
    { (yyval.node) = new FieldInitializerList(SLOC((yylsp[(1) - (1)]))); (yyval.node)->add_child((yyvsp[(1) - (1)].node)); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 109 "parser.yy"
    { (yyval.node) = new FieldInitialization((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 112 "parser.yy"
    { (yyval.node) = (yyvsp[(3) - (5)].node); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 113 "parser.yy"
    { (yyval.node) = new MemberInitializerList(SLOC((yylsp[(1) - (2)]))); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 116 "parser.yy"
    { (yyvsp[(1) - (4)].node)->add_child((yyvsp[(4) - (4)].node)); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 117 "parser.yy"
    { (yyval.node) = new MemberInitializerList(SLOC((yylsp[(1) - (1)]))); (yyval.node)->add_child((yyvsp[(1) - (1)].node)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 121 "parser.yy"
    { (yyvsp[(1) - (3)].node)->lhs = true; (yyval.node) = new AssignmentStatement((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 124 "parser.yy"
    { (yyval.node) = new WriteStatement((ExpressionList*) (yyvsp[(3) - (4)].node), SLOC((yylsp[(1) - (4)]))); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 127 "parser.yy"
    { (yyval.node) = new AssertStatement((yyvsp[(3) - (4)].node), SLOC((yylsp[(1) - (4)]))); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 130 "parser.yy"
    { (yyval.node) = new ReturnStatement(NULL, SLOC((yylsp[(1) - (1)]))); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 131 "parser.yy"
    { (yyval.node) = new ReturnStatement((yyvsp[(2) - (2)].node), SLOC((yylsp[(1) - (2)]))); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 134 "parser.yy"
    { (yyval.node) = new IfStatement((yyvsp[(3) - (9)].node), (StatementList*) (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node), SLOC((yylsp[(1) - (9)]))); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 137 "parser.yy"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 138 "parser.yy"
    { (yyval.node) = (yyvsp[(4) - (5)].node); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 139 "parser.yy"
    { (yyval.node) = NULL; }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 142 "parser.yy"
    { (yyval.node) = new WhileStatement((yyvsp[(3) - (8)].node), (StatementList*) (yyvsp[(7) - (8)].node), SLOC((yylsp[(1) - (8)]))); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 145 "parser.yy"
    { (yyval.node) = new DoWhileStatement((yyvsp[(9) - (10)].node), (StatementList*) (yyvsp[(4) - (10)].node), SLOC((yylsp[(9) - (10)]))); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 148 "parser.yy"
    { (yyval.node) = new FunctionDeclaration((yyvsp[(2) - (9)].str), (ParameterList*) (yyvsp[(4) - (9)].node), (StatementList*) (yyvsp[(8) - (9)].node), SLOC((yylsp[(1) - (9)]))); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 150 "parser.yy"
    { ((ParameterList*) (yyvsp[(1) - (3)].node))->add_child((yyvsp[(3) - (3)].str)); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 151 "parser.yy"
    { (yyval.node) = new ParameterList(SLOC((yylsp[(1) - (1)]))); ((ParameterList*) (yyval.node))->add_child((yyvsp[(1) - (1)].str)); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 152 "parser.yy"
    { (yyval.node) = new ParameterList(SLOC((yyloc))); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 154 "parser.yy"
    { (yyvsp[(1) - (3)].node)->add_child((yyvsp[(3) - (3)].node)); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 155 "parser.yy"
    { (yyval.node) = new ExpressionList(SLOC((yylsp[(1) - (1)]))); (yyval.node)->add_child((yyvsp[(1) - (1)].node)); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 156 "parser.yy"
    { (yyval.node) = new ExpressionList(SLOC((yyloc))); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 163 "parser.yy"
    { (yyval.node) = new LogicalOpExpression((yyvsp[(1) - (3)].node), "||", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 167 "parser.yy"
    { (yyval.node) = new LogicalOpExpression((yyvsp[(1) - (3)].node), "&&", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 171 "parser.yy"
    { (yyval.node) = new EqualityOpExpression((yyvsp[(1) - (3)].node), "==", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 172 "parser.yy"
    { (yyval.node) = new EqualityOpExpression((yyvsp[(1) - (3)].node), "!=", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 176 "parser.yy"
    { (yyval.node) = new RelationalOpExpression((yyvsp[(1) - (3)].node), "<",  (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 177 "parser.yy"
    { (yyval.node) = new RelationalOpExpression((yyvsp[(1) - (3)].node), ">",  (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 178 "parser.yy"
    { (yyval.node) = new RelationalOpExpression((yyvsp[(1) - (3)].node), ">=", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 179 "parser.yy"
    { (yyval.node) = new RelationalOpExpression((yyvsp[(1) - (3)].node), "<=", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 183 "parser.yy"
    { (yyval.node) = new BinaryOpExpression((yyvsp[(1) - (3)].node), "+", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 184 "parser.yy"
    { (yyval.node) = new BinaryOpExpression((yyvsp[(1) - (3)].node), "-", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 188 "parser.yy"
    { (yyval.node) = new BinaryOpExpression((yyvsp[(1) - (3)].node), "*", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 189 "parser.yy"
    { (yyval.node) = new BinaryOpExpression((yyvsp[(1) - (3)].node), "/", (yyvsp[(3) - (3)].node), SLOC((yylsp[(1) - (3)]))); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 193 "parser.yy"
    { (yyval.node) = new NegationOpExpression((yyvsp[(2) - (2)].node), SLOC((yylsp[(1) - (2)]))); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 197 "parser.yy"
    { (yyval.node) = new ObjectReference((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].str), SLOC((yylsp[(3) - (3)]))); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 198 "parser.yy"
    { (yyval.node) = new ArraySubscript((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), SLOC((yylsp[(3) - (4)]))); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 199 "parser.yy"
    { (yyval.node) = new FunctionCall((yyvsp[(1) - (4)].node), (ExpressionList*) (yyvsp[(3) - (4)].node), SLOC((yylsp[(1) - (4)]))); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 202 "parser.yy"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 203 "parser.yy"
    { (yyval.node) = new VariableReference((yyvsp[(1) - (1)].str), SLOC((yylsp[(1) - (1)]))); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 204 "parser.yy"
    { (yyval.node) = new NumericLiteral((yyvsp[(1) - (1)].num),    SLOC((yylsp[(1) - (1)]))); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 205 "parser.yy"
    { (yyval.node) = new StringLiteral((yyvsp[(1) - (1)].str),     SLOC((yylsp[(1) - (1)]))); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 206 "parser.yy"
    { (yyval.node) = new BooleanLiteral(true,  SLOC((yylsp[(1) - (1)]))); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 207 "parser.yy"
    { (yyval.node) = new BooleanLiteral(false, SLOC((yylsp[(1) - (1)]))); }
    break;


/* Line 1787 of yacc.c  */
#line 2021 "parser.tab.cc"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 210 "parser.yy"


void yyerror(const char *s) {
  fprintf(stderr, "%s\n", s);
}

int main(int charc, char** argv) {
  yyin = fopen(argv[1], "r");

  yyparse();

  /* Set up the initial Symbol Table */
  SYMTAB.push_scope(new Scope());
  ast->visit();
  /* Clear the last scope from the table */
  SYMTAB.pop_scope();
}
