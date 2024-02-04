//
// Created by bools on 4/02/2024.
//


#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeNode* Mirror(TreeNode*pRoot) {

    if(pRoot == nullptr) return nullptr;

    std::swap(pRoot->right , pRoot->left);
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return pRoot;
}