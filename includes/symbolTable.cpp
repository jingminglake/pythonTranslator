#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"

void SymbolTable::setValue(const std::string& name, const Node* val) { 
  table[name] = val;
}

const Node* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = table.find(name);
  // if ( it == table.end() ) throw name+std::string(" not found");
  if ( it == table.end() )
      return nullptr;
  return it->second;
}

void SymbolTable::removeValue(const std::string& name) {
  auto it = table.find(name);
  table.erase(it);
}
