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
    throw std::out_of_range(name);
}

void TableManager::removeEntry(const std::string& name) {
    tables[currentScope]->removeValue(name);
}

void TableManager::setEntry(const std::string& name, const Literal* val) {
    tables[currentScope]->setValue(name, val);
}

void TableManager::insertFunc(const std::string& name, Node* node) { 
    if (currentScope == (int)tables.size()) {
	tables.push_back(new SymbolTable());
	funcTables.push_back(new FuncTable());
    }
    funcTables[currentScope]->setValue(name, node);
}

bool TableManager::checkName(const std::string& name) const {
    int tempScope = currentScope;
    while (tempScope >= 0) {
        //std::cout << "----------CallNode::eval()-22------------" << tempScope << std::endl;
        const Node* val = funcTables[tempScope]->getValue(name);
        if (val) {
            return true;
        } else {
            tempScope--;
        }
    }
    return false;
}

bool TableManager::checkVariable(const std::string& name) const {
    const Literal* val = tables[currentScope]->getValue(name);
    return val ? true : false;
}

void TableManager::pushScope() {
    currentScope++;
}

void TableManager::popScope() {
    /* if (tables.empty() || funcTables.empty())
	return;
    SymbolTable* st = tables.back();
    delete st;
    tables.pop_back();
    FuncTable* ft = funcTables.back();
    delete ft;
    funcTables.pop_back(); */
    currentScope--;
}

bool TableManager::getReturnFlag() {
    return returnFlag;
}

void TableManager::setReturnFlag(bool flag) {
    returnFlag = flag;
}

const Node* TableManager::getSuite(const std::string& name) {
    int tempScope = currentScope;
    while (tempScope >= 1) {
        const Node* val = funcTables[tempScope]->getValue(name);
        if (val) {
            return val;
        } else {
            tempScope--;
        }
    }
    throw std::out_of_range(name);
}
