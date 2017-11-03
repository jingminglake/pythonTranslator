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
#line 2 "parse.y" /* yacc.c:339  */

        #include <iostream>
        #include <vector>
        #include <sstream>
        #include "includes/ast.h"
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
        // extern YYSTYPE yylval;
        void deleteName(char *name);
        PoolOfNodes& pool = PoolOfNodes::getInstance(); 

#line 79 "parse.tab.c" /* yacc.c:339  */

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
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "parse.y" /* yacc.c:355  */

   class Node;
   typedef struct YYLTYPE {
     int first_line;
     int first_column;
     int last_line;
     int last_column;
   } YYLTYPE;
   #define YYLTYPE_IS_DECLARED 1

#line 120 "parse.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMPEREQUAL = 258,
    AMPERSAND = 259,
    AND = 260,
    AS = 261,
    ASSERT = 262,
    AT = 263,
    BACKQUOTE = 264,
    BAR = 265,
    BREAK = 266,
    CIRCUMFLEX = 267,
    CIRCUMFLEXEQUAL = 268,
    CLASS = 269,
    COLON = 270,
    COMMA = 271,
    CONTINUE = 272,
    DEDENT = 273,
    DEF = 274,
    DEL = 275,
    DOT = 276,
    DOUBLESLASH = 277,
    DOUBLESLASHEQUAL = 278,
    DOUBLESTAR = 279,
    DOUBLESTAREQUAL = 280,
    ELIF = 281,
    ELSE = 282,
    ENDMARKER = 283,
    EQEQUAL = 284,
    EQUAL = 285,
    EXCEPT = 286,
    EXEC = 287,
    FINALLY = 288,
    FOR = 289,
    FROM = 290,
    GLOBAL = 291,
    GREATER = 292,
    GREATEREQUAL = 293,
    GRLT = 294,
    IF = 295,
    IMPORT = 296,
    IN = 297,
    INDENT = 298,
    IS = 299,
    LAMBDA = 300,
    LBRACE = 301,
    LEFTSHIFT = 302,
    LEFTSHIFTEQUAL = 303,
    LESS = 304,
    LESSEQUAL = 305,
    LPAR = 306,
    LSQB = 307,
    MINEQUAL = 308,
    NEWLINE = 309,
    NOT = 310,
    NOTEQUAL = 311,
    NUMBER = 312,
    MINUS = 313,
    OR = 314,
    PLUS = 315,
    PASS = 316,
    PERCENT = 317,
    PERCENTEQUAL = 318,
    PLUSEQUAL = 319,
    PRINT = 320,
    RAISE = 321,
    RBRACE = 322,
    RETURN = 323,
    RIGHTSHIFT = 324,
    RIGHTSHIFTEQUAL = 325,
    RPAR = 326,
    RSQB = 327,
    SEMI = 328,
    SLASHEQUAL = 329,
    STAREQUAL = 330,
    STAR = 331,
    SLASH = 332,
    STRING = 333,
    TILDE = 334,
    TRY = 335,
    VBAREQUAL = 336,
    WHILE = 337,
    WITH = 338,
    YIELD = 339,
    NAME = 340,
    FLOATNUMBER = 341,
    INTNUMBER = 342
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 26 "parse.y" /* yacc.c:355  */

  Node* node;
  int intNumber;
  float fltNumber;
  char *id;
  int tokenId;

