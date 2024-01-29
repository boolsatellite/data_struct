//
// Created by bools on 2024-01-29.
//


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* Merge1(ListNode* pHead1, ListNode* pHead2) {
    if(pHead1 == nullptr) return pHead2;
    else if(pHead2 == nullptr) return pHead1;

    ListNode* head = nullptr;

    if(pHead1->val <= pHead2->val) {
        head = pHead1;
        pHead1 = pHead1->next;
    } else {
        head = pHead2;
        pHead2 = pHead2->next;
    }
    ListNode* cur = head;

    while(pHead1 && pHead2 ) {
        if(pHead1->val < pHead2->val) {         //phead1 加入链表
            cur->next = pHead1;
            pHead1 = pHead1->next;
        } else {                                //phead2 加入链表
            cur->next = pHead2;
            pHead2 = pHead2->next;
        }
        cur = cur->next;
    }
    if(!pHead1) {                               //加入 phead2 剩余
        cur->next = pHead2;
    } else {
        cur->next = pHead1;
    }
    return head;
}


ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {   //递归解决
    if(pHead1 == nullptr) return pHead2;
    if(pHead2 == nullptr) return pHead1;

    if(pHead1->val <= pHead2->val) {
        pHead1->next = Merge(pHead1->next , pHead2);
        return pHead1;
    } else {
        pHead2->next = Merge(pHead2->next , pHead1);
        return pHead2;
    }
}








