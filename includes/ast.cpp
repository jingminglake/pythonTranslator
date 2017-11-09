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

const Literal* TildeUnaryNode::eval() const {
    const Literal* temp = node->eval();
    const Literal* res = nullptr;
    try {
      res = ~(*temp);
    } catch(const std::string& msg) {
      std::cout << msg << std::endl;
    }
    return res;
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
  //SymbolTable::getInstance().getValue(n)->eval()->print();
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

PlusAsgBinaryNode::PlusAsgBinaryNode(Node* left, Node* right) : 
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

const Literal* PlusAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = *oldValue + *augVal;
  //std::cout << "-=-=-=-2=-=-=-=-=--" << std::endl;
  SymbolTable::getInstance().setValue(n, res);
  //SymbolTable::getInstance().getValue(n)->eval()->print();
  //res->eval()->print();
  return res;
}

MinAsgBinaryNode::MinAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = *oldValue - *augVal;
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* MinAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = *oldValue - *augVal;
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

StarAsgBinaryNode::StarAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue) * (*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* StarAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = (*oldValue) * (*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

SlashAsgBinaryNode::SlashAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue) / (*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* SlashAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = (*oldValue) / (*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

DoubleSlashAsgBinaryNode::DoubleSlashAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue).opDoubleDiv(*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* DoubleSlashAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = (*oldValue).opDoubleDiv(*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

DoubleStarAsgBinaryNode::DoubleStarAsgBinaryNode(Node* left, Node* right) : 
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

const Literal* DoubleStarAsgBinaryNode::eval() const { 
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

PercentAsgBinaryNode::PercentAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue) % (*augVal);
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* PercentAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = (*oldValue) % (*augVal);
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

LShiftAsgBinaryNode::LShiftAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) << (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* LShiftAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) << (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

RShiftAsgBinaryNode::RShiftAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) >> (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* RShiftAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) >> (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

AmperAsgBinaryNode::AmperAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) & (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* AmperAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) & (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

VBarAsgBinaryNode::VBarAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) | (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* VBarAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) | (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

CircumflexAsgBinaryNode::CircumflexAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
      oldValue = SymbolTable::getInstance().getValue(n);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) ^ (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  SymbolTable::getInstance().setValue(n, res);
}

const Literal* CircumflexAsgBinaryNode::eval() const { 
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
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) ^ (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
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
  const Literal* res = nullptr;
  try {
    res = ((*x)/(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}

const Literal* FloorDivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = nullptr;
  try {
    res = ((*x).opDoubleDiv(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}

const Literal* ModBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = nullptr;
  try {
    res = ((*x)%(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}

const Literal* PowBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return x->opPower(*y);
}

const Literal* LeftShiftBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = nullptr;
  try {
    res = ((*x)<<(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}

const Literal* RightShiftBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = nullptr;
  try {
    res = ((*x)>>(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}

const Literal* AmpersandBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = nullptr;
  try {
    res = ((*x)&(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}

const Literal* BarBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = nullptr;
  try {
    res = ((*x)|(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}

const Literal* CircumflexBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* res = nullptr;
  try {
    res = ((*x)^(*y));
  } catch(const std::string &msg) {
    std::cout << msg << std::endl;
  }
  return res;
}