#line 228 "parse.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "parse.tab.c" /* yacc.c:358  */

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
#define YYLAST   943

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  314
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  477

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    67,    73,    77,    83,    84,    87,    88,
      91,    92,    95,    96,    99,   100,   103,   106,   107,   110,
     111,   114,   115,   118,   119,   122,   126,   129,   133,   139,
     140,   143,   147,   150,   151,   154,   155,   158,   164,   171,
     175,   186,   190,   196,   201,   208,   209,   210,   211,   212,
     213,   214,   217,   228,   241,   246,   253,   263,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     284,   289,   296,   297,   300,   304,   310,   311,   314,   315,
     318,   321,   324,   325,   326,   327,   328,   331,   334,   337,
     338,   341,   344,   345,   348,   349,   352,   353,   356,   357,
     360,   363,   366,   367,   370,   371,   372,   375,   380,   386,
     390,   393,   394,   397,   398,   401,   402,   405,   409,   415,
     421,   425,   428,   429,   432,   433,   436,   437,   438,   439,
     440,   441,   442,   443,   446,   447,   450,   451,   454,   455,
     458,   459,   463,   464,   467,   468,   471,   472,   475,   476,
     479,   482,   483,   486,   487,   490,   491,   494,   495,   498,
     499,   502,   504,   508,   509,   512,   513,   516,   517,   520,
     521,   524,   525,   528,   532,   536,   537,   540,   545,   549,
     554,   558,   562,   569,   574,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   591,   599,   605,   609,
     613,   618,   624,   629,   633,   634,   637,   642,   655,   660,
     666,   671,   682,   687,   692,   693,   700,   704,   711,   712,
     713,   716,   721,   727,   729,   733,   734,   735,   736,   737,
     744,   750,   756,   759,   760,   763,   764,   767,   768,   771,
     772,   775,   776,   779,   780,   783,   784,   787,   788,   791,
     792,   793,   800,   801,   804,   805,   808,   809,   810,   813,
     814,   817,   818,   821,   822,   825,   826,   829,   830,   833,
     838,   845,   846,   849,   850,   853,   854,   857,   858,   861,
     862,   865,   866,   869,   872,   873,   876,   877,   880,   881,
     884,   885,   886,   889,   890,   893,   894,   897,   898,   901,
     902,   905,   906,   909,   910,   913,   914,   917,   918,   921,
     922,   925,   926,   929,   930
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPEREQUAL", "AMPERSAND", "AND", "AS",
  "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASH", "DOUBLESLASHEQUAL", "DOUBLESTAR",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA",
  "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR",
  "LSQB", "MINEQUAL", "NEWLINE", "NOT", "NOTEQUAL", "NUMBER", "MINUS",
  "OR", "PLUS", "PASS", "PERCENT", "PERCENTEQUAL", "PLUSEQUAL", "PRINT",
  "RAISE", "RBRACE", "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL", "RPAR",
  "RSQB", "SEMI", "SLASHEQUAL", "STAREQUAL", "STAR", "SLASH", "STRING",
  "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH", "YIELD", "NAME",
  "FLOATNUMBER", "INTNUMBER", "$accept", "start", "file_input",
  "pick_NEWLINE_stmt", "star_NEWLINE_stmt", "decorator", "opt_arglist",
  "decorators", "decorated", "funcdef", "parameters", "varargslist",
  "opt_EQUAL_test", "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME",
  "pick_STAR_DOUBLESTAR", "opt_COMMA", "fpdef", "fplist",
  "star_fpdef_notest", "stmt", "simple_stmt", "star_SEMI_small_stmt",
  "small_stmt", "expr_stmt", "pick_yield_expr_testlist", "star_EQUAL",
  "augassign", "print_stmt", "star_COMMA_test", "opt_test",
  "plus_COMMA_test", "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "pick_dotted_name", "pick_STAR_import", "import_as_name",
  "dotted_as_name", "import_as_names", "star_COMMA_import_as_name",
  "dotted_as_names", "dotted_name", "global_stmt", "star_COMMA_NAME",
  "exec_stmt", "assert_stmt", "compound_stmt", "if_stmt", "star_ELIF",
  "while_stmt", "for_stmt", "try_stmt", "plus_except", "opt_ELSE",
  "opt_FINALLY", "with_stmt", "star_COMMA_with_item", "with_item",
  "except_clause", "pick_AS_COMMA", "opt_AS_COMMA", "suite", "plus_stmt",
  "testlist_safe", "plus_COMMA_old_test", "old_test", "old_lambdef",
  "test", "opt_IF_ELSE", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "star_COMMA_subscript",
  "subscript", "opt_test_only", "opt_sliceop", "sliceop", "exprlist",
  "star_COMMA_expr", "testlist", "dictorsetmaker", "star_test_COLON_test",
  "pick_for_test_test", "pick_for_test", "classdef", "opt_testlist",
  "arglist", "star_argument_COMMA", "star_COMMA_argument",
  "opt_DOUBLESTAR_test", "pick_argument", "argument", "opt_comp_for",
  "list_iter", "list_for", "list_if", "comp_iter", "comp_for", "comp_if",
  "testlist1", "yield_expr", "star_DOT", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -395

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-395)))

