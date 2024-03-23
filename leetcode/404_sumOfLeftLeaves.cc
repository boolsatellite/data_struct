#include <iostream>

//
// Created by bools on 22/03/2024.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode* root) {           // 左叶子和
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 0;
    // 后序

    int leftSum = sumOfLeftLeaves(root->left);
    int rightSum = sumOfLeftLeaves(root->right);

    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
        leftSum = root->left->val;
    }

    return leftSum + rightSum;
}
