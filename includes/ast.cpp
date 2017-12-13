#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "literal.h"
#include "funcScope.h"
#include "tableManager.h"

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
  //std::cout << "ident " << ident << "--->eval()"  << std::endl;
  const Literal* res = nullptr;
  TableManager& tm = TableManager::getInstance();
  try {
    const Node* temp = tm.getCurrentFuncScope()->getEntry(ident);
    if ( dynamic_cast<const FuncDefNode*>(temp) ) {
      //std::cout << "IdentNode is a function!!!" << std::endl;
      ReturnFuncNode *rfn = new ReturnFuncNode(tm.getCurrentFuncScope(), temp);
      res = reinterpret_cast<const Literal*>(rfn);
      PoolOfNodes::getInstance().add(rfn);
    }
    else 
      res = temp->eval();
  } catch (const std::out_of_range& e) {
    throw std::string("NameError1: name '") + e.what() + std::string("' is not defined");
  }
  return res;
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

const Literal* AsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw std::string("SyntaxError: can't assign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( TableManager::getInstance().getCurrentFuncScope()->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") + name + std::string("' referenced before assignment");
  }
  //std::cout << "AsgBinaryNode::eval() " << name << std::endl;
  const Literal* res = right->eval();
  TableManager::getInstance().getCurrentFuncScope()->setEntry(name, res); // copy to current scope
  return res;
}

const Literal* PlusAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't plusAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = *oldValue + *augVal;
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* MinAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't minAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = *oldValue - *augVal;
  funcS->setEntry(name, res); // copy to current scope
  return res;
}

const Literal* StarAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't starAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue) * (*augVal);
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* SlashAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't slashAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue) / (*augVal);
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* DoubleSlashAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string(std::string("error"));
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't doubleSlashAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue).opDoubleDiv(*augVal);
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* DoubleStarAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't doubleStarAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = oldValue->opPower(*augVal);
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* PercentAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't percentAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue) % (*augVal);
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* LShiftAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't LShiftAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) << (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* RShiftAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't RShiftAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) >> (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* AmperAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't RShiftAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) & (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* VBarAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't VBarAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) | (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* CircumflexAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't CircumflexAssign to operator");
  }
  FuncScope *funcS = TableManager::getInstance().getCurrentFuncScope();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if ( !funcS->isLocalVariable(name) && !funcS->isGlobalVariable(name) ) {
     throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  if ( !funcS->isLocalVariable(name) && funcS->isOnlyReadableGlobalVariable(name) ) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = funcS->getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) ^ (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  funcS->setEntry(name, res); // modify
  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x+*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
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
    throw std::string("error");
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
    throw std::string("error");
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
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return x->opPower(*y);
}

const Literal* LeftShiftBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
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
    throw std::string("error");
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
    throw std::string("error");
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
    throw std::string("error");
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
    throw std::string("error");
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

const Literal* EqEqualNode::eval() const {
  const Literal* res = nullptr;
  int boolVal = 0;
  if (!dynamic_cast<LessNode*>(left) && !dynamic_cast<GreaterNode*>(left) && !dynamic_cast<EqEqualNode*>(left) && !dynamic_cast<GreaterEqualNode*>(left) && !dynamic_cast<LessEqualNode*>(left) && !dynamic_cast<NotEqualNode*>(left)) { // if it is not comparision Node
    if (*left->eval() == *right->eval()) {
      boolVal = 1;
    }
  } else {
    if (*left->eval() == BoolLiteral(0)) { //if left is false, no need to caculate next
      boolVal = 0;
    } else {
      const BinaryNode *temp = static_cast<const BinaryNode*>(left);
      boolVal = (*temp->getRight()->eval() == *right->eval()) ? 1 : 0;
    }
  }
  res = new BoolLiteral(boolVal);
  PoolOfNodes::getInstance().add(res);
  return res;
}

