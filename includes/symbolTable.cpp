#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "node.h"

const Node* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = table.find(name);
  // if ( it == table.end() ) throw name+std::string(" not found");
  if ( it == table.end() )
      return NULL;
  return it->second;
}

void SymbolTable::setValue(const std::string& name, const Node* val) { 
    //std::pair<std::string, const Literal*> temp(name, val);
  table[name] = val;
}
