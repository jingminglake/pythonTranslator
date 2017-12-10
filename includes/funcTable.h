#ifndef FUNCSCOPE__H
#define FUNCSCOPE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "symbolTable.h"

class Node;

class FuncScope {
public:
 FuncScope() : currentScope(0), table(){}
  ~FuncScope();
  const Node* getEntry(const std::string& name);
  void setEntry(const std::string& name, const Node* val);
  void removeEntry(const std::string& name);
  bool checkName(const std::string& name) const;
  void insertFunc(const std::string& name, const Node* node);
  const Node* getSuite();
  int setCurrentScope(int scope);
private:
  int scope;
  SymbolTable* table;   // fun's local variables --> value
  vector<pair<const string&, FuncTable*> > funcs;
};

#endif
