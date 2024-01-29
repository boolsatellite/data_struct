//
// Created by bools on 2024-01-27.
//

#include <vector>
#include <stack>
#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* ReverseList1(ListNode* head) {            //利用栈
    std::stack<ListNode*> s;
    while(head != nullptr) {
        s.push(head);
        head = head->next;
    }

    head = new ListNode(0);
    ListNode* l = head;
    while(!s.empty()) {
        l->next = s.top();
        s.pop();
        l = l->next;
        l->next = nullptr;
    }
    ListNode* tmp = head->next;
    delete head;
    return tmp;
}

//==================================================================

ListNode* ReverseList02(ListNode* head) {             //双指针
    if(head == nullptr) return nullptr;         //防止空指针访问

    ListNode* l = head;
    ListNode* r = head->next;
    head->next = nullptr;

    while(r != nullptr) {
        ListNode* t = r->next;
        r->next = l;            // l  r
        l = r;
        r = t;
    }
    return l;
}



int main() {

}