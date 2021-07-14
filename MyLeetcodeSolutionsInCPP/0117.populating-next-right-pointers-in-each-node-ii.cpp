/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;  // the node just above current needling

    while (node) {
      Node dummy(0);  // dummy node before needling
      // needle children of node
      for (Node* needle = &dummy; node; node = node->next) {
        if (node->left) {  // needle left child
          needle->next = node->left;
          needle = needle->next;
        }
        if (node->right) {  // needle right child
          needle->next = node->right;
          needle = needle->next;
        }
      }
      node = dummy.next;  // move node to the next level
    }

    return root;
  }
};
