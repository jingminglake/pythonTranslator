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
  FuncTable() : table(), funcTables, currentScope(0){}
  ~FuncTable();
  const Node* getEntry(const std::string& name);
  void setEntry(const std::string& name, const Node* val);
  void removeEntry(const std::string& name);
  bool checkName(const std::string& name) const;
  void insertFunc(const std::string& name, const Node* node);
  void pushScope();
  void popScope();
  int getCurrentScope();
private:
  int currentScope;
  std::vector<SymbolTable*> tables;   // fun's local variables --> value
};

#endif
