#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"

const Node* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = table.find(name);
  // if ( it == table.end() ) throw name+std::string(" not found");
  if ( it == table.end() )
      return NULL;
  return it->second;
}

void SymbolTable::setValue(const std::string& name, const Node* val) { 
  table[name] = val;
}

void SymbolTable::removeValue(const std::string& name) {
    auto it = table.find(name);
    table.erase(it);
}
