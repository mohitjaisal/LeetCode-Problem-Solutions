/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {

    if (!head)
      return NULL;

    int n = 0;
    ListNode *temp = head;
    ListNode *tail = temp;
    while (temp) {
      n++;
      tail = temp;
      temp = temp->next;
    }

    k %= n;

    k = (n - k) % n;

    tail->next = head;

    ListNode *newHead = head;
    ListNode *newTail = tail;

    while (k--) {
      newTail = newHead;
      newHead = newHead->next;
    }

    newTail->next = NULL;
    return newHead;
  }
};
