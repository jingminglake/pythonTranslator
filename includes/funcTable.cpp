#include <map>
#include <algorithm>
#include "funcTable.h"
#include "node.h"

const Node* FuncTable::getValue(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = table.find(name);
  // if ( it == table.end() ) throw name+std::string(" not found");
  if ( it == table.end() )
      return nullptr;
  return it->second;
}

void FuncTable::setValue(const std::string& name, const Node* val) { 
  table[name] = val;
}
