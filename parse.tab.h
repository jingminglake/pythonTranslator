/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 19 "parse.y" /* yacc.c:1909  */

   class Node;
   typedef struct YYLTYPE {
     int first_line;
     int first_column;
     int last_line;
     int last_column;
   } YYLTYPE;
   #define YYLTYPE_IS_DECLARED 1

#line 55 "parse.tab.h" /* yacc.c:1909  */

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
#line 30 "parse.y" /* yacc.c:1909  */

  Node* node;
  long long intNumber;
  long double fltNumber;
  char *id;
  int tokenId;
  std::vector<Node*>* nodes;

#line 166 "parse.tab.h" /* yacc.c:1909  */
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
