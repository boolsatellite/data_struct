
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

// 完全二叉树 => 2 ^ n -1
int countNodes(TreeNode* root) {
    if(root == nullptr) return 0;
    TreeNode* left = root->left;
    int leftDepth = 0;
    TreeNode* right = root->right;
    int rightDepth = 0;

    while(left) {
        left = left->left;
        leftDepth++;
    }
    while(right) {
        right = right->right;
        rightDepth++;
    }
    if(leftDepth == rightDepth) {
        return (2 << leftDepth) - 1;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;

}