#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <vector>
#include "symbolTable.h"
#include "funcTable.h"

class TableManager {
 public:
    static TableManager& getInstance();
    const Literal* getEntry(const std::string& name);
    void setEntry(const std::string& name, const Literal* val);
    void insertFunc(const std::string& name, Node* node);
    bool checkName(const std::string& name) const;
    bool checkVariable(const std::string& name) const;

    void pushScope();
    void popScope();
    const Node* getSuite(const std::string& name);
 private:
    int currentScope;
    std::vector<SymbolTable*> tables;
    std::vector<FuncTable*> funcTables;  // funcName --> its suite Node
    TableManager() : currentScope(0), tables() {
        tables.push_back(new SymbolTable());
        funcTables.push_back(NULL);
    }
    ~TableManager() {
        for (SymbolTable *t : tables)
            delete t;
        tables.clear();
	for (FuncTable *t : funcTables)
            delete t;
        funcTables.clear();
    }
};

#endif
