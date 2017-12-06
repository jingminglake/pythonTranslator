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
        #include "includes/ast.h"
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
        // extern YYSTYPE yylval;
        void deleteName(char *name);
        PoolOfNodes& pool = PoolOfNodes::getInstance();
        bool myDebug = true;
        void printDebugMsg(const char *);
        extern bool cmdlineMode;

#line 81 "parse.tab.c" /* yacc.c:339  */

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
#line 17 "parse.y" /* yacc.c:355  */

   class Node;
   typedef struct YYLTYPE {
     int first_line;
     int first_column;
     int last_line;
     int last_column;
   } YYLTYPE;
   #define YYLTYPE_IS_DECLARED 1

#line 122 "parse.tab.c" /* yacc.c:355  */

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
    EXCEPT = 285,
    EXEC = 286,
    FINALLY = 287,
    FOR = 288,
    FROM = 289,
    GLOBAL = 290,
    GREATER = 291,
    GREATEREQUAL = 292,
    GRLT = 293,
    IF = 294,
    IMPORT = 295,
    IN = 296,
    INDENT = 297,
    IS = 298,
    LAMBDA = 299,
    LBRACE = 300,
    LEFTSHIFT = 301,
    LEFTSHIFTEQUAL = 302,
    LESS = 303,
    LESSEQUAL = 304,
    LPAR = 305,
    LSQB = 306,
    MINEQUAL = 307,
    NEWLINE = 308,
    NOT = 309,
    NOTEQUAL = 310,
    NUMBER = 311,
    MINUS = 312,
    OR = 313,
    PLUS = 314,
    PASS = 315,
    PERCENT = 316,
    PERCENTEQUAL = 317,
    PLUSEQUAL = 318,
    PRINT = 319,
    RAISE = 320,
    RBRACE = 321,
    RETURN = 322,
    RIGHTSHIFT = 323,
    RIGHTSHIFTEQUAL = 324,
    RPAR = 325,
    RSQB = 326,
    SEMI = 327,
    SLASHEQUAL = 328,
    STAREQUAL = 329,
    STAR = 330,
    SLASH = 331,
    STRING = 332,
    TILDE = 333,
    TRY = 334,
    VBAREQUAL = 335,
    WHILE = 336,
    WITH = 337,
    YIELD = 338,
    NAME = 339,
    FLOATNUMBER = 340,
    INTNUMBER = 341,
    TRUE = 342,
    FALSE = 343,
    EQUAL = 344
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 28 "parse.y" /* yacc.c:355  */

  Node* node;
  long long intNumber;
  long double fltNumber;
  char *id;
  int tokenId;
  std::vector<Node*>* nodes;

#line 233 "parse.tab.c" /* yacc.c:355  */
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

#line 262 "parse.tab.c" /* yacc.c:358  */

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
#define YYLAST   1056

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  317
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  481

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   344

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
      85,    86,    87,    88,    89
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    76,   100,   105,   114,   122,   130,   131,
     134,   135,   138,   139,   142,   143,   146,   155,   156,   159,
     160,   163,   164,   167,   168,   171,   175,   178,   182,   188,
     189,   192,   196,   199,   200,   203,   204,   207,   213,   220,
     224,   231,   235,   241,   246,   255,   257,   259,   261,   263,
     265,   267,   271,   328,   345,   350,   379,   386,   396,   404,
     408,   412,   416,   420,   424,   428,   432,   437,   441,   445,
     449,   455,   460,   467,   468,   471,   476,   483,   484,   487,
     488,   491,   494,   498,   500,   502,   504,   506,   510,   513,
     516,   517,   520,   523,   524,   527,   528,   531,   532,   535,
     536,   539,   542,   545,   546,   549,   550,   551,   554,   559,
     565,   569,   572,   573,   576,   577,   580,   581,   584,   588,
     594,   600,   604,   607,   608,   611,   612,   615,   617,   619,
     621,   623,   625,   630,   632,   636,   641,   648,   649,   652,
     656,   662,   663,   666,   667,   670,   671,   674,   675,   678,
     679,   682,   685,   686,   689,   690,   693,   694,   697,   698,
     701,   702,   705,   711,   719,   724,   732,   733,   736,   737,
     740,   741,   744,   745,   748,   752,   756,   760,   766,   771,
     775,   780,   785,   789,   796,   801,   816,   820,   824,   828,
     832,   836,   840,   844,   848,   852,   856,   862,   870,   878,
     882,   890,   895,   903,   908,   921,   923,   927,   932,   945,
     950,   956,   961,   980,   984,   988,   992,   998,  1011,  1018,
    1022,  1026,  1032,  1038,  1052,  1058,  1065,  1070,  1072,  1074,
    1076,  1083,  1089,  1095,  1101,  1107,  1111,  1116,  1122,  1127,
    1134,  1135,  1138,  1139,  1142,  1143,  1146,  1147,  1150,  1154,
    1160,  1161,  1164,  1170,  1175,  1183,  1184,  1187,  1188,  1191,
    1192,  1193,  1196,  1197,  1200,  1201,  1204,  1205,  1208,  1209,
    1212,  1213,  1216,  1221,  1228,  1229,  1232,  1233,  1236,  1237,
    1240,  1241,  1244,  1246,  1250,  1251,  1254,  1257,  1258,  1261,
    1262,  1265,  1266,  1269,  1270,  1271,  1274,  1275,  1278,  1279,
    1282,  1283,  1286,  1287,  1290,  1291,  1294,  1295,  1298,  1299,
    1302,  1303,  1306,  1307,  1310,  1312,  1316,  1317
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
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EXCEPT",
  "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER", "GREATEREQUAL",
  "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA", "LBRACE",
  "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR", "LSQB",
  "MINEQUAL", "NEWLINE", "NOT", "NOTEQUAL", "NUMBER", "MINUS", "OR",
  "PLUS", "PASS", "PERCENT", "PERCENTEQUAL", "PLUSEQUAL", "PRINT", "RAISE",
  "RBRACE", "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL", "RPAR", "RSQB",
  "SEMI", "SLASHEQUAL", "STAREQUAL", "STAR", "SLASH", "STRING", "TILDE",
  "TRY", "VBAREQUAL", "WHILE", "WITH", "YIELD", "NAME", "FLOATNUMBER",
  "INTNUMBER", "TRUE", "FALSE", "EQUAL", "$accept", "start", "file_input",
  "pick_NEWLINE_stmt", "star_NEWLINE_stmt", "decorator", "opt_arglist",
  "decorators", "decorated", "funcdef", "parameters", "varargslist",
  "opt_EQUAL_test", "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME",
  "pick_STAR_DOUBLESTAR", "opt_COMMA", "fpdef", "fplist",
  "star_fpdef_notest", "stmt", "simple_stmt", "star_SEMI_small_stmt",
  "small_stmt", "expr_stmt", "pick_yield_expr_testlist", "star_EQUAL",
  "star_EQUAL_R", "augassign", "print_stmt", "star_COMMA_test", "opt_test",
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344
};
# endif

