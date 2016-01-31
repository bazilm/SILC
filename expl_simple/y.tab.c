/* A Bison parser, made by GNU Bison 3.0.2.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "expl.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "parse.h"

STable *sTableBeg,*sTableEnd;
int lineNo;
bool has_error = false;
FILE * out;
int reg_count=-1;
int mem = 0,if_count=1,while_count=1;

#include "compiler.c"

#line 83 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEG = 258,
    DECL = 259,
    ENDDECL = 260,
    INTEGER = 261,
    BOOL = 262,
    END = 263,
    READ = 264,
    WRITE = 265,
    TRUE = 266,
    FALSE = 267,
    EQ = 268,
    NE = 269,
    LE = 270,
    GE = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    ENDIF = 278,
    WHILE = 279,
    DO = 280,
    ENDWHILE = 281,
    CONST = 282,
    STRCONST = 283,
    VAR = 284
  };
#endif
/* Tokens.  */
#define BEG 258
#define DECL 259
#define ENDDECL 260
#define INTEGER 261
#define BOOL 262
#define END 263
#define READ 264
#define WRITE 265
#define TRUE 266
#define FALSE 267
#define EQ 268
#define NE 269
#define LE 270
#define GE 271
#define AND 272
#define OR 273
#define NOT 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ENDIF 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define CONST 282
#define STRCONST 283
#define VAR 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "expl.y" /* yacc.c:355  */

int ival;
char * sval;
struct NodeTag* nval;

#line 187 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      42,    43,    36,    34,    39,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      32,    30,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    51,    54,    55,    58,    59,    60,    61,
      64,    65,    66,    67,    71,    72,    75,    76,    77,    78,
      79,    80,    81,    82,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "DECL", "ENDDECL", "INTEGER",
  "BOOL", "END", "READ", "WRITE", "TRUE", "FALSE", "EQ", "NE", "LE", "GE",
  "AND", "OR", "NOT", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "CONST", "STRCONST", "VAR", "'='", "'>'", "'<'", "'%'",
  "'+'", "'-'", "'*'", "'/'", "';'", "','", "'['", "']'", "'('", "')'",
  "$accept", "program", "declblock", "decl_stmt", "var_list", "stmt_list",
  "stmt", "expr", YY_NULLPTR
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
      61,    62,    60,    37,    43,    45,    42,    47,    59,    44,
      91,    93,    40,    41
};
# endif

#define YYPACT_NINF -88

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -88,    17,    34,    56,   132,   -88,    35,    35,    53,
      32,    37,    39,    49,    21,    46,   -88,    58,    14,    30,
     -88,    35,    35,    64,    38,    38,    38,    38,    38,   -88,
     -88,    80,   -88,    91,   -88,    33,    57,   -26,   -88,   -88,
      38,   -88,    89,    38,    38,    -8,    69,   100,   213,   162,
      97,   111,   -88,   -88,    38,    92,   247,    38,    74,   131,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,   117,   136,   133,   -88,   139,   -88,   143,
     173,   -88,   202,   -88,   247,   247,   247,   247,   272,   272,
     247,   247,    90,    74,    74,   -88,   -88,   -88,   132,   132,
      38,   119,   128,   -88,    99,    68,   239,   -88,   134,   132,
     135,   144,   -88,   -88,   130,   -88,   -88,   145,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     5,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    12,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     2,
      14,     0,     8,     0,     9,     0,     0,     0,    41,    42,
       0,    40,    43,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     6,     7,     0,     0,    37,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,    13,     0,
       0,    16,     0,    39,    29,    34,    32,    33,    35,    36,
      31,    30,    28,    24,    25,    26,    27,    18,     0,     0,
       0,     0,     0,    44,     0,     0,     0,    11,     0,     0,
       0,     0,    23,    17,     0,    20,    21,     0,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,   -88,    10,   -87,   -15,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     5,     9,    18,    15,    16,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    46,    47,    48,    49,    60,    61,    62,    63,    64,
      65,   104,   105,     1,    54,     2,    56,    55,    19,    58,
      59,     4,   114,    66,    67,    68,    69,    70,    71,    72,
      80,    35,    36,    82,     6,    73,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    38,
      39,    27,    32,    33,    29,    10,    11,    40,    20,    21,
      22,    28,     7,     8,    17,    41,    12,    42,    34,    33,
      13,    52,    33,    43,    23,    14,   106,    10,    11,    24,
      44,    25,    60,    61,    62,    63,    64,    65,    12,    30,
      30,    26,    13,    37,   111,    53,    33,    14,    31,    30,
      66,    67,    68,    69,    70,    71,    72,    50,    10,    11,
      71,    72,    74,    60,    61,    62,    63,    64,    65,    12,
      51,   109,   110,    13,    69,    70,    71,    72,    14,    57,
      81,    66,    67,    68,    69,    70,    71,    72,    78,    10,
      11,    10,    11,    75,    60,    61,    62,    63,    64,    65,
      12,    79,    12,   117,    13,    97,    13,    98,    99,    14,
     107,    14,    66,    67,    68,    69,    70,    71,    72,   100,
     101,   108,   113,   115,    83,    60,    61,    62,    63,    64,
      65,     0,   116,   118,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     0,    77,    66,    67,    68,    69,    70,    71,
      72,     0,     0,     0,   102,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     0,   103,    66,    67,    68,    69,    70,    71,
      72,    76,    60,    61,    62,    63,    64,    65,     0,     0,
      -1,    -1,    -1,    -1,     0,     0,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,   112,    -1,    -1,
      68,    69,    70,    71,    72,    60,    61,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72
};

