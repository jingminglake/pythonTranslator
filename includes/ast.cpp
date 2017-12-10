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
    res = TableManager::getInstance().getCurrentFuncScope()->getEntry(ident)->eval();
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
  TableManager::getInstance().getCurrentFuncScope().setEntry(name, res); // copy to current scope
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
  const Literal* oldValue = TableManager::getInstance().getCurrentFuncScope().getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = *oldValue + *augVal;
  TableManager::getInstance().getCurrentFuncScope().setEntry(name, res); // copy to current scope
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
  const Literal* oldValue = TableManager::getInstance().getCurrentFuncScope().getEntry(name)->eval();
  const Literal* augVal = right->eval();
  const Literal* res = *oldValue - *augVal;
  TableManager::getInstance().getCurrentFuncScope().setEntry(name, res); // copy to current scope
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
  //TableManager::getInstance().pushScope();
  //SymbolTable* t = new SymbolTable();
  //TableManager::getInstance().insertFunc(funcName, );
  //TableManager::getInstance().pushScope();
}

const Literal* FuncDefNode::eval() const {
  //std::cout << "----------FuncDefNode::eval()----------------" << std::endl;
  //std::cout << "funcName-->" << funcName << std::endl;
  TableManager &tm = TableManager::getInstance();
  FuncTable *curFuncT = tm.getCurrentFuncTable();
  curFuncT->setEntry(funcName, node);
  return nullptr;
}

const Literal* SuiteNode::eval() const {
  //std::cout << "----------SuiteNode::eval()----------------" << std::endl;
  const Literal* res = nullptr;
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
  try {
    tm.pushScope( callObjectName );
  } catch(const std::string& msg) {
    std::cout << msg << std::endl;
  }
  FuncTable *curFuncT = tm.getCurrentFuncTable();
  res = curFuncT->getParentFuncScope()->getSuite()->eval();
 // std::cout << "function " << callObjectName << "-->call() " << std::endl;
  if (tm.getReturnFlag()) {
    tm.setReturnFlag(false);
  }
  tm.popScope();
  return res;
}

const Literal* IfNode::eval() const {
  //std::cout << "IfNode::eval IfNode::eval IfNode::eval" << std::endl;
  const Literal* res = nullptr;
  if ( *tNode->eval() != BoolLiteral(0) )
    ifNode->eval();
  else if (elseNode)
    elseNode->eval();
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
  const Literal *res = node->eval();
  if (res)
    res->printStmt();
  else
    std::cout << "None" << std::endl;
  return nullptr;
}

const Literal* TrailerNode::eval() const {
  if (node)
     node->eval();
  return nullptr;
}

