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

STable *sTableBeg=NULL,*sTableEnd;
LTable *lTableBeg=NULL,*lTableEnd;
IdList * idListBeg=NULL, *idListEnd;
int lineNo;
bool has_error = false;
FILE * out;
int reg_count=-1;
int mem = 0,if_count=1,while_count=1,fmem=1;

#include "helper.c"
#include "semantics.c"
#include "compiler.c"
//#include "interpreter.c"


#line 89 "y.tab.c" /* yacc.c:339  */

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
    MAIN = 278,
    ENDIF = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    RET = 283,
    CONST = 284,
    STRCONST = 285,
    VAR = 286
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
#define MAIN 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define RET 283
#define CONST 284
#define STRCONST 285
#define VAR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "expl.y" /* yacc.c:355  */

int ival;
char * sval;
struct NodeTag* nval;
struct ArgList * argval;
struct IdList * idval;

#line 199 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 214 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    35,    46,     2,
      44,    45,    38,    36,    41,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      34,    32,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    70,    73,    74,    77,    78,    79,    82,
      83,    84,    85,    86,    87,    90,    91,    92,    95,    96,
      97,    98,   101,   106,   110,   111,   114,   115,   118,   119,
     120,   123,   124,   127,   130,   133,   134,   137,   138,   139,
     140,   141,   142,   143,   144,   147,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   175,   176,
     177,   178,   179,   180,   181,   182
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "DECL", "ENDDECL", "INTEGER",
  "BOOL", "END", "READ", "WRITE", "TRUE", "FALSE", "EQ", "NE", "LE", "GE",
  "AND", "OR", "NOT", "IF", "THEN", "ELSE", "MAIN", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "RET", "CONST", "STRCONST", "VAR", "'='", "'>'", "'<'",
  "'%'", "'+'", "'-'", "'*'", "'/'", "';'", "','", "'['", "']'", "'('",
  "')'", "'&'", "'{'", "'}'", "$accept", "program", "Gdeclblock",
  "Gdecllist", "Gvarlist", "Farglist", "Fargvarlist", "Fdeflist", "Fdef",
  "Fdeclblock", "Fdecllist", "Fvarlist", "Fbody", "Main", "stmt_list",
  "stmt", "ret_stmt", "expr", "Fcalllist", YY_NULLPTR
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
     285,   286,    61,    62,    60,    37,    43,    45,    42,    47,
      59,    44,    91,    93,    40,    41,    38,   123,   125
};
# endif

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-33)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      87,  -157,  -157,    27,  -157,   119,  -157,   121,  -157,     2,
       2,    -1,    19,  -157,  -157,    65,   100,   113,    17,    24,
      29,    26,  -157,  -157,    56,  -157,    71,  -157,  -157,   112,
       4,   107,   115,     6,     8,  -157,    36,    36,  -157,   141,
    -157,   183,   150,   159,   166,   177,   178,   175,   188,   174,
      11,  -157,   224,   183,   183,  -157,  -157,    38,  -157,  -157,
    -157,   132,   334,   181,   224,   224,   196,   207,  -157,   208,
     208,   197,   204,   205,   206,   -11,    61,  -157,  -157,   192,
     210,  -157,  -157,   131,   133,   228,    46,    46,    46,    46,
      46,    46,  -157,   252,  -157,  -157,  -157,   245,  -157,   -17,
    -157,  -157,    46,  -157,   108,    46,    46,    84,    97,   130,
     229,   176,   257,  -157,  -157,    46,   237,   273,    46,    -5,
     145,   143,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,   244,   264,   291,  -157,   286,
    -157,   187,  -157,   218,  -157,  -157,  -157,  -157,    21,  -157,
     273,   273,   273,   273,   300,   300,   273,   273,    67,   145,
     145,  -157,  -157,  -157,   334,   334,    46,   274,  -157,    23,
    -157,    54,   320,   265,   280,  -157,  -157,  -157,  -157,   334,
     281,   282,  -157,  -157,   332,  -157,  -157,   283,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     8,     0,    23,     0,     1,     0,     4,     0,
       0,     0,     0,    22,     2,    12,     0,     0,     0,     0,
       0,     0,    17,     6,     0,     7,     0,    17,    17,     0,
       0,     9,     0,     0,     0,    13,     0,     0,    14,     0,
      17,    27,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    30,     0,    27,    27,    21,    15,     0,    16,    10,
      11,     0,     0,     0,     0,     0,    18,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    34,     0,
       0,    19,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,    24,    25,    28,     0,    29,     0,
      63,    64,     0,    62,    65,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    31,     0,     0,    59,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
      45,     0,    37,     0,    74,    75,    72,    73,     0,    61,
      51,    56,    54,    55,    57,    58,    53,    52,    50,    46,
      47,    48,    49,    39,     0,     0,     0,     0,    66,     0,
      67,     0,     0,     0,     0,    70,    71,    68,    69,     0,
       0,     0,    44,    38,     0,    41,    42,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,  -157,   314,    32,   288,  -157,  -157,   142,
    -157,   116,   134,  -157,  -156,   -76,  -157,   -86,  -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    30,    46,     7,    13,    52,
      61,    47,    63,    14,    76,    77,    93,   107,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   108,   109,   110,   111,   112,   144,   145,   171,   172,
      36,    37,    36,    37,    36,    37,   117,    36,    37,   120,
     121,    89,    18,   184,   146,   115,   147,     6,   116,   141,
      19,    90,   143,    15,   175,   176,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    38,
      20,    42,   177,    43,   178,    29,    60,   100,   101,    33,
      34,    26,   169,    71,    72,   102,   170,    44,    27,    66,
      71,    72,    50,    28,    73,   103,   179,   104,   180,    74,
     173,    73,    45,   105,    67,    75,    74,    31,     1,    91,
     106,     2,    75,    -5,    -5,    92,    92,   122,   123,   124,
     125,   126,   127,   131,   132,   133,   134,    21,    92,    22,
     122,   123,   124,   125,   126,   127,    32,   128,   129,   130,
     131,   132,   133,   134,     8,     9,    10,    11,    12,   135,
     128,   129,   130,   131,   132,   133,   134,    68,    69,    70,
      23,    24,   136,   122,   123,   124,   125,   126,   127,    39,
     118,    40,   119,    25,    24,    35,   122,   123,   124,   125,
     126,   127,    41,   128,   129,   130,   131,   132,   133,   134,
      49,    96,    97,    98,    97,   137,   128,   129,   130,   131,
     132,   133,   134,   133,   134,    83,    84,    51,   149,   122,
     123,   124,   125,   126,   127,    64,    65,    53,    79,    80,
     122,   123,   124,   125,   126,   127,    54,   -32,    55,   128,
     129,   130,   131,   132,   133,   134,    57,    59,    56,   139,
     128,   129,   130,   131,   132,   133,   134,    62,    58,    78,
     167,   122,   123,   124,   125,   126,   127,   -31,    81,    82,
      94,    85,   122,   123,   124,   125,   126,   127,    86,    87,
      88,   128,   129,   130,   131,   132,   133,   134,    95,    99,
     113,   168,   128,   129,   130,   131,   132,   133,   134,   138,
     122,   123,   124,   125,   126,   127,   114,   142,   122,   123,
     124,   125,   126,   127,   163,   164,   -33,   -33,   -33,   -33,
     128,   129,   130,   131,   132,   133,   134,   140,   128,   129,
     130,   131,   132,   133,   134,   182,   -33,   -33,   130,   131,
     132,   133,   134,   122,   123,   124,   125,   165,   166,   174,
     183,   185,   186,   188,    17,    48,     0,     0,     0,    71,
      72,     0,     0,   128,   129,   130,   131,   132,   133,   134,
      73,    71,    72,    71,    72,    74,     0,   181,     0,     0,
       0,    75,    73,     0,    73,     0,   187,    74,     0,    74,
       0,     0,     0,    75,     0,    75
};

