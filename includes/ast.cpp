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

FuncDefNode::FuncDefNode(const char* name, Node* suiteNode) : Node(), funcName(std::string(name)), node(static_cast<SuiteNode*>(suiteNode) ) {
  TableManager::getInstance().insertFunc(funcName, node);
}

const Literal* FuncDefNode::eval() const {
  return nullptr;
}

const Literal* PlusStmtNode::eval() const {
  std::cout << "----------PlusStmtNode::eval()----------------" << std::endl;
  auto it = stmts.begin();
  while (it != stmts.end()) {
    if ((*it)) {
      (*it)->eval();
    }
    if (TableManager::getInstance().checkName("__RETURN__"))
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
  std::cout << "----------SuiteNode::eval()----------------" << std::endl;
  node->eval();
  return nullptr;
}

void PlusStmtNode::insertStmt(Node* n) {
  stmts.push_back(n);
}

const Literal* CallNode::eval() const {
  std::cout << "----------CallNode::eval()-------------" << std::endl;
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

const Literal* PrintNode::eval() const {
  std::cout << "PrintNode::eval PrintNode::eval PrintNode::eval" << std::endl;
  if (node->eval())
    node->eval()->printStmt();
  return nullptr;
}

const Literal* TrailerNode::eval() const {
  if (node)
    node->eval();
  return nullptr;
}