#define YYPACT_NINF -389

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-389)))

#define YYTABLE_NINF -264

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -389,    43,  -389,   419,  -389,   878,   -28,   878,  -389,   -25,
    -389,   -23,   948,  -389,   948,   948,  -389,     0,   878,   -28,
      60,   878,   263,   878,  -389,    77,  -389,  -389,  -389,   770,
     878,   878,  -389,  -389,   117,   878,   878,   878,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,   101,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,     7,    96,  -389,  1001,   106,   139,
     148,    -1,    45,    36,  -389,   948,  -389,  -389,    76,  -389,
      25,  -389,  -389,   140,  -389,    28,  -389,   108,    18,   110,
     106,  -389,    29,   118,   126,    11,  -389,   143,  -389,   151,
      48,   878,   153,     5,    49,   103,  -389,   137,  -389,   111,
    -389,  -389,   138,   104,  -389,  -389,   878,  -389,  -389,   156,
    -389,   665,   158,  -389,   170,  -389,  -389,  -389,  -389,    -9,
     162,    77,    77,  -389,    77,  -389,  -389,  -389,  -389,  -389,
     125,  -389,  -389,   142,  -389,   948,   948,   948,   948,  -389,
    -389,   948,  -389,  -389,   948,  -389,  -389,  -389,  -389,   948,
    -389,    89,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,   263,  -389,  -389,   263,   878,
     112,   122,  -389,  -389,   878,   665,   878,   128,   165,   171,
     878,   878,   -13,   161,   167,   177,   665,   -28,   119,  -389,
     878,   124,   -10,   127,  -389,  -389,   113,   878,   948,   191,
    -389,  -389,  -389,   191,  -389,  -389,   948,   191,  -389,  -389,
     199,   191,   878,  -389,   174,  -389,   105,   665,   130,   948,
    -389,   724,   878,    15,    96,  -389,  -389,  -389,   106,   139,
     148,    -1,    45,    36,  -389,   133,   948,   122,   816,  -389,
     131,  -389,  -389,  -389,  -389,  -389,   149,  -389,   200,  -389,
    -389,  -389,   155,  -389,   159,   665,   948,   205,   211,   152,
    -389,   226,  -389,  -389,  -389,   154,  -389,  -389,  -389,  -389,
    -389,  -389,   169,   224,   878,   225,   137,   201,   878,  -389,
    -389,   202,  -389,   878,   231,  -389,  -389,   205,   583,   878,
     233,    73,   234,   228,   665,   878,   106,  -389,  -389,  -389,
     878,  -389,  -389,   182,   235,   243,   189,  -389,   246,  -389,
     209,   878,   878,     2,  -389,   249,   251,  -389,  -389,   106,
     878,  -389,   665,   197,   185,   254,  -389,   123,   255,  -389,
     252,  -389,  -389,    26,  -389,   264,  -389,  -389,    77,   924,
    -389,   878,  -389,  -389,  -389,   501,   102,   665,   266,   247,
     267,   665,   268,  -389,  -389,  -389,  -389,   269,  -389,   275,
     878,  -389,  -389,  -389,   878,  -389,  -389,   222,  -389,   665,
    -389,   270,  -389,  -389,   152,   878,   279,   -10,   212,   878,
    -389,    27,   280,    86,   284,  -389,   244,  -389,  -389,  -389,
    -389,  -389,   878,  -389,  -389,   665,   286,  -389,   665,  -389,
     665,  -389,   315,  -389,   296,   300,  -389,  -389,   297,  -389,
     303,   665,  -389,  -389,   304,   924,  -389,  -389,  -389,   924,
     306,   924,  -389,  -389,  -389,   924,   307,  -389,  -389,   665,
    -389,  -389,  -389,   878,  -389,  -389,   862,  -389,   665,   665,
    -389,   878,   109,  -389,   924,    86,  -389,   924,  -389,  -389,
    -389,   878,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,     0,     0,     0,    88,     0,
      89,     0,     0,     3,     0,     0,   317,     0,     0,     0,
      24,   243,   239,   241,     4,     0,   220,   219,    82,    76,
      94,    91,   245,   221,     0,     0,     0,   315,   230,   231,
     232,   233,   234,     6,    13,     0,   134,   132,     5,    37,
      42,    43,    44,    45,    46,    47,    83,    84,    85,    87,
      86,    48,    99,   100,    49,    50,    51,    38,   127,   128,
     129,   130,   131,    74,   177,   178,   180,   183,   184,   197,
     199,   201,   203,   207,   211,     0,   218,   225,   235,   175,
      58,   133,    92,   126,   118,     0,   312,     0,     0,     0,
     271,    81,   124,     0,     0,     0,   122,     0,   116,   101,
     111,     0,     0,     0,    74,     0,   242,    74,   238,     0,
     237,   236,    74,     0,   240,   182,     0,    71,    74,    98,
      90,     0,     0,   153,   155,   314,    12,    15,    14,     0,
     273,     0,     0,   174,     0,   188,   187,   189,   191,   193,
     195,   186,   190,     0,   192,     0,     0,     0,     0,   205,
     206,     0,   210,   209,     0,   216,   215,   213,   214,     0,
     217,   223,   244,    64,    66,    70,    69,    67,    60,    63,
      59,    68,    62,    61,    65,     0,    53,    56,     0,     0,
       0,   288,     9,   229,     0,     0,   285,    24,     0,   269,
       0,     0,     0,   316,   103,   120,     0,     0,     0,   251,
       0,     0,     0,     0,    31,    19,    22,     0,     0,    30,
     275,   280,   228,    30,   248,   226,     0,    30,   246,   227,
      80,    30,     0,    93,     0,   162,     0,     0,     0,     0,
      40,     0,   272,     0,   179,   181,   196,   194,   185,   198,
     200,   202,   204,   208,   212,     0,     0,   288,   263,   224,
      58,    55,    54,    52,   125,   119,     0,    10,     0,   313,
     283,   284,     0,    18,     0,     0,   268,    96,     0,     0,
     105,   109,   102,   115,   107,     0,   138,   117,   110,   250,
      28,    36,     0,    26,     0,    30,   277,     0,    29,   281,
     249,     0,   247,     0,    30,    72,    75,    96,     0,   157,
       0,   148,     0,   140,     0,     0,   154,    39,    41,    73,
       0,   254,   222,     0,     0,   260,     0,   258,     0,    57,
       0,     0,     0,   299,   286,    30,     0,    17,    16,   270,
       0,   123,     0,     0,     0,   113,   121,   136,    34,    32,
       0,    27,    21,    23,    20,    30,   274,   278,     0,     0,
      78,    29,    79,    97,   165,     0,   161,     0,     0,   150,
       0,     0,     0,   151,   152,   176,   252,     0,   253,   256,
     263,     8,   295,   290,     0,   296,   298,   287,   293,     0,
      95,   142,   106,   108,   112,     0,     0,    33,     0,    29,
     279,   309,    24,   303,   167,   171,   170,    77,   163,   164,
     158,   159,     0,   156,   144,     0,     0,   143,     0,   146,
       0,   259,   255,   262,   265,   292,   297,   282,     0,   114,
       0,     0,    35,    25,     0,     0,   308,   306,   307,     0,
       0,     0,   302,   300,   301,     0,    30,   160,   147,     0,
     145,   139,   257,   267,   261,   264,     0,   294,     0,     0,
     135,     0,   311,   173,     0,   305,   169,    29,   166,   149,
     266,     0,   289,   141,   137,   276,   310,   172,   304,   168,
     291
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -389,  -389,  -389,  -389,  -389,   287,    68,  -389,  -389,   288,
    -389,  -189,  -389,  -389,  -389,  -389,  -212,  -198,  -389,  -389,
    -272,    -2,  -389,    88,  -389,   146,  -389,    78,  -389,  -389,
      16,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,    30,  -389,  -389,  -389,  -389,  -389,  -389,   -55,
     135,    64,  -389,  -389,    21,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
      37,    33,  -389,  -389,  -185,  -389,  -389,  -389,  -388,  -389,
      -5,  -389,  -136,   203,    -3,  -389,  -389,    -8,   198,   196,
     204,  -389,   194,  -389,   193,  -389,   -62,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,   -64,   -19,  -389,  -389,   -12,  -389,   -11,  -389,
    -389,  -389,  -389,   319,  -389,  -389,  -389,  -389,  -389,  -389,
     -89,  -389,   -97,   248,  -389,   -91,  -105,  -389,  -389,    12,
    -389
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    43,     3,    44,   266,    45,    46,    47,
     198,   112,   295,   113,   351,   215,   299,   216,   292,   348,
      48,   235,   139,    50,    51,   260,   186,   187,   188,    52,
     140,   127,   304,   305,    53,    54,    55,    56,    57,    58,
      59,    60,   341,   233,    61,    62,    63,   104,   282,   283,
     108,   284,   345,   109,   110,    64,   205,    65,    66,    67,
      68,   347,    69,    70,    71,   311,   369,   417,    72,   238,
     133,   312,   412,   413,   236,   365,   403,   446,   404,   405,
      73,   143,    74,    75,    76,    77,   155,    78,    79,    80,
      81,   161,    82,   164,    83,   169,    84,    85,    86,   171,
      87,   118,   119,   123,   115,    88,   124,   120,    89,   259,
     326,   379,   327,   328,   454,   455,   101,   199,    90,   116,
     355,   356,   220,    91,   272,   267,   268,   425,   457,   334,
     335,   385,   442,   443,   444,   436,   437,   438,    97,    92,
     105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    49,    96,   103,   100,   243,   102,   100,   274,   221,
     270,   300,   224,   107,   291,   302,   114,   117,   122,   306,
     130,   286,   125,   170,   128,   129,   135,    95,   173,   211,
     132,   134,   203,   195,   121,   218,   364,   279,   174,   156,
     212,   -29,   320,     4,   240,   159,   141,   462,   175,   190,
     176,   463,   313,   465,   208,   212,    94,   466,   165,    98,
     218,    99,   280,   241,   217,   142,   435,   160,   196,   190,
     200,   281,   177,   142,   214,   111,   477,   178,   191,   479,
     213,   192,   218,   354,   106,   142,     7,   179,   180,   214,
     338,   384,   362,   409,   181,    94,   -29,   166,   182,   183,
     368,   144,   162,   309,   163,   184,   209,   254,   410,     6,
     255,   167,   168,   256,   185,     9,   156,   193,   411,   226,
      11,   230,    21,   388,   194,   441,   204,    22,    23,   373,
     219,    25,   131,   223,    26,   309,    27,   310,   227,   257,
     258,   245,   218,   400,   231,   314,   315,   248,   435,   395,
     396,   157,   158,   172,    32,    33,   189,   391,   206,   201,
     197,    38,    39,    40,    41,    42,   202,   207,   210,   222,
     218,   226,   232,   237,   261,   229,   239,   261,   242,   246,
     275,   225,   414,   247,   264,   271,   419,   276,   190,   269,
     278,   357,   -11,   285,   322,   277,   265,   262,   273,   432,
     262,  -104,   294,   288,   427,   289,   297,   298,   290,     7,
     100,   293,   296,   440,   301,   303,   308,   321,   100,   330,
     185,   340,   401,   406,   331,   336,   342,   307,   386,   337,
     448,   316,   344,   450,   468,   451,   281,   319,   346,   349,
     350,   353,   358,   359,    20,    21,   460,   361,   367,   371,
      22,    23,   376,   325,    25,   372,   377,    26,  -262,    27,
     378,   380,   381,   333,   469,   387,   389,   392,   339,   393,
     394,   397,     7,   473,   474,   332,   398,    32,    33,   416,
     399,   415,   418,   420,    38,    39,    40,    41,    42,   352,
     421,   422,   -29,   319,   431,   439,   433,   428,   360,   406,
     445,   449,   142,   406,   366,   406,    49,    20,    21,   406,
     134,   453,   458,    22,    23,   375,   456,    25,   459,   461,
      26,   464,    27,   467,     7,   323,   382,   383,   406,   318,
    -263,   406,   136,   137,   263,   390,   324,   363,   329,   429,
      32,    33,   287,   343,   370,   244,    37,    38,    39,    40,
      41,    42,   374,   250,   249,   252,   407,   253,   452,    20,
      21,   424,   251,    49,   138,    22,    23,   472,   478,    25,
     228,   476,    26,     0,    27,   423,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,     0,    32,    33,   434,     0,     0,     0,     0,    38,
      39,    40,    41,    42,     0,     0,     0,   447,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     0,
       8,     0,     0,     9,     0,     0,    10,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,    13,   470,     0,
      14,   333,    15,    16,    17,     0,   475,     0,    18,    19,
       0,     0,     0,    20,    21,     0,   480,     0,     0,    22,
      23,     0,    24,    25,     0,     0,    26,     0,    27,    28,
       0,     0,     0,    29,    30,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,     5,     6,
       7,     0,     8,     0,     0,     9,     0,     0,    10,   408,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,    15,    16,    17,     0,     0,     0,
      18,    19,     0,     0,     0,    20,    21,     0,     0,     0,
       0,    22,    23,     0,     0,    25,     0,     0,    26,     0,
      27,    28,     0,     0,     0,    29,    30,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
       5,     6,     7,     0,     8,     0,     0,     9,     0,     0,
      10,     0,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,    15,    16,    17,     0,
       0,     0,    18,    19,     0,     0,     0,    20,    21,     0,
       0,     0,     0,    22,    23,     0,     0,    25,     0,     0,
      26,     0,    27,    28,     0,     0,     0,    29,    30,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,     5,     0,     7,     0,     8,     0,     0,     0,
       0,     0,    10,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    16,
      17,     0,     0,     0,     0,    19,     0,     0,     0,    20,
      21,     0,     0,     0,     0,    22,    23,     0,   234,    25,
       0,     0,    26,     0,    27,    28,     0,     0,     0,    29,
      30,     5,    31,     7,     0,     8,     0,     0,     0,     0,
       0,    10,    32,    33,    12,     0,     0,     0,    37,    38,
      39,    40,    41,    42,     0,    14,     0,     0,    16,    17,
       0,     0,     0,     0,    19,     0,     0,     0,    20,    21,
       0,     0,     0,     0,    22,    23,     0,   317,    25,     7,
       0,    26,     0,    27,    28,     0,     0,     0,    29,    30,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,     0,     0,    37,    38,    39,
      40,    41,    42,     0,    20,    21,     0,     0,     0,     0,
      22,    23,     0,     0,    25,     7,     0,    26,     0,    27,
       0,     0,     0,     0,     0,     0,     0,   324,   126,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,     0,
      20,    21,     0,     0,     0,     0,    22,    23,     0,     0,
      25,     7,     0,    26,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,     7,     0,     0,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,     0,    20,    21,     0,     0,
       0,     0,    22,    23,     0,     0,    25,     0,     0,    26,
       0,    27,    20,    21,     0,     0,     0,     0,    22,    23,
       0,     0,    25,     7,     0,    26,     0,    27,     0,    32,
      33,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,     0,    32,    33,     7,     0,     0,
       0,     0,    38,    39,    40,    41,    42,     0,   402,    21,
       0,     0,     0,     0,    22,    23,     0,     0,    25,     0,
       0,    26,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,    22,    23,
       0,    32,    33,     0,     0,    26,     0,    27,    38,    39,
      40,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,     0,
     145,     0,    38,    39,    40,    41,    42,   146,   147,   148,
       0,     0,   149,     0,   150,     0,     0,     0,     0,   151,
     152,     0,     0,     0,     0,   153,   154
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,    15,    12,   141,    14,    15,   197,   114,
     195,   223,   117,    18,   212,   227,    21,    22,    23,   231,
      31,   206,    25,    85,    29,    30,    37,     6,     3,    24,
      35,    36,    21,    15,    22,    33,   308,    50,    13,    10,
      50,    15,    27,     0,    53,    46,    39,   435,    23,    21,
      25,   439,   237,   441,     6,    50,    84,   445,    22,    84,
      33,    84,    75,    72,    15,    58,    39,    68,    50,    21,
      41,    84,    47,    58,    84,    15,   464,    52,    50,   467,
      75,    53,    33,   295,    84,    58,     9,    62,    63,    84,
     275,    89,   304,   365,    69,    84,    70,    61,    73,    74,
      27,     5,    57,    30,    59,    80,   111,   169,     6,     8,
      21,    75,    76,    24,    89,    14,    10,     9,    16,    33,
      19,   126,    45,   335,    16,    39,   105,    50,    51,   314,
     114,    54,    15,   117,    57,    30,    59,    32,   122,    50,
      51,   144,    33,   355,   128,    15,    16,   155,    39,    26,
      27,    12,     4,    77,    77,    78,    16,   342,    15,    41,
      50,    84,    85,    86,    87,    88,    40,    16,    15,    66,
      33,    33,    16,    15,   185,    71,     6,   188,    16,    54,
      15,    70,   367,    41,   189,   196,   371,    16,    21,   194,
     201,   296,    70,    16,   256,   200,    84,   185,    70,   397,
     188,    40,    89,    84,   389,   210,   218,    16,    84,     9,
     218,    84,   217,   402,   226,    16,    42,    84,   226,    70,
      89,    16,   358,   359,    24,    70,    15,   232,   333,    70,
     415,   239,     6,   418,   446,   420,    84,   242,    84,    70,
      16,    16,    41,    41,    44,    45,   431,    16,    15,    15,
      50,    51,    70,   258,    54,    27,    21,    57,    15,    59,
      71,    15,    53,   268,   449,    16,    15,    70,   276,    84,
      16,    16,     9,   458,   459,    75,    24,    77,    78,    32,
      16,    15,    15,    15,    84,    85,    86,    87,    88,   294,
      21,    16,    70,   298,    15,    15,    84,    27,   303,   435,
      16,    15,    58,   439,   309,   441,   308,    44,    45,   445,
     315,    15,    15,    50,    51,   320,    16,    54,    15,    15,
      57,    15,    59,    16,     9,   257,   331,   332,   464,   241,
      15,   467,    45,    45,   188,   340,    21,   307,   260,   394,
      77,    78,   207,   279,   311,   142,    83,    84,    85,    86,
      87,    88,   315,   157,   156,   161,   361,   164,   422,    44,
      45,   380,   158,   365,    45,    50,    51,   456,   465,    54,
     122,   462,    57,    -1,    59,   380,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     395,    -1,    77,    78,   399,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    -1,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    -1,    17,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,   453,    -1,
      31,   456,    33,    34,    35,    -1,   461,    -1,    39,    40,
      -1,    -1,    -1,    44,    45,    -1,   471,    -1,    -1,    50,
      51,    -1,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      -1,    -1,    -1,    64,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    -1,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    -1,
      17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    60,    -1,    -1,    -1,    64,    65,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,     7,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,     7,    67,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    77,    78,    20,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    51,    -1,    53,    54,     9,
      -1,    57,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,     9,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,     9,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     9,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    54,    -1,    -1,    57,
      -1,    59,    44,    45,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,     9,    -1,    57,    -1,    59,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    77,    78,     9,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      -1,    77,    78,    -1,    -1,    57,    -1,    59,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,
      29,    -1,    84,    85,    86,    87,    88,    36,    37,    38,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    91,    92,    94,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    28,    31,    33,    34,    35,    39,    40,
      44,    45,    50,    51,    53,    54,    57,    59,    60,    64,
      65,    67,    77,    78,    79,    81,    82,    83,    84,    85,
      86,    87,    88,    93,    95,    97,    98,    99,   110,   111,
     113,   114,   119,   124,   125,   126,   127,   128,   129,   130,
     131,   134,   135,   136,   145,   147,   148,   149,   150,   152,
     153,   154,   158,   170,   172,   173,   174,   175,   177,   178,
     179,   180,   182,   184,   186,   187,   188,   190,   195,   198,
     208,   213,   229,   170,    84,   144,   170,   228,    84,    84,
     177,   206,   177,   206,   137,   230,    84,   170,   140,   143,
     144,    15,   101,   103,   170,   194,   209,   170,   191,   192,
     197,   229,   170,   193,   196,   174,    68,   121,   170,   170,
     208,    15,   170,   160,   170,   208,    95,    99,   213,   112,
     120,    39,    58,   171,     5,    29,    36,    37,    38,    41,
      43,    48,    49,    54,    55,   176,    10,    12,     4,    46,
      68,   181,    57,    59,   183,    22,    61,    75,    76,   185,
     186,   189,    77,     3,    13,    23,    25,    47,    52,    62,
      63,    69,    73,    74,    80,    89,   116,   117,   118,    16,
      21,    50,    53,     9,    16,    15,    50,    50,   100,   207,
      41,    41,    40,    21,   144,   146,    15,    16,     6,   170,
      15,    24,    50,    75,    84,   105,   107,    15,    33,   120,
     212,   226,    66,   120,   226,    70,    33,   120,   223,    71,
     170,   120,    16,   133,    53,   111,   164,    15,   159,     6,
      53,    72,    16,   172,   173,   174,    54,    41,   177,   178,
     179,   180,   182,   184,   186,    21,    24,    50,    51,   199,
     115,   208,   229,   115,   170,    84,    96,   215,   216,   170,
     164,   208,   214,    70,   101,    15,    16,   170,   208,    50,
      75,    84,   138,   139,   141,    16,   164,   140,    84,   170,
      84,   107,   108,    84,    89,   102,   170,   206,    16,   106,
     106,   206,   106,    16,   122,   123,   106,   170,    42,    30,
      32,   155,   161,   164,    15,    16,   177,    53,   113,   170,
      27,    84,   186,    96,    21,   170,   200,   202,   203,   117,
      70,    24,    75,   170,   219,   220,    70,    70,   164,   177,
      16,   132,    15,   141,     6,   142,    84,   151,   109,    70,
      16,   104,   170,    16,   106,   210,   211,   226,    41,    41,
     170,    16,   106,   132,   110,   165,   170,    15,    27,   156,
     161,    15,    27,   164,   160,   170,    70,    21,    71,   201,
      15,    53,   170,   170,    89,   221,   226,    16,   106,    15,
     170,   164,    70,    84,    16,    26,    27,    16,    24,    16,
     106,   172,    44,   166,   168,   169,   172,   170,    18,   110,
       6,    16,   162,   163,   164,    15,    32,   157,    15,   164,
      15,    21,    16,   170,   203,   217,   170,   164,    27,   139,
     170,    15,   107,    84,   170,    39,   225,   226,   227,    15,
     101,    39,   222,   223,   224,    16,   167,   170,   164,    15,
     164,   164,   202,    15,   204,   205,    16,   218,    15,    15,
     164,    15,   168,   168,    15,   168,   168,    16,   106,   164,
     170,    24,   220,   164,   164,   170,   225,   168,   222,   168,
     170
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   125,   126,   126,   126,   126,   126,   127,   128,
     129,   129,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   136,   137,   137,   138,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   149,
     149,   149,   149,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   157,
     157,   158,   159,   159,   160,   160,   161,   161,   162,   162,
     163,   163,   164,   164,   165,   165,   166,   166,   167,   167,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     183,   184,   184,   185,   185,   185,   185,   186,   186,   187,
     187,   187,   188,   188,   189,   189,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   197,
     198,   198,   199,   199,   199,   200,   200,   201,   201,   202,
     202,   202,   203,   203,   204,   204,   205,   205,   206,   206,
     207,   207,   208,   208,   209,   209,   210,   210,   211,   211,
     212,   212,   213,   213,   214,   214,   215,   216,   216,   217,
     217,   218,   218,   219,   219,   219,   220,   220,   221,   221,
     222,   222,   223,   223,   224,   224,   225,   225,   226,   226,
     227,   227,   228,   228,   229,   229,   230,   230
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     5,     3,     2,     2,
       4,     2,     0,     4,     0,     3,     0,     3,     2,     1,
       0,     1,     3,     3,     2,     3,     0,     1,     1,     4,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     0,     3,     0,     3,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     2,     0,     3,     0,     1,
       1,     2,     4,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     3,     0,     1,     3,     1,     3,
       3,     3,     0,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     5,     5,     0,     7,
       4,     9,     6,     6,     6,     4,     3,     3,     0,     3,
       0,     5,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     4,     2,     1,     3,     1,     3,     2,
       1,     1,     4,     3,     2,     1,     4,     0,     1,     3,
       1,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     4,     2,     2,     0,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     1,     0,     2,     1,     2,     3,     2,     3,
       4,     3,     3,     3,     2,     3,     2,     3,     0,     3,
       1,     4,     1,     0,     1,     0,     2,     1,     3,     2,
       3,     0,     3,     2,     4,     2,     5,     0,     1,     2,
       1,     2,     7,     4,     1,     0,     2,     3,     0,     3,
       0,     3,     0,     2,     4,     2,     2,     3,     1,     0,
       1,     1,     5,     4,     3,     2,     1,     1,     5,     4,
       3,     2,     1,     3,     2,     1,     2,     0
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
#line 70 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("file_input -> start");
        }
