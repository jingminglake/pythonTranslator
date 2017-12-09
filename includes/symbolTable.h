#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Node;

class SymbolTable {
public:
  SymbolTable() : table() {}
  ~SymbolTable() {
      table.clear();
  }
  void setValue(const std::string& name, const Node* val);
  const Node* getValue(const std::string& name) const;
  void removeValue(const std::string& name);
private:
  std::map<std::string, const Node*> table;
};

#endif
