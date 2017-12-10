#ifndef FUNCTABLE__H
#define FUNCTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "symbolTable.h"

class Node;

class FuncTable {
public:
 FuncTable() : currentScope(0), table(){}
  ~FuncTable();
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
  std::unordered_map<const string&, FuncTable*> funcs;
};

#endif
