//
// Created by bools on 18/03/2024.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val) {
    ListNode virHead{};
    virHead.next = head;

    ListNode* cur = &virHead;
    ListNode* p = cur->next;

    while(p != nullptr) {
        if(p->val == val) {
            p = p->next;
            cur->next = p;
        } else {
            cur = cur->next;
            p = p->next;
        }
    }
    return virHead.next;
}
