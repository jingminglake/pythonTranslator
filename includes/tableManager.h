#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "symbolTable.h"
#include "funcTable.h"

class TableManager {
 public:
    static TableManager& getInstance();
    void insertFunc(const std::string& name, Node* node);
    void removeEntry(const std::string& name);
    bool checkName(const std::string& name) const;
    FuncTable* getFuncTable(const std::string& name);
    bool getReturnFlag();
    void setReturnFlag(bool);
    void pushScope();
    void popScope();
    int getCurrentScope();
 private:
    int currentScope;
    bool returnFlag;
    SymbolTable* table; // global variables
    std::unordered_map<const string& funcName, FuncTable*> globalFuncs;  // global funcs
    TableManager() : currentScope(0), returnFlag(false), table(new SymbolTable()), globalFuncs() {}
    ~TableManager() {
       delete table;
       for(auto it = globalFuncs.begin(); it != globalFuncs.end(); ++it)
 	 delete it->second;
       globalFuncs.clear();
    }
};

#endif
