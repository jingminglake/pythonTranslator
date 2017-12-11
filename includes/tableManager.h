#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class FuncScope;

class TableManager {
 public:
    static TableManager& getInstance();
    bool getReturnFlag();
    void setReturnFlag(bool);
    void pushScope(const std::string& funcName);
    void popScope();
    FuncScope* getCurrentFuncScope();
 private:
    FuncScope* currentFuncScope;
    bool returnFlag;
    std::stack<FuncScope* > funcCallStack;
    TableManager();
    ~TableManager(){};
};

#endif
