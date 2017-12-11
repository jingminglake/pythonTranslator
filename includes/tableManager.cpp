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
  if (funcName == currentFuncScope->getFuncName())  // recursion 
    return; // recursion need not change Scope
  funcCallStack.push(currentFuncScope);
  // check if it is predefined in the current scope
  if (currentFuncScope->isLocalVariable(funcName)) {
    currentFuncScope = currentFuncScope->getFuncScope(funcName);
  } else {
    FuncScope *parentFuncS = currentFuncScope->getParentFuncScope();
    //std::cout << "---------parentFuncS->getFuncName()-----------" << parentFuncS->getFuncName() << std::endl;
    while (parentFuncS) {
      if ( parentFuncS->isLocalVariable(funcName) ) {
        currentFuncScope = parentFuncS->getFuncScope(funcName);
	return;
      }
      parentFuncS = parentFuncS->getParentFuncScope();
    }
    throw std::string("function '") + funcName + std::string("' is not defined");
  }
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
