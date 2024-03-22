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

int maxDepth(TreeNode *root) {
    if(root == nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return std::max(left , right) + 1;
}
