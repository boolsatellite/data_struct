#include "list.h"
#include <cstddef>

ListNode *removeElements(ListNode *head, int val) {
  ListNode* vir = new ListNode;
  vir->next = head;
  ListNode* l = vir;
  ListNode* r = head;
  while(r!=nullptr) {
    if(r->val == val) {   // remove
      l->next = r->next;
      r = r->next;
    } else {
      l = l->next;
      r = r->next;
    }
  }
  ListNode* result = vir->next;
  delete vir;
  return result;
}