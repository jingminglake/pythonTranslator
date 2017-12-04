#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <vector>
#include "symbolTable.h"

class TableManager {
 public:
    static TableManager& getInstance();
    const Node* getEntry(const std::string& name);
    void setEntry(const std::string& name, Node* node);
    void insertFunc(const std::string& name, Node* node);
    bool checkName(const std::string& name) const;

    void pushScope();
    void popScope();
    const Node* getSuite(const std::string& name);
 private:
    int currentScope;
    std::vector<SymbolTable*> tables;
    std::vector<SymbolTable*> funcSuiteTables;  // funcName --> suiteNode
    TableManager() : currentScope(0), tables() {
        tables.push_back(new SymbolTable());
        funcSuiteTables.push_back(NULL);
    }
    ~TableManager() {
        for (SymbolTable *t : tables)
            delete t;
        tables.clear();
    }
};

#endif