const Literal* LessNode::eval() const {
  const Literal* res = nullptr;
  int boolVal = 0;
  if (!dynamic_cast<LessNode*>(left) && !dynamic_cast<GreaterNode*>(left) && !dynamic_cast<EqEqualNode*>(left)  && !dynamic_cast<GreaterEqualNode*>(left) && !dynamic_cast<LessEqualNode*>(left) && !dynamic_cast<NotEqualNode*>(left)) { // if it is not comparision Node
    if (*left->eval() < *right->eval()) {
      boolVal = 1;
    }
  } else {
    if (*left->eval() == BoolLiteral(0)) { //if left is false, no need to caculate next
      boolVal = 0;
    } else {
      const BinaryNode *temp = static_cast<const BinaryNode*>(left);
      boolVal = (*temp->getRight()->eval() < *right->eval()) ? 1 : 0;
    }
  }
  res = new BoolLiteral(boolVal);
  PoolOfNodes::getInstance().add(res);
  return res; 
}

const Literal* GreaterNode::eval() const {
  const Literal* res = nullptr;
  int boolVal = 0;
   if (!dynamic_cast<LessNode*>(left) && !dynamic_cast<GreaterNode*>(left) && !dynamic_cast<EqEqualNode*>(left) && !dynamic_cast<GreaterEqualNode*>(left) && !dynamic_cast<LessEqualNode*>(left) && !dynamic_cast<NotEqualNode*>(left)) { // if it is not comparision Node
    if (*left->eval() > *right->eval()) {
      boolVal = 1;
    }
  } else {
    if (*left->eval() == BoolLiteral(0)) { //if left is false, no need to caculate next
      boolVal = 0;
    } else {
      const BinaryNode *temp = static_cast<const BinaryNode*>(left);
      boolVal = (*temp->getRight()->eval() > *right->eval()) ? 1 : 0;
    }
  }
  res = new BoolLiteral(boolVal);
  PoolOfNodes::getInstance().add(res);
  return res; 
}

const Literal* GreaterEqualNode::eval() const {
  const Literal* res = nullptr;
  int boolVal = 0;
   if (!dynamic_cast<LessNode*>(left) && !dynamic_cast<GreaterNode*>(left) && !dynamic_cast<EqEqualNode*>(left) && !dynamic_cast<GreaterEqualNode*>(left) && !dynamic_cast<LessEqualNode*>(left) && !dynamic_cast<NotEqualNode*>(left)) { // if it is not comparision Node
    if (*left->eval() >= *right->eval()) {
      boolVal = 1;
    }
  } else {
    if (*left->eval() == BoolLiteral(0)) { //if left is false, no need to caculate next
      boolVal = 0;
    } else {
      const BinaryNode *temp = static_cast<const BinaryNode*>(left);
      boolVal = (*temp->getRight()->eval() >= *right->eval()) ? 1 : 0;
    }
  }
  res = new BoolLiteral(boolVal);
  PoolOfNodes::getInstance().add(res);
  return res; 
}

const Literal* LessEqualNode::eval() const {
  const Literal* res = nullptr;
  int boolVal = 0;
   if (!dynamic_cast<LessNode*>(left) && !dynamic_cast<GreaterNode*>(left) && !dynamic_cast<EqEqualNode*>(left) && !dynamic_cast<GreaterEqualNode*>(left) && !dynamic_cast<LessEqualNode*>(left) && !dynamic_cast<NotEqualNode*>(left)) { // if it is not comparision Node
    if (*left->eval() <= *right->eval()) {
      boolVal = 1;
    }
  } else {
    if (*left->eval() == BoolLiteral(0)) { //if left is false, no need to caculate next
      boolVal = 0;
    } else {
      const BinaryNode *temp = static_cast<const BinaryNode*>(left);
      boolVal = (*temp->getRight()->eval() <= *right->eval()) ? 1 : 0;
    }
  }
  res = new BoolLiteral(boolVal);
  PoolOfNodes::getInstance().add(res);
  return res; 
}

/*const Literal* GRLTNode::eval() const {
  const Literal* res = nullptr;
  int boolVal = 0;
   if (!dynamic_cast<LessNode*>(left) && !dynamic_cast<GreaterNode*>(left) && !dynamic_cast<EqEqualNode*>(left)) { // if it is not comparision Node
    if (*left->eval() > *right->eval()) {
      boolVal = 1;
    }
  } else {
    if (*left->eval() == BoolLiteral(0)) { //if left is false, no need to caculate next
      boolVal = 0;
    } else {
      const BinaryNode *temp = static_cast<const BinaryNode*>(left);
      boolVal = (*temp->getRight()->eval() > *right->eval()) ? 1 : 0;
    }
  }
  res = new BoolLiteral(boolVal);
  PoolOfNodes::getInstance().add(res);
  return res; 
  } */

