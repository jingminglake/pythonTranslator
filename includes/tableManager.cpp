#include "tableManager.h"

TableManager& TableManager::getInstance() {
   static TableManager instance;
   return instance;
}

const Node* TableManager::getEntry(const std::string& name) {
    int tempScope = currentScope;
    while (tempScope >= 0) {
        const Node* n = tables[tempScope]->getValue(name);
        if (n) {
            return n;
        } else {
            tempScope--;
        }
    }
    throw name + std::string(" not found");
}

void TableManager::setEntry(const std::string& name, Node* node) {
    tables[currentScope]->setValue(name, node);
}

void TableManager::insertFunc(const std::string& name, Node* node) {
    SymbolTable *temp = new SymbolTable();
    temp->setValue(name, node);
    tables.push_back(new SymbolTable());
    funcSuiteTables.insert(funcSuiteTables.begin()+1, temp);
}

bool TableManager::checkName(const std::string& name) const {
    const Node* n = funcSuiteTables[currentScope]->getValue(name);
    return n ? true : false;
}

void TableManager::pushScope() {
    currentScope++;
}

void TableManager::popScope() {
    currentScope--;
}

const Node* TableManager::getSuite(const std::string& name) {
    return funcSuiteTables[currentScope]->getValue(name);
}
