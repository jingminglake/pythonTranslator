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
  // const Literal* val = TableManager::getInstance().getEntry(ident)->eval();
  
  return val;
}

void IdentNode::setValue(const Literal *v) {
  val = v;
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
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  // must keep the binding information in static table,
  // because we need find the asg node later in other stmt
  TableManager::getInstance().setEntry(name, right);
}

const Literal* AsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  // must find in the table, and could not use right->eval(), 
  // because right may be a NULL node for current asg node, but from a higher
  // perspection, the right must be a left value in previous stmt
  const Literal* res = TableManager::getInstance().getEntry(name)->eval();
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

PlusAsgBinaryNode::PlusAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) {
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
    oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  //std::cout << "-=-=-=-1=-=-=-=-=--" << std::endl;
}

const Literal* PlusAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = *oldValue + *augVal;
  //std::cout << "-=-=-=-2=-=-=-=-=--" << std::endl;
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

MinAsgBinaryNode::MinAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
    oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* MinAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(n)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = *oldValue - *augVal;
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

StarAsgBinaryNode::StarAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
      oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* StarAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue) * (*augVal);
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

SlashAsgBinaryNode::SlashAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
      oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* SlashAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue) / (*augVal);
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

DoubleSlashAsgBinaryNode::DoubleSlashAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
      oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* DoubleSlashAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string(std::string("error"));
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue).opDoubleDiv(*augVal);
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

DoubleStarAsgBinaryNode::DoubleStarAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
    oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
}

const Literal* DoubleStarAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
      exit(-1);
  }
  const Literal* res = oldValue->opPower(*augVal);
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

PercentAsgBinaryNode::PercentAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
      oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* PercentAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = (*oldValue) % (*augVal);
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

LShiftAsgBinaryNode::LShiftAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
    oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* LShiftAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) << (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

RShiftAsgBinaryNode::RShiftAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
      oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* RShiftAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) >> (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

AmperAsgBinaryNode::AmperAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
    oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* AmperAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) & (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

VBarAsgBinaryNode::VBarAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
      oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* VBarAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) | (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  static_cast<IdentNode*>(left)->setValue(res);
  return res;
}

CircumflexAsgBinaryNode::CircumflexAsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Node* oldRight = NULL;
  try {
    oldRight = TableManager::getInstance().getEntry(name);
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
}

const Literal* CircumflexAsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* augVal = right->eval();
  const std::string name = static_cast<IdentNode*>(left)->getIdent();
  const Literal* oldValue = NULL;
  try {
    oldValue = TableManager::getInstance().getEntry(name)->eval();
  } catch(const std::string& msg) {
      std::cout << msg << std::endl;
  }
  const Literal* res = nullptr;
  try {
    res = (*oldValue) ^ (*augVal);
  } catch (const std::string& msg) {
    std::cout << msg << std::endl;
  }
  static_cast<IdentNode*>(left)->setValue(res);
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
  return NULL;
}

const Literal* PlusStmtNode::eval() const {
  std::cout << "----------6----------------" << std::endl;
  auto it = stmts.rbegin();
  while (it != stmts.rend()) {
    if ((*it)) {
      (*it)->eval();
    }
    if (TableManager::getInstance().checkName("__RETURN__"))
      break;
    ++it;
  }
  return NULL;
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
  std::cout << "----------5----------------" << std::endl;
  node->eval();
  return NULL;
}

void PlusStmtNode::insertStmt(Node* n) {
  stmts.push_back(n);
}

const Literal* CallNode::eval() const {
  std::cout << "----------100----------------" << std::endl;
  TableManager& tm = TableManager::getInstance();
  tm.pushScope();
  if (!tm.checkName(callObjectName)) {
    std::cout << "function " << callObjectName << " not found" << std::endl;
    std::exception up = std::exception();
    throw up;
  }
  tm.getSuite(callObjectName)->eval();
  const Literal* res = NULL;
  if (tm.checkName("__RETURN__"))
    res = tm.getEntry("__RETURN__")->eval();
  tm.popScope();
  return res;
}

const Literal* PrintNode::eval() const {
   std::cout << "PrintNode::eval PrintNode::eval PrintNode::eval" << std::endl;
  node->eval()->printStmt();
  return NULL;
}

const Literal* TrailerNode::eval() const {
  if (node)
    node->eval();
  return NULL;
}

