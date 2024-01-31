//
// Created by bools on 31/01/2024.
//

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};


ListNode* deleteDuplication(ListNode* pHead) {
    if(pHead == nullptr) return nullptr;

    ListNode* res = new ListNode(0);
    res->next = pHead;
    ListNode* cur = res;
    while(cur->next != nullptr && cur->next->next != nullptr) {
        if(cur->next->val == cur->next->next->val) {
            //跳过val
            int tmp = cur->next->val;
            while(cur->next != nullptr && cur->next->val != tmp) {
                cur->next = cur->next->next;
            }
        } else {
            cur = cur->next;
        }
    }
    return res->next;
}
