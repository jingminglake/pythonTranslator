#include "tableManager.h"

TableManager& TableManager::getInstance() {
   static TableManager instance;
   return instance;
}

const Literal* TableManager::getEntry(const std::string& name) {
    int tempScope = currentScope;
    while (tempScope >= 0) {
        const Literal* val = tables[tempScope]->getValue(name);
        if (val) {
            return val;
        } else {
            tempScope--;
        }
    }
    throw std::string("'") +  name  + std::string("'") + std::string(" is not defined");
}

void TableManager::setEntry(const std::string& name, const Literal* val) {
    tables[currentScope]->setValue(name, val);
}

void TableManager::insertFunc(const std::string& name, Node* node) {
    FuncTable *temp = new FuncTable();
    temp->setValue(name, node);
    tables.push_back(new SymbolTable());
    funcTables.insert(funcTables.begin()+1, temp);
}

bool TableManager::checkName(const std::string& name) const {
    const Node* n = funcTables[currentScope]->getValue(name);
    return n ? true : false;
}

void TableManager::pushScope() {
    currentScope++;
}

void TableManager::popScope() {
    currentScope--;
}

const Node* TableManager::getSuite(const std::string& name) {
    return funcTables[currentScope]->getValue(name);
}
