#include <map>
#include <algorithm>
#include "funcScope.h"
#include "node.h"

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
    tables[currentScope]->setValue(name, val);
    if ( dynamic_cast<SuiteNode*>(val) ) { // if val is a suiteNode, then we should create its FuncScope
      FuncScope *newFunc = new FuncScope(name, this);
      newFunc->setParentFuncScope(this);
      for (auto& func : funcs) { // if it contains same name func, then should be override
	if (func.first == name) {
	  delete func.second; // remove the old one
          func.second = newFunc; // create a new one
	}
      }
      // if it not contains same name func, create a new one directly
      funcs.push_back(make_pair(name, newFunc));
    }
}

void FuncScope::removeEntry(const std::string& name) {
    tables[currentScope]->removeValue(name);
}

bool FuncScope::checkName(const std::string& name) const {
  /* while (currentScope >= 0) {
        const Node* val = tables[currentScope]->getValue(name);
        if (val) {
            return true;
        } else {
            currentScope--;
        }
    }
    return false; */
  table->checkName(name);
}

bool FuncScope::checkVariable(const std::string& name) const {
    const Literal* val = tables[currentScope]->getValue(name);
    return val ? true : false;
}

void FuncScope::insertFunc(const std::string& name, Node* node) {
    Symboltable * st = new SymbolTable();
    st.setValue(name, node);
    tables.push_back(st);
}

const Node* FuncScope::getSuite(int currentScope) {
  if(currentScope > tables)
    throw std::out_of_range(currentScope);
  return tables[currentScope];
}

FuncScope* FuncScope::getFuncScope(const std::string& name) {
  if(!checkName(name))
    throw std::string("something wrong in getFuncScope: ") + name;
  if ( dynamic_cast<SuiteNode*>(table[name]))
    throw std::string("TypeError: object '") + name + std::string("' is not callable");
  for (auto& func : funcs) {
    if (func.first == name)
      return func.second;
  }
  throw std::string("ss wrong in getFuncScope: ") + name;
}
