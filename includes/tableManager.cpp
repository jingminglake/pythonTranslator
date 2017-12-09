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