static const yytype_int16 yycheck[] =
{
      76,    87,    88,    89,    90,    91,    11,    12,   164,   165,
       6,     7,     6,     7,     6,     7,   102,     6,     7,   105,
     106,    32,    23,   179,    29,    42,    31,     0,    45,   115,
      31,    42,   118,    31,    11,    12,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    45,
      31,    45,    29,    45,    31,    29,    45,    11,    12,    27,
      28,    44,    41,     9,    10,    19,    45,    31,    44,    31,
       9,    10,    40,    44,    20,    29,    22,    31,    24,    25,
     166,    20,    46,    37,    46,    31,    25,    31,     1,    28,
      44,     4,    31,     6,     7,   171,   172,    13,    14,    15,
      16,    17,    18,    36,    37,    38,    39,    42,   184,    44,
      13,    14,    15,    16,    17,    18,    45,    33,    34,    35,
      36,    37,    38,    39,     5,     6,     7,     6,     7,    45,
      33,    34,    35,    36,    37,    38,    39,     5,     6,     7,
      40,    41,    45,    13,    14,    15,    16,    17,    18,    42,
      42,    44,    44,    40,    41,    43,    13,    14,    15,    16,
      17,    18,    47,    33,    34,    35,    36,    37,    38,    39,
      29,    40,    41,    40,    41,    45,    33,    34,    35,    36,
      37,    38,    39,    38,    39,    69,    70,     4,    45,    13,
      14,    15,    16,    17,    18,    53,    54,    47,    64,    65,
      13,    14,    15,    16,    17,    18,    47,    41,    31,    33,
      34,    35,    36,    37,    38,    39,    41,    43,    40,    43,
      33,    34,    35,    36,    37,    38,    39,     3,    40,    48,
      43,    13,    14,    15,    16,    17,    18,    41,    31,    31,
      48,    44,    13,    14,    15,    16,    17,    18,    44,    44,
      44,    33,    34,    35,    36,    37,    38,    39,    48,    31,
       8,    43,    33,    34,    35,    36,    37,    38,    39,    40,
      13,    14,    15,    16,    17,    18,    31,    40,    13,    14,
      15,    16,    17,    18,    40,    21,    13,    14,    15,    16,
      33,    34,    35,    36,    37,    38,    39,    40,    33,    34,
      35,    36,    37,    38,    39,    40,    33,    34,    35,    36,
      37,    38,    39,    13,    14,    15,    16,    26,    32,    45,
      40,    40,    40,    40,    10,    37,    -1,    -1,    -1,     9,
      10,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      20,     9,    10,     9,    10,    25,    -1,    27,    -1,    -1,
      -1,    31,    20,    -1,    20,    -1,    24,    25,    -1,    25,
      -1,    -1,    -1,    31,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,    50,    51,    52,     0,    56,     5,     6,
       7,     6,     7,    57,    62,    31,    53,    53,    23,    31,
      31,    42,    44,    40,    41,    40,    44,    44,    44,    29,
      54,    31,    45,    54,    54,    43,     6,     7,    45,    42,
      44,    47,    45,    45,    31,    46,    55,    60,    55,    29,
      54,     4,    58,    47,    47,    31,    40,    41,    40,    43,
      45,    59,     3,    61,    58,    58,    31,    46,     5,     6,
       7,     9,    10,    20,    25,    31,    63,    64,    48,    61,
      61,    31,    31,    60,    60,    44,    44,    44,    44,    32,
      42,    28,    64,    65,    48,    48,    40,    41,    40,    31,
      11,    12,    19,    29,    31,    37,    44,    66,    66,    66,
      66,    66,    66,     8,    31,    42,    45,    66,    42,    44,
      66,    66,    13,    14,    15,    16,    17,    18,    33,    34,
      35,    36,    37,    38,    39,    45,    45,    45,    40,    43,
      40,    66,    40,    66,    11,    12,    29,    31,    67,    45,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    40,    21,    26,    32,    43,    43,    41,
      45,    63,    63,    66,    45,    11,    12,    29,    31,    22,
      24,    27,    40,    40,    63,    40,    40,    24,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    60,    60,    61,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     0,     4,     4,     0,     3,
       6,     6,     1,     4,     4,     4,     4,     0,     3,     4,
       1,     2,     2,     0,     9,     9,     3,     0,     4,     4,
       0,     3,     1,     4,     8,     2,     1,     5,     8,     5,
      10,     8,     8,     4,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     1,     1,     1,     1,     4,     4,     3,     3,
       3,     3,     1,     1,     1,     1
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
#line 49 "expl.y" /* yacc.c:1646  */
    {
								if((yyvsp[-1].nval))
									(yyval.nval) = makeOperNode('S',2,(yyvsp[-1].nval),(yyvsp[0].nval));
								else
									(yyval.nval) = (yyvsp[0].nval);
								semanticAnalyzer((yyval.nval));
								if(!has_error)
								{
								out = fopen("sil.out","w");
								fprintf(out,"START\n");
								fprintf(out,"MOV SP,1535\n");
								fprintf(out,"MOV BP,1535\n");
								fprintf(out,"JMP MAIN\n");
								compile((yyval.nval));
								fprintf(out,"MAIN:\n");
								fprintf(out,"PUSH R0\n");
								fprintf(out,"CALL main\n");
								fprintf(out,"HALT");
								}
								return 0;
								}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "expl.y" /* yacc.c:1646  */
    {return 0;}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "expl.y" /* yacc.c:1646  */
    {}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "expl.y" /* yacc.c:1646  */
    {}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "expl.y" /* yacc.c:1646  */
    {makeSTable((yyvsp[-1].idval),INT);}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 78 "expl.y" /* yacc.c:1646  */
    {makeSTable((yyvsp[-1].idval),BOOLEAN);}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "expl.y" /* yacc.c:1646  */
    {}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-2].idval),(yyvsp[0].sval),INT,1,NULL,0);}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 83 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-5].idval),(yyvsp[-3].sval),INT,(yyvsp[-1].ival),NULL,0);}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 84 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-5].idval),(yyvsp[-3].sval),INT,1,(yyvsp[-1].argval),1);}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[0].sval),INT,1,NULL,0);}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[-3].sval),INT,(yyvsp[-1].ival),NULL,0);}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[-3].sval),INT,1,(yyvsp[-1].argval),1);}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeArgList((yyvsp[-3].argval),(yyvsp[-1].idval),INT);		}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeArgList((yyvsp[-3].argval),(yyvsp[-1].idval),BOOLEAN);		}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 92 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = NULL;}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 95 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-2].idval),(yyvsp[0].sval),INT,1,NULL,0);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 96 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-3].idval),(yyvsp[0].sval),INT,1,NULL,1);}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[0].sval),INT,1,NULL,0);}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 98 "expl.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[0].sval),INT,1,NULL,1);}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "expl.y" /* yacc.c:1646  */
    {if((yyval.nval))
									(yyval.nval) = makeOperNode('S',2,(yyvsp[-1].nval),(yyvsp[0].nval));
								 else
									(yyval.nval) = (yyvsp[0].nval);
								}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = NULL;}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 110 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeFuncNode(INT,(yyvsp[-7].sval),(yyvsp[-5].argval),(yyvsp[-1].nval));}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 111 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeFuncNode(BOOLEAN,(yyvsp[-7].sval),(yyvsp[-5].argval),(yyvsp[-1].nval));}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "expl.y" /* yacc.c:1646  */
    {}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 115 "expl.y" /* yacc.c:1646  */
    {}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 118 "expl.y" /* yacc.c:1646  */
    {makeLTable((yyvsp[-1].idval),INT);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "expl.y" /* yacc.c:1646  */
    {makeLTable((yyvsp[-1].idval),BOOLEAN);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 120 "expl.y" /* yacc.c:1646  */
    {}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 123 "expl.y" /* yacc.c:1646  */
    {(yyval.idval) =makeIdList((yyvsp[-2].idval),(yyvsp[0].sval),INT,1,NULL,0);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 124 "expl.y" /* yacc.c:1646  */
    {(yyval.idval) =makeIdList(NULL,(yyvsp[0].sval),INT,1,NULL,0);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 127 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('S',2,(yyvsp[-2].nval),(yyvsp[-1].nval));}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeFuncNode(INT,"main",NULL,(yyvsp[-1].nval));}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 133 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('S',2,(yyvsp[-1].nval),(yyvsp[0].nval));	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 134 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[0].nval);				}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 137 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(READ,1,makeVarNode((yyvsp[-2].sval),NULL,NULL,0));			}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 138 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(READ,1,makeVarNode((yyvsp[-5].sval),(yyvsp[-3].nval),NULL,0));			}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 139 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(WRITE,1,(yyvsp[-2].nval));						}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 140 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(IF,3,(yyvsp[-7].nval),(yyvsp[-4].nval),(yyvsp[-2].nval));					}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 141 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(IF,2,(yyvsp[-5].nval),(yyvsp[-2].nval));						}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 142 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(WHILE,2,(yyvsp[-5].nval),(yyvsp[-2].nval));					}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 143 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('=',2,makeVarNode((yyvsp[-3].sval),NULL,NULL,0),(yyvsp[-1].nval));		}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 144 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('=',2,makeVarNode((yyvsp[-6].sval),(yyvsp[-4].nval),NULL,0),(yyvsp[-1].nval));			}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 147 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('R',1,(yyvsp[-1].nval));		}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 151 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('+',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 152 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('-',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 153 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('*',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 154 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('/',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 155 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('%',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 156 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(EQ,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 157 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('<',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 158 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('>',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 159 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(LE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 160 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(GE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 161 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(NE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 162 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(AND,2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 163 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(OR,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 164 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(NOT,1,(yyvsp[0].nval));		}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 165 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('-',1,(yyvsp[0].nval));		}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 166 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[-1].nval);				}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 167 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(INTEGER,(yyvsp[0].ival));}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 168 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(BOOLEAN,1);	}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 169 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(BOOLEAN,0);}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 170 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeVarNode((yyvsp[0].sval),NULL,NULL,0);		}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 171 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeVarNode((yyvsp[-3].sval),(yyvsp[-1].nval),NULL,0);		}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 172 "expl.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('f',1,makeVarNode((yyvsp[-3].sval),NULL,(yyvsp[-1].argval),0));		}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 175 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList((yyvsp[-2].argval),NULL,INT,(yyvsp[0].ival));}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 176 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList((yyvsp[-2].argval),(yyvsp[0].sval),INT,0);}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 177 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList((yyvsp[-2].argval),NULL,BOOLEAN,1);}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 178 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList((yyvsp[-2].argval),NULL,BOOLEAN,0);}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 179 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList(NULL,NULL,INT,(yyvsp[0].ival));}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 180 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList(NULL,(yyvsp[0].sval),INT,0);}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 181 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList(NULL,NULL,BOOLEAN,1);}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 182 "expl.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList(NULL,NULL,BOOLEAN,0);}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1908 "y.tab.c" /* yacc.c:1646  */
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
#line 184 "expl.y" /* yacc.c:1906  */


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

