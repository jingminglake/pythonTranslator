// Generated by transforming |cwd:///work-in-progress/2.7.2-bisonified.y| on 2016-11-23 at 15:46:56 +0000
%{
        #include <iostream>
        #include <vector>
        #include "includes/ast.h"
        #include "includes/literal.h"
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
        // extern YYSTYPE yylval;
        void deleteName(char *name);
        PoolOfNodes& pool = PoolOfNodes::getInstance();
        bool myDebug = true;
        void printDebugMsg(const char *);
        void printDebugMsg(const std::string&);
        extern bool cmdlineMode;
%}

%code requires {
   class Node;
   typedef struct YYLTYPE {
     int first_line;
     int first_column;
     int last_line;
     int last_column;
   } YYLTYPE;
   #define YYLTYPE_IS_DECLARED 1
}

%union {
  Node* node;
  long long intNumber;
  long double fltNumber;
  char *id;
  int tokenId;
  std::vector<Node*>* nodes;
}

// 83 tokens, in alphabetical order:
%token AMPEREQUAL AMPERSAND AND AS ASSERT AT BACKQUOTE BAR BREAK CIRCUMFLEX
%token CIRCUMFLEXEQUAL CLASS COLON COMMA CONTINUE DEDENT DEF DEL DOT DOUBLESLASH
%token DOUBLESLASHEQUAL DOUBLESTAR DOUBLESTAREQUAL ELIF ELSE ENDMARKER EQEQUAL
%token  EXCEPT EXEC FINALLY FOR FROM GLOBAL GREATER GREATEREQUAL GRLT
%token IF IMPORT IN INDENT IS LAMBDA LBRACE LEFTSHIFT LEFTSHIFTEQUAL LESS
%token LESSEQUAL LPAR LSQB MINEQUAL NEWLINE NOT NOTEQUAL NUMBER MINUS
%token OR PLUS PASS PERCENT PERCENTEQUAL PLUSEQUAL PRINT RAISE RBRACE RETURN
%token RIGHTSHIFT RIGHTSHIFTEQUAL RPAR RSQB SEMI SLASHEQUAL STAREQUAL STAR
%token SLASH STRING TILDE TRY VBAREQUAL WHILE WITH YIELD


%token<id> NAME
%start start
%locations

%type<tokenId> pick_PLUS_MINUS pick_multop pick_unop
%type<tokenId> augassign pick_LEFTSHIFT_RIGHTSHIFT comp_op
%type<node> arith_expr atom power factor term shift_expr and_expr xor_expr expr
%type<node> comparison not_test and_test or_test test pick_yield_expr_testlist
%type<node> testlist star_EQUAL expr_stmt small_stmt simple_stmt
%type<node> stmt print_stmt opt_test opt_yield_test pick_yield_expr_testlist_comp star_EQUAL_R
%type<node> compound_stmt flow_stmt return_stmt
%type<node> plus_stmt funcdef if_stmt suite trailer
%type<node> pick_NEWLINE_stmt argument pick_argument fpdef
%type<nodes> star_trailer star_NEWLINE_stmt arglist opt_arglist star_argument_COMMA
%type<nodes> star_fpdef_COMMA varargslist parameters
%token<fltNumber> FLOATNUMBER
%token<intNumber> INTNUMBER TRUE FALSE
%right EQUAL
%%

start
	: file_input
        {
            printDebugMsg("file_input -> start");
        }
	;

