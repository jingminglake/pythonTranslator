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
 FuncScope() : funcName(), parentFuncScope(nullptr), table(new SymbolTable()), funcs(), globalVars(){}
 FuncScope(const std::string& name) : funcName(name), parentFuncScope(nullptr), table(new SymbolTable()), funcs(), globalVars() {}
 FuncScope(const std::string& name, FuncScope* funcS) : funcName(name), parentFuncScope(funcS), table(new SymbolTable()), funcs(), globalVars() {}
  FuncScope(FuncScope*);
  ~FuncScope();
  const std::string getFuncName() const;
  const Node* getEntry(const std::string& name);
  void setEntry(const std::string& name, const Node* val);
  void setGlobalEntry(const std::string& name, const Node* val);
  void setGlobalVars(const std::string&, bool);
  void removeEntry(const std::string& name);
  bool isLocalVariable(const std::string& name) const;
  bool isOnlyReadableGlobalVariable(const std::string& name);
  bool isGlobalVariable(const std::string& name) const;
  const Node* getFuncDefNode(const std::string& funcName);
  FuncScope* getFuncScope(const std::string& name);
  void setParentFuncScope(FuncScope *parentFuncS);
  FuncScope *getParentFuncScope();
private:
  std::string funcName;
  FuncScope *parentFuncScope;
  SymbolTable* table;   // fun's local variables --> value  && fun's local subFuncs --> suiteNode
  std::unordered_map<std::string, FuncScope*> funcs; // fun's local subFuncs --> its FuncScope
  std::unordered_map<std::string, bool> globalVars; // global variables, true --> can be modified; false --> could not modified
};

#endif
