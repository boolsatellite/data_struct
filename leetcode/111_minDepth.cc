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

int minDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right != nullptr) return minDepth(root->right) + 1;
    if(root->right == nullptr && root->left != nullptr) return minDepth(root->left) + 1;

    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return std::min(left , right) + 1;
}