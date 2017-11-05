#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

void freeAST(Node* node) {
  if ( node ) {
    BinaryNode* temp = dynamic_cast<BinaryNode*>(node);
    if ( temp ) {
      freeAST(temp->getLeft());
      freeAST(temp->getRight());
    }
    delete node;
  }
}

const Literal* IdentNode::eval() const { 
  const Literal* val = SymbolTable::getInstance().getValue(ident);
  return val;
}

const Literal* MinusUnaryNode::eval() const {
    const Literal* res = node->eval();
    return res->opMin();
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}


const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

PlusasgBinaryNode::PlusasgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = *oldValue + *augVal;
  SymbolTable::getInstance().setValue(n, res);
  //std::cout << "-=-=-=-1=-=-=-=-=--" << std::endl;
  //SymbolTable::getInstance().getValue(n)->eval()->print();
  //res->eval()->print();
}

const Literal* PlusasgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = *oldValue + *augVal;
  //std::cout << "-=-=-=-2=-=-=-=-=--" << std::endl;
  SymbolTable::getInstance().setValue(n, res);
  //SymbolTable::getInstance().getValue(n)->eval()->print();
  //res->eval()->print();
  return res;
}

MinasgBinaryNode::MinasgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = *oldValue - *augVal;
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* MinasgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = *oldValue - *augVal;
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

StarasgBinaryNode::StarasgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = (*oldValue) * (*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* StarasgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = (*oldValue) * (*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

SlashasgBinaryNode::SlashasgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = (*oldValue) / (*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* SlashasgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = (*oldValue) / (*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

DoubleStartasgBinaryNode::DoubleStartasgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = oldValue->opPower(*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* DoubleStartasgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = oldValue->opPower(*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

PercentStartasgBinaryNode::PercentStartasgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = (*oldValue) % (*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* PercentStartasgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = (*oldValue) % (*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x+*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* ModBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* PowBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return x->opPower(*y);
}