#line 1960 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].nodes)) {
                auto it = (yyvsp[-1].nodes)->begin();
                while (it != (yyvsp[-1].nodes)->end()) {
                    if ((*it)) {
                      try {
                        (*it)->eval();
                      } catch (const std::string& msg) {
                          std::cout << msg << std::endl;
                      } catch (const char* msg) {
                          std::cout << msg << std::endl;
                      } catch (...) {
                          std::cout << "opps, something wrong happened!" << std::endl;
                      }
                    }
                    ++it;
                }
            }
            delete (yyvsp[-1].nodes);
            printDebugMsg("star_NEWLINE_stmt ENDMARKER -> file_input");
        }
#line 1986 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
            printDebugMsg("NEWLINE -> pick_NEWLINE_stmt");
        }
#line 1995 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 106 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            if (cmdlineMode && (yyval.node))
                (yyval.node)->eval();
            printDebugMsg("stmt -> pick_NEWLINE_stmt");
        }
#line 2006 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "parse.y" /* yacc.c:1646  */
    {
            (yyval.nodes) = (yyvsp[-1].nodes);
            if ((yyvsp[0].node)) {
                (yyval.nodes)->push_back((yyvsp[0].node));
            }
            printDebugMsg("star_NEWLINE_stmt pick_NEWLINE_stmt -> star_NEWLINE_stmt");
        }
