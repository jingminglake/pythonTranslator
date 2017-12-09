#include <map>
#include <algorithm>
#include "funcTable.h"
#include "node.h"

FuncTable::~FuncTable() {
    for (SymbolTable *t : tables)
      delete t;
    tables.clear();
    for (FuncTable *t : funcTables)
      delete t;
    funcTables.clear();
}

const Literal* FuncTable::getEntry(const std::string& name) {
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

void FuncTable::setEntry(const std::string& name, const Literal* val) {
    tables[currentScope]->setValue(name, val);
}

void FuncTable::removeEntry(const std::string& name) {
    tables[currentScope]->removeValue(name);
}

bool FuncTable::checkName(const std::string& name) const {
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

void FuncTable::pushScope() {
    currentScope++;
}

void FuncTable::popScope() {
    currentScope--;
}

bool FuncTable::checkVariable(const std::string& name) const {
    const Literal* val = tables[currentScope]->getValue(name);
    return val ? true : false;
}

void FuncTable::insertFunc(const std::string& name, Node* node) { 
    if (currentScope == (int)tables.size()) {
	tables.push_back(new SymbolTable());
	funcTables.push_back(new FuncTable());
    }
    funcTables[currentScope]->setValue(name, node);
}

const Node* FuncTable::getSuite(const std::string& name) {
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
