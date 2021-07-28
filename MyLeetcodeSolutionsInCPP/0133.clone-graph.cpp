/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node)
      return nullptr;

    queue<Node*> q{{node}};
    unordered_map<Node*, Node*> map;
    map[node] = new Node(node->val);

    while (!q.empty()) {
      Node* n = q.front();
      q.pop();
      for (Node* neighbor : n->neighbors) {
        if (!map.count(neighbor)) {
          map[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }
        map[n]->neighbors.push_back(map[neighbor]);
      }
    }

    return map[node];
  }
};
