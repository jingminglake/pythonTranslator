#include "node.h"
#include "funScope.h"
#include "poolOfNodes.h"

PoolOfNodes& PoolOfNodes::getInstance() {
  static PoolOfNodes pool;
  return pool;
}

void PoolOfNodes::drainThePool() {
  for ( const Node* node : nodePool ) {
    delete node;
  }
  nodePool.clear();
  for ( FuncScope* funcS : funcScopePool ) {
    delete funcS;
  }
  funcScopePool.clear();
}