#define YYTABLE_NINF -261

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -395,    60,  -395,   388,  -395,   802,    -3,   802,  -395,    27,
    -395,    30,   282,  -395,   282,   282,  -395,    43,   802,    -3,
     101,   802,   735,   802,  -395,   856,  -395,  -395,  -395,    92,
     802,   802,  -395,  -395,   117,   802,   802,   802,  -395,  -395,
    -395,  -395,  -395,   115,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,     8,   131,  -395,   615,   132,   134,   144,   -13,
      81,    48,  -395,   282,  -395,  -395,    71,  -395,   207,  -395,
    -395,   137,  -395,    21,  -395,    52,    20,   104,   132,  -395,
      36,   114,   116,    12,  -395,   147,  -395,   148,    97,   802,
     151,     3,    42,    96,  -395,   135,  -395,   103,  -395,  -395,
     138,   110,  -395,  -395,   802,  -395,  -395,   157,  -395,   631,
     160,  -395,   178,  -395,  -395,  -395,  -395,    11,   170,   856,
     856,  -395,   856,  -395,  -395,  -395,  -395,  -395,   133,  -395,
    -395,   152,  -395,   282,   282,   282,   282,  -395,  -395,   282,
    -395,  -395,   282,  -395,  -395,  -395,  -395,   282,  -395,    75,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,   163,   735,   802,   105,   125,  -395,  -395,
     802,   631,   802,   126,   183,   184,   802,   802,   -12,   158,
     181,   187,   631,    -3,   119,  -395,   802,   124,   -22,   127,
    -395,  -395,   186,   802,   282,   195,  -395,  -395,  -395,   195,
    -395,  -395,   282,   195,  -395,  -395,   197,   195,   802,  -395,
     174,  -395,   102,   631,    90,   282,  -395,   691,   802,    18,
     131,  -395,  -395,  -395,   132,   134,   144,   -13,    81,    48,
    -395,   136,   282,   125,   746,  -395,   735,  -395,  -395,  -395,
    -395,  -395,   154,  -395,    35,  -395,  -395,  -395,   164,  -395,
     166,   631,   282,   206,   213,   153,  -395,   223,  -395,  -395,
    -395,   156,  -395,  -395,  -395,  -395,  -395,  -395,   171,   227,
     802,   228,   135,   203,   802,  -395,  -395,   204,  -395,   802,
     232,  -395,  -395,   206,   550,   802,   235,    31,   237,   226,
     631,   802,   132,  -395,  -395,  -395,   802,  -395,  -395,   185,
     233,   242,   189,  -395,   243,  -395,   208,   802,   802,    55,
    -395,   247,   251,  -395,  -395,   132,   802,  -395,   631,   198,
     191,   252,  -395,    25,   256,  -395,   254,  -395,  -395,    23,
    -395,   264,  -395,  -395,   856,   846,  -395,   802,  -395,  -395,
    -395,   469,    34,   631,   268,   253,   269,   631,   272,  -395,
    -395,  -395,  -395,   271,  -395,   274,   802,  -395,  -395,  -395,
     802,  -395,  -395,   222,  -395,   631,  -395,   270,  -395,  -395,
     153,   802,   281,   -22,   229,   802,  -395,    15,   283,    58,
     291,  -395,   249,  -395,  -395,  -395,  -395,  -395,   802,  -395,
    -395,   631,   297,  -395,   631,  -395,   631,  -395,   258,  -395,
     300,   301,  -395,  -395,   304,  -395,   305,   631,  -395,  -395,
     306,   846,  -395,  -395,  -395,   846,   310,   846,  -395,  -395,
    -395,   846,   313,  -395,  -395,   631,  -395,  -395,  -395,   802,
    -395,  -395,   791,  -395,   631,   631,  -395,   802,    68,  -395,
     846,    58,  -395,   846,  -395,  -395,  -395,   802,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,     0,     0,     0,    87,     0,
      88,     0,     0,     3,     0,     0,   314,     0,     0,     0,
      24,   240,   236,   238,     4,     0,   219,   218,    81,    75,
      93,    90,   242,   220,     0,     0,     0,   312,   229,   230,
     231,     6,    13,     0,   133,   131,     5,    37,    42,    43,
      44,    45,    46,    47,    82,    83,    84,    86,    85,    48,
      98,    99,    49,    50,    51,    38,   126,   127,   128,   129,
     130,    73,   176,   177,   179,   182,   183,   196,   198,   200,
     202,   206,   210,     0,   217,   224,   232,   174,    57,   132,
      91,   125,   117,     0,   309,     0,     0,     0,   268,    80,
     123,     0,     0,     0,   121,     0,   115,   100,   110,     0,
       0,     0,    73,     0,   239,    73,   235,     0,   234,   233,
      73,     0,   237,   181,     0,    70,    73,    97,    89,     0,
       0,   152,   154,   311,    12,    15,    14,     0,   270,     0,
       0,   173,     0,   187,   186,   188,   190,   192,   194,   185,
     189,     0,   191,     0,     0,     0,     0,   204,   205,     0,
     209,   208,     0,   215,   214,   212,   213,     0,   216,   222,
     241,    63,    65,    69,    68,    66,    59,    62,    58,    67,
      61,    60,    64,    53,     0,     0,     0,   285,     9,   228,
       0,     0,   282,    24,     0,   266,     0,     0,     0,   313,
     102,   119,     0,     0,     0,   248,     0,     0,     0,     0,
      31,    19,    22,     0,     0,    30,   272,   277,   227,    30,
     245,   225,     0,    30,   243,   226,    79,    30,     0,    92,
       0,   161,     0,     0,     0,     0,    40,     0,   269,     0,
     178,   180,   195,   193,   184,   197,   199,   201,   203,   207,
     211,     0,     0,   285,   260,   223,     0,    52,    55,    54,
     124,   118,     0,    10,     0,   310,   280,   281,     0,    18,
       0,     0,   265,    95,     0,     0,   104,   108,   101,   114,
     106,     0,   137,   116,   109,   247,    28,    36,     0,    26,
       0,    30,   274,     0,    29,   278,   246,     0,   244,     0,
      30,    71,    74,    95,     0,   156,     0,   147,     0,   139,
       0,     0,   153,    39,    41,    72,     0,   251,   221,     0,
       0,   257,     0,   255,     0,    56,     0,     0,     0,   296,
     283,    30,     0,    17,    16,   267,     0,   122,     0,     0,
       0,   112,   120,   135,    34,    32,     0,    27,    21,    23,
      20,    30,   271,   275,     0,     0,    77,    29,    78,    96,
     164,     0,   160,     0,     0,   149,     0,     0,     0,   150,
     151,   175,   249,     0,   250,   253,   260,     8,   292,   287,
       0,   293,   295,   284,   290,     0,    94,   141,   105,   107,
     111,     0,     0,    33,     0,    29,   276,   306,    24,   300,
     166,   170,   169,    76,   162,   163,   157,   158,     0,   155,
     143,     0,     0,   142,     0,   145,     0,   256,   252,   259,
     262,   289,   294,   279,     0,   113,     0,     0,    35,    25,
       0,     0,   305,   303,   304,     0,     0,     0,   299,   297,
     298,     0,    30,   159,   146,     0,   144,   138,   254,   264,
     258,   261,     0,   291,     0,     0,   134,     0,   308,   172,
       0,   302,   168,    29,   165,   148,   263,     0,   286,   140,
     136,   273,   307,   171,   301,   167,   288
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -395,  -395,  -395,  -395,  -395,   287,    73,  -395,  -395,   289,
    -395,  -174,  -395,  -395,  -395,  -395,  -191,  -198,  -395,  -395,
    -278,    -2,  -395,    98,  -395,    82,  -395,  -395,  -395,    39,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,    38,  -395,  -395,  -395,  -395,  -395,  -395,   -51,   143,
      72,  -395,  -395,    14,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,    37,
      44,  -395,  -395,  -180,  -395,  -395,  -395,  -394,  -395,    -5,
    -395,  -136,   209,   -11,  -395,  -395,    -8,   196,   199,   200,
    -395,   194,  -395,   193,  -395,   -60,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,   -61,   -18,  -395,  -395,    -7,  -395,   -16,  -395,  -395,
    -395,  -395,   319,  -395,  -395,  -395,  -395,  -395,  -395,   -89,
    -395,   -97,   245,  -395,   -92,  -103,  -395,  -395,   -17,  -395
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,     3,    42,   262,    43,    44,    45,
     194,   110,   291,   111,   347,   211,   295,   212,   288,   344,
      46,   231,   137,    48,    49,   257,   183,   184,    50,   138,
     125,   300,   301,    51,    52,    53,    54,    55,    56,    57,
      58,   337,   229,    59,    60,    61,   102,   278,   279,   106,
     280,   341,   107,   108,    62,   201,    63,    64,    65,    66,
     343,    67,    68,    69,   307,   365,   413,    70,   234,   131,
     308,   408,   409,   232,   361,   399,   442,   400,   401,    71,
     141,    72,    73,    74,    75,   153,    76,    77,    78,    79,
     159,    80,   162,    81,   167,    82,    83,    84,   169,    85,
     116,   117,   121,   113,    86,   122,   118,    87,   255,   322,
     375,   323,   324,   450,   451,    99,   195,    88,   114,   351,
     352,   216,    89,   268,   263,   264,   421,   453,   330,   331,
     381,   438,   439,   440,   432,   433,   434,    95,    90,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    47,    94,   239,    98,   119,   100,    98,   101,   217,
     287,   266,   220,   105,   123,   128,   112,   115,   120,   270,
      93,   133,   282,   168,   126,   127,   360,   207,   296,   208,
     130,   132,   298,   199,   157,   191,   302,   458,   -29,   275,
     406,   459,   186,   461,     7,   316,   154,   462,   139,   214,
     407,   391,   392,   309,   208,   431,   158,   213,   364,   327,
       4,   189,   305,   210,   276,   236,   473,   140,   190,   475,
     163,   192,   187,   277,   140,   188,   214,   140,   196,   209,
      20,    21,    92,   405,   237,   380,    22,    23,   210,   214,
      25,   334,   222,    26,   -29,    27,   251,    92,   437,   252,
     350,     7,   214,   204,   205,   310,   311,   250,   431,   358,
     164,   328,    96,    32,    33,    97,   109,   200,   186,   226,
      38,    39,    40,     6,   165,   166,   253,   254,   104,     9,
     369,   241,   129,   305,    11,   306,   142,    20,    21,   160,
     384,   161,   154,    22,    23,   244,   155,    25,   156,   170,
      26,   215,    27,   185,   219,   193,   197,   198,   387,   223,
     396,   124,   202,   218,   203,   227,   206,   259,   258,   214,
      32,    33,   222,   228,   221,   233,   267,    38,    39,    40,
     260,   274,   225,   410,   235,   265,   238,   415,   242,   353,
     261,   273,   318,   256,   243,   428,   -11,   269,   271,  -103,
     272,   285,   186,   281,   284,   423,    98,   293,   292,   286,
     171,   294,   289,   299,    98,   297,   290,   304,   397,   402,
     172,   317,   336,   303,   436,   326,   382,   312,   338,   340,
     173,   444,   174,   315,   446,   332,   447,   333,   277,   259,
     258,   342,   345,   346,   349,   354,   355,   456,   357,   321,
     363,   464,   367,   368,   373,   175,   372,  -259,   376,   329,
     176,   374,   377,   383,   335,   465,   385,     7,   390,   388,
     177,   178,   393,  -260,   469,   470,   389,   179,   394,   320,
     395,   180,   181,   411,   414,   348,   412,   416,   182,   315,
     418,     7,   417,   -29,   356,   402,   427,   424,   435,   402,
     362,   402,    47,    20,    21,   402,   132,   441,   140,    22,
      23,   371,   445,    25,   429,   449,    26,   452,    27,   454,
     455,   457,   378,   379,   402,   460,   319,   402,    21,   463,
     134,   386,   135,    22,    23,   314,    32,    33,   325,   425,
      26,   359,    27,    38,    39,    40,   283,   339,   370,   240,
     245,   366,   403,   248,   246,   249,   247,   448,   420,    47,
      32,    33,   136,   468,   474,   224,   472,    38,    39,    40,
       0,   419,     0,     0,     0,   422,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   426,     0,     0,     0,
     430,     0,     0,     0,     0,     5,     6,     7,     0,     8,
       0,     0,     9,   443,     0,    10,     0,    11,    12,     0,
       0,     0,     0,   321,     0,     0,    13,     0,     0,     0,
      14,     0,    15,    16,    17,     0,     0,     0,    18,    19,
       0,     0,     0,    20,    21,     0,     0,     0,     0,    22,
      23,     0,    24,    25,   466,     0,    26,   329,    27,    28,
       0,     0,   471,    29,    30,     0,    31,     0,     0,     0,
       0,     0,   476,     0,     0,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,     5,     6,     7,     0,
       8,     0,     0,     9,     0,     0,    10,   404,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,    17,     0,     0,     0,    18,
      19,     0,     0,     0,    20,    21,     0,     0,     0,     0,
      22,    23,     0,     0,    25,     0,     0,    26,     0,    27,
      28,     0,     0,     0,    29,    30,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,     5,     6,     7,
       0,     8,     0,     0,     9,     0,     0,    10,     0,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,    15,    16,    17,     0,     0,     0,
      18,    19,     0,     0,     0,    20,    21,     0,     0,     0,
       0,    22,    23,     0,     0,    25,     0,     0,    26,     0,
      27,    28,     0,     0,     0,    29,    30,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,     5,     0,
       7,     0,     8,     0,   143,     0,     0,     0,    10,     0,
       0,    12,   144,   145,   146,     0,     0,   147,     0,   148,
       0,     0,     0,    14,   149,   150,    16,    17,     0,     0,
     151,   152,    19,     0,     0,     0,    20,    21,     0,     0,
       0,     0,    22,    23,     0,   230,    25,     0,     0,    26,
       0,    27,    28,     0,     0,     0,    29,    30,     5,    31,
       7,     0,     8,     0,     0,     0,     0,     0,    10,    32,
      33,    12,     0,     0,     0,    37,    38,    39,    40,     0,
       0,     0,     0,    14,     0,     0,    16,    17,     0,     0,
       0,     0,    19,     0,     0,     0,    20,    21,     0,     0,
       0,     0,    22,    23,     7,   313,    25,     0,     0,    26,
       0,    27,    28,     0,     0,     7,    29,    30,     0,    31,
       0,     0,     0,     0,     0,     0,     0,   320,     0,    32,
      33,     0,     0,     0,     0,    37,    38,    39,    40,     0,
      20,    21,     0,     0,     0,     0,    22,    23,     0,     0,
      25,    20,    21,    26,     0,    27,     0,    22,    23,     0,
       7,    25,     0,     0,    26,     0,    27,     0,     0,     0,
       0,     7,     0,    32,    33,   467,     0,     0,     0,    37,
      38,    39,    40,     0,    32,    33,     0,     0,     0,     0,
       0,    38,    39,    40,     0,     0,    20,    21,     0,     0,
       0,     0,    22,    23,     0,     0,    25,    20,    21,    26,
       0,    27,     0,    22,    23,     7,     0,    25,     0,     0,
      26,     0,    27,     0,     0,     7,     0,     0,     0,    32,
      33,     0,     0,     0,     0,     0,    38,    39,    40,     0,
      32,    33,     0,     0,     0,     0,     0,    38,    39,    40,
       0,   398,    21,     0,     0,     0,     0,    22,    23,     0,
       0,    25,    21,     0,    26,     0,    27,    22,    23,     0,
       0,    25,     0,     0,    26,     0,    27,     0,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,     0,     0,
       0,    38,    39,    40,    32,    33,     0,     0,     0,     0,
       0,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,   139,    12,    22,    14,    15,    15,   112,
     208,   191,   115,    18,    25,    31,    21,    22,    23,   193,
       6,    37,   202,    83,    29,    30,   304,    24,   219,    51,
      35,    36,   223,    21,    47,    15,   227,   431,    15,    51,
       6,   435,    21,   437,     9,    27,    10,   441,    40,    34,
      16,    26,    27,   233,    51,    40,    69,    15,    27,    24,
       0,     9,    31,    85,    76,    54,   460,    59,    16,   463,
      22,    51,    51,    85,    59,    54,    34,    59,    42,    76,
      45,    46,    85,   361,    73,    30,    51,    52,    85,    34,
      55,   271,    34,    58,    71,    60,    21,    85,    40,    24,
     291,     9,    34,     6,   109,    15,    16,   167,    40,   300,
      62,    76,    85,    78,    79,    85,    15,   103,    21,   124,
      85,    86,    87,     8,    76,    77,    51,    52,    85,    14,
     310,   142,    15,    31,    19,    33,     5,    45,    46,    58,
     331,    60,    10,    51,    52,   153,    12,    55,     4,    78,
      58,   112,    60,    16,   115,    51,    42,    41,   338,   120,
     351,    69,    15,    67,    16,   126,    15,   184,   184,    34,
      78,    79,    34,    16,    71,    15,   192,    85,    86,    87,
     185,   197,    72,   363,     6,   190,    16,   367,    55,   292,
      85,   196,   252,    30,    42,   393,    71,    71,    15,    41,
      16,   206,    21,    16,    85,   385,   214,   214,   213,    85,
       3,    16,    85,    16,   222,   222,    30,    43,   354,   355,
      13,    85,    16,   228,   398,    71,   329,   235,    15,     6,
      23,   411,    25,   238,   414,    71,   416,    71,    85,   256,
     256,    85,    71,    16,    16,    42,    42,   427,    16,   254,
      15,   442,    15,    27,    21,    48,    71,    15,    15,   264,
      53,    72,    54,    16,   272,   445,    15,     9,    16,    71,
      63,    64,    16,    15,   454,   455,    85,    70,    24,    21,
      16,    74,    75,    15,    15,   290,    33,    15,    81,   294,
      16,     9,    21,    71,   299,   431,    15,    27,    15,   435,
     305,   437,   304,    45,    46,   441,   311,    16,    59,    51,
      52,   316,    15,    55,    85,    15,    58,    16,    60,    15,
      15,    15,   327,   328,   460,    15,   253,   463,    46,    16,
      43,   336,    43,    51,    52,   237,    78,    79,   256,   390,
      58,   303,    60,    85,    86,    87,   203,   275,   311,   140,
     154,   307,   357,   159,   155,   162,   156,   418,   376,   361,
      78,    79,    43,   452,   461,   120,   458,    85,    86,    87,
      -1,   376,    -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,    -1,
     395,    -1,    -1,    -1,    -1,     7,     8,     9,    -1,    11,
      -1,    -1,    14,   408,    -1,    17,    -1,    19,    20,    -1,
      -1,    -1,    -1,   418,    -1,    -1,    28,    -1,    -1,    -1,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    51,
      52,    -1,    54,    55,   449,    -1,    58,   452,    60,    61,
      -1,    -1,   457,    65,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,   467,    -1,    -1,    -1,    78,    79,    80,    -1,
      82,    83,    84,    85,    86,    87,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    -1,    -1,    58,    -1,    60,
      61,    -1,    -1,    -1,    65,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    82,    83,    84,    85,    86,    87,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    -1,    17,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    -1,    -1,    58,    -1,
      60,    61,    -1,    -1,    -1,    65,    66,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    -1,    82,    83,    84,    85,    86,    87,     7,    -1,
       9,    -1,    11,    -1,    29,    -1,    -1,    -1,    17,    -1,
      -1,    20,    37,    38,    39,    -1,    -1,    42,    -1,    44,
      -1,    -1,    -1,    32,    49,    50,    35,    36,    -1,    -1,
      55,    56,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    -1,    -1,    58,
      -1,    60,    61,    -1,    -1,    -1,    65,    66,     7,    68,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    78,
      79,    20,    -1,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,     9,    54,    55,    -1,    -1,    58,
      -1,    60,    61,    -1,    -1,     9,    65,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    78,
      79,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    -1,
      45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    45,    46,    58,    -1,    60,    -1,    51,    52,    -1,
       9,    55,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,     9,    -1,    78,    79,    24,    -1,    -1,    -1,    84,
      85,    86,    87,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    45,    46,    58,
      -1,    60,    -1,    51,    52,     9,    -1,    55,    -1,    -1,
      58,    -1,    60,    -1,    -1,     9,    -1,    -1,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      -1,    45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    46,    -1,    58,    -1,    60,    51,    52,    -1,
      -1,    55,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    28,    32,    34,    35,    36,    40,    41,
      45,    46,    51,    52,    54,    55,    58,    60,    61,    65,
      66,    68,    78,    79,    80,    82,    83,    84,    85,    86,
      87,    91,    93,    95,    96,    97,   108,   109,   111,   112,
     116,   121,   122,   123,   124,   125,   126,   127,   128,   131,
     132,   133,   142,   144,   145,   146,   147,   149,   150,   151,
     155,   167,   169,   170,   171,   172,   174,   175,   176,   177,
     179,   181,   183,   184,   185,   187,   192,   195,   205,   210,
     226,   167,    85,   141,   167,   225,    85,    85,   174,   203,
     174,   203,   134,   227,    85,   167,   137,   140,   141,    15,
      99,   101,   167,   191,   206,   167,   188,   189,   194,   226,
     167,   190,   193,   171,    69,   118,   167,   167,   205,    15,
     167,   157,   167,   205,    93,    97,   210,   110,   117,    40,
      59,   168,     5,    29,    37,    38,    39,    42,    44,    49,
      50,    55,    56,   173,    10,    12,     4,    47,    69,   178,
      58,    60,   180,    22,    62,    76,    77,   182,   183,   186,
      78,     3,    13,    23,    25,    48,    53,    63,    64,    70,
      74,    75,    81,   114,   115,    16,    21,    51,    54,     9,
      16,    15,    51,    51,    98,   204,    42,    42,    41,    21,
     141,   143,    15,    16,     6,   167,    15,    24,    51,    76,
      85,   103,   105,    15,    34,   117,   209,   223,    67,   117,
     223,    71,    34,   117,   220,    72,   167,   117,    16,   130,
      54,   109,   161,    15,   156,     6,    54,    73,    16,   169,
     170,   171,    55,    42,   174,   175,   176,   177,   179,   181,
     183,    21,    24,    51,    52,   196,    30,   113,   205,   226,
     167,    85,    94,   212,   213,   167,   161,   205,   211,    71,
      99,    15,    16,   167,   205,    51,    76,    85,   135,   136,
     138,    16,   161,   137,    85,   167,    85,   105,   106,    85,
      30,   100,   167,   203,    16,   104,   104,   203,   104,    16,
     119,   120,   104,   167,    43,    31,    33,   152,   158,   161,
      15,    16,   174,    54,   111,   167,    27,    85,   183,    94,
      21,   167,   197,   199,   200,   113,    71,    24,    76,   167,
     216,   217,    71,    71,   161,   174,    16,   129,    15,   138,
       6,   139,    85,   148,   107,    71,    16,   102,   167,    16,
     104,   207,   208,   223,    42,    42,   167,    16,   104,   129,
     108,   162,   167,    15,    27,   153,   158,    15,    27,   161,
     157,   167,    71,    21,    72,   198,    15,    54,   167,   167,
      30,   218,   223,    16,   104,    15,   167,   161,    71,    85,
      16,    26,    27,    16,    24,    16,   104,   169,    45,   163,
     165,   166,   169,   167,    18,   108,     6,    16,   159,   160,
     161,    15,    33,   154,    15,   161,    15,    21,    16,   167,
     200,   214,   167,   161,    27,   136,   167,    15,   105,    85,
     167,    40,   222,   223,   224,    15,    99,    40,   219,   220,
     221,    16,   164,   167,   161,    15,   161,   161,   199,    15,
     201,   202,    16,   215,    15,    15,   161,    15,   165,   165,
      15,   165,   165,    16,   104,   161,   167,    24,   217,   161,
     161,   167,   222,   165,   219,   165,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   122,   123,   123,   123,   123,   123,   124,   125,   126,
     126,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   133,   134,   134,   135,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   175,   175,
     176,   176,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   181,   182,   182,   182,   182,   183,   183,   184,   184,
     184,   185,   185,   186,   186,   187,   187,   187,   187,   187,
     187,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     196,   196,   197,   197,   198,   198,   199,   199,   199,   200,
     200,   201,   201,   202,   202,   203,   203,   204,   204,   205,
     205,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   212,   213,   213,   214,   214,   215,   215,
     216,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   226,   226,   227,   227
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     5,     3,     2,     2,
       4,     2,     0,     4,     0,     3,     0,     3,     2,     1,
       0,     1,     3,     3,     2,     3,     0,     1,     1,     4,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     0,     3,     0,     3,     2,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     1,     2,     0,     3,     0,     1,     1,
       2,     4,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     3,     0,     1,     3,     1,     3,     3,
       3,     0,     5,     2,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     8,     5,     5,     0,     7,     4,
       9,     6,     6,     6,     4,     3,     3,     0,     3,     0,
       5,     3,     0,     3,     1,     3,     1,     1,     1,     2,
       0,     1,     4,     2,     1,     3,     1,     3,     2,     1,
       1,     4,     3,     2,     1,     4,     0,     1,     3,     1,
       3,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     4,     2,     2,     0,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       0,     2,     1,     2,     3,     2,     3,     4,     3,     3,
       3,     2,     3,     2,     3,     0,     3,     1,     4,     1,
       0,     1,     0,     2,     1,     3,     2,     3,     0,     3,
       2,     4,     2,     5,     0,     1,     2,     1,     2,     7,
       4,     1,     0,     2,     3,     0,     3,     0,     3,     0,
       2,     4,     2,     2,     3,     1,     0,     1,     1,     5,
       4,     3,     2,     1,     1,     5,     4,     3,     2,     1,
       3,     2,     1,     2,     0
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
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
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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
     '$$ = $1'.

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
#line 62 "parse.y" /* yacc.c:1646  */
    {
             std::cout <<  "file_input -> start" << std::endl;
        }
