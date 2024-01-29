//
// Created by bools on 2024-01-29.
//


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(!pHead1 && !pHead2) return nullptr;
    ListNode* first = pHead1;
    ListNode* second = pHead2;
    while(pHead2 != pHead1) {
        pHead2 = pHead2->next;
        pHead1 = pHead1->next;

        if(pHead1 == nullptr) pHead1 = second;
        if(pHead2 == nullptr) pHead2 = first;
    }
    return pHead1;
}