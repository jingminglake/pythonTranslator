CCC = clang++
LEX = flex
YACC = bison
CFLAGS = -g -Wall -std=c++11 -W -Weffc++ -Wextra -pedantic -O0
LEXFLAGS = -Wno-unused -Wno-sign-compare -Wno-deprecated-register

#LEXDEBUG = -d
LEXDEBUG =
YACCDEBUG = -vtd

OBJS = main.o parse.tab.o lex.yy.o ast.o literal.o symbolTable.o funcScope.o poolOfNodes.o tableManager.o

run: $(OBJS)
	$(CCC) $(CFLAGS) -o run $(OBJS)

main.o: main.cpp parse.y scan.l parse.tab.c lex.yy.c
	$(CCC) $(CFLAGS) -c main.cpp

parse.tab.c: parse.y includes/ast.h includes/literal.h
	$(YACC) $(YACCDEBUG) parse.y

parse.tab.o: parse.tab.c
	$(CCC) $(CFLAGS) -c parse.tab.c

lex.yy.c: scan.l parse.tab.o
	$(LEX) $(LEXDEBUG) scan.l

lex.yy.o: lex.yy.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c

ast.o: includes/ast.cpp includes/ast.h includes/literal.h
	$(CCC) $(CFLAGS) -c includes/ast.cpp

literal.o: includes/literal.h includes/literal.cpp
	$(CCC) $(CFLAGS) -c includes/literal.cpp

symbolTable.o: includes/symbolTable.cpp includes/symbolTable.h includes/ast.h
	$(CCC) $(CFLAGS) -c includes/symbolTable.cpp

funcScope.o: includes/funcScope.cpp includes/funcScope.h includes/ast.h
	$(CCC) $(CFLAGS) -c includes/funcScope.cpp

poolOfNodes.o: includes/poolOfNodes.cpp includes/poolOfNodes.h \
        includes/node.h
	$(CCC) $(CFLAGS) -c includes/poolOfNodes.cpp

tableManager.o: includes/tableManager.h includes/tableManager.cpp symbolTable.o
	$(CCC) $(CFLAGS) -c includes/tableManager.cpp

clean:
	rm -f run *.o parse.tab.c lex.yy.c
	rm -f parse.tab.h
	rm -f parse.output
	rm -f cases/*.out
	rm -f *.*~
	rm -f *~
	rm -f cases/*.*~