#line 1928 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 68 "parse.y" /* yacc.c:1646  */
    {
            std::cout <<  "star_NEWLINE_stmt ENDMARKER -> file_input" << std::endl;
        }
#line 1936 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "parse.y" /* yacc.c:1646  */
    {
          std::cout << "NEWLINE -> pick_NEWLINE_stmt" << std::endl;
        }
#line 1944 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 78 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "stmt -> pick_NEWLINE_stmt" << std::endl;
        }
#line 1952 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 1960 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 130 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[-1].id));
        }
#line 1968 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 134 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 1976 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 144 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 1984 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
	     //($$)->eval()->print();
             std::cout << "simple_stmt -> stmt" << std::endl;
         }
#line 1994 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "parse.y" /* yacc.c:1646  */
    {
	     (yyval.node) = NULL;
             std::cout << "compound_stmt -> stmt" << std::endl;
         }
#line 2003 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 172 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[-3].node);
             std::cout << "small_stmt star_SEMI_small_stmt SEMI NEWLINE -> simple_stmt" << std::endl;          }
#line 2011 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 176 "parse.y" /* yacc.c:1646  */
    {
	     // print 
	     (yyval.node) = (yyvsp[-2].node);
	     std::cout << "---------print3---------" << std::endl;
	     ((yyval.node))->eval()->print();
	     std::cout << "---------print3---------" << std::endl;
             std::cout << "small_stmt star_SEMI_small_stmt NEWLINE  -> simple_stmt" << std::endl;
         }
