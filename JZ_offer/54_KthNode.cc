//
// Created by bools on 2/02/2024.
//

#include "iostream"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int cont = 0;
TreeNode* res = nullptr;

void midOrder(TreeNode* node , int k) {
    if(node == nullptr || cont > k) {
        return;
    } else {
        midOrder(node->left , k);
        cont++;
        if(cont == k) {
            res = node;
            return;
        }
        midOrder(node->right , k);
    }
}

int KthNode(TreeNode* proot, int k) {

    midOrder(proot , k);

    if(res == nullptr) return -1;
    else return res->val;

}

