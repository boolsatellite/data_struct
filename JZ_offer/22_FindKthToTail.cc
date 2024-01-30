//
// Created by bools on 30/01/2024.
//


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* FindKthToTail01(ListNode* pHead, int k) {
    // write code here
    int length = 0;
    ListNode* cur = pHead;
    while (cur != nullptr) {
        cur = cur->next;
        length++;
    }
    int time = length - k;
    if(time < 0) return nullptr;
    for (int i = 0 ; i <time ; ++i) {
        pHead = pHead->next;
    }
    return pHead;
}

ListNode* FindKthToTail(ListNode* pHead, int k) {       //双指针
    if(pHead == nullptr) return nullptr;

    ListNode* fast = pHead;
    ListNode* slow = pHead;

    for(int i=0 ; i<k ; ++i) {
        if(fast == nullptr) return nullptr;
        fast = fast->next;
    }

    while(fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
