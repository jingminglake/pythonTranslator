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
    void setEntry(const std::string& name, const Node* val);
    const Node* getEntry(const std::string& name);
    void removeEntry(const std::string& name);
    bool checkName(const std::string& name) const;
    void setCurrentFuncTable(const std::string& name);
    FuncTable* getCurrentFuncTable();
    bool getReturnFlag();
    void setReturnFlag(bool);
    void pushScope();
    void popScope();
    int getCurrentScope();
 private:
    int currentScope;
    bool returnFlag;
    SymbolTable* table; // global variables -->node && global funcs --> suiteNode
    std::unordered_map<const string&, FuncTable*> globalFuncs;  // global funcs's symbolTables
    TableManager() : currentScope(0), returnFlag(false), table(new SymbolTable()), globalFuncs() {}
    ~TableManager() {
       delete table;
       for(auto it = globalFuncs.begin(); it != globalFuncs.end(); ++it)
 	 delete it->second;
       globalFuncs.clear();
    }
};

#endif
