/* A Bison parser, made from ast.y, by GNU bison 1.75.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON	1

/* Pure parsers.  */
#define YYPURE	0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse ast_yyparse
#define yylex   ast_yylex
#define yyerror ast_yyerror
#define yylval  ast_yylval
#define yychar  ast_yychar
#define yydebug ast_yydebug
#define yynerrs ast_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     CLASS = 259,
     METHOD = 260,
     ATTR = 261,
     FORMAL = 262,
     BRANCH = 263,
     ASSIGN = 264,
     STATIC_DISPATCH = 265,
     DISPATCH = 266,
     COND = 267,
     LOOP = 268,
     TYPCASE = 269,
     BLOCK = 270,
     LET = 271,
     PLUS = 272,
     SUB = 273,
     MUL = 274,
     DIVIDE = 275,
     NEG = 276,
     LT = 277,
     EQ = 278,
     LEQ = 279,
     COMP = 280,
     INT = 281,
     STR = 282,
     BOOL = 283,
     NEW = 284,
     ISVOID = 285,
     NO_EXPR = 286,
     OBJECT = 287,
     NO_TYPE = 288,
     STR_CONST = 289,
     INT_CONST = 290,
     ID = 291,
     LINENO = 292
   };
#endif
#define PROGRAM 258
#define CLASS 259
#define METHOD 260
#define ATTR 261
#define FORMAL 262
#define BRANCH 263
#define ASSIGN 264
#define STATIC_DISPATCH 265
#define DISPATCH 266
#define COND 267
#define LOOP 268
#define TYPCASE 269
#define BLOCK 270
#define LET 271
#define PLUS 272
#define SUB 273
#define MUL 274
#define DIVIDE 275
#define NEG 276
#define LT 277
#define EQ 278
#define LEQ 279
#define COMP 280
#define INT 281
#define STR 282
#define BOOL 283
#define NEW 284
#define ISVOID 285
#define NO_EXPR 286
#define OBJECT 287
#define NO_TYPE 288
#define STR_CONST 289
#define INT_CONST 290
#define ID 291
#define LINENO 292




/* Copy the first part of user declarations.  */
#line 6 "ast.y"

#include <iostream>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"

