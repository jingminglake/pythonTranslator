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

bool FuncTable::checkName(const std::string& name, int currentScope) const {
    while (currentScope >= 0) {
        const Node* val = tables[currentScope]->getValue(name);
        if (val) {
            return true;
        } else {
            currentScope--;
        }
    }
    return false;
}

bool FuncTable::checkVariable(const std::string& name) const {
    const Literal* val = tables[currentScope]->getValue(name);
    return val ? true : false;
}

void FuncTable::insertFunc(const std::string& name, Node* node) {
    Symboltable * st = new SymbolTable();
    st.setValue(name, node);
    tables.push_back(st);
}

const Node* FuncTable::getSuite(int currentScope) {
  if(currentScope > tables)
    throw std::out_of_range(currentScope);
  return tables[currentScope];
}
