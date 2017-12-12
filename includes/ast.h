#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "node.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

void freeAST(Node*);
class IdentNode : public Node {
public:
 IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};


class UnaryNode : public Node {
public:
  UnaryNode(Node *n) : Node(), node(n) {}
  Node* getVal()  const { return node; }
  virtual const Literal* eval() const = 0;
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode& operator=(const UnaryNode&) = delete;
protected:
  Node *node;
};

class MinusUnaryNode : public UnaryNode {
public:
  MinusUnaryNode(Node *n) : UnaryNode(n) {}
  virtual const Literal* eval() const;
};

class TildeUnaryNode : public UnaryNode {
public:
  TildeUnaryNode(Node *n) : UnaryNode(n) {}
  virtual const Literal* eval() const;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class PlusAsgBinaryNode : public BinaryNode {
public:
  PlusAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class MinAsgBinaryNode : public BinaryNode {
public:
  MinAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class StarAsgBinaryNode : public BinaryNode {
public:
  StarAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class SlashAsgBinaryNode : public BinaryNode {
public:
  SlashAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class DoubleSlashAsgBinaryNode : public BinaryNode {
public:
  DoubleSlashAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class DoubleStarAsgBinaryNode : public BinaryNode {
public:
  DoubleStarAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class PercentAsgBinaryNode : public BinaryNode {
public:
  PercentAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class LShiftAsgBinaryNode : public BinaryNode {
public:
  LShiftAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class RShiftAsgBinaryNode : public BinaryNode {
public:
  RShiftAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class AmperAsgBinaryNode : public BinaryNode {
public:
  AmperAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class VBarAsgBinaryNode : public BinaryNode {
public:
  VBarAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class CircumflexAsgBinaryNode : public BinaryNode {
public:
  CircumflexAsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {};
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class FloorDivBinaryNode : public BinaryNode {
public:
  FloorDivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class LeftShiftBinaryNode : public BinaryNode {
public:
  LeftShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class RightShiftBinaryNode : public BinaryNode {
public:
  RightShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class AmpersandBinaryNode : public BinaryNode {
public:
  AmpersandBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class BarBinaryNode : public BinaryNode {
public:
  BarBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class CircumflexBinaryNode : public BinaryNode {
public:
  CircumflexBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class EqEqualNode : public BinaryNode {
public:
  EqEqualNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class LessNode : public BinaryNode {
public:
  LessNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GreaterNode : public BinaryNode {
public:
  GreaterNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GreaterEqualNode : public BinaryNode {
public:
  GreaterEqualNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class LessEqualNode : public BinaryNode {
public:
  LessEqualNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GRLTNode : public BinaryNode {
public:
  GRLTNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class NotEqualNode : public BinaryNode {
public:
  NotEqualNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class SuiteNode;

class FuncDefNode : public Node {
public:
  FuncDefNode(const char* name, std::vector<Node*> parameter, Node* suiteNode);
  FuncDefNode(const char* name, Node* suiteNode);
  virtual const Literal* eval() const;
  void evalParameter(std::vector<Node*>& actualParameter) const;
private:
  std::string funcName;
  std::vector<Node*> formalParameter;
  SuiteNode* node;
};

class SuiteNode : public Node {
public:
  SuiteNode() : Node() {
    stmts.reserve(8);
  }
  virtual const Literal* eval() const;
  void insertStmt(Node* n) {
    stmts.push_back(n);
  }
private:
  std::vector<Node*> stmts;
};

class NewStmtNode : public Node {
public:
  NewStmtNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval() const;
private:
  Node* node;
};

class TrailerNode : public Node {
public:
  TrailerNode(std::vector<Node*>* n) : Node() {
    if(n)
      node = *n;
    std::cout << "----------TrailerNode----------------" << std::endl;
  }
  virtual const Literal* eval() const;
  std::vector<Node*> getNode() const;
private:
  std::vector<Node*> node;
};

class CallNode : public Node {
public:
  CallNode(const std::string& name, std::vector<Node*>* parameter) : Node(), callObjectName(name) {
    std::vector<Node*>::iterator it = parameter->begin();
    while ( it != parameter->end() ) {
      actualParameters.push_back( static_cast<TrailerNode*>(*it) );
      ++it;
    }
};
  virtual const Literal* eval() const;
private:
  std::string callObjectName;
  std::vector<TrailerNode*> actualParameters;
};

class IfNode : public Node {
public:
  IfNode(Node* testNode, Node* suiteNode) : Node(), tNode(testNode), ifNode(static_cast<SuiteNode*>(suiteNode)), elseNode(nullptr){}
  IfNode(Node* testNode, Node* suiteNode_if, Node* suiteNode_else) : Node(), tNode(testNode), ifNode(static_cast<SuiteNode*>(suiteNode_if)), elseNode(static_cast<SuiteNode*>(suiteNode_else)){}
  virtual const Literal* eval() const;
private:
  Node* tNode;
  SuiteNode* ifNode;
  SuiteNode* elseNode;
};

class ReturnNode : public Node {
public:
  ReturnNode(Node* n) : Node(), node(n){}
  virtual const Literal* eval() const;
private:
  Node* node;
};

class PrintNode : public Node {
public:
  PrintNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval() const;
private:
  Node *node;
};
