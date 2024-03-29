//
// Created by bools on 24/03/2024.
//

#include <vector>
#include <algorithm>
#include <type_traits>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 前序
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr) return root2;
    if(root2 == nullptr) return root1;

    TreeNode* node = new TreeNode(root1->val + root2->val);
    node->left = mergeTrees(root1->left , root2->left);
    node->right = mergeTrees(root1->right , root2->right);
    return node;
}


