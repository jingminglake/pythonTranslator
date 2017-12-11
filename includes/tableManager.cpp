#include "tableManager.h"
#include "poolOfNodes.h"
#include "funcScope.h"

TableManager& TableManager::getInstance() {
   static TableManager instance;
   return instance;
}

TableManager::TableManager() : currentFuncScope( new FuncScope("__MAIN__") ), returnFlag(false), funcCallStack() {
  PoolOfNodes::getInstance().addFuncScopeNode(currentFuncScope);
}

bool TableManager::getReturnFlag() {
    return returnFlag;
}

void TableManager::setReturnFlag(bool flag) {
    returnFlag = flag;
}

void TableManager::pushScope(const std::string& funcName) {
  // recursion need not change Scope
  if (funcName == currentFuncScope->getFuncName())
    return;
  // check if it is predefined in the current scope
  if (currentFuncScope->isLocalVariable(funcName))
    funcCallStack.push(currentFuncScope);
    currentFuncScope = currentFuncScope->getFuncScope(funcName);
}

void TableManager::popScope() {
  if (!funcCallStack.empty()) {
    currentFuncScope = funcCallStack.top();
    funcCallStack.pop();
  }
}

FuncScope* TableManager::getCurrentFuncScope() {
  return currentFuncScope;
}