#line 2024 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 187 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "star_SEMI_small_stmt SEMI small_stmt -> star_SEMI_small_stmt" << std::endl;
        }
#line 2032 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 191 "parse.y" /* yacc.c:1646  */
    {
           std::cout << " -> star_SEMI_small_stmt" << std::endl; 
        }
#line 2040 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = (yyvsp[0].node);
          std::cout << "expr_stmt -> small_stmt" << std::endl; 
        }
#line 2049 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 202 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = (yyvsp[0].node);
	  std::cout << "---------print4---------" << std::endl;
	  ((yyval.node))->eval()->print();
	  std::cout << "---------print4---------" << std::endl;
        }
#line 2060 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 218 "parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0].node) == NULL) {
	      (yyval.node) = (yyvsp[-2].node);
            }
            else {
              (yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
              pool.add((yyval.node));
	    }
            std::cout << "testlist augassign pick_yield_expr_testlist -> expr_stmt" << std::endl;
        }
#line 2075 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 229 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "---------print---------" << std::endl;
	    if ((yyvsp[0].node) == NULL)
	      (yyval.node) = (yyvsp[-1].node);
            else {
              (yyval.node) = new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node)); 
              pool.add((yyval.node));
	    }
            std::cout << "testlist star_EQUAL -> expr_stmt" << std::endl;
        }
