#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
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
  try {
    res = TableManager::getInstance().getEntry(ident)->eval();
  } catch (const std::out_of_range& e) {
    std::cout << "NameError: name '" << e.what() <<"' is not defined" << std::endl;
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
  //std::cout << "AsgBinaryNode::eval() " << name << std::endl;
  const Literal* res = right->eval();
  TableManager::getInstance().setEntry(name, res); // copy to current scope
  return res;
}

const Literal* PlusAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't plusAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = *oldValue + *augVal;
  TableManager::getInstance().setEntry(name, res); // copy to current scope
  return res;
}

const Literal* MinAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't minAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = *oldValue - *augVal;
  TableManager::getInstance().setEntry(name, res); // copy to current scope
  return res;
}

const Literal* StarAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't starAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue) * (*augVal);
  TableManager::getInstance().setEntry(name, res); // modify
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
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue) / (*augVal);
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* DoubleSlashAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string(std::string("error"));
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't doubleSlashAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue).opDoubleDiv(*augVal);
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* DoubleStarAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't doubleStarAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = oldValue->opPower(*augVal);
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* PercentAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't percentAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = (*oldValue) % (*augVal);
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* LShiftAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't LShiftAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) << (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* RShiftAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't RShiftAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) >> (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* AmperAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't RShiftAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) & (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* VBarAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't VBarAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) | (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  TableManager::getInstance().setEntry(name, res); // modify
  return res;
}

const Literal* CircumflexAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  if (!dynamic_cast<IdentNode*>(left)) {
    throw  std::string("SyntaxError: can't CircumflexAssign to operator");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  if (!TableManager::getInstance().checkVariable(name)) {
    throw std::string("UnboundLocalError: local variable '") +  name + std::string("' referenced before assignment");
  }
  const Literal* oldValue = TableManager::getInstance().getEntry(name);
  const Literal* augVal = right->eval();
  const Literal* res = nullptr;
  try {
    res = (*oldValue) ^ (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  TableManager::getInstance().setEntry(name, res); // modify
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

FuncDefNode::FuncDefNode(const char* name, Node* suiteNode) : Node(), funcName(std::string(name)), node(static_cast<SuiteNode*>(suiteNode) ) {
}

const Literal* FuncDefNode::eval() const {
  //std::cout << "----------FuncDefNode::eval()----------------" << std::endl;
  TableManager::getInstance().insertFunc(funcName, node); //should store func's suiteNode in table, because func's suiteNode will eval at the call point, not in the fundefNode eval time
  return nullptr;
}

const Literal* PlusStmtNode::eval() const {
  //std::cout << "----------PlusStmtNode::eval()----------------" << std::endl;
  auto it = stmts.begin();
  while (it != stmts.end()) {
    if ((*it)) {
      (*it)->eval();
    }
    if (TableManager::getInstance().checkVariable("__RETURN__"))
      break;
    ++it;
  }
  return nullptr;
}


const Literal* SuiteNode::eval() const {
  /* PlusStmtNode *psn = dynamic_cast<PlusStmtNode*>(n);
  if (psn) {
    psn->eval();
  } else {
    //
    }*/
  if (!node) {
    throw std::string("suite node is nullptr!!");
  }
  //std::cout << "----------SuiteNode::eval()----------------" << std::endl;
  node->eval();
  return nullptr;
}

const Literal* CallNode::eval() const {
  //std::cout << "----------CallNode::eval()-------------" << std::endl;
  TableManager& tm = TableManager::getInstance();
  tm.pushScope();
  if (!tm.checkName(callObjectName)) {
    std::cout << "function " << callObjectName << " not found" << std::endl;
    std::exception up = std::exception();
    throw up;
  }
  tm.getSuite(callObjectName)->eval();
  const Literal* res = nullptr;
  if (tm.checkName("__RETURN__"))
    res = tm.getEntry("__RETURN__")->eval();
  tm.popScope();
  return res;
}

const Literal* IfNode::eval() const {
  //std::cout << "IfNode::eval IfNode::eval IfNode::eval" << std::endl;
  const Literal* res = nullptr;
  if ( *tNode->eval() != BoolLiteral(0) )
     sNode->eval();
  return res;
}


const Literal* PrintNode::eval() const {
  //std::cout << "PrintNode::eval PrintNode::eval PrintNode::eval" << std::endl;
  if (node->eval())
    node->eval()->printStmt();
  return nullptr;
}

const Literal* TrailerNode::eval() const {
  if (node)
    node->eval();
  return nullptr;
}

