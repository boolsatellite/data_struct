#include "list.h"
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode* pa=headA;
  ListNode* pb=headB;
  while(headA != headB) {
    pa = pa == nullptr ?  headB : pa->next;
    pb = pb == nullptr ?  headA : pb->next;
  }
  return headA;
}