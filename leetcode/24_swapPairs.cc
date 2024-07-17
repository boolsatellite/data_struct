#include "list.h"

ListNode *swapPairs(ListNode *head) {
  ListNode* vir = new ListNode();
  vir->next = head;
  ListNode* cur = vir;
  while(cur->next && cur->next->next) {
    ListNode* l = cur->next;
    ListNode* r = cur->next->next;
    cur->next = r;
    l->next = r->next;
    r->next = l;
    //l->next = r->next;
    cur = cur->next->next;
  }
  ListNode* result = vir->next;
  delete vir;
  return result;
}