#line 2018 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 123 "parse.y" /* yacc.c:1646  */
    {
            (yyval.nodes) = new std::vector<Node*>();
            (yyval.nodes)->reserve(8);
            printDebugMsg(" -> star_NEWLINE_stmt");
        }
#line 2028 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = new FuncDefNode((yyvsp[-3].id), (yyvsp[0].node));
          pool.add((yyval.node));
          deleteName((yyvsp[-3].id));
          printDebugMsg("DEF NAME parameters COLON suite -> funcdef");
        }
#line 2039 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 172 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2047 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 179 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[-1].id));
        }
#line 2055 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 183 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2063 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 193 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2071 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 208 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
	     //($$)->eval()->print();
             printDebugMsg("simple_stmt -> stmt");
         }
#line 2081 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 214 "parse.y" /* yacc.c:1646  */
    {
	     (yyval.node) = (yyvsp[0].node);
             printDebugMsg("compound_stmt -> stmt");
         }
#line 2090 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 221 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[-3].node);
             printDebugMsg("small_stmt star_SEMI_small_stmt SEMI NEWLINE -> simple_stmt");          }
#line 2098 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 225 "parse.y" /* yacc.c:1646  */
    {
	     (yyval.node) = (yyvsp[-2].node);
             printDebugMsg("small_stmt star_SEMI_small_stmt NEWLINE  -> simple_stmt");
         }
