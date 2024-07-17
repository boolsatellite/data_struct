#include "list.h"
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode* vir = new ListNode();
  vir->next = head;
  head = vir;
  ListNode* end = vir;
  for(int i=0 ; i<n ; ++i) {
    end = end->next;
  }
  while(end->next == nullptr) {
    end = end->next;
    vir = vir->next;
  }
  vir->next = vir->next->next;
  ListNode* result = head->next;
  delete head;
  return result;
}