const Literal* NotEqualNode::eval() const {
  const Literal* res = nullptr;
  int boolVal = 0;
   if (!dynamic_cast<LessNode*>(left) && !dynamic_cast<GreaterNode*>(left) && !dynamic_cast<EqEqualNode*>(left) && !dynamic_cast<GreaterEqualNode*>(left) && !dynamic_cast<LessEqualNode*>(left) && !dynamic_cast<NotEqualNode*>(left)) { // if it is not comparision Node
    if (*left->eval() != *right->eval()) {
      boolVal = 1;
    }
  } else {
    if (*left->eval() == BoolLiteral(0)) { //if left is false, no need to caculate next
      boolVal = 0;
    } else {
      const BinaryNode *temp = static_cast<const BinaryNode*>(left);
      boolVal = (*temp->getRight()->eval() != *right->eval()) ? 1 : 0;
    }
  }
  res = new BoolLiteral(boolVal);
  PoolOfNodes::getInstance().add(res);
  return res; 
}

FuncDefNode::FuncDefNode(const char* name, std::vector<Node*> parameter, Node* suiteNode) : Node(), funcName( std::string(name) ), formalParameter(parameter), node(static_cast<SuiteNode*>(suiteNode) ) {
  //std::cout << "----------FuncDefNode::FuncDefNode()----------------" << std::endl;
  for (Node* n : parameter) {
    if (!dynamic_cast<IdentNode*>(n)) {
      throw std::string("SyntaxError: in function '") + funcName + std::string("' invalid parameter syntax");
    }
  }
}

FuncDefNode::FuncDefNode(const char* name, Node* suiteNode) : Node(), funcName( std::string(name) ), node(static_cast<SuiteNode*>(suiteNode) ) {
}

const Literal* FuncDefNode::eval() const {
  //std::cout << "----------FuncDefNode::eval()----------------" << std::endl;
  //std::cout << "funcName-->" << funcName << std::endl;
  TableManager &tm = TableManager::getInstance();
  FuncScope *curFuncS = tm.getCurrentFuncScope();
  curFuncS->setEntry(funcName, this);
  return nullptr;
}

void FuncDefNode::evalParameter(std::vector<const Literal*>& actualParameter) const {
  //std::cout << "----------FuncDefNode::evalParameter()------1-------" << std::endl;
  int fpSize = (int) formalParameter.size();
  int apSize = (int) actualParameter.size();
  std::string fpNum = fpSize ? std::to_string(fpSize) : std::string("no");
  //std::cout << "----------FuncDefNode::evalParameter()------2-------" << fpSize << "  " << apSize << std::endl;
  if ( fpSize != apSize )
    throw std::string("TypeError: ") + funcName + std::string("() takes exactly ") + fpNum + std::string(" arguments (") + std::to_string(apSize) + std::string(" given)");
  for (int i = 0; i < fpSize; i++) {
    const std::string fpName = static_cast<IdentNode*>(formalParameter[i])->getIdent();
    TableManager::getInstance().getCurrentFuncScope()->setEntry(fpName, actualParameter[i]);
    //std::cout << "----------FuncDefNode::evalParameter()-----setEntry-------" << fpName <<  std::endl;
    //res->print();
  }
}

const Literal* FuncDefNode::evalSuite() const {
  return node->eval();
}

const Literal* SuiteNode::eval() const {
  // std::cout << "----------SuiteNode::eval()----------------" << std::endl;
  const Literal* res = nullptr;
  //std::cout << "----------SuiteNode::size----------------" << stmts.size() << std::endl;
  auto it = stmts.begin();
  while (it != stmts.end()) {
    if (TableManager::getInstance().getReturnFlag())
      break;
    if (*it) {
      res = (*it)->eval();
    }
    if (dynamic_cast<ReturnNode*>(*it)) {
      TableManager::getInstance().setReturnFlag(true);
      break;
    }
    //if (TableManager::getInstance().checkVariable("__RETURN__")) {
    //  break;
    //}
    ++it;
  }
  return res;
}

const Literal* NewStmtNode::eval() const {
  return node->eval();
}