#line 2107 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 232 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("star_SEMI_small_stmt SEMI small_stmt -> star_SEMI_small_stmt");
        }
#line 2115 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg(" -> star_SEMI_small_stmt"); 
        }
#line 2123 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 242 "parse.y" /* yacc.c:1646  */
    {
           (yyval.node) = (yyvsp[0].node);
           printDebugMsg("expr_stmt -> small_stmt"); 
        }
#line 2132 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 247 "parse.y" /* yacc.c:1646  */
    {
	   printDebugMsg("---------print_stmt---------");
           // if (($$)->eval())
	   //  ($$)->eval()->printStmt();
           (yyval.node) = new PrintNode((yyvsp[0].node));
           pool.add((yyval.node));
	   printDebugMsg("---------print_stmt---------");
        }
#line 2145 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 256 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2151 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 258 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2157 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 260 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2163 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 262 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2169 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 264 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2175 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 266 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2181 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 268 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2187 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 272 "parse.y" /* yacc.c:1646  */
    {
            switch((yyvsp[-1].tokenId)) {
              case PLUSEQUAL:
		  (yyval.node) = new PlusAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case MINEQUAL:
		  (yyval.node) = new MinAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case STAREQUAL:
		  (yyval.node) = new StarAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case SLASHEQUAL:
                  (yyval.node) = new SlashAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case DOUBLESLASHEQUAL:
                  (yyval.node) = new DoubleSlashAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case DOUBLESTAREQUAL:
                  (yyval.node) = new DoubleStarAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case PERCENTEQUAL:
                  (yyval.node) = new PercentAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case LEFTSHIFTEQUAL:
                  (yyval.node) = new LShiftAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case RIGHTSHIFTEQUAL:
                  (yyval.node) = new RShiftAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case AMPEREQUAL:
                  (yyval.node) = new AmperAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case VBAREQUAL:
                  (yyval.node) = new VBarAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
              case CIRCUMFLEXEQUAL:
                  (yyval.node) = new CircumflexAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                  pool.add((yyval.node));
                  break;
            }
            /*if ($3 == nullptr) {
	      $$ = $1;
              }*/
            printDebugMsg("testlist augassign pick_yield_expr_testlist -> expr_stmt");
        }
