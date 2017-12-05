#ifndef FUNCTABLE__H
#define FUNCTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Node;

class FuncTable {
public:
  FuncTable() : table() {}
  ~FuncTable() {
      table.clear();
  }
  void setValue(const std::string& name, const Node* val);
  const Node* getValue(const std::string& name) const;
private:
  std::map<std::string, const Node*> table;
};

#endif