void ast_yyerror(char *);
extern int curr_lineno;
extern int yylex();           /* the entry point to the lexer  */
Program ast_root;             /* the result of the parse  */
Classes parse_results;        /* for use in parsing multiple files */
int omerrs = 0;               /* number of errors in lexing and parsing */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#ifndef YYSTYPE
#line 21 "ast.y"
typedef union {
  int lineno;
  Boolean boolean;
  Symbol symbol;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions;
} yystype;
/* Line 193 of /usr/sww/pkg/bison-1.75/share/bison/yacc.c.  */
#line 187 "ast.tab.c"
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} yyltype;
# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 213 of /usr/sww/pkg/bison-1.75/share/bison/yacc.c.  */
#line 208 "ast.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];	\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
#define YYLAST   115

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  16
/* YYNRULES -- Number of rules. */
#define YYNRULES  50
/* YYNRULES -- Number of states. */
#define YYNSTATES  121

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     7,     8,    10,    13,    22,    23,    25,
      27,    30,    37,    43,    44,    46,    48,    51,    56,    60,
      64,    69,    76,    82,    88,    93,    97,   104,   109,   113,
     117,   122,   127,   132,   137,   141,   146,   151,   156,   160,
     164,   168,   172,   176,   179,   182,   186,   188,   191,   193,
     196
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      42,     0,    -1,    37,     3,    43,    -1,    -1,    44,    -1,
      43,    44,    -1,    37,     4,    36,    36,    34,    38,    45,
      39,    -1,    -1,    46,    -1,    47,    -1,    46,    47,    -1,
      37,     5,    36,    48,    36,    51,    -1,    37,     6,    36,
      36,    51,    -1,    -1,    49,    -1,    50,    -1,    49,    50,
      -1,    37,     7,    36,    36,    -1,    52,    40,    36,    -1,
      52,    40,    33,    -1,    37,     9,    36,    51,    -1,    37,
      10,    51,    36,    36,    53,    -1,    37,    11,    51,    36,
      53,    -1,    37,    12,    51,    51,    51,    -1,    37,    13,
      51,    51,    -1,    37,    15,    54,    -1,    37,    16,    36,
      36,    51,    51,    -1,    37,    14,    51,    55,    -1,    37,
      29,    36,    -1,    37,    30,    51,    -1,    37,    17,    51,
      51,    -1,    37,    18,    51,    51,    -1,    37,    19,    51,
      51,    -1,    37,    20,    51,    51,    -1,    37,    21,    51,
      -1,    37,    22,    51,    51,    -1,    37,    23,    51,    51,
      -1,    37,    24,    51,    51,    -1,    37,    25,    51,    -1,
      37,    26,    35,    -1,    37,    27,    34,    -1,    37,    28,
      35,    -1,    37,    32,    36,    -1,    37,    31,    -1,    38,
      39,    -1,    38,    54,    39,    -1,    51,    -1,    54,    51,
      -1,    56,    -1,    55,    56,    -1,    37,     8,    36,    36,
      51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char yyrline[] =
{
       0,    68,    68,    70,    75,    78,    83,    89,    91,    96,
      98,   102,   104,   108,   110,   115,   117,   121,   125,   129,
     132,   135,   138,   141,   144,   147,   150,   153,   156,   159,
     162,   165,   168,   171,   174,   177,   180,   183,   186,   189,
     192,   195,   203,   206,   210,   212,   217,   219,   224,   226,
     231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "CLASS", "METHOD", "ATTR", 
  "FORMAL", "BRANCH", "ASSIGN", "STATIC_DISPATCH", "DISPATCH", "COND", 
  "LOOP", "TYPCASE", "BLOCK", "LET", "PLUS", "SUB", "MUL", "DIVIDE", 
  "NEG", "LT", "EQ", "LEQ", "COMP", "INT", "STR", "BOOL", "NEW", "ISVOID", 
  "NO_EXPR", "OBJECT", "NO_TYPE", "STR_CONST", "INT_CONST", "ID", 
  "LINENO", "'('", "')'", "':'", "$accept", "program", "class_list", 
  "class", "optional_feature_list", "feature_list", "feature", "formals", 
  "formal_list", "formal", "expr", "expr_aux", "actuals", "expr_list", 
  "case_list", "simple_case", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    40,    41,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    54,    55,    55,
      56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     3,     0,     1,     2,     8,     0,     1,     1,
       2,     6,     5,     0,     1,     1,     2,     4,     3,     3,
       4,     6,     5,     5,     4,     3,     6,     4,     3,     3,
       4,     4,     4,     4,     3,     4,     4,     4,     3,     3,
       3,     3,     3,     2,     2,     3,     1,     2,     1,     2,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       3,     0,     0,     0,     1,     0,     2,     4,     0,     5,
       0,     0,     0,     7,     0,     0,     8,     9,     0,     0,
       6,    10,    13,     0,     0,     0,    14,    15,     0,     0,
       0,    16,     0,    12,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    46,
      25,     0,     0,     0,     0,     0,    34,     0,     0,     0,
      38,    39,    40,    41,    28,    29,    42,    19,    18,    20,
       0,     0,     0,    24,     0,    27,    48,    47,     0,    30,
      31,    32,    33,    35,    36,    37,     0,     0,    22,    23,
       0,    49,     0,    21,    44,     0,     0,    26,    45,     0,
      50
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     2,     6,     7,    15,    16,    17,    25,    26,    27,
      69,    34,   108,    70,    95,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -35
static const yysigned_char yypact[] =
{
     -30,     6,    26,   -10,   -35,    24,   -10,   -35,    -7,   -35,
      -5,    -2,    -4,    -1,    10,    -6,    -1,   -35,     1,     4,
     -35,   -35,    11,     5,    36,    16,    11,   -35,    17,    19,
      17,   -35,    83,   -35,    13,    20,   -35,    21,    17,    17,
      17,    17,    17,    17,    22,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    25,    27,    28,    23,    17,   -35,
      29,   -32,   -35,    17,    30,    31,    17,    17,    32,   -35,
      17,    35,    17,    17,    17,    17,   -35,    17,    17,    17,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
      37,    34,    17,   -35,    54,    32,   -35,   -35,    17,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,    34,   -34,   -35,   -35,
      38,   -35,    17,   -35,   -35,   -31,    39,   -35,   -35,    17,
     -35
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -35,   -35,   -35,    62,   -35,   -35,    60,   -35,   -35,    51,
     -28,   -35,   -27,   -29,   -35,   -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      33,    87,    36,    32,    88,   114,    32,     1,   118,     3,
      64,    65,    66,    67,    68,    18,    19,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     4,     5,     8,    10,
      85,    11,    12,    20,    13,    89,    14,    22,    92,    93,
      23,    28,    97,    29,    99,   100,   101,   102,    24,   103,
     104,   105,    30,    61,    32,    35,    62,    63,    71,    84,
      81,    82,   110,    83,   109,    86,    90,    91,     9,    94,
     112,    98,   107,   106,   116,   119,    21,    31,   115,   113,
     111,     0,     0,     0,   117,     0,     0,    97,     0,     0,
       0,   120,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

static const yysigned_char yycheck[] =
{
      28,    33,    30,    37,    36,    39,    37,    37,    39,     3,
      38,    39,    40,    41,    42,     5,     6,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    37,     4,    36,
      58,    36,    34,    39,    38,    63,    37,    36,    66,    67,
      36,    36,    70,     7,    72,    73,    74,    75,    37,    77,
      78,    79,    36,    40,    37,    36,    36,    36,    36,    36,
      35,    34,     8,    35,    92,    36,    36,    36,     6,    37,
      98,    36,    38,    36,    36,    36,    16,    26,   107,   106,
      95,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,
      -1,   119,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    37,    42,     3,     0,    37,    43,    44,     4,    44,
      36,    36,    34,    38,    37,    45,    46,    47,     5,     6,
      39,    47,    36,    36,    37,    48,    49,    50,    36,     7,
      36,    50,    37,    51,    52,    36,    51,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    40,    36,    36,    51,    51,    51,    51,    51,    51,
      54,    36,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    35,    34,    35,    36,    51,    36,    33,    36,    51,
      36,    36,    51,    51,    37,    55,    56,    51,    36,    51,
      51,    51,    51,    51,    51,    51,    36,    38,    53,    51,
       8,    56,    51,    53,    39,    54,    36,    51,    39,    36,
      51
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)           \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#define YYLEX	yylex ()

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
} while (0)
# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*-----------------------------.
| Print this symbol on YYOUT.  |
`-----------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue)
#else
yysymprint (yyout, yytype, yyvalue)
    FILE* yyout;
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyout, yytoknum[yytype], yyvalue);
# endif
    }
  else
    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyout, ")");
}
#endif /* YYDEBUG. */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yydestruct (int yytype, YYSTYPE yyvalue)
#else
yydestruct (yytype, yyvalue)
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  switch (yytype)
    {
      default:
        break;
    }
}



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of parse errors so far.  */
int yynerrs;


int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with.  */

  if (yychar <= 0)		/* This means end of input.  */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more.  */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

      /* We have to keep this `#if YYDEBUG', since we use variables
	 which are defined only if `YYDEBUG' is set.  */
      YYDPRINTF ((stderr, "Next token is "));
      YYDSYMPRINT ((stderr, yychar1, yylval));
      YYDPRINTF ((stderr, "\n"));
    }

  /* If the proper action on seeing token YYCHAR1 is to reduce or to
     detect an error, take that action.  */
  yyn += yychar1;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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



#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn - 1, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif
  switch (yyn)
    {
        case 2:
#line 69 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; ast_root = program(yyvsp[0].classes); }
    break;

  case 3:
#line 71 "ast.y"
    { exit(1); }
    break;

  case 4:
#line 76 "ast.y"
    { yyval.classes = single_Classes(yyvsp[0].class_);
                  parse_results = yyval.classes; }
    break;

  case 5:
#line 79 "ast.y"
    { yyval.classes = append_Classes(yyvsp[-1].classes,single_Classes(yyvsp[0].class_)); 
                  parse_results = yyval.classes; }
    break;

  case 6:
#line 84 "ast.y"
    { curr_lineno = yyvsp[-7].lineno;
		  yyval.class_ = class_(yyvsp[-5].symbol,yyvsp[-4].symbol,yyvsp[-1].features,yyvsp[-3].symbol); }
    break;

  case 7:
#line 90 "ast.y"
    {  yyval.features = nil_Features(); }
    break;

  case 8:
#line 92 "ast.y"
    {  yyval.features = yyvsp[0].features; }
    break;

  case 9:
#line 97 "ast.y"
    {  yyval.features = single_Features(yyvsp[0].feature); }
    break;

  case 10:
#line 99 "ast.y"
    {  yyval.features = append_Features(yyvsp[-1].features,single_Features(yyvsp[0].feature)); }
    break;

  case 11:
#line 103 "ast.y"
    { curr_lineno = yyvsp[-5].lineno; yyval.feature = method(yyvsp[-3].symbol,yyvsp[-2].formals,yyvsp[-1].symbol,yyvsp[0].expression); }
    break;

  case 12:
#line 105 "ast.y"
    { curr_lineno = yyvsp[-4].lineno; yyval.feature = attr(yyvsp[-2].symbol,yyvsp[-1].symbol,yyvsp[0].expression); }
    break;

  case 13:
#line 109 "ast.y"
    { yyval.formals = nil_Formals(); }
    break;

  case 14:
#line 111 "ast.y"
    { yyval.formals = yyvsp[0].formals; }
    break;

  case 15:
#line 116 "ast.y"
    {  yyval.formals = single_Formals(yyvsp[0].formal); }
    break;

  case 16:
#line 118 "ast.y"
    { yyval.formals = append_Formals(yyvsp[-1].formals,single_Formals(yyvsp[0].formal)); }
    break;

  case 17:
#line 122 "ast.y"
    {  curr_lineno = yyvsp[-3].lineno; yyval.formal = formal(yyvsp[-1].symbol,yyvsp[0].symbol); }
    break;

  case 18:
#line 126 "ast.y"
    { yyval.expression = yyvsp[-2].expression;
            yyval.expression->set_type(yyvsp[0].symbol); }
    break;

  case 19:
#line 130 "ast.y"
    { yyval.expression = yyvsp[-2].expression; }
    break;

  case 20:
#line 133 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = assign(yyvsp[-1].symbol,yyvsp[0].expression); }
    break;

  case 21:
#line 136 "ast.y"
    { curr_lineno = yyvsp[-5].lineno; yyval.expression = static_dispatch(yyvsp[-3].expression,yyvsp[-2].symbol,yyvsp[-1].symbol,yyvsp[0].expressions);}
    break;

  case 22:
#line 139 "ast.y"
    { curr_lineno = yyvsp[-4].lineno; yyval.expression = dispatch(yyvsp[-2].expression,yyvsp[-1].symbol,yyvsp[0].expressions); }
    break;

  case 23:
#line 142 "ast.y"
    { curr_lineno = yyvsp[-4].lineno; yyval.expression = cond(yyvsp[-2].expression,yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 24:
#line 145 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = loop(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 25:
#line 148 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = block(yyvsp[0].expressions); }
    break;

  case 26:
#line 151 "ast.y"
    { curr_lineno = yyvsp[-5].lineno; yyval.expression = let(yyvsp[-3].symbol,yyvsp[-2].symbol,yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 27:
#line 154 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = typcase(yyvsp[-1].expression,yyvsp[0].cases); }
    break;

  case 28:
#line 157 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = new_(yyvsp[0].symbol); }
    break;

  case 29:
#line 160 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = isvoid(yyvsp[0].expression); }
    break;

  case 30:
#line 163 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = plus(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 31:
#line 166 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = sub(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 32:
#line 169 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = mul(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 33:
#line 172 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = divide(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 34:
#line 175 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = neg(yyvsp[0].expression); }
    break;

  case 35:
#line 178 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = lt(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 36:
#line 181 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = eq(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 37:
#line 184 "ast.y"
    { curr_lineno = yyvsp[-3].lineno; yyval.expression = leq(yyvsp[-1].expression,yyvsp[0].expression); }
    break;

  case 38:
#line 187 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = comp(yyvsp[0].expression); }
    break;

  case 39:
#line 190 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = int_const(yyvsp[0].symbol); }
    break;

  case 40:
#line 193 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = string_const(yyvsp[0].symbol); }
    break;

  case 41:
#line 196 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; 
            if (*(yyvsp[0].symbol->get_string()) == '1')
	      yyval.expression = bool_const(1); 
	    else
              yyval.expression = bool_const(0);
          }
    break;

  case 42:
#line 204 "ast.y"
    { curr_lineno = yyvsp[-2].lineno; yyval.expression = object(yyvsp[0].symbol); }
    break;

  case 43:
#line 207 "ast.y"
    { curr_lineno = yyvsp[-1].lineno; yyval.expression = no_expr(); }
    break;

  case 44:
#line 211 "ast.y"
    {  yyval.expressions = nil_Expressions(); }
    break;

  case 45:
#line 213 "ast.y"
    {  yyval.expressions = yyvsp[-1].expressions; }
    break;

  case 46:
#line 218 "ast.y"
    { yyval.expressions = single_Expressions(yyvsp[0].expression); }
    break;

  case 47:
#line 220 "ast.y"
    { yyval.expressions = append_Expressions(yyvsp[-1].expressions,single_Expressions(yyvsp[0].expression)); }
    break;

  case 48:
#line 225 "ast.y"
    { yyval.cases = single_Cases(yyvsp[0].case_); }
    break;

  case 49:
#line 227 "ast.y"
    { yyval.cases = append_Cases(yyvsp[-1].cases,single_Cases(yyvsp[0].case_)); }
    break;

  case 50:
#line 232 "ast.y"
    { curr_lineno = yyvsp[-4].lineno; yyval.case_ = branch(yyvsp[-2].symbol,yyvsp[-1].symbol,yyvsp[0].expression); }
    break;


    }

/* Line 1016 of /usr/sww/pkg/bison-1.75/share/bison/yacc.c.  */
#line 1377 "ast.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyssp > yyss)
	    {
	      YYDPRINTF ((stderr, "Error: popping "));
	      YYDSYMPRINT ((stderr,
			    yystos[*yyssp],
			    *yyvsp));
	      YYDPRINTF ((stderr, "\n"));
	      yydestruct (yystos[*yyssp], *yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yydestruct (yychar1, yylval);
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      YYDPRINTF ((stderr, "Error: popping "));
      YYDSYMPRINT ((stderr,
		    yystos[*yyssp], *yyvsp));
      YYDPRINTF ((stderr, "\n"));

      yydestruct (yystos[yystate], *yyvsp);
      yyvsp--;
      yystate = *--yyssp;


#if YYDEBUG
      if (yydebug)
	{
	  short *yyssp1 = yyss - 1;
	  YYFPRINTF (stderr, "Error: state stack now");
	  while (yyssp1 != yyssp)
	    YYFPRINTF (stderr, " %d", *++yyssp1);
	  YYFPRINTF (stderr, "\n");
	}
#endif
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 237 "ast.y"


void ast_yyerror(char *)
{
   std::cerr << "??? unexpected error in ast parsing." << std::endl;
   exit(1);
}


