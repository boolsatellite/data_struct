//
// Created by bools on 8/02/2024.
//

#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int high(TreeNode* node) {

    if(node == nullptr) return 0;
    int l = high(node->left); if(l == -1) return -1;
    int r = high(node->right); if(r == -1) return -1;
    if(abs(l - r) > 1) return -1;
    return std::max(l , r) + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    // write code here
    if(pRoot == nullptr) {
        return true;
    }
    int ret = high(pRoot);
    if(ret == -1) return false;

    return true;
}