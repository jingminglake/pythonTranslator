#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include "symbolTable.h"
#include "funcScope.h"

class TableManager {
 public:
    static TableManager& getInstance();
    void setCurrentFuncTable(const std::string& name);
    bool getReturnFlag();
    void setReturnFlag(bool);
    void pushScope();
    void popScope();
    FuncScope* getCurrentFuncScope();
 private:
    FuncScope* currentFuncScope;
    bool returnFlag;
    SymbolTable* table; // global variables -->node && global funcs --> suiteNode
    std::unordered_map<const string&, FuncTable*> globalFuncs;  // global funcs's symbolTables
    std::stack<FuncScope* > funcCallStack;
 TableManager() : currentFuncScope( new FuncScope("__MAIN__") ), returnFlag(false), table( new SymbolTable() ), globalFuncs() {}
    ~TableManager() {
       delete table;
       for(auto it = globalFuncs.begin(); it != globalFuncs.end(); ++it)
 	 delete it->second;
       globalFuncs.clear();
    }
};

#endif
