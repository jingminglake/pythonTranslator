#include "tableManager.h"

TableManager& TableManager::getInstance() {
   static TableManager instance;
   return instance;
}

bool TableManager::getReturnFlag() {
    return returnFlag;
}

void TableManager::setReturnFlag(bool flag) {
    returnFlag = flag;
}

void TableManager::pushScope(const std::string& funcName) {
  // recursion need not change Scope
  if (funcName = currentFuncScope->getFuncName())
    return;
  // check if it is predefined in the current scope
  if (currentFuncScope->checkName(funcName))
    funcCallStack.push(currentFuncScope);
    currentFuncScope = currentFuncScope->getFuncScope(funcName);
}

void TableManager::popScope() {
  if (!funcCallStack.empty()) {
    currentFuncScope = funcCallStack.top();
    funcCallStack.pop();
  }
}

void TableManager::setCurrentFuncTable(const std::string& funcName) {
    if (!tm.checkName(funcName)) {
      std::cout << "global function " << funcName << " not found" << std::endl;
      std::exception up = std::exception();
      throw up;
    }
    currentFunc = globalFuncs[funcName];
}

FuncScope* TableManager::getCurrentFuncScope() {
  return currentFuncScope;
}