#line 2090 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 242 "parse.y" /* yacc.c:1646  */
    {
	    (yyval.node) = NULL;
            std::cout << "yield_expr -> pick_yield_expr_testlist" << std::endl;
        }
#line 2099 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 247 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "testlist -> pick_yield_expr_testlist" << std::endl;
        }
#line 2108 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 254 "parse.y" /* yacc.c:1646  */
    {
          if ((yyvsp[-2].node) == NULL) {
	    (yyval.node) = (yyvsp[0].node);
          } else {
	      (yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
	      pool.add((yyval.node));
          }
            std::cout << "star_EQUAL EQUAL pick_yield_expr_testlist -> star_EQUAL" << std::endl;  
        }
#line 2122 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 264 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = NULL;
            std::cout << "  -> star_EQUAL" << std::endl;
        }
#line 2131 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 285 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = (yyvsp[0].node);
	  std::cout << "PRINT opt_test -> print_stmt" << std::endl; 
        }
#line 2140 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 290 "parse.y" /* yacc.c:1646  */
    {
	  (yyval.node) = (yyvsp[-1].node);
          std::cout << "PRINT RIGHTSHIFT test opt_test_2 -> print_stmt" << std::endl;
        }
#line 2149 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 301 "parse.y" /* yacc.c:1646  */
    {
	  (yyval.node) = (yyvsp[-2].node);
        }
