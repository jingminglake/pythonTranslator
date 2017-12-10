#include <map>
#include <algorithm>
#include "funcScope.h"
#include "node.h"
#include "poolOfNodes.h"

class SuiteNode;

FuncScope::~FuncScope() {
    delete table;
    for (auto& func: funcs)
      delete func->second;
    funcs.clear();
}

const std::string getFuncName() const {
  return funcName;
}

const Node* FuncScope::getEntry(const std::string& name) {
  if (checkName(name))
    return table[name];
  else if (!parentFuncScope)
    throw std::out_of_range(name);
  else 
    return parentFuncScope->getEntry();
}

void FuncScope::setEntry(const std::string& name, const Node* val) {
    tables->setValue(name, val);
    if ( dynamic_cast<SuiteNode*>(val) ) { // if val is a suiteNode, then we should create its FuncScope
      FuncScope *newFunc = new FuncScope(name, this);
      PoolOfNodes::getInstance().addFuncScopeNode(newFunc);
      //newFunc->setParentFuncScope(this);
      std::unordered_map<std::string, FuncTable*>::iterator = func.find(name); 
      if (it != funcs.end()) { // if it contains same name func, then should be override
	//delete it->second; // remove the old one
          it->second = newFunc; // create a new one
	}
      }
      // if it not contains same name func, create a new one directly
      funcs.insert(make_pair(name, newFunc));
    }
}

void FuncScope::removeEntry(const std::string& name) {
    table->removeValue(name);
}

bool FuncScope::isLocalVariable(const std::string& name) const {
  return table->getValue(name) ? true : false;
}

const Node* FuncScope::getSuite(const std::string& funcName) {
  return table[funcName];
}

FuncScope* FuncScope::getFuncScope(const std::string& name) {
  if( !checkName(name) )
    throw std::string("something wrong in getFuncScope: ") + name;
  if ( dynamic_cast<SuiteNode*>(table[name]))
    throw std::string("TypeError: object '") + name + std::string("' is not callable");
  for (auto& func : funcs) {
    if (func.first == name)
      return func.second;
  }
  throw std::string("ss wrong in getFuncScope: ") + name;
}
