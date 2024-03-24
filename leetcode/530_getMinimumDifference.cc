#include <climits>
#include <algorithm>

//
// Created by bools on 24/03/2024.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* pre = nullptr;
int result = INT_MAX;


void sub_getMinimumDifference(TreeNode* root) {
    if(root == nullptr) return;

    sub_getMinimumDifference(root->left);
    if(pre != nullptr) {
        result = std::min(result , root->val - pre->val);
    }
    pre = root;

    sub_getMinimumDifference(root->right);
}

int getMinimumDifference(TreeNode* root) {
    sub_getMinimumDifference(root);
    return result;
}
