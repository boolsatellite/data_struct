//
// Created by bools on 30/01/2024.
//


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};


ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if(pHead == nullptr) return nullptr;
    ListNode* fast = pHead;
    ListNode* slow = pHead;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(fast == nullptr || fast->next == nullptr) return nullptr;        //无环

    //找入口节点
    fast = pHead;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