const Literal* CallNode::eval() const {
  //std::cout << "----------CallNode::eval()-------------" << std::endl;
  const Literal* res = nullptr;
  TableManager &tm = TableManager::getInstance();
  // get current actual parameters
  std::vector<Node*> actualParameter = actualParameters[0]->getNode();
  std::vector<const Literal*> actualParameterVal;
  for (Node *ap : actualParameter) {
    try {
      actualParameterVal.push_back(ap->eval());
    } catch(const std::string& msg) {
      throw std::string("In function '") + callObjectName + std::string("' call: ") + msg;
    }
  }
  // change scope to call func's
  try {
    tm.pushScope( callObjectName );
  } catch(const std::string& msg) {
    std::cout << msg << std::endl;
  }
  FuncScope *curFuncT = tm.getCurrentFuncScope();
  const FuncDefNode* funcNode = static_cast<const FuncDefNode*>( curFuncT->getParentFuncScope()->getFuncDefNode( callObjectName ) );
  // eval the parameter part
  try {
    funcNode->evalParameter(actualParameterVal);
  } catch(const std::string& msg) {
    throw msg;
  }
  res = funcNode->evalSuite();
 // std::cout << "function " << callObjectName << "-->call() " << std::endl;
  if (tm.getReturnFlag()) {
    tm.setReturnFlag(false);
  }
  tm.popScope();
  // if it returns function:
  int callNum = (int) actualParameters.size();
  int i = 1;
  const ReturnFuncNode* returnFuncNode = nullptr;
  bool needPop = false;
  while (i < callNum) { // < callNum means res is a funcdef
    //std::cout << "return to function!!!" << std::endl;
    std::vector<Node*> actualParameter = actualParameters[i]->getNode();
    std::vector<const Literal*> actualParameterVal;
    for (Node *ap : actualParameter) {
      try {
        actualParameterVal.push_back(ap->eval());
      } catch(const std::string& msg) {
        throw std::string("In function '") + callObjectName + std::string("' call: ") + msg;
      }
    }
    //std::cout << "--------------here-------------" << std::endl;
    returnFuncNode = reinterpret_cast<const ReturnFuncNode*>(res);
    tm.setCurrentFuncScope( const_cast<FuncScope *> (returnFuncNode->getFuncScope() ) );
    needPop = true;
    returnFuncNode->getNode()->evalParameter(actualParameterVal);
    res = returnFuncNode->getNode()->evalSuite();
    if (tm.getReturnFlag()) {
      tm.setReturnFlag(false);
    }
    i++;
  }
  if (needPop)
    tm.popScope();
  return res;
}

const Literal* IfNode::eval() const {
  //std::cout << "IfNode::eval IfNode::eval IfNode::eval" << std::endl;
  const Literal* res = nullptr;
  if ( *tNode->eval() != BoolLiteral(0) )
    res = ifNode->eval();
  else if (elseNode)
    res = elseNode->eval();
  return res;
}

const Literal* ReturnNode::eval() const {
  //std::cout << "ReturnNode::eval ReturnNode::eval ReturnNode::eval" << std::endl;
  //const Literal* res = new NullLiteral;
  const Literal* res = nullptr;
  //PoolOfNodes::getInstance().add(res);
  if (node)
    res = node->eval();
  //TableManager::getInstance().setEntry(std::string("__RETURN__"), res);
  TableManager::getInstance().setReturnFlag(true);
  return res;
}


const Literal* PrintNode::eval() const {
  //std::cout << "PrintNode::eval PrintNode::eval PrintNode::eval" << std::endl;
  const Literal *res = nullptr;
  if (node)
    res = node->eval();
  if (res)
    res->printStmt();
  else
    std::cout << "None" << std::endl;
  return nullptr;
}

const Literal* TrailerNode::eval() const {
  // if (node)
  //   node->eval();
  return nullptr;
}

std::vector<Node*> TrailerNode::getNode() const {
  return node;
}

const Literal* ReturnFuncNode::eval() const {
  return nullptr;
}

const Literal* GlobalNode::eval() const {
  //std::cout << "GlobalNode::eval() GlobalNode::eval() GlobalNode::eval()" << std::endl;
  TableManager::getInstance().getCurrentFuncScope()->setGlobalVars(varName, true);
  return nullptr;
}
