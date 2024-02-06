#include <iostream>

//
// Created by bools on 6/02/2024.
//
class TreeNode {
public:
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int val) {
        this->val = val;
    }
};

bool hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr) {
        return false;
    }
    if(root->left == nullptr && root->right == nullptr) {
        if(sum - root->val == 0) return true;
    }

    return hasPathSum(root->left , sum - root->val) || hasPathSum(root->right , sum - root->val);

}

