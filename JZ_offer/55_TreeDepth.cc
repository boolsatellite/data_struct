//
// Created by bools on 1/02/2024.
//


#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};


// h(pRoot) = std::max(h(pRoot->left) , h(pRoot->right)) + 1
int TreeDepth(TreeNode* pRoot) {
    if(pRoot == nullptr) {
        return 0;
    } else {
        int h1 = TreeDepth(pRoot->left);
        int h2 = TreeDepth(pRoot->right);
        return std::max(h1+1 , h2+1);
    }
}
