#include <vector>
class Node;
class FuncScope;

class PoolOfNodes {
public:
  static PoolOfNodes& getInstance();
  void add(const Node* node) { nodePool.push_back(node); }
  void addFuncScopeNode(FuncScope* funcS) { funcScopePool.push_back(funcS); }
  void drainThePool();
private:
  std::vector<const Node*> nodePool;
  std::vector<FuncScope*> funcScopePool;
  PoolOfNodes() : nodePool() {}
};
