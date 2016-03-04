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
#line 1 "sil.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "parse.h"
#include "helper.c"
#include "semantics.c"
#include "compiler.c"
//#include "interpreter.c"


#line 79 "y.tab.c" /* yacc.c:339  */

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
    TYPEDEF = 258,
    BEG = 259,
    DECL = 260,
    ENDDECL = 261,
    TYPE = 262,
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
    NEW = 284,
    FREE = 285,
    CONST = 286,
    STRCONST = 287,
    VAR = 288
  };
#endif
/* Tokens.  */
#define TYPEDEF 258
#define BEG 259
#define DECL 260
#define ENDDECL 261
#define TYPE 262
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
#define NEW 284
#define FREE 285
#define CONST 286
#define STRCONST 287
#define VAR 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 15 "sil.y" /* yacc.c:355  */

int ival;
char * sval;
struct NodeTag* nval;
struct ArgList * argval;
struct typetable * typeTable;
struct IdList * idval;

#line 194 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,    51,     2,
      49,    50,    40,    38,    45,    39,    52,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      36,    34,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    50,    53,    54,    57,    58,    61,    62,
      65,    66,    67,    68,    69,    70,    71,    72,    76,    77,
      80,    81,    84,    85,    86,    87,    90,    95,    99,   102,
     103,   106,   107,   110,   111,   112,   113,   116,   119,   122,
     123,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   162,   163,   164,   167,   168,   169
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPEDEF", "BEG", "DECL", "ENDDECL",
  "TYPE", "END", "READ", "WRITE", "TRUE", "FALSE", "EQ", "NE", "LE", "GE",
  "AND", "OR", "NOT", "IF", "THEN", "ELSE", "MAIN", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "RET", "NEW", "FREE", "CONST", "STRCONST", "VAR", "'='",
  "'>'", "'<'", "'%'", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "';'",
  "','", "'^'", "'['", "']'", "'('", "')'", "'&'", "'.'", "$accept",
  "program", "TypeDefBlock", "Gdeclblock", "Gdecllist", "Gvarlist",
  "Farglist", "Fargtypelist", "Fargvarlist", "Fdeflist", "Fdef",
  "Fdeclblock", "Fdecllist", "Fvarlist", "Fbody", "Main", "stmt_list",
  "stmt", "expr", "Id", "Fcalllist", YY_NULLPTR
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
     285,   286,   287,   288,    61,    62,    60,    37,    43,    45,
      42,    47,   123,   125,    59,    44,    94,    91,    93,    40,
      41,    38,    46
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -6

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-6)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     117,   -87,     3,   116,   -87,   -10,   -87,   -87,   -15,    13,
      60,   -87,   -87,   -18,    39,   -87,   -87,     2,     4,    49,
      11,    46,    54,    15,   -87,    68,   119,   -87,   -87,    19,
      91,   119,   -87,   131,   153,   147,   -25,   -19,   -87,    76,
     146,   177,    44,   -87,   -87,    43,   -87,   -87,   184,   176,
     119,   -87,   189,   119,   -87,   217,   188,   -87,   198,   -87,
      30,   -87,   185,    48,   -87,   228,   217,   -87,   -87,   207,
     -87,   -87,   193,   335,   199,   228,   -87,   -87,   192,   194,
     195,   196,    38,   204,   216,    50,   -87,   -30,   -87,   229,
     231,    38,    38,    38,   -87,   -87,    38,   -87,   113,    38,
      38,   211,   202,   231,    38,   -87,   -87,    35,   244,   -87,
     111,    92,    99,   130,   260,    38,   161,   137,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,   -87,   144,   175,   230,   221,   -87,   234,   240,   264,
     261,   253,   -34,   -87,   260,   260,   260,   260,   267,   267,
     260,   260,   118,   161,   161,   -87,   -87,   242,   -87,    38,
     -87,   -87,   -87,   335,   335,    38,   -87,   -87,   168,   300,
     307,   253,   268,   335,   269,   270,   -87,   329,   -87,   -87,
     271,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     7,     1,     0,     9,    27,     0,     0,
       0,    32,     6,     0,     0,    26,     2,     0,    14,     0,
       0,     0,     0,     0,     4,     0,    21,    15,     8,     0,
       0,    21,    35,     0,     0,     0,     0,     0,    19,    10,
       0,     0,     0,    36,    31,     0,    16,    24,     0,    20,
      21,    17,     0,    21,    11,    30,     0,    33,     0,    25,
       0,    18,     0,     0,    32,     0,    30,    34,    22,     0,
      12,    13,     0,     0,     0,     0,    23,    29,     0,     0,
       0,     0,     0,     0,    72,     0,    40,     0,    38,     0,
       0,     0,     0,     0,    67,    68,     0,    66,    72,     0,
       0,     0,    69,     0,     0,    37,    39,     0,     0,    28,
       0,     0,     0,     0,    63,    76,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,    71,     0,     0,     0,
       0,    75,     0,    65,    55,    60,    58,    59,    61,    62,
      57,    56,    54,    50,    51,    52,    53,     0,    73,     0,
      46,    41,    42,     0,     0,     0,    70,    48,     0,     0,
       0,    74,     0,     0,     0,     0,    47,     0,    44,    45,
       0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -29,   273,   -87,   -87,
     -87,   245,   254,   -87,   246,   -87,   -62,   -84,   -86,   -73,
     -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     9,    20,    37,    38,    49,    10,
      15,    65,    17,    34,    74,    16,    85,    86,   101,   102,
     142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   106,    42,     4,   107,   111,   112,   113,    47,    23,
     114,   165,    87,   116,   117,    18,   166,   110,   133,    12,
      13,   135,   108,     8,    63,    50,    48,    11,    19,   141,
     132,    51,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    24,    94,    95,    32,    94,
      95,    25,    39,    26,    96,    28,    29,    96,   105,    78,
      79,    33,    21,    68,   134,    40,    97,    14,    98,    97,
      80,    98,    22,   168,    99,    81,    57,    99,    82,   171,
      83,    69,    27,    84,   100,   106,   106,   100,    50,    58,
      87,    87,    50,   106,    56,    30,    87,    87,    71,    35,
      87,   169,   170,    31,    87,   118,   119,   120,   121,   122,
     123,   177,   118,   119,   120,   121,   122,   123,     1,     5,
      -5,     6,    -5,    52,    -5,    53,    36,   124,   125,   126,
     127,   128,   129,   130,   124,   125,   126,   127,   128,   129,
     130,    41,   138,   118,   119,   120,   121,   122,   123,   139,
     118,   119,   120,   121,   122,   123,   127,   128,   129,   130,
     104,   137,   115,   108,    43,   124,   125,   126,   127,   128,
     129,   130,   124,   125,   126,   127,   128,   129,   130,    54,
     140,   118,   119,   120,   121,   122,   123,   143,   118,   119,
     120,   121,   122,   123,   157,    46,   108,    44,    45,    77,
      23,   129,   130,   124,   125,   126,   127,   128,   129,   130,
     124,   125,   126,   127,   128,   129,   130,    59,   172,    55,
      62,    60,    64,   158,   118,   119,   120,   121,   122,   123,
      66,    67,    73,    70,   118,   119,   120,   121,   122,   123,
      76,    90,    88,    91,    92,    93,   124,   125,   126,   127,
     128,   129,   130,   103,   108,   131,   124,   125,   126,   127,
     128,   129,   130,   104,    84,   160,   118,   119,   120,   121,
     122,   123,   109,    -6,    -6,    -6,    -6,   136,   161,   159,
     118,   119,   120,   121,   162,   163,   167,   164,   124,   125,
     126,   127,   128,   129,   130,    -6,    -6,   126,   127,   128,
     129,   130,   124,   125,   126,   127,   128,   129,   130,    78,
      79,    75,   176,   178,   179,   181,    78,    79,    72,     0,
      80,    89,   173,    61,   174,    81,     0,    80,    82,     0,
      83,     0,    81,    84,   175,    82,     0,    83,    78,    79,
      84,     0,     0,     0,    78,    79,     0,     0,     0,    80,
       0,     0,     0,   180,    81,    80,     0,    82,     0,    83,
      81,     0,    84,    82,     0,    83,     0,     0,    84
};