static const yytype_int8 yycheck[] =
{
      15,    25,    26,    27,    28,    13,    14,    15,    16,    17,
      18,    98,    99,     1,    40,     3,    40,    43,     8,    43,
      44,     4,   109,    31,    32,    33,    34,    35,    36,    37,
      54,    21,    22,    57,     0,    43,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    11,
      12,    30,    38,    39,     8,     9,    10,    19,     5,     6,
       7,    40,     6,     7,    29,    27,    20,    29,    38,    39,
      24,    38,    39,    35,    42,    29,   100,     9,    10,    42,
      42,    42,    13,    14,    15,    16,    17,    18,    20,   104,
     105,    42,    24,    29,    26,    38,    39,    29,    40,   114,
      31,    32,    33,    34,    35,    36,    37,    27,     9,    10,
      36,    37,    43,    13,    14,    15,    16,    17,    18,    20,
      29,    22,    23,    24,    34,    35,    36,    37,    29,    40,
      38,    31,    32,    33,    34,    35,    36,    37,    41,     9,
      10,     9,    10,    43,    13,    14,    15,    16,    17,    18,
      20,    40,    20,    23,    24,    38,    24,    21,    25,    29,
      41,    29,    31,    32,    33,    34,    35,    36,    37,    30,
      27,    43,    38,    38,    43,    13,    14,    15,    16,    17,
      18,    -1,    38,    38,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    41,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    31,    32,    33,    34,    35,    36,
      37,    38,    13,    14,    15,    16,    17,    18,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    31,    32,
      33,    34,    35,    36,    37,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    45,     4,    46,     0,     6,     7,    47,
       9,    10,    20,    24,    29,    49,    50,    29,    48,    48,
       5,     6,     7,    42,    42,    42,    42,    30,    40,     8,
      50,    40,    38,    39,    38,    48,    48,    29,    11,    12,
      19,    27,    29,    35,    42,    51,    51,    51,    51,    51,
      27,    29,    38,    38,    40,    43,    51,    40,    51,    51,
      13,    14,    15,    16,    17,    18,    31,    32,    33,    34,
      35,    36,    37,    43,    43,    43,    38,    41,    41,    40,
      51,    38,    51,    43,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    38,    21,    25,
      30,    27,    41,    41,    49,    49,    51,    41,    43,    22,
      23,    26,    38,    38,    49,    38,    38,    23,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      48,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     3,     0,     4,     4,     3,     3,
       3,     6,     1,     4,     2,     1,     5,     8,     5,    10,
       8,     8,     4,     7,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       1,     1,     1,     1,     4
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
  YYUSE (yytype);
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
  YYUSE (yytype);
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
#line 40 "expl.y" /* yacc.c:1646  */
    {semanticAnalyzer((yyvsp[-1].nval));
								if(!has_error)
								{
								out = fopen("sil.out","w");
								fprintf(out,"START\n");
								fprintf(out,"MOV SP,1535\n");
								fprintf(out,"MOV BP,1535\n");
								compile((yyvsp[-1].nval));
								fprintf(out,"HALT");
								}
								return 0;}
#line 1394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "expl.y" /* yacc.c:1646  */
    { return 0;					}
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "expl.y" /* yacc.c:1646  */
    {makeSTable((yyvsp[-1].nval),INT);}
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "expl.y" /* yacc.c:1646  */
    {makeSTable((yyvsp[-1].nval),BOOLEAN);}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "expl.y" /* yacc.c:1646  */
    {makeSTable((yyvsp[-1].nval),INT);}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "expl.y" /* yacc.c:1646  */
    {makeSTable((yyvsp[-1].nval),BOOLEAN);}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 64 "expl.y" /* yacc.c:1646  */
    {(yyval.nval)=makeOperNode('S',2,(yyvsp[-2].nval),makeVarNode((yyvsp[0].sval),NULL,1));			}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 65 "expl.y" /* yacc.c:1646  */
    {(yyval.nval)=makeOperNode('S',2,(yyvsp[-5].nval),makeVarNode((yyvsp[-3].sval),NULL,(yyvsp[-1].ival)));}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 66 "expl.y" /* yacc.c:1646  */
    {(yyval.nval)=makeVarNode((yyvsp[0].sval),NULL,1);						}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 67 "expl.y" /* yacc.c:1646  */
    {(yyval.nval)=makeVarNode((yyvsp[-3].sval),NULL,(yyvsp[-1].ival));			}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 71 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('$',2,(yyvsp[-1].nval),(yyvsp[0].nval));	}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[0].nval);				}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(READ,1,makeVarNode((yyvsp[-2].sval),NULL,0));			}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(READ,1,makeVarNode((yyvsp[-5].sval),(yyvsp[-3].nval),0));			}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 77 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(WRITE,1,(yyvsp[-2].nval));						}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 78 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(IF,3,(yyvsp[-7].nval),(yyvsp[-4].nval),(yyvsp[-2].nval));					}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(IF,2,(yyvsp[-5].nval),(yyvsp[-2].nval));						}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 80 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(WHILE,2,(yyvsp[-5].nval),(yyvsp[-2].nval));					}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 81 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('=',2,makeVarNode((yyvsp[-3].sval),NULL,0),(yyvsp[-1].nval));			}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 82 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('=',2,makeVarNode((yyvsp[-6].sval),(yyvsp[-4].nval),0),(yyvsp[-1].nval));			}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('+',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 88 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('-',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 89 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('*',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('/',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('%',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(EQ,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('<',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 94 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('>',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 95 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(LE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 96 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(GE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 97 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(NE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 98 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(AND,2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 99 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(OR,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 100 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(NOT,1,(yyvsp[0].nval));		}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 101 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('-',1,(yyvsp[0].nval));		}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 102 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[-1].nval);				}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 103 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(INTEGER,(yyvsp[0].ival));}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 104 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(BOOLEAN,1);	}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 105 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(BOOLEAN,0);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 106 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeVarNode((yyvsp[0].sval),NULL,0);		}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 107 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeVarNode((yyvsp[-3].sval),(yyvsp[-1].nval),0);		}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1638 "y.tab.c" /* yacc.c:1646  */
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
#line 109 "expl.y" /* yacc.c:1906  */


int main(int argc, char *argv[])
{
if(argc>1)
{
extern FILE * yyin;
yyin = fopen(argv[1],"r");
}

lineNo=1;
yyparse();
return 0;
}


void yyerror(char * s)
{
printf("%s:%d\n",s,lineNo);
}

void makeSTable(Node * root,Type type)
{
STable * sTableEntry;

switch(root->nodeType)
{

	case OPERATOR:
			{
			makeSTable(&root->oper.operands[0],type);
			makeSTable(&root->oper.operands[1],type);
			break;
			}

	case VARIABLE:
			{
			
			sTableEntry = LookUp(root->var.name);
			if(!sTableEntry)
				{
				
				if(root->var.size<1)
					{
					printf("Error in %d: Cant have size less than 1\n",root->lineNo);
					has_error=true;
					}
				else
					GInstall(root->var.name,type,root->var.size);
				break;
				}
			else
				{
				printf("Error in %d :Variable %s declared once\n",root->lineNo,root->var.name);
				has_error=true;
				break;
				}
			}
}
}

STable *GInstall(char *name,Type type,int size)
{
STable *sTable = malloc(sizeof(STable));
sTable->name = name;
sTable->type = type;

switch(type)
{
	case INT:
		{
		sTable->size = size;
		sTable->binding = mem;
		mem+=size;
		break;
		}

	
	case BOOLEAN:
		{
		sTable->size=size;
		sTable->binding = mem;
		mem+=size;
		break;
		}
}

sTable->next = NULL;

if(sTableBeg==NULL)
	{
	sTableBeg=sTable;
	sTableEnd=sTable;
	}
else
	{
	sTableEnd->next = sTable;
	sTableEnd = sTable;
	}
return sTableEnd;
}

STable *LookUp(char * name)
{
STable * sTable = sTableBeg;
while(sTable!=NULL)
	{
	if(strcmp(sTable->name,name)==0)
		return sTable;

	sTable=sTable->next;
	}
return NULL;
}

void setVariableValue(char *name,Node *index)
{
STable *sTableEntry = LookUp(name);
if(!index)
{
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
}
else
{
compile(index);
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
reg_count--;
}

}

void getVariableValue(char *name,Node *index)
{
STable *sTableEntry = LookUp(name);
if(!index)
{
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
fprintf(out,"MOV R%d,[R%d]\n",reg_count,reg_count);
}
else
{
compile(index);
reg_count++;
fprintf(out,"MOV R%d,%d\n",reg_count,sTableEntry->binding);
fprintf(out,"ADD R%d,R%d\n",reg_count-1,reg_count);
reg_count--;
fprintf(out,"MOV R%d,[R%d]\n",reg_count,reg_count);
}
}

	
Node * makeConNode(Type type,int value)
{

Node * p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
switch(type)
{
case INTEGER:
	{
	
	p->nodeType = CONSTANT;
	p->type = INT;
	p->con.value = value;
	break;
	}

case BOOLEAN:
	{
	p->nodeType = CONSTANT;
	p->type = BOOLEAN;
	p->con.value = value;
	break;
	}
}
p->lineNo=lineNo;
return p;
}

Node * makeVarNode(char *name,Node *index,int size)
{

Node *p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}
p->nodeType = VARIABLE;
p->type = INT;
p->var.name = malloc(sizeof(name));
strcpy(p->var.name,name);
p->var.index=index;
p->var.size = size;
p->lineNo=lineNo;
return p;
}

Node * makeOperNode(int oper,int nops,...)
{

va_list temp_args;
va_start(temp_args,nops);

Node * p;
if((p =malloc(sizeof(Node))) == NULL)
	{
	printf("No memory\n");
	exit(0);
	}

p->nodeType = OPERATOR;
p->oper.op = oper;
p->oper.nops = nops;

if((p->oper.operands = malloc(nops * sizeof(Node)))==NULL)
	{
	printf("No memory\n");
	exit(0);
	}
	
int i=0;
for(i=0;i<nops;i++)
{
p->oper.operands[i] = *va_arg(temp_args,Node*);
}
p->lineNo=lineNo;
return p;
}

/*
int interpret(Node * root)
{

STable * sTableEntry;
int res1,res2,res3;
int nops;
Node *oper1,*oper2,*oper3;

if(!root)
	return 0;


switch(root->nodeType)
{
case CONSTANT:
	{
	return root->con.value;
	break;
	}

case VARIABLE:
	{
	return getVariableValue(root->var.name,root->var.index);
	break;
	}

case OPERATOR:
	{
	oper1 = &root->oper.operands[0];
	if(root->oper.nops>=2)
		oper2 = &root->oper.operands[1];

	if(root->oper.nops==3)
		oper3 = &root->oper.operands[2];
	nops = root->oper.nops;
	switch(root->oper.op)
	{
		case '+':
			{
			return interpret(oper1)+interpret(oper2);
			break;
			}

		case '-':
			{
			if(nops==1)
				return -interpret(oper1);
			else
				return interpret(oper1)-interpret(oper2);
			break;
			}
	
		case '*':
			{
			return interpret(oper1)*interpret(oper2);
			break;
			}
	
		case '/':
			{
			return interpret(oper1)/interpret(oper2);
			break;
			}
	
		case '%':
			{
			return interpret(oper1)%interpret(oper2);
			break;
			}

		case '=':
			{
			setVariableValue(oper1->var.name,oper1->var.index,oper2);
			return 1;
			break;
			}	
			
		case EQ:
			{
			return interpret(oper1)==interpret(oper2);
			break;
			}
		case '<':
			{
			return interpret(oper1)<interpret(oper2);
			break;
			}

		case '>':
			{
			
			return interpret(oper1)>interpret(oper2);
			break;
							
			}

		case LE:
			{
			return interpret(oper1)<=interpret(oper2);
			break;
			}

		case GE:
			{
			
			return interpret(oper1)>=interpret(oper2);
			break;		
			}

		case NE:
			{
			return interpret(oper1)!=interpret(oper2);
			break;
			}
	
		case AND:
			{
			return interpret(oper1)&&interpret(oper2);
			break;
			}

		case OR:
			{
			return interpret(oper1)||interpret(oper2);
			break;
			}

		case NOT:
			{
			return !interpret(oper1);
			break;
			}
		case READ:
			{
			int int_value;
			char *str_value = malloc(sizeof(char)*24);
			scanf("%d",&int_value);
			setVariableValue(oper1->var.name,oper1->var.index,makeConNode(INTEGER,int_value));
									
			return 1;
			break;
			}

		case WRITE:
			{
			
			if(oper1->nodeType == VARIABLE)
				printf("%d\n",getVariableValue(oper1->var.name,oper1->var.index));
					
			
			else
				printf("%d\n",interpret(oper1));
				
							
			return 1;
			break;
			}

		case IF:
		       {
			
			if(interpret(oper1))
				interpret(oper2);
			else if(root->oper.nops==3)
				interpret(oper3);
			break;
			}

		case WHILE:
			{
			while(interpret(oper1))
				interpret(oper2);
			break;
			}

		case '$':
			{
			interpret(oper1);
			interpret(oper2);
			break;

			}
	}
	}
}
}
*/

void semanticAnalyzer(Node * root)
{
STable *sTableEntry;
Node * oper1,*oper2,*oper3;
int nops;
if(!root)
	{
	printf("Parse Tree Root Null\n");
	exit(1);
	}
switch(root->nodeType)
{
	case CONSTANT:
		break;

	case VARIABLE:
		{
		sTableEntry = LookUp(root->var.name);
		
		if(sTableEntry==NULL)
			{
			printf("Error in %d: Variable %s not declared\n",root->lineNo,root->var.name);
			has_error = true;
			}
		else
			root->type = sTableEntry->type;

		if(root->var.index)
		{
		semanticAnalyzer(root->var.index);

		if(root->var.index->type!=INT)
			{
			printf("Error in %d: Index must be a number\n",root->lineNo);
			has_error=true;
			}
		}
		break;
		}

	case OPERATOR:
		{
		oper1 = &root->oper.operands[0];
		if(root->oper.nops>=2)
			oper2 = &root->oper.operands[1];

		if(root->oper.nops==3)
			oper3 = &root->oper.operands[2];
		nops = root->oper.nops;
		switch(root->oper.op)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			{
			if(nops==1)
			{
				semanticAnalyzer(oper1);
				root->type=oper1->type;
			}
			else
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			if((oper1->type == INT) && (oper2->type == INT))
				root->type = INT;
				
			else
				{
				printf("Error in %d: Type Error in %c \n",root->lineNo,root->oper.op);
				has_error = true;
				}
			}
			break;
			}

		case '=':
			{
			
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if(oper1->type != oper2->type)
				{
				printf("Error in %d: Type Error in =\n",root->lineNo);
				has_error = true;
				}

				
			break;
			}	
			
		case EQ:
		case '<':
		case '>':
		case LE:
		case GE:
		case NE:
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if(oper1->type == INT && oper2->type==INT)
				root->type = BOOLEAN;
				
			else
			{
				printf("Error in %d: Type Error in logical operator\n",root->lineNo);
				has_error = true;
			}
			break;
			}
		case AND:
		case OR:
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			
			if((oper1->type == BOOLEAN) && (oper2->type==BOOLEAN))
				root->type = BOOLEAN;
				
			else
			{
				printf("Error in %d: Type Error in logical operator\n",root->lineNo);
				has_error = true;
			}
			break;
			}

		case NOT:
			{
			semanticAnalyzer(oper1);
			if(oper1->type == BOOLEAN)
				root->type = BOOLEAN;
			
			else
			{
				printf("Error in %d: Type Error in NOT\n",root->lineNo);
				has_error = true;
			}
			break;

			}
		case READ:
			{
			semanticAnalyzer(oper1);
			if(oper1->type==BOOLEAN)
				{
				printf("Error in %d: Type Error in READ\n",root->lineNo);
				has_error=true;
				}
			break;
			}

		case WRITE:
			{
			semanticAnalyzer(oper1);
			if(oper1->type==BOOLEAN)
				{
				printf("Error in %d: Type Error in READ\n",root->lineNo);
				has_error=true;
				}
			
			break;
			}

		case IF:
		       {
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			if(root->oper.nops==3)
				semanticAnalyzer(oper3);
			break;
			}

		case WHILE:
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			break;
			}

		case '$':
			{
			semanticAnalyzer(oper1);
			semanticAnalyzer(oper2);
			break;
			}

			}
		}
	}
}

void freeNode (Node * node)
{
switch(node->nodeType)
{
case CONSTANT:
	{
	
	free(node);
	break;
	}

case VARIABLE:
	{
	
	free(node);
	break;
	}

case OPERATOR:
	{
	
	freeNode(&node->oper.operands[0]);
	freeNode(&node->oper.operands[1]);
	free(&node->oper.op);
	free(node);
	break;
	}
}
}








