#include <map>
#include <algorithm>
#include "funcScope.h"
#include "node.h"
#include "poolOfNodes.h"
#include "ast.h"

FuncScope::FuncScope(FuncScope* rhs) {
  funcName = rhs->funcName;
  //table = rhs.table;
  parentFuncScope = rhs->parentFuncScope;
  table = new SymbolTable();
  funcs = rhs->funcs;
  globalVars = rhs->globalVars;
}

FuncScope::~FuncScope() {
    delete table;
    funcs.clear();
}

const std::string FuncScope::getFuncName() const {
  return funcName;
}

const Node* FuncScope::getEntry(const std::string& name) {
  if (isLocalVariable(name))
    return table->getValue(name);
  else if (!parentFuncScope)
    throw std::out_of_range(name);
  else {
    if (globalVars.count(name) == 0)
      globalVars.insert(make_pair(name, false));
    return parentFuncScope->getEntry(name);
  }
}

void FuncScope::setGlobalEntry(const std::string& name, const Node* val) {
  if (isLocalVariable(name))
    return table->setValue(name, val);
  else if (!parentFuncScope)
    throw std::out_of_range(name);
  else 
    return parentFuncScope->setGlobalEntry(name, val);
}

void FuncScope::setGlobalVars(const std::string& varName, bool ref) {
  globalVars[varName] = ref;
}

void FuncScope::setEntry(const std::string& name, const Node* val) {
  if (globalVars.count(name) > 0 && globalVars[name]) { // is Global && referenced
    setGlobalEntry(name, val);
    return;
  }
  table->setValue(name, val);
  if ( dynamic_cast<const FuncDefNode*>(val) ) { // if val is a FuncDefNode, then we should create its FuncScope
    FuncScope *newFuncS = new FuncScope(name, this);
    PoolOfNodes::getInstance().addFuncScopeNode(newFuncS);
    //newFunc->setParentFuncScope(this);
    std::unordered_map<std::string, FuncScope*>::iterator it = funcs.find(name);
    //std::cout << "funcs.find(name)----> before " << name << " in " << funcName << std::endl;
    if (it != funcs.end()) { // if it contains same name func, then should be overrided
      //delete it->second; // remove the old one
      it->second = newFuncS; // create a new one
    } else { // if it not contains same name func, create a new one directly
      funcs.insert(make_pair(name, newFuncS));
    }
  }
}

void FuncScope::removeEntry(const std::string& name) {
    table->removeValue(name);
}

bool FuncScope::isLocalVariable(const std::string& name) const {
  return ( table->getValue(name) )? true : false;
}

bool FuncScope::isOnlyReadableGlobalVariable(const std::string& name) {
  return ( globalVars.count(name) > 0 && !globalVars[name] ) ? true : false;
}

const Node* FuncScope::getFuncDefNode(const std::string& funcName) {
  return table->getValue(funcName);
}

FuncScope* FuncScope::getFuncScope(const std::string& name) {
  if( !isLocalVariable(name) )
    throw std::string("something wrong in getFuncScope: ") + name;
  if ( !dynamic_cast<const FuncDefNode*>( table->getValue(name) ) )
    throw std::string("TypeError: object '") + name + std::string("' is not callable");
  for (auto& func : funcs) {
    if (func.first == name)
      return func.second;
  }
  throw std::string("ss wrong in getFuncScope: ") + name;
}

void  FuncScope::setParentFuncScope(FuncScope *parentFuncS) {
  parentFuncScope = parentFuncS;
}

FuncScope * FuncScope::getParentFuncScope() {
  return parentFuncScope;
}
