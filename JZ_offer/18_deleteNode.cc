//
// Created by bools on 31/01/2024.
//

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteNode(ListNode* head, int val) {
    // write code here
    if(head == nullptr) return nullptr;

    ListNode* res = new ListNode(0);
    res->next = head;
    ListNode* cur = res;
    while(cur->next->val != val && cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return res->next;
}