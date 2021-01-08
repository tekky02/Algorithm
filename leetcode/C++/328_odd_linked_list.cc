/**defination for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode() : val(0), next(nullptr) {}
 **     ListNode(int x) : val(x), next(nullptr) {}
 **     ListNode(int x, ListNode *next) : val(x), next(next) {}
 ** };
 **/
class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    ListNode *newHead = new ListNode(0, head);
    ListNode *h1 = nullptr;
    ListNode *h2 = nullptr;
    ListNode *p2 = nullptr;
    int count = 1;
    auto item = head;
    while (item) {
      if (count % 2) {
        if (!h1) {
          h1 = item;
        } else {
          h1->next = item;
          h1 = h1->next;
        }
      } else {
        if (!h2) {
          h2 = item;
          p2 = item;
        } else {
          h2->next = item;
          h2 = h2->next;
        }
      }
      ++count;
      item = item->next;
    }
    if (h2)
      h2->next = nullptr;
    if (h1)
      h1->next = p2;
    return newHead->next;
  }
};
