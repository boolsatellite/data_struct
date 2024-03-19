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


ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }


    ListNode* p1 = headA;
    ListNode* p2 = headB;

    while (headA != headB) {

        if (headA == nullptr) {
            headA = p2;
        }
        if (headB == nullptr) {
            headB = p1;
        }

        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}