file_input // Used in: start
	: star_NEWLINE_stmt ENDMARKER
        {
            if ($1) {
                auto it = $1->begin();
                while (it != $1->end()) {
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
            delete $1;
            printDebugMsg("star_NEWLINE_stmt ENDMARKER -> file_input");
        }
	;
pick_NEWLINE_stmt // Used in: star_NEWLINE_stmt
	: NEWLINE
        {
            $$ = nullptr;
            printDebugMsg("NEWLINE -> pick_NEWLINE_stmt");
        }
	| stmt
        {
            if (cmdlineMode) {
	      try {
		$1->eval();
	      } catch (const std::string& msg) {
		std::cout << msg << std::endl;
	      } catch (const char* msg) {
		std::cout << msg << std::endl;
	      } catch (...) {
		std::cout << "opps, something wrong happened!" << std::endl;
	      }
            }
	    $$ = new NewStmtNode($1);
	    pool.add($$);
            printDebugMsg("stmt -> pick_NEWLINE_stmt");
        }
	;
star_NEWLINE_stmt // Used in: file_input, star_NEWLINE_stmt
	: star_NEWLINE_stmt pick_NEWLINE_stmt
        {
            $$ = $1;
            if ($2) {
                $$->push_back($2);
            }
            printDebugMsg("star_NEWLINE_stmt pick_NEWLINE_stmt -> star_NEWLINE_stmt");
        }
	| %empty
        {
            $$ = new std::vector<Node*>();
            $$->reserve(8);
            printDebugMsg(" -> star_NEWLINE_stmt");
        }
	;
decorator // Used in: decorators
	: AT dotted_name LPAR opt_arglist RPAR NEWLINE
	| AT dotted_name NEWLINE
	;
opt_arglist // Used in: decorator, trailer
	: arglist
        {
          $$ = $1;
          printDebugMsg("arglist -> opt_arglist");
        }
	| %empty
	{
          $$ = nullptr;
          printDebugMsg(" -> opt_arglist");
        }
	;
decorators // Used in: decorators, decorated
	: decorators decorator
	| decorator
	;
decorated // Used in: compound_stmt
        : decorators classdef
	| decorators funcdef
	;
funcdef // Used in: decorated, compound_stmt
        : DEF NAME parameters COLON suite
	{
          if ($3)
	    $$ = new FuncDefNode($2, *$3, $5);
          $$ = new FuncDefNode($2, $5);
          pool.add($$);
          delete $3;
          deleteName($2);
          printDebugMsg("DEF NAME parameters COLON suite -> funcdef");
        }
	;
parameters // Used in: funcdef
	: LPAR varargslist RPAR
	{
          $$ = $2;
	  printDebugMsg("LPAR varargslist RPAR -> parameters");
        }
	| LPAR RPAR
        {
          $$ = nullptr;
	  printDebugMsg("LPAR RPAR -> parameters");
        }
	;
varargslist // Used in: parameters, old_lambdef, lambdef
	: star_fpdef_COMMA pick_STAR_DOUBLESTAR
        { 
          $$ = $1;
	  printDebugMsg("star_fpdef_COMMA pick_STAR_DOUBLESTAR -> varargslist");
        }
	| star_fpdef_COMMA fpdef opt_EQUAL_test opt_COMMA
        {
          $$ = $1;
          $$->push_back($2);
	  printDebugMsg("star_fpdef_COMMA fpdef opt_EQUAL_test opt_COMMA -> varargslist");
        }
	;
opt_EQUAL_test // Used in: varargslist, star_fpdef_COMMA
	: EQUAL test
	{
          printDebugMsg("EQUAL_test -> opt_EQUAL_test"); 
        }
	| %empty
	{
	  printDebugMsg(" -> opt_EQUAL_test");
        }
	;
star_fpdef_COMMA // Used in: varargslist, star_fpdef_COMMA
	: star_fpdef_COMMA fpdef opt_EQUAL_test COMMA
	{
          $$ = $1;
          $$->push_back($2);
	  printDebugMsg("star_fpdef_COMMA fpdef opt_EQUAL_test COMMA -> star_fpdef_COMMA");
        }
	| %empty
        {
          $$ = new std::vector<Node*>();
          $$->reserve(4);
	  printDebugMsg(" -> star_fpdef_COMMA");
        }
	;
opt_DOUBLESTAR_NAME // Used in: pick_STAR_DOUBLESTAR
	: COMMA DOUBLESTAR NAME
        {
          deleteName($3);
        }
	| %empty
	;
pick_STAR_DOUBLESTAR // Used in: varargslist
	: STAR NAME opt_DOUBLESTAR_NAME
        {
	  printDebugMsg("STAR NAME opt_DOUBLESTAR_NAME -> pick_STAR_DOUBLESTAR");
          deleteName($2);
        }
	| DOUBLESTAR NAME
        {
	  printDebugMsg("DOUBLESTAR NAME -> pick_STAR_DOUBLESTAR");
          deleteName($2);
        } 
	;
opt_COMMA // Used in: varargslist, opt_test, opt_test_2, testlist_safe, listmaker, testlist_comp, pick_for_test_test, pick_for_test, pick_argument
	: COMMA
        {
	  printDebugMsg("COMMA -> opt_COMMA");
        }
	| %empty
        {
	  printDebugMsg(" -> opt_COMMA");
        }
	;
fpdef // Used in: varargslist, star_fpdef_COMMA, fplist, star_fpdef_notest
	: NAME
        {
	  printDebugMsg("NAME -> fpdef");
          $$ = new IdentNode($1);
          pool.add($$);
          deleteName($1);
        }
	| LPAR fplist RPAR
        {
          $$ = nullptr;
	  printDebugMsg("LPAR fplist RPAR -> fpdef");
        }
	;
fplist // Used in: fpdef
	: fpdef star_fpdef_notest COMMA
        {
	  printDebugMsg("fpdef star_fpdef_notest COMMA -> fplist");
        }
	| fpdef star_fpdef_notest
        {
	  printDebugMsg("fpdef star_fpdef_notest -> fplist");
        }
	;
star_fpdef_notest // Used in: fplist, star_fpdef_notest
	: star_fpdef_notest COMMA fpdef
        {
	  printDebugMsg("star_fpdef_notest COMMA fpdef -> star_fpdef_notest");
        }
	| %empty
        {
	  printDebugMsg(" -> star_fpdef_notest");
        }
	;
stmt // Used in: pick_NEWLINE_stmt, plus_stmt
	: simple_stmt
         {
             $$ = $1;
	     //($$)->eval()->print();
             printDebugMsg("simple_stmt -> stmt");
         }
	| compound_stmt
         {
	     $$ = $1;
             printDebugMsg("compound_stmt -> stmt");
         }
	;
simple_stmt // Used in: stmt, suite
	: small_stmt star_SEMI_small_stmt SEMI NEWLINE
         {
             $$ = $1;
             printDebugMsg("small_stmt star_SEMI_small_stmt SEMI NEWLINE -> simple_stmt");          }
	| small_stmt star_SEMI_small_stmt NEWLINE
         {
	     $$ = $1;
             printDebugMsg("small_stmt star_SEMI_small_stmt NEWLINE  -> simple_stmt");
         }
	;
star_SEMI_small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: star_SEMI_small_stmt SEMI small_stmt
        {
            printDebugMsg("star_SEMI_small_stmt SEMI small_stmt -> star_SEMI_small_stmt");
        }
	| %empty
        {
            printDebugMsg(" -> star_SEMI_small_stmt"); 
        }
	;
small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: expr_stmt
        {
           $$ = $1;
           printDebugMsg("expr_stmt -> small_stmt"); 
        }
	| print_stmt
        {
	   printDebugMsg("---------print_stmt---------");
           // if (($$)->eval())
	   //  ($$)->eval()->printStmt();
           $$ = new PrintNode($1);
           pool.add($$);
	   printDebugMsg("---------print_stmt---------");
        }
	| del_stmt
	{ $$ = nullptr; }
	| pass_stmt
	{ $$ = nullptr; }
	| flow_stmt
        { $$ = $1; }
	| import_stmt
        { $$ = nullptr; }
	| global_stmt
        { $$ = nullptr; }
	| exec_stmt
        { $$ = nullptr; }
	| assert_stmt
        { $$ = nullptr; }
	;
expr_stmt // Used in: small_stmt
	: testlist augassign pick_yield_expr_testlist
        {
            switch($2) {
              case PLUSEQUAL:
		  $$ = new PlusAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case MINEQUAL:
		  $$ = new MinAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case STAREQUAL:
		  $$ = new StarAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case SLASHEQUAL:
                  $$ = new SlashAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case DOUBLESLASHEQUAL:
                  $$ = new DoubleSlashAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case DOUBLESTAREQUAL:
                  $$ = new DoubleStarAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case PERCENTEQUAL:
                  $$ = new PercentAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case LEFTSHIFTEQUAL:
                  $$ = new LShiftAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case RIGHTSHIFTEQUAL:
                  $$ = new RShiftAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case AMPEREQUAL:
                  $$ = new AmperAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case VBAREQUAL:
                  $$ = new VBarAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
              case CIRCUMFLEXEQUAL:
                  $$ = new CircumflexAsgBinaryNode($1, $3);
                  pool.add($$);
                  break;
            }
            /*if ($3 == nullptr) {
	      $$ = $1;
              }*/
            printDebugMsg("testlist augassign pick_yield_expr_testlist -> expr_stmt");
        }
        | testlist star_EQUAL
        {
            if ($2 == nullptr) {
	      $$ = $1;
              printDebugMsg("---------testlist star_EQUAL---------");
              //if (($$)->eval())
	      //  ($$)->eval()->print();
	      printDebugMsg("---------testlist star_EQUAL---------");
            }
            else {
              $$ = new AsgBinaryNode($1, $2); 
              pool.add($$);
	    }
            printDebugMsg("testlist star_EQUAL -> expr_stmt");
        }
	;
pick_yield_expr_testlist // Used in: expr_stmt, star_EQUAL
	: yield_expr
        {
	    $$ = nullptr;
            printDebugMsg("yield_expr -> pick_yield_expr_testlist");
        }
	| testlist
        {
            $$ = $1;
            printDebugMsg("testlist -> pick_yield_expr_testlist");
        }
	;
/*star_EQUAL // Used in: expr_stmt, star_EQUAL
	: star_EQUAL EQUAL  pick_yield_expr_testlist
        {
          if ($1 == nullptr) {
	    $$ = $3;
            printDebugMsg("-=-=-=---------------------1--");
            //($$)->eval()->print();
          } else {
              printDebugMsg("-=-=-=--------------------2---");
              //($$)->eval()->print();
	      $$ = new AsgBinaryNode($1, $3);
	      pool.add($$);
          }
          printDebugMsg("star_EQUAL EQUAL pick_yield_expr_testlist -> star_EQUAL");
        }
	| %empty
        {
            $$ = nullptr;
            printDebugMsg("  -> star_EQUAL");
        }
	; */

star_EQUAL
        : star_EQUAL_R
        {
            $$ = $1;
            printDebugMsg("star_EQUAL_R -> star_EQUAL");
        }
        ;
star_EQUAL_R // Used in: expr_stmt, star_EQUAL
	: EQUAL pick_yield_expr_testlist star_EQUAL_R
        {
            if ($3 == nullptr) {
                $$ = $2;
            } else {
                $$ = new AsgBinaryNode($2, $3);
                pool.add($$);
            }
            printDebugMsg("EQUAL pick_yield_expr_testlist star_EQUAL_R -> star_EQUAL");
        }
        | %empty
        {
            $$ = nullptr;
            printDebugMsg(" -> star_EQUAL_R");
        }
	;

augassign // Used in: expr_stmt
	: PLUSEQUAL
	{
           $$ = PLUSEQUAL;
        }
	| MINEQUAL
        {
           $$ = MINEQUAL;
        }
	| STAREQUAL
        {
           $$ = STAREQUAL;
        }
	| SLASHEQUAL
        {
           $$ = SLASHEQUAL;
        }
	| PERCENTEQUAL
        {
           $$ = PERCENTEQUAL;
        }
	| AMPEREQUAL
        {
           $$ = AMPEREQUAL;
        }
	| VBAREQUAL
        {
           $$ = VBAREQUAL;
        }
	| CIRCUMFLEXEQUAL
        {
           // ^|
           $$ = CIRCUMFLEXEQUAL;
        }
	| LEFTSHIFTEQUAL
        {
           $$ = LEFTSHIFTEQUAL;
        }
	| RIGHTSHIFTEQUAL
        {
           $$ = RIGHTSHIFTEQUAL;
        }
	| DOUBLESTAREQUAL
        {
           $$ = DOUBLESTAREQUAL;
        }
	| DOUBLESLASHEQUAL
        {
           $$ = DOUBLESLASHEQUAL;
        }
	;
print_stmt // Used in: small_stmt
	: PRINT opt_test
        {
          $$ = $2;
	  printDebugMsg("PRINT opt_test -> print_stmt"); 
        }
	| PRINT RIGHTSHIFT test opt_test_2
        {
	  $$ = $3;
          printDebugMsg("PRINT RIGHTSHIFT test opt_test_2 -> print_stmt");
        }
	;
star_COMMA_test // Used in: star_COMMA_test, opt_test, listmaker, testlist_comp, testlist, pick_for_test
	: star_COMMA_test COMMA test
	| %empty
	;
opt_test // Used in: print_stmt
	: test star_COMMA_test opt_COMMA
	{
	  printDebugMsg("test star_COMMA_test opt_COMMA -> opt_test");
	  $$ = $1;
        }
	| %empty
        {
	  printDebugMsg(" -> opt_test");
	  $$ = nullptr;
        }
	;
plus_COMMA_test // Used in: plus_COMMA_test, opt_test_2
	: plus_COMMA_test COMMA test
	| COMMA test
	;
opt_test_2 // Used in: print_stmt
	: plus_COMMA_test opt_COMMA
	| %empty
	;
del_stmt // Used in: small_stmt
	: DEL exprlist
	;
pass_stmt // Used in: small_stmt
	: PASS
	;
flow_stmt // Used in: small_stmt
	: break_stmt
          { $$ = nullptr; }
	| continue_stmt
          { $$ = nullptr; }
	| return_stmt
          { 
            $$ = $1;
            printDebugMsg("return_stmt -> flow_stmt");
          }
	| raise_stmt
          { $$ = nullptr; }
	| yield_stmt
          { $$ = nullptr; }
	;
break_stmt // Used in: flow_stmt
	: BREAK
	;
continue_stmt // Used in: flow_stmt
	: CONTINUE
	;
return_stmt // Used in: flow_stmt
	: RETURN testlist
        {
	  $$ = new ReturnNode($2);
	  pool.add($$);
          printDebugMsg("RETURN testlist -> return_stmt");
        }
	| RETURN
        {
          $$ = new ReturnNode(nullptr);
          pool.add($$);
          printDebugMsg("RETURN -> return_stmt");
        }
	;
yield_stmt // Used in: flow_stmt
	: yield_expr
	;
raise_stmt // Used in: flow_stmt
	: RAISE test opt_test_3
	| RAISE
	;
opt_COMMA_test // Used in: opt_test_3, exec_stmt
	: COMMA test
	| %empty
	;
opt_test_3 // Used in: raise_stmt
	: COMMA test opt_COMMA_test
	| %empty
	;
import_stmt // Used in: small_stmt
	: import_name
	| import_from
	;
import_name // Used in: import_stmt
	: IMPORT dotted_as_names
	;
import_from // Used in: import_stmt
	: FROM pick_dotted_name IMPORT pick_STAR_import
	;
pick_dotted_name // Used in: import_from
	: star_DOT dotted_name
	| star_DOT DOT
	;
pick_STAR_import // Used in: import_from
	: STAR
	| LPAR import_as_names RPAR
	| import_as_names
	;
import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: NAME AS NAME
        {
          deleteName($1);
          deleteName($3);
        }
	| NAME
        {
          deleteName($1);
        }
	;
dotted_as_name // Used in: dotted_as_names
	: dotted_name AS NAME
        {
          deleteName($3);
        }
	| dotted_name
	;
import_as_names // Used in: pick_STAR_import
	: import_as_name star_COMMA_import_as_name COMMA
	| import_as_name star_COMMA_import_as_name
	;
star_COMMA_import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: star_COMMA_import_as_name COMMA import_as_name
	| %empty
	;
dotted_as_names // Used in: import_name, dotted_as_names
	: dotted_as_name
	| dotted_as_names COMMA dotted_as_name
	;
dotted_name // Used in: decorator, pick_dotted_name, dotted_as_name, dotted_name
	: NAME
        {
          deleteName($1);
        }
	| dotted_name DOT NAME
        {
          deleteName($3);
        }
	;
global_stmt // Used in: small_stmt
	: GLOBAL NAME star_COMMA_NAME
        {
          deleteName($2);
        }
	;
star_COMMA_NAME // Used in: global_stmt, star_COMMA_NAME
	: star_COMMA_NAME COMMA NAME
        {
          deleteName($3);
        }
	| %empty
	;
exec_stmt // Used in: small_stmt
	: EXEC expr IN test opt_COMMA_test
	| EXEC expr
	;
assert_stmt // Used in: small_stmt
	: ASSERT test COMMA test
	| ASSERT test
	;
compound_stmt // Used in: stmt
	: if_stmt
          { $$ = $1; }
	| while_stmt
          { $$ = nullptr; }
 	| for_stmt
          { $$ = nullptr; }
	| try_stmt
          { $$ = nullptr; }
	| with_stmt
          { $$ = nullptr; }
	| funcdef
          {
            printDebugMsg("funcdef -> compound_stmt");
            $$ = $1;
          }
	| classdef
          { $$ = nullptr; }
	| decorated
          { $$ = nullptr; }
	;
if_stmt // Used in: compound_stmt
        : IF test COLON suite star_ELIF ELSE COLON suite
          {
            $$ = new IfNode($2, $4, $8);
            pool.add($$);
          }
	| IF test COLON suite star_ELIF
          {
            $$ = new IfNode($2, $4);
            pool.add($$);
          }
	;
star_ELIF // Used in: if_stmt, star_ELIF
	: star_ELIF ELIF test COLON suite
	| %empty
	;
while_stmt // Used in: compound_stmt
	: WHILE test COLON suite ELSE COLON suite      
	| WHILE test COLON suite
	;
for_stmt // Used in: compound_stmt
        : FOR exprlist IN testlist COLON suite ELSE COLON suite
	| FOR exprlist IN testlist COLON suite
        ;
try_stmt // Used in: compound_stmt
	: TRY COLON suite plus_except opt_ELSE opt_FINALLY
	| TRY COLON suite FINALLY COLON suite
	;
plus_except // Used in: try_stmt, plus_except
	: plus_except except_clause COLON suite
	| except_clause COLON suite
	;
opt_ELSE // Used in: try_stmt
	: ELSE COLON suite
	| %empty
	;
opt_FINALLY // Used in: try_stmt
	: FINALLY COLON suite
	| %empty
	;
with_stmt // Used in: compound_stmt
: WITH  with_item star_COMMA_with_item COLON suite
	;
star_COMMA_with_item // Used in: with_stmt, star_COMMA_with_item
	: star_COMMA_with_item COMMA with_item
	| %empty
	;
with_item // Used in: with_stmt, star_COMMA_with_item
	: test AS expr
	| test
	;
except_clause // Used in: plus_except
	: EXCEPT test opt_AS_COMMA
	| EXCEPT
	;
pick_AS_COMMA // Used in: opt_AS_COMMA
	: AS
	| COMMA
	;
opt_AS_COMMA // Used in: except_clause
	: pick_AS_COMMA test
	| %empty
	;
suite // Used in: funcdef, if_stmt, star_ELIF, while_stmt, for_stmt, try_stmt, plus_except, opt_ELSE, opt_FINALLY, with_stmt, classdef
	: simple_stmt
	{
	  $$ = $1;
	  printDebugMsg("simple_stmt -> suite");
        }
	| NEWLINE INDENT plus_stmt DEDENT
        {
	  printDebugMsg("NEWLINE INDENT plus_stmt DEDENT -> suite");
	  $$ = $3;
        }
	;
plus_stmt // Used in: suite, plus_stmt
	: plus_stmt stmt
        {
          $$ = $1;
          static_cast<SuiteNode*>($$)->insertStmt($2);
          printDebugMsg("plus_stmt stmt -> plus_stmt");
        }
	| stmt
        {
          $$ = new SuiteNode();
          pool.add($$);
          static_cast<SuiteNode*>($$)->insertStmt($1); // use cast because insertStmt() is not a virtual function
          printDebugMsg("stmt -> plus_stmt");
        }
	;
testlist_safe // Used in: list_for
	: old_test plus_COMMA_old_test opt_COMMA
	| old_test
	;
plus_COMMA_old_test // Used in: testlist_safe, plus_COMMA_old_test
	: plus_COMMA_old_test COMMA old_test
	| COMMA old_test
	;
old_test // Used in: testlist_safe, plus_COMMA_old_test, old_lambdef, list_if, comp_if
	: or_test
	| old_lambdef
	;
old_lambdef // Used in: old_test
	: LAMBDA varargslist COLON old_test
	| LAMBDA COLON old_test
	;
test // Used in: opt_EQUAL_test, print_stmt, star_COMMA_test, opt_test, plus_COMMA_test, raise_stmt, opt_COMMA_test, opt_test_3, exec_stmt, assert_stmt, if_stmt, star_ELIF, while_stmt, with_item, except_clause, opt_AS_COMMA, opt_IF_ELSE, listmaker, testlist_comp, lambdef, subscript, opt_test_only, sliceop, testlist, dictorsetmaker, star_test_COLON_test, opt_DOUBLESTAR_test, pick_argument, argument, testlist1
	: or_test opt_IF_ELSE
        {
            $$ = $1;
            printDebugMsg("or_test opt_IF_ELSE -> test"); }
	| lambdef
	{ $$ = nullptr;} 
	;
opt_IF_ELSE // Used in: test
	: IF or_test ELSE test
        {
          printDebugMsg("IF or_test ELSE test -> opt_IF_ELSE");
        }
	| %empty
        {
          printDebugMsg(" -> opt_IF_ELSE");
        }
	;
or_test // Used in: old_test, test, opt_IF_ELSE, or_test, comp_for
	: and_test
         {
             $$ = $1;
             printDebugMsg("and_test -> or_test");
         }
	| or_test OR and_test
         { printDebugMsg("or_test OR and_test -> or_test"); }
	;
and_test // Used in: or_test, and_test
	: not_test
         {
             $$ = $1;
             printDebugMsg("not_test -> and_test");
         }
	| and_test AND not_test
         {
           printDebugMsg("and_test AND not_test  -> and_test");
         }
	;
not_test // Used in: and_test, not_test
	: NOT not_test
         {
             printDebugMsg("NOT not_test -> not_test");
         }
	| comparison
         {
            $$ = $1;  
            printDebugMsg("comparison -> not_test"); 
         }
	;
comparison // Used in: not_test, comparison
	: expr
         {
             $$ = $1;
             printDebugMsg("expr -> comparison");
         }
	| comparison comp_op expr
         {
	   switch($2) {
	     case LESS:
               $$ = new LessNode($1, $3);
               break;
  	     case GREATER:
               $$ = new GreaterNode($1, $3);
               break;
	     case EQEQUAL:
               $$ = new EqEqualNode($1, $3);
	       break;
             case GREATEREQUAL:
               $$ = new GreaterEqualNode($1, $3);
	       break;
	     case LESSEQUAL:
               $$ = new LessEqualNode($1, $3);
	       break;
	       /*             case GRLT:
               $$ = new GRLTNode($1, $3);
	       break; */
             case NOTEQUAL:
               $$ = new NotEqualNode($1, $3);
	       break;
           }
           pool.add($$);
           printDebugMsg("comparison comp_op expr -> comparison"); 
         }
	;
comp_op // Used in: comparison
	: LESS
        {
           $$ = LESS; 
        }
	| GREATER
	{
           $$ = GREATER; 
        }
	| EQEQUAL
	{
           $$ = EQEQUAL; 
        }
	| GREATEREQUAL
	{
           $$ = GREATEREQUAL; 
        }
	| LESSEQUAL
	{
           $$ = LESSEQUAL; 
        }
	| GRLT
	{
           $$ = GRLT; 
        }
	| NOTEQUAL
	{
           $$ = NOTEQUAL; 
        }
	| IN
	{
           $$ = IN; 
        }
	| NOT IN
	{
           $$ = NOT + IN; 
        }
	| IS
	{
           $$ = IS; 
        }
	| IS NOT
	{
           $$ = IS + NOT; 
        }
	;
expr // Used in: exec_stmt, with_item, comparison, expr, exprlist, star_COMMA_expr
	: xor_expr
        {
            $$ = $1;
            printDebugMsg("xor_expr -> expr"); 
        }
	| expr BAR xor_expr
        {
            $$ = new BarBinaryNode($1, $3);
            pool.add($$);
            printDebugMsg("expr BAR xor_expr -> expr");
        }
	;
xor_expr // Used in: expr, xor_expr
	: and_expr
        {
            $$ = $1;
            printDebugMsg("and_expr -> xor_expr"); }
	| xor_expr CIRCUMFLEX and_expr
        {
            $$ =  new CircumflexBinaryNode($1, $3); 
            pool.add($$);
            printDebugMsg(" xor_expr CIRCUMFLEX and_expr -> xor_expr"); 
        }
	;
and_expr // Used in: xor_expr, and_expr
	: shift_expr
        {
            $$ = $1;
            printDebugMsg("shift_expr -> and_expr");
        }
	| and_expr AMPERSAND shift_expr
        {
	    $$ = new AmpersandBinaryNode($1, $3);
            pool.add($$);
            printDebugMsg("and_expr AMPERSAND shift_expr -> and_expr");
        }
	;
shift_expr // Used in: and_expr, shift_expr
	: arith_expr
        {
            $$ = $1;
            printDebugMsg("arith_expr -> shift_expr");
        }
	| shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr
        { 
            if ($2 == LEFTSHIFT) {
		$$ = new LeftShiftBinaryNode($1, $3);
                pool.add($$);
            } else if ($2 == RIGHTSHIFT){
                $$ = new RightShiftBinaryNode($1, $3);
                pool.add($$);
            }
            printDebugMsg("shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr -> shift_expr"); 
        }
	;
pick_LEFTSHIFT_RIGHTSHIFT // Used in: shift_expr
	: LEFTSHIFT
	{ $$ = LEFTSHIFT; }
	| RIGHTSHIFT
	{ $$ = RIGHTSHIFT; }
	;
arith_expr // Used in: shift_expr, arith_expr
	: term
        {
            $$ = $1;
            printDebugMsg("term -> arith_expr");
        }
	| arith_expr pick_PLUS_MINUS term
        {
            printDebugMsg("arith_expr pick_PLUS_MINUS term -> arith_expr");
            if ($2 == PLUS) {
                $$ = new AddBinaryNode($1, $3);
                pool.add($$);
            } else if ($2 == MINUS) {
                $$ = new SubBinaryNode($1, $3);
                pool.add($$);
            }
        }
	;
pick_PLUS_MINUS // Used in: arith_expr
	: PLUS
        {
            $$ = PLUS;
            printDebugMsg("PLUS -> pick_PLUS_MINUS");
        }
	| MINUS
        {
            $$ = MINUS;
            printDebugMsg("MINUS -> pick_PLUS_MINUS"); }
	;
term // Used in: arith_expr, term
	: factor
        {
            $$ = $1;
            printDebugMsg("factor -> term");
        }
	| term pick_multop factor
        {
	  if ($2 == STAR) {
	    $$ = new MulBinaryNode($1, $3);
            pool.add($$);
          } else if ($2 == SLASH) {
	    $$ = new DivBinaryNode($1, $3);
            pool.add($$);
	  } else if ($2 == DOUBLESLASH) {
            $$ = new FloorDivBinaryNode($1, $3);
            pool.add($$);
          } else if ($2 == PERCENT) {
            $$ = new ModBinaryNode($1, $3);
            pool.add($$);
          }      
            printDebugMsg("term pick_multop factor -> term");
        }
	;
pick_multop // Used in: term
	: STAR
        {
            $$ = STAR;
        }
	| SLASH
        {
            $$ = SLASH;
        }
	| PERCENT
	{
            $$ = PERCENT;
        }
	| DOUBLESLASH
	{ 
	    $$ = DOUBLESLASH;
	}
	;
factor // Used in: term, factor, power
	: pick_unop factor
        {
            if ($1 == MINUS) {
		$$ = new MinusUnaryNode($2);
		pool.add($$);
            } else if ($1 == TILDE) {
                $$ = new TildeUnaryNode($2);
		pool.add($$);
            } else if ($1 == PLUS){
		$$ = $2;
            }
            printDebugMsg("pick_unop factor -> factor");
        }
	| power
        {
            $$ = $1;
            printDebugMsg("power -> factor"); 
        }
	;
pick_unop // Used in: factor
	: PLUS
	{
	    $$ = PLUS;
        }
	| MINUS
	{
	    $$ = MINUS;
        }
	| TILDE
        {
	    $$ = TILDE;
        }
	;
power // Used in: factor
	: atom star_trailer DOUBLESTAR factor
         {
             $$ = new PowBinaryNode($1, $4);
             pool.add($$);
             printDebugMsg("atom star_trailer DOUBLESTAR factor -> power");
         }
	| atom star_trailer
         {
           if (!($2->empty())) {
              std::string n = reinterpret_cast<IdentNode*>($1)->getIdent();
              $$ = new CallNode(n, $2);
              pool.add($$);
           }
           else {
              $$ = $1;
           }
	   delete $2;
           printDebugMsg("atom star_trailer -> power");
         }
	;
star_trailer // Used in: power, star_trailer
	: star_trailer trailer
	{
          printDebugMsg("star_trailer trailer -> star_trailer");
          $$ = $1;
          $$->push_back($2);
        }
	| %empty
        {
          $$ = new std::vector<Node*>();
          printDebugMsg(" -> star_trailer");
        }
	;
atom // Used in: power
	: LPAR opt_yield_test RPAR
	{
            $$ = $2;
	    printDebugMsg("LPAR opt_yield_test RPAR -> atom");
        }
	| LSQB opt_listmaker RSQB
	{ $$ = nullptr; }
	| LBRACE opt_dictorsetmaker RBRACE
	{ $$ = nullptr; }
	| BACKQUOTE testlist1 BACKQUOTE
	{ $$ = nullptr; }
	| NAME
        {
            printDebugMsg("NAME -> atom");
            $$ = new IdentNode($1);
            deleteName($1);
            pool.add($$);
        }
        | FLOATNUMBER
        {
            printDebugMsg("FLOATNUMBER -> atom");
            $$ = new FloatLiteral($1);
            pool.add($$);
        }
        | INTNUMBER
        {
            printDebugMsg(std::string("INTNUMBER: ") + std::to_string($1) + std::string(" -> atom"));
            $$ = new IntLiteral($1);
            pool.add($$);
        }
	| TRUE
	{
            printDebugMsg("TRUE -> atom");
            $$ = new BoolLiteral($1);
            pool.add($$);
        }
	| FALSE
	{
	    printDebugMsg("FALSE -> atom");
            $$ = new BoolLiteral($1);
            pool.add($$);
        }
	| plus_STRING
        { $$ = nullptr; }
	;
pick_yield_expr_testlist_comp // Used in: opt_yield_test
	: yield_expr
	{ 
            //$$ = nullptr;
	    printDebugMsg("yield_expr -> pick_yield_expr_testlist_comp");
	}
	| testlist_comp
	{
	    printDebugMsg("testlist_comp -> pick_yield_expr_testlist_comp");
	}
	;
opt_yield_test // Used in: atom
	: pick_yield_expr_testlist_comp
	{
	    $$ = $1;
	    printDebugMsg("pick_yield_expr_testlist_comp -> opt_yield_test"); 
	}
	| %empty
        {
            $$ = nullptr;
	    printDebugMsg(" -> opt_yield_test");
	}
	;
opt_listmaker // Used in: atom
	: listmaker
	| %empty
	;
opt_dictorsetmaker // Used in: atom
	: dictorsetmaker
	| %empty
	;
plus_STRING // Used in: atom, plus_STRING
	: plus_STRING STRING
	| STRING
	;
listmaker // Used in: opt_listmaker
	: test list_for
	| test star_COMMA_test opt_COMMA
	;
testlist_comp // Used in: pick_yield_expr_testlist_comp
	: test comp_for
        {
	    printDebugMsg("test comp_for -> testlist_comp");
        }
	| test star_COMMA_test opt_COMMA
        {
	    printDebugMsg("test star_COMMA_test opt_COMMA -> testlist_comp");
        }
	;
lambdef // Used in: test
	: LAMBDA varargslist COLON test
	| LAMBDA COLON test
	;
trailer // Used in: star_trailer
	: LPAR opt_arglist RPAR
	{
            $$ = new TrailerNode($2);
            pool.add($$);
            delete $2;
	    printDebugMsg("LPAR opt_arglist RPAR -> trailer");
	}
	| LSQB subscriptlist RSQB
	{
            $$ = nullptr;
	    printDebugMsg("LSQB subscriptlist RSQB -> trailer");
	}
	| DOT NAME
        {
            $$ = nullptr;
	    printDebugMsg("DOT NAME -> trailer"); 
	    deleteName($2);
        }
	;
subscriptlist // Used in: trailer
	: subscript star_COMMA_subscript COMMA
	| subscript star_COMMA_subscript
	;
star_COMMA_subscript // Used in: subscriptlist, star_COMMA_subscript
	: star_COMMA_subscript COMMA subscript
	| %empty
	;
subscript // Used in: subscriptlist, star_COMMA_subscript
	: DOT DOT DOT
	| test
	| opt_test_only COLON opt_test_only opt_sliceop
	;
opt_test_only // Used in: subscript
	: test
	| %empty
	;
opt_sliceop // Used in: subscript
	: sliceop
	| %empty
	;
sliceop // Used in: opt_sliceop
	: COLON test
	| COLON
	;
exprlist // Used in: del_stmt, for_stmt, list_for, comp_for
	: expr star_COMMA_expr COMMA
	| expr star_COMMA_expr
	;
star_COMMA_expr // Used in: exprlist, star_COMMA_expr
	: star_COMMA_expr COMMA expr
	| %empty
	;
testlist // Used in: expr_stmt, pick_yield_expr_testlist, return_stmt, for_stmt, opt_testlist, yield_expr
	: test star_COMMA_test COMMA
        {
            $$ = $1;
            printDebugMsg("test star_COMMA_test COMMA -> testlist");
        }
	| test star_COMMA_test
        {
            $$ = $1;
            printDebugMsg("test star_COMMA_test -> testlist");
        }
	;
dictorsetmaker // Used in: opt_dictorsetmaker
	: test COLON test pick_for_test_test
	| test pick_for_test
	;
star_test_COLON_test // Used in: star_test_COLON_test, pick_for_test_test
	: star_test_COLON_test COMMA test COLON test
	| %empty
	;
pick_for_test_test // Used in: dictorsetmaker
	: comp_for
	| star_test_COLON_test opt_COMMA
	;
pick_for_test // Used in: dictorsetmaker
	: comp_for
	| star_COMMA_test opt_COMMA
	;
classdef // Used in: decorated, compound_stmt
        : CLASS NAME LPAR opt_testlist RPAR COLON suite
	{ deleteName($2); }
	| CLASS NAME COLON suite
        { deleteName($2); }
	;
opt_testlist // Used in: classdef
	: testlist
	| %empty
	;
arglist // Used in: opt_arglist
	: star_argument_COMMA pick_argument
        { 
          $$ = $1;
          $$->push_back($2);
          printDebugMsg("star_argument_COMMA pick_argument -> arglist");
        }
	;
star_argument_COMMA // Used in: arglist, star_argument_COMMA
	: star_argument_COMMA argument COMMA
        {
          $$ = $1;
          $$->push_back($2);
          printDebugMsg("star_argument_COMMA argument COMMA -> star_argument_COMMA");
        }
	| %empty
        {
	  $$ = new std::vector<Node*>();
	  $$->reserve(4);
          printDebugMsg(" -> star_argument_COMMA");
        }
	;
star_COMMA_argument // Used in: star_COMMA_argument, pick_argument
	: star_COMMA_argument COMMA argument
        {
          printDebugMsg("star_COMMA_argument COMMA argument -> star_COMMA_argument");
        }
	| %empty
        {
          printDebugMsg(" -> star_COMMA_argument");
        }
	;
opt_DOUBLESTAR_test // Used in: pick_argument
	: COMMA DOUBLESTAR test
	| %empty
	;
pick_argument // Used in: arglist
	: argument opt_COMMA
        {
          $$ = $1;
          printDebugMsg("argument opt_COMMA -> pick_argument");
        }
	| STAR test star_COMMA_argument opt_DOUBLESTAR_test
        {
          $$ = nullptr;
          printDebugMsg("STAR test star_COMMA_argument opt_DOUBLESTAR_test -> pick_argument");
        }
	| DOUBLESTAR test
        {
          $$ = nullptr;
          printDebugMsg("DOUBLESTAR test -> pick_argument");
        }
	;
argument // Used in: star_argument_COMMA, star_COMMA_argument, pick_argument
	: test opt_comp_for
        {
          $$ = $1;
          printDebugMsg("test opt_comp_for -> argument");
        }
	| test EQUAL test
        {
          printDebugMsg("test EQUAL test -> argument");
        }
	;
opt_comp_for // Used in: argument
	: comp_for
        {
          printDebugMsg("comp_for -> opt_comp_for");
        }
	| %empty
        {
          printDebugMsg(" -> opt_comp_for");
        }
	;
list_iter // Used in: list_for, list_if
	: list_for
	| list_if
	;
list_for // Used in: listmaker, list_iter
	: FOR exprlist IN testlist_safe list_iter
	| FOR exprlist IN testlist_safe
	;
list_if // Used in: list_iter
	: IF old_test list_iter
	| IF old_test
	;
comp_iter // Used in: comp_for, comp_if
	: comp_for
	| comp_if
	;
comp_for // Used in: testlist_comp, pick_for_test_test, pick_for_test, opt_comp_for, comp_iter
	: FOR exprlist IN or_test comp_iter
        {
          printDebugMsg("FOR exprlist IN or_test comp_iter -> comp_for");
        }
	| FOR exprlist IN or_test
        {
          printDebugMsg("FOR exprlist IN or_test -> comp_for");
        }
	;
comp_if // Used in: comp_iter
	: IF old_test comp_iter
	| IF old_test
	;
testlist1 // Used in: atom, testlist1
	: test
	| testlist1 COMMA test
	;
yield_expr // Used in: pick_yield_expr_testlist, yield_stmt, pick_yield_expr_testlist_comp
	: YIELD testlist
	{ printDebugMsg("YIELD testlist -> yield_expr"); }
	| YIELD
        { printDebugMsg("YIELD -> yield_expr"); }
	;
star_DOT // Used in: pick_dotted_name, star_DOT
	: star_DOT DOT
	| %empty
	;
%%

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
  if (name != nullptr) {
    delete [] name;
    name = nullptr;
  }
}

void printDebugMsg(const char *msg) {
  if (myDebug)
     std::cout << msg << std::endl;
}

void printDebugMsg(const std::string& msg) {
  if (myDebug)
     std::cout << msg << std::endl;
}
