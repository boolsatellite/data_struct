//
// Created by bools on 22/03/2024.
//

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int func(TreeNode* node) {
    if(node == nullptr) return 0;

    int leftHigh = func(node->left);
    if(leftHigh == -1) return -1;
    int rightHigh = func(node->right);
    if(rightHigh == -1) return -1;
    if(abs(leftHigh - rightHigh) > 1) return -1;

    return std::max(leftHigh , rightHigh) + 1;
}

bool isBalanced(TreeNode *root) {
    if(root == nullptr) return true;
    int high = func(root);
    if(high == -1) return false;
    return true;
}