//
// Created by bools on 2024-01-12.
//

//合并 n 个有序链表

#include <iostream>
#include <vector>
#include <algorithm>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x) , next(nullptr) {}
};


ListNode* init_link(std::initializer_list<int> list) {
    ListNode* head = nullptr;
    ListNode* p = nullptr;
    for(auto v : list) {
        if(head == nullptr) {
            head = new ListNode(v);
            p = head;
        } else {
            p->next = new ListNode(v);
            p = p->next;
        }
    }
    return head;
}

ListNode* mergeTwoLink(ListNode* left , ListNode* right) {
    if(left == nullptr) return right;
    if(right == nullptr) return left;

    ListNode* head = nullptr;
    if(left->val < right->val) {
        head = left;
        left = left->next;
    } else {
        head = right;
        right = right->next;
    }

    ListNode* p = head;
    while(left != nullptr && right != nullptr) {
        if(left->val > right->val) {
            p->next = right;
            right = right->next;
            p = p->next;
        } else {
            p->next = left;
            left = left->next;
            p = p->next;
        }
    }
    if(left != nullptr) {
        p->next = left;
    }
    if(right != nullptr) {
        p->next = right;
    }
    return head;
}

ListNode* merge(std::vector<ListNode*>& vlink , int i , int j) {
    if(i >= j) {
        return vlink[i];
    }

    int mid = (i + j) / 2;
    ListNode* left = merge(vlink , i , mid);
    ListNode* right = merge(vlink , mid + 1 , j);

    return mergeTwoLink(left , right);

}

int main() {
    ListNode* p1 = init_link({1,3,5,7});
    ListNode* p2 = init_link({1,2,4,5 ,6,8});

    std::vector<ListNode*> vlink;
    vlink.push_back(p1);
    vlink.push_back(p2);

    ListNode* p = merge(vlink , 0 , vlink.size() - 1);
    while(p) {
        std::cout << p->val << " ";
        p = p->next;
    }
}