#line 2248 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 329 "parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0].node) == nullptr) {
	      (yyval.node) = (yyvsp[-1].node);
              printDebugMsg("---------testlist star_EQUAL---------");
              //if (($$)->eval())
	      //  ($$)->eval()->print();
	      printDebugMsg("---------testlist star_EQUAL---------");
            }
            else {
              (yyval.node) = new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node)); 
              pool.add((yyval.node));
	    }
            printDebugMsg("testlist star_EQUAL -> expr_stmt");
        }
#line 2267 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 346 "parse.y" /* yacc.c:1646  */
    {
	    (yyval.node) = nullptr;
            printDebugMsg("yield_expr -> pick_yield_expr_testlist");
        }
#line 2276 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 351 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("testlist -> pick_yield_expr_testlist");
        }
#line 2285 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 380 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("star_EQUAL_R -> star_EQUAL");
        }
#line 2294 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 387 "parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0].node) == nullptr) {
                (yyval.node) = (yyvsp[-1].node);
            } else {
                (yyval.node) = new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
            printDebugMsg("EQUAL pick_yield_expr_testlist star_EQUAL_R -> star_EQUAL");
        }
#line 2308 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 397 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
            printDebugMsg(" -> star_EQUAL_R");
        }
#line 2317 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 405 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = PLUSEQUAL;
        }
#line 2325 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 409 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = MINEQUAL;
        }
#line 2333 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 413 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = STAREQUAL;
        }
#line 2341 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 417 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = SLASHEQUAL;
        }
#line 2349 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 421 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = PERCENTEQUAL;
        }
#line 2357 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 425 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = AMPEREQUAL;
        }
#line 2365 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 429 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = VBAREQUAL;
        }
#line 2373 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 433 "parse.y" /* yacc.c:1646  */
    {
           // ^|
           (yyval.tokenId) = CIRCUMFLEXEQUAL;
        }
#line 2382 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 438 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = LEFTSHIFTEQUAL;
        }
#line 2390 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 442 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = RIGHTSHIFTEQUAL;
        }
#line 2398 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 446 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = DOUBLESTAREQUAL;
        }
#line 2406 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 450 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = DOUBLESLASHEQUAL;
        }
#line 2414 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 456 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = (yyvsp[0].node);
	  printDebugMsg("PRINT opt_test -> print_stmt"); 
        }
#line 2423 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 461 "parse.y" /* yacc.c:1646  */
    {
	  (yyval.node) = (yyvsp[-1].node);
          printDebugMsg("PRINT RIGHTSHIFT test opt_test_2 -> print_stmt");
        }
#line 2432 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 472 "parse.y" /* yacc.c:1646  */
    {
	  printDebugMsg("test star_COMMA_test opt_COMMA -> opt_test");
	  (yyval.node) = (yyvsp[-2].node);
        }
#line 2441 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 477 "parse.y" /* yacc.c:1646  */
    {
	  printDebugMsg(" -> opt_test");
	  (yyval.node) = nullptr;
        }
#line 2450 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 495 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2456 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 499 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2462 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 501 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2468 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 503 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2474 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 505 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2480 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 507 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2486 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 555 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[-2].id));
          deleteName((yyvsp[0].id));
        }