static const yytype_int16 yycheck[] =
{
      73,    85,    31,     0,    34,    91,    92,    93,    33,     7,
      96,    45,    85,    99,   100,    33,    50,    90,   104,     6,
       7,   107,    52,    33,    53,    44,    51,    42,    46,   115,
     103,    50,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    43,    11,    12,    33,    11,
      12,    47,    33,    49,    19,    44,    45,    19,     8,     9,
      10,    46,    23,    33,    29,    46,    31,     7,    33,    31,
      20,    33,    33,   159,    39,    25,    33,    39,    28,   165,
      30,    51,    33,    33,    49,   169,   170,    49,    44,    46,
     163,   164,    44,   177,    50,    49,   169,   170,    50,    31,
     173,   163,   164,    49,   177,    13,    14,    15,    16,    17,
      18,   173,    13,    14,    15,    16,    17,    18,     1,     3,
       3,     5,     5,    47,     7,    49,     7,    35,    36,    37,
      38,    39,    40,    41,    35,    36,    37,    38,    39,    40,
      41,    50,    50,    13,    14,    15,    16,    17,    18,    50,
      13,    14,    15,    16,    17,    18,    38,    39,    40,    41,
      47,    50,    49,    52,    33,    35,    36,    37,    38,    39,
      40,    41,    35,    36,    37,    38,    39,    40,    41,    33,
      50,    13,    14,    15,    16,    17,    18,    50,    13,    14,
      15,    16,    17,    18,    50,    48,    52,    44,    45,     6,
       7,    40,    41,    35,    36,    37,    38,    39,    40,    41,
      35,    36,    37,    38,    39,    40,    41,    33,    50,    42,
      31,    45,     5,    48,    13,    14,    15,    16,    17,    18,
      42,    33,     4,    48,    13,    14,    15,    16,    17,    18,
      33,    49,    43,    49,    49,    49,    35,    36,    37,    38,
      39,    40,    41,    49,    52,    44,    35,    36,    37,    38,
      39,    40,    41,    47,    33,    44,    13,    14,    15,    16,
      17,    18,    43,    13,    14,    15,    16,    33,    44,    49,
      13,    14,    15,    16,    44,    21,    44,    26,    35,    36,
      37,    38,    39,    40,    41,    35,    36,    37,    38,    39,
      40,    41,    35,    36,    37,    38,    39,    40,    41,     9,
      10,    66,    44,    44,    44,    44,     9,    10,    64,    -1,
      20,    75,    22,    50,    24,    25,    -1,    20,    28,    -1,
      30,    -1,    25,    33,    27,    28,    -1,    30,     9,    10,
      33,    -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    20,    -1,    28,    -1,    30,
      25,    -1,    33,    28,    -1,    30,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    54,    55,     0,     3,     5,    56,    33,    57,
      62,    42,     6,     7,     7,    63,    68,    65,    33,    46,
      58,    23,    33,     7,    43,    47,    49,    33,    44,    45,
      49,    49,    33,    46,    66,    31,     7,    59,    60,    33,
      46,    50,    59,    33,    44,    45,    48,    33,    51,    61,
      44,    50,    47,    49,    33,    42,    50,    33,    46,    33,
      45,    60,    31,    59,     5,    64,    42,    33,    33,    51,
      48,    50,    65,     4,    67,    64,    33,     6,     9,    10,
      20,    25,    28,    30,    33,    69,    70,    72,    43,    67,
      49,    49,    49,    49,    11,    12,    19,    31,    33,    39,
      49,    71,    72,    49,    47,     8,    70,    34,    52,    43,
      72,    71,    71,    71,    71,    49,    71,    71,    13,    14,
      15,    16,    17,    18,    35,    36,    37,    38,    39,    40,
      41,    44,    72,    71,    29,    71,    33,    50,    50,    50,
      50,    71,    73,    50,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    50,    48,    49,
      44,    44,    44,    21,    26,    45,    50,    44,    71,    69,
      69,    71,    50,    22,    24,    27,    44,    69,    44,    44,
      24,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    66,    66,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     6,     0,     3,     0,     4,     0,
       3,     4,     6,     6,     1,     2,     4,     4,     3,     1,
       2,     0,     3,     4,     1,     2,     2,     0,     9,     3,
       0,     4,     0,     3,     4,     1,     2,     3,     8,     2,
       1,     5,     5,    10,     8,     8,     4,     7,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     1,     1,     1,     1,
       4,     3,     1,     4,     3,     1,     0
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
#line 41 "sil.y" /* yacc.c:1646  */
    {
								if((yyvsp[-1].nval))
									(yyval.nval) = makeOperNode('S',2,(yyvsp[-1].nval),(yyvsp[0].nval));
								else
									(yyval.nval) = (yyvsp[0].nval);
								
								root = (yyval.nval);
								}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 50 "sil.y" /* yacc.c:1646  */
    {return 0;}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "sil.y" /* yacc.c:1646  */
    {typeTableInstall((yyvsp[-3].sval));}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "sil.y" /* yacc.c:1646  */
    {}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 57 "sil.y" /* yacc.c:1646  */
    {}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 58 "sil.y" /* yacc.c:1646  */
    {}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "sil.y" /* yacc.c:1646  */
    {makeSTable((yyvsp[-1].idval),(yyvsp[-2].typeTable));}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "sil.y" /* yacc.c:1646  */
    {}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 65 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-2].idval),(yyvsp[0].sval),NULL,1,NULL,0,0,0);	}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 66 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-3].idval),(yyvsp[0].sval),NULL,1,NULL,0,1,0);	}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 67 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-5].idval),(yyvsp[-3].sval),NULL,(yyvsp[-1].ival),NULL,0,0,1);	}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 68 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-5].idval),(yyvsp[-3].sval),NULL,1,(yyvsp[-1].argval),1,0,0);	}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[0].sval),NULL,1,NULL,0,0,0);	}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 70 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[0].sval),NULL,1,NULL,0,1,0);	}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[-3].sval),NULL,(yyvsp[-1].ival),NULL,0,0,1);	}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[-3].sval),NULL,1,(yyvsp[-1].argval),1,0,0);	}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "sil.y" /* yacc.c:1646  */
    {(yyval.argval) = joinArgList((yyvsp[-2].argval),(yyvsp[0].argval));		}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 77 "sil.y" /* yacc.c:1646  */
    {(yyval.argval) = (yyvsp[0].argval);				}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "sil.y" /* yacc.c:1646  */
    {(yyval.argval) = makeArgList(NULL,(yyvsp[0].idval),(yyvsp[-1].typeTable));		}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 81 "sil.y" /* yacc.c:1646  */
    {(yyval.argval) = NULL; 				}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 84 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-2].idval),(yyvsp[0].sval),NULL,1,NULL,0,0,0);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 85 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList((yyvsp[-3].idval),(yyvsp[0].sval),NULL,1,NULL,1,0,0);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 86 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[0].sval),NULL,1,NULL,0,0,0);}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 87 "sil.y" /* yacc.c:1646  */
    {(yyval.idval)=makeIdList(NULL,(yyvsp[0].sval),NULL,1,NULL,1,0,0);}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 90 "sil.y" /* yacc.c:1646  */
    {if((yyval.nval))
									(yyval.nval) = makeOperNode('S',2,(yyvsp[-1].nval),(yyvsp[0].nval));
								 else
									(yyval.nval) = (yyvsp[0].nval);
								}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = NULL;}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 99 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeFuncNode((yyvsp[-8].typeTable),(yyvsp[-7].sval),(yyvsp[-5].argval),(yyvsp[-1].nval));}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 102 "sil.y" /* yacc.c:1646  */
    {}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 103 "sil.y" /* yacc.c:1646  */
    {}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 106 "sil.y" /* yacc.c:1646  */
    {makeLTable((yyvsp[-1].idval),(yyvsp[-2].typeTable));}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 107 "sil.y" /* yacc.c:1646  */
    {}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 110 "sil.y" /* yacc.c:1646  */
    {(yyval.idval) =makeIdList((yyvsp[-2].idval),(yyvsp[0].sval),NULL,1,NULL,0,0,0);}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 111 "sil.y" /* yacc.c:1646  */
    {(yyval.idval) =makeIdList((yyvsp[-3].idval),(yyvsp[0].sval),NULL,1,NULL,0,1,1);}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 112 "sil.y" /* yacc.c:1646  */
    {(yyval.idval) =makeIdList(NULL,(yyvsp[0].sval),NULL,1,NULL,0,0,0);}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 113 "sil.y" /* yacc.c:1646  */
    {(yyval.idval) =makeIdList(NULL,(yyvsp[0].sval),NULL,1,NULL,0,1,1);}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 116 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[-1].nval);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 119 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeFuncNode((yyvsp[-7].typeTable),"main",NULL,(yyvsp[-1].nval));}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 122 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('S',2,(yyvsp[-1].nval),(yyvsp[0].nval));	}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 123 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[0].nval);				}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 126 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(READ,1,(yyvsp[-2].nval));			}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 127 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(WRITE,1,(yyvsp[-2].nval));			}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 128 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(IF,3,(yyvsp[-7].nval),(yyvsp[-4].nval),(yyvsp[-2].nval));		}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(IF,2,(yyvsp[-5].nval),(yyvsp[-2].nval));			}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(WHILE,2,(yyvsp[-5].nval),(yyvsp[-2].nval));		}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('=',2,(yyvsp[-3].nval),(yyvsp[-1].nval));		}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 132 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(NEW,2,(yyvsp[-6].nval),(yyvsp[-2].nval));		}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(FREE,1,(yyvsp[-2].nval));			}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 134 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('R',1,(yyvsp[-1].nval));			}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 139 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('+',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 140 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('-',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 141 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('*',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 142 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('/',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 143 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('%',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 144 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(EQ,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 145 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('<',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 146 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('>',2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 147 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(LE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 148 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(GE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 149 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(NE,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 150 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(AND,2,(yyvsp[-2].nval),(yyvsp[0].nval));	}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 151 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(OR,2,(yyvsp[-2].nval),(yyvsp[0].nval));		}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 152 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode(NOT,1,(yyvsp[0].nval));		}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 153 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('-',1,(yyvsp[0].nval));		}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 154 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[-1].nval);				}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 155 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(INT,(yyvsp[0].ival));		}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 156 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(BOOLEAN,1);		}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 157 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeConNode(BOOLEAN,0);		}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 158 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = (yyvsp[0].nval);				}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 159 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeOperNode('f',1,makeVarNode((yyvsp[-3].sval),NULL,(yyvsp[-1].argval),0));		}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 162 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = addInnerId((yyvsp[-2].nval),(yyvsp[0].sval));					}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 163 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeVarNode((yyvsp[0].sval),NULL,NULL,0);				}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 164 "sil.y" /* yacc.c:1646  */
    {(yyval.nval) = makeVarNode((yyvsp[-3].sval),(yyvsp[-1].nval),NULL,0);				}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 167 "sil.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList((yyvsp[-2].argval),(yyvsp[0].nval));}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 168 "sil.y" /* yacc.c:1646  */
    {(yyval.argval) = makeCallList(NULL,(yyvsp[0].nval));}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 169 "sil.y" /* yacc.c:1646  */
    {(yyval.argval) = NULL;		}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1900 "y.tab.c" /* yacc.c:1646  */
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
#line 171 "sil.y" /* yacc.c:1906  */


int main(int argc, char *argv[])
{
if(argc>1)
{
extern FILE * yyin;
yyin = fopen(argv[1],"r");
}

lineNo=1;
initializeTypeTable();
initializeSymbolTable();
yyparse();

semanticAnalyzer(root);
if(!has_error)
{
out = fopen("sil.out","w");
fprintf(out,"START\n");
fprintf(out,"MOV SP,1535\n");
fprintf(out,"MOV BP,1535\n");
fprintf(out,"PUSH R0\n");
fprintf(out,"CALL main\n");
fprintf(out,"HALT\n");
compile(root);
}								
return 0;
}


void yyerror(char * s)
{
printf("Syntax Error in %d\n",lineNo);
}

