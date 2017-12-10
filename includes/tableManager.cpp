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

void TableManager::pushScope() {
    currentScope++;
}

void TableManager::popScope() {
    currentScope--;
}

void TableManager::setCurrentFuncTable(const std::string& funcName) {
    if (!tm.checkName(funcName)) {
      std::cout << "global function " << funcName << " not found" << std::endl;
      std::exception up = std::exception();
      throw up;
    }
    currentFunc = globalFuncs[funcName];
}