#line 2157 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 305 "parse.y" /* yacc.c:1646  */
    {
	  (yyval.node) = NULL;
        }
#line 2165 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 376 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[-2].id));
          deleteName((yyvsp[0].id));
        }
#line 2174 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 381 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2182 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 387 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2190 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 406 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2198 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 410 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2206 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 416 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[-1].id));
        }
#line 2214 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 422 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2222 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 503 "parse.y" /* yacc.c:1646  */
    { std::cout << "simple_stmt -> suite" << std::endl; }
#line 2228 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 505 "parse.y" /* yacc.c:1646  */
    { std::cout << "NEWLINE INDENT plus_stmt DEDENT -> suite" << std::endl; }
#line 2234 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 529 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            std::cout << "or_test opt_IF_ELSE -> test" << std::endl; }
#line 2242 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 533 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;}
#line 2248 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 541 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
             std::cout << "and_test -> or_test" << std::endl;
         }
#line 2257 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 546 "parse.y" /* yacc.c:1646  */
    { std::cout << "or_test OR and_test -> or_test" << std::endl; }
#line 2263 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 550 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
             std::cout << "not_test -> and_test" << std::endl;
         }
#line 2272 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 555 "parse.y" /* yacc.c:1646  */
    { std::cout << "and_test AND not_test  -> and_test" << std::endl; }
