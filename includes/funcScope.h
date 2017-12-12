#ifndef FUNCSCOPE__H
#define FUNCSCOPE__H

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "symbolTable.h"

class Node;

class FuncScope {
public:
  FuncScope() : scope(0), funcName(), parentFuncScope(nullptr), table(new SymbolTable()), funcs(){}
  FuncScope(const std::string& name) : scope(0), funcName(name), parentFuncScope(nullptr), table(new SymbolTable()), funcs(){}
  FuncScope(const std::string& name, FuncScope* funcS) : scope(0), funcName(name), parentFuncScope(funcS), table(new SymbolTable()), funcs(){}
  ~FuncScope();
  const std::string getFuncName() const;
  const Node* getEntry(const std::string& name);
  void setEntry(const std::string& name, const Node* val);
  void removeEntry(const std::string& name);
  bool isLocalVariable(const std::string& name) const;
  const Node* getFuncDefNode(const std::string& funcName);
  int setCurrentScope(int scope);
  FuncScope* getFuncScope(const std::string& name);
  void setParentFuncScope(FuncScope *parentFuncS);
  FuncScope *getParentFuncScope();
private:
  int scope;
  std::string funcName;
  FuncScope *parentFuncScope;
  SymbolTable* table;   // fun's local variables --> value  && fun's local subFuncs --> suiteNode
  std::unordered_map<std::string, FuncScope*> funcs; // fun's local subFuncs --> its FuncScope
};

#endif
