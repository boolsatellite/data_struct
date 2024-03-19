//
// Created by bools on 19/03/2024.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* virHead = new ListNode{};
    virHead->next = head;

    ListNode* fast = virHead;
    ListNode* slow = virHead;

    for(int i=0 ; i<n ; ++i) {
        fast = fast->next;
    }

    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return virHead->next;
}