#line 2495 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 560 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2503 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 566 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2511 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 585 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2519 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 589 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2527 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 595 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[-1].id));
        }
#line 2535 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 601 "parse.y" /* yacc.c:1646  */
    {
          deleteName((yyvsp[0].id));
        }
#line 2543 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 616 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2549 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 618 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2555 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 620 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2561 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 622 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2567 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 624 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2573 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 626 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("funcdef -> compound_stmt");
            (yyval.node) = (yyvsp[0].node);
          }
#line 2582 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 631 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2588 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 633 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2594 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 637 "parse.y" /* yacc.c:1646  */
    {
            //$$ = new IfNode($2, $4, $8);
            //pool.add($$);
          }
#line 2603 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 642 "parse.y" /* yacc.c:1646  */
    {
            //$$ = new IfNode($2, $4, nullptr);
            //pool.add($$);
          }
#line 2612 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 653 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = nullptr;
        }
#line 2620 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 657 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = nullptr;
        }
#line 2628 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 706 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new SuiteNode((yyvsp[0].node));
            pool.add((yyval.node));
            printDebugMsg("simple_stmt -> suite");
        }
#line 2638 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 712 "parse.y" /* yacc.c:1646  */
    {
          printDebugMsg("NEWLINE INDENT plus_stmt DEDENT -> suite");
          (yyval.node) = new SuiteNode((yyvsp[-1].node));
          pool.add((yyval.node));
        }
#line 2648 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 720 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = (yyvsp[-1].node);
          static_cast<PlusStmtNode*>((yyval.node))->insertStmt((yyvsp[0].node));
        }
#line 2657 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 725 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node) = new PlusStmtNode();
          pool.add((yyval.node));
          static_cast<PlusStmtNode*>((yyval.node))->insertStmt((yyvsp[0].node));
        }
#line 2667 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 749 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            printDebugMsg("or_test opt_IF_ELSE -> test"); }
#line 2675 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 753 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;}
#line 2681 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 757 "parse.y" /* yacc.c:1646  */
    {
          printDebugMsg("IF or_test ELSE test -> opt_IF_ELSE");
        }
#line 2689 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 761 "parse.y" /* yacc.c:1646  */
    {
          printDebugMsg(" -> opt_IF_ELSE");
        }
#line 2697 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 767 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
             printDebugMsg("and_test -> or_test");
         }
#line 2706 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 772 "parse.y" /* yacc.c:1646  */
    { printDebugMsg("or_test OR and_test -> or_test"); }
#line 2712 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 776 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
             printDebugMsg("not_test -> and_test");
         }
#line 2721 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 781 "parse.y" /* yacc.c:1646  */
    {
           printDebugMsg("and_test AND not_test  -> and_test"); }
#line 2728 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 786 "parse.y" /* yacc.c:1646  */
    {
             printDebugMsg("NOT not_test -> not_test");
         }
#line 2736 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 790 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);   
            printDebugMsg("comparison -> not_test"); 
         }
#line 2745 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 797 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = (yyvsp[0].node);
             printDebugMsg("expr -> comparison");
         }
#line 2754 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 802 "parse.y" /* yacc.c:1646  */
    { 
	   switch((yyvsp[-1].tokenId)) {
	     case LESS:
               //$$ = new Node($1, $3);
               break;
  	     case GREATER:
               break;
	     case EQEQUAL:
	       break;
           }
           printDebugMsg("comp_op expr -> comparison"); 
         }
#line 2771 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 817 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = LESS; 
        }
#line 2779 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 821 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = GREATER; 
        }
#line 2787 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 825 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = EQEQUAL; 
        }
#line 2795 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 829 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = GREATEREQUAL; 
        }
#line 2803 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 833 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = LESSEQUAL; 
        }
#line 2811 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 837 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = GRLT; 
        }
#line 2819 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 841 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = NOTEQUAL; 
        }
#line 2827 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 845 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = IN; 
        }
#line 2835 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 849 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = NOT + IN; 
        }
#line 2843 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 853 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = IS; 
        }
#line 2851 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 857 "parse.y" /* yacc.c:1646  */
    {
           (yyval.tokenId) = IS + NOT; 
        }
#line 2859 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 863 "parse.y" /* yacc.c:1646  */
    {
	    //std::cout << "---------print----1-----" << std::endl;
	    //($$)->eval()->print();
	    //std::cout << "---------print----1-----" << std::endl;
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("xor_expr -> expr"); 
        }
#line 2871 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 871 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new BarBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
            printDebugMsg("expr BAR xor_expr -> expr");
        }
#line 2881 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 879 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("and_expr -> xor_expr"); }
#line 2889 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 883 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) =  new CircumflexBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
            pool.add((yyval.node));
            printDebugMsg(" xor_expr CIRCUMFLEX and_expr -> xor_expr"); 
        }
#line 2899 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 891 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("shift_expr -> and_expr");
        }
#line 2908 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 896 "parse.y" /* yacc.c:1646  */
    {
	    (yyval.node) = new AmpersandBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
            printDebugMsg("and_expr AMPERSAND shift_expr -> and_expr");
        }
#line 2918 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 904 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("arith_expr -> shift_expr");
        }
#line 2927 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 909 "parse.y" /* yacc.c:1646  */
    { 
            if ((yyvsp[-1].tokenId) == LEFTSHIFT) {
		(yyval.node) = new LeftShiftBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                pool.add((yyval.node));
            } else if ((yyvsp[-1].tokenId) == RIGHTSHIFT){
                (yyval.node) = new RightShiftBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
            printDebugMsg("shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr -> shift_expr"); 
        }
#line 2942 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 922 "parse.y" /* yacc.c:1646  */
    { (yyval.tokenId) = LEFTSHIFT; }
#line 2948 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 924 "parse.y" /* yacc.c:1646  */
    { (yyval.tokenId) = RIGHTSHIFT; }
#line 2954 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 928 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("term -> arith_expr");
        }
#line 2963 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 933 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("arith_expr pick_PLUS_MINUS term -> arith_expr");
            if ((yyvsp[-1].tokenId) == PLUS) {
                (yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                pool.add((yyval.node));
            } else if ((yyvsp[-1].tokenId) == MINUS) {
                (yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
        }
#line 2978 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 946 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = PLUS;
            printDebugMsg("PLUS -> pick_PLUS_MINUS");
        }
#line 2987 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 951 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = MINUS;
            printDebugMsg("MINUS -> pick_PLUS_MINUS"); }
#line 2995 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 957 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("factor -> term");
        }
