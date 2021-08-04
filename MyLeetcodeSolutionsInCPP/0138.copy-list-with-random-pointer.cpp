class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head) return head;
 
    unordered_map<Node*, Node*> m;    
    Node* cur = m[head] = new Node(head->val);
    Node* ans = cur;
 
    while (head) {
      if (head->random) {
        auto it = m.find(head->random);
        if (it == end(m))
          it = m.emplace(head->random, new Node(head->random->val)).first;
        cur->random = it->second;
      }
 
      if (head->next) {
        auto it = m.find(head->next);
        if (it == end(m))
          it = m.emplace(head->next, new Node(head->next->val)).first;        
        cur->next = it->second;
      }
 
      head = head->next;
      cur = cur->next;
    }
    
    return ans;
  }
};
