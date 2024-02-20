//
// Created by bools on 19/02/2024.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int n = 0;

void dfs(TreeNode *node, int sum) {
    if (node == nullptr) return;

    sum -= node->val;
    if (sum == 0) {
        n++;
    }
    dfs(node->left, sum);
    dfs(node->right, sum);

}

int FindPath(TreeNode *root, int sum) {
    // write code here
    if (root == nullptr) return 0;

    dfs(root, sum);
    FindPath(root->left, sum);
    FindPath(root->right, sum);

    return n;

}