#line 2278 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 559 "parse.y" /* yacc.c:1646  */
    {
             std::cout << "NOT not_test -> not_test" << std::endl;
         }
#line 2286 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 563 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);   
            std::cout << "comparison -> not_test" << std::endl; 
         }
#line 2295 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 570 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
             std::cout << "expr -> comparison" << std::endl;
         }
#line 2304 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 575 "parse.y" /* yacc.c:1646  */
    { std::cout << "comp_op expr -> comparison" << std::endl; }
#line 2310 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 592 "parse.y" /* yacc.c:1646  */
    {
	    std::cout << "---------print----1-----" << std::endl;
	    //($$)->eval()->print();
	    std::cout << "---------print----1-----" << std::endl;
            (yyval.node) = (yyvsp[0].node);
            std::cout << "xor_expr -> expr" << std::endl; 
        }
#line 2322 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 600 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "expr BAR xor_expr -> expr" << std::endl;
        }
#line 2330 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 606 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "and_expr -> xor_expr" << std::endl; }
#line 2338 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 610 "parse.y" /* yacc.c:1646  */
    { std::cout << " xor_expr CIRCUMFLEX and_expr -> xor_expr" << std::endl; }
#line 2344 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 614 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "shift_expr -> and_expr" << std::endl;
        }
#line 2353 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 619 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "and_expr AMPERSAND shift_expr -> and_expr" << std::endl;
        }
#line 2361 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 625 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "arith_expr -> shift_expr" << std::endl;
        }
#line 2370 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 630 "parse.y" /* yacc.c:1646  */
    { std::cout << "shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr -> shift_expr" << std::endl; }
#line 2376 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 638 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "term -> arith_expr" << std::endl;
        }
#line 2385 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 643 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "arith_expr pick_PLUS_MINUS term -> arith_expr" << std::endl;
            if ((yyvsp[-1].tokenId) == PLUS) {
                (yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                pool.add((yyval.node));
            } else if ((yyvsp[-1].tokenId) == MINUS) {
                (yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
        }
#line 2400 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 656 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = PLUS;
            std::cout << "PLUS -> pick_PLUS_MINUS" << std::endl;
        }
#line 2409 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 661 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = MINUS;
            std::cout << "PLUS -> pick_PLUS_MINUS -" << std::endl; }
#line 2417 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 667 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "factor -> term" << std::endl;
        }
#line 2426 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 672 "parse.y" /* yacc.c:1646  */
    {
	  if ((yyvsp[-1].tokenId) == STAR) {
	    (yyval.node) = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          } else if ((yyvsp[-1].tokenId) == SLASH || (yyvsp[-1].tokenId) == DOUBLESLASH) {
	    (yyval.node) = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
	  }
            std::cout << "term pick_multop factor -> term" << std::endl;
        }
#line 2439 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 683 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = STAR;
            std::cout << "pick_multop *" << std::endl;
        }
#line 2448 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 688 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = SLASH;
            std::cout << "pick_multop /" << std::endl;
        }
#line 2457 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 694 "parse.y" /* yacc.c:1646  */
    { 
	     (yyval.tokenId) = DOUBLESLASH;
	     std::cout << " pick_multop **" << std::endl;
         }
#line 2466 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 701 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "pick_unop factor -> factor" << std::endl;
        }
#line 2474 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 705 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "power -> factor" << std::endl; 
        }
#line 2483 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 717 "parse.y" /* yacc.c:1646  */
    {
             //$$ = 
             std::cout << "atom star_trailer DOUBLESTAR factor -> power" << std::endl;
         }
#line 2492 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 722 "parse.y" /* yacc.c:1646  */
    {
            std::cout <<  "atom star_trailer -> power" << std::endl;
        }
#line 2500 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 728 "parse.y" /* yacc.c:1646  */
    {  std::cout << "star_trailer trailer -> star_trailer" << std::endl; }
#line 2506 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 730 "parse.y" /* yacc.c:1646  */
    {  std::cout << " -> star_trailer" << std::endl; }
#line 2512 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 738 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "NAME -> atom" << std::endl;
            (yyval.node) = new IdentNode((yyvsp[0].id));
            deleteName((yyvsp[0].id));
            pool.add((yyval.node));
        }
#line 2523 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 745 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "FLOATNUMBER -> atom" << std::endl;
            (yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
            pool.add((yyval.node));
        }
#line 2533 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 751 "parse.y" /* yacc.c:1646  */
    {
            std::cout << "INTNUMBER -> atom" << std::endl;
            (yyval.node) = new IntLiteral((yyvsp[0].intNumber));
            pool.add((yyval.node));
        }
#line 2543 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 794 "parse.y" /* yacc.c:1646  */
    {
	  std::cout << "DOT NAME -> trailer" << std::endl;  
          deleteName((yyvsp[0].id));
        }
#line 2552 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 834 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            std::cout << "test star_COMMA_test COMMA -> testlist" << std::endl;
        }
#line 2561 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 839 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            std::cout << "test star_COMMA_test -> testlist" << std::endl;
        }
#line 2570 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2574 "parse.tab.c" /* yacc.c:1646  */
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 933 "parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}

void deleteName(char *name) {
  if (name != NULL)
    delete [] name;
    name = NULL;
}