#line 3004 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 962 "parse.y" /* yacc.c:1646  */
    {
	  if ((yyvsp[-1].tokenId) == STAR) {
	    (yyval.node) = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
          } else if ((yyvsp[-1].tokenId) == SLASH) {
	    (yyval.node) = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
	  } else if ((yyvsp[-1].tokenId) == DOUBLESLASH) {
            (yyval.node) = new FloorDivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
          } else if ((yyvsp[-1].tokenId) == PERCENT) {
            (yyval.node) = new ModBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
          }      
            printDebugMsg("term pick_multop factor -> term");
        }
#line 3025 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 981 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = STAR;
        }
#line 3033 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 985 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = SLASH;
        }
#line 3041 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 989 "parse.y" /* yacc.c:1646  */
    {
            (yyval.tokenId) = PERCENT;
        }
#line 3049 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 993 "parse.y" /* yacc.c:1646  */
    { 
	    (yyval.tokenId) = DOUBLESLASH;
	}
#line 3057 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 999 "parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].tokenId) == MINUS) {
		(yyval.node) = new MinusUnaryNode((yyvsp[0].node));
		pool.add((yyval.node));
            } else if ((yyvsp[-1].tokenId) == TILDE) {
                (yyval.node) = new TildeUnaryNode((yyvsp[0].node));
		pool.add((yyval.node));
            } else if ((yyvsp[-1].tokenId) == PLUS){
		(yyval.node) = (yyvsp[0].node);
            }
            printDebugMsg("pick_unop factor -> factor");
        }
#line 3074 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1012 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            printDebugMsg("power -> factor"); 
        }
#line 3083 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1019 "parse.y" /* yacc.c:1646  */
    {
	    (yyval.tokenId) = PLUS;
        }
#line 3091 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1023 "parse.y" /* yacc.c:1646  */
    {
	    (yyval.tokenId) = MINUS;
        }
#line 3099 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1027 "parse.y" /* yacc.c:1646  */
    {
	    (yyval.tokenId) = TILDE;
        }
#line 3107 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1033 "parse.y" /* yacc.c:1646  */
    {
             (yyval.node) = new PowBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
             pool.add((yyval.node));
             printDebugMsg("atom star_trailer DOUBLESTAR factor -> power");
         }
#line 3117 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1039 "parse.y" /* yacc.c:1646  */
    {
           if (!((yyvsp[0].nodes)->empty())) {
              std::string n = reinterpret_cast<IdentNode*>((yyvsp[-1].node))->getIdent();
              (yyval.node) = new CallNode(n);
              pool.add((yyval.node));
              delete (yyvsp[0].nodes);
            }
            else
              (yyval.node) = (yyvsp[-1].node);
            printDebugMsg("atom star_trailer -> power");
         }
#line 3133 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1053 "parse.y" /* yacc.c:1646  */
    {
          printDebugMsg("star_trailer trailer -> star_trailer");
          (yyval.nodes) = (yyvsp[-1].nodes);
          (yyval.nodes)->push_back((yyvsp[0].node));
        }
#line 3143 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1059 "parse.y" /* yacc.c:1646  */
    {
          (yyval.nodes) = new std::vector<Node*>();
          printDebugMsg(" -> star_trailer");
        }
#line 3152 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1066 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
	    printDebugMsg("LPAR opt_yield_test RPAR -> atom");
        }
#line 3161 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1071 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3167 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1073 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3173 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1075 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3179 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1077 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("NAME -> atom");
            (yyval.node) = new IdentNode((yyvsp[0].id));
            deleteName((yyvsp[0].id));
            pool.add((yyval.node));
        }
#line 3190 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1084 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("FLOATNUMBER -> atom");
            (yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
            pool.add((yyval.node));
        }
#line 3200 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1090 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("INTNUMBER -> atom");
            (yyval.node) = new IntLiteral((yyvsp[0].intNumber));
            pool.add((yyval.node));
        }
#line 3210 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1096 "parse.y" /* yacc.c:1646  */
    {
            printDebugMsg("TRUE -> atom");
            (yyval.node) = new BoolLiteral((yyvsp[0].intNumber));
            pool.add((yyval.node));
        }
#line 3220 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1102 "parse.y" /* yacc.c:1646  */
    {
	    printDebugMsg("FALSE -> atom");
            (yyval.node) = new BoolLiteral((yyvsp[0].intNumber));
            pool.add((yyval.node));
        }
#line 3230 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1108 "parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3236 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1112 "parse.y" /* yacc.c:1646  */
    { 
            //$$ = nullptr;
	    printDebugMsg("yield_expr -> pick_yield_expr_testlist_comp");
	}
#line 3245 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1117 "parse.y" /* yacc.c:1646  */
    {
	    printDebugMsg("testlist_comp -> pick_yield_expr_testlist_comp");
	}
#line 3253 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1123 "parse.y" /* yacc.c:1646  */
    {
	    (yyval.node) = (yyvsp[0].node);
	    printDebugMsg("pick_yield_expr_testlist_comp -> opt_yield_test"); 
	}
#line 3262 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1128 "parse.y" /* yacc.c:1646  */
    { 
            (yyval.node) = nullptr;
	    printDebugMsg(" -> opt_yield_test");
	}
#line 3271 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1151 "parse.y" /* yacc.c:1646  */
    {
	    printDebugMsg("test comp_for -> testlist_comp");
        }
#line 3279 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1155 "parse.y" /* yacc.c:1646  */
    {
	    printDebugMsg("test star_COMMA_test opt_COMMA -> testlist_comp");
        }
#line 3287 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1165 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new TrailerNode((yyvsp[-1].node));
            pool.add((yyval.node));
	    printDebugMsg("LPAR opt_arglist RPAR -> trailer");
	}
#line 3297 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1171 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
	    printDebugMsg("LSQB subscriptlist RSQB -> trailer");
	}
#line 3306 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1176 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
	    printDebugMsg("DOT NAME -> trailer"); 
	    deleteName((yyvsp[0].id));
        }
#line 3316 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1217 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            printDebugMsg("test star_COMMA_test COMMA -> testlist");
        }
#line 3325 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1222 "parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            printDebugMsg("test star_COMMA_test -> testlist");
        }
#line 3334 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1245 "parse.y" /* yacc.c:1646  */
    { deleteName((yyvsp[-5].id)); }
#line 3340 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1247 "parse.y" /* yacc.c:1646  */
    { deleteName((yyvsp[-2].id)); }
#line 3346 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1311 "parse.y" /* yacc.c:1646  */
    { printDebugMsg("YIELD testlist -> yield_expr"); }
#line 3352 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1313 "parse.y" /* yacc.c:1646  */
    { printDebugMsg("YIELD -> yield_expr"); }
#line 3358 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3362 "parse.tab.c" /* yacc.c:1646  */
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
#line 1319 "parse.y" /* yacc.c:1906  */


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
  if (name != nullptr)
    delete [] name;
    name = nullptr;
}

void printDebugMsg(const char *msg) {
  if (myDebug)
     std::cout << msg << std::endl;
}
