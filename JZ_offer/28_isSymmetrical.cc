//
// Created by bools on 15/02/2024.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool func(TreeNode* fir , TreeNode* sec) {
    if(fir == nullptr && sec == nullptr) return true;
    if(fir == nullptr && sec != nullptr || fir != nullptr && sec == nullptr) return false;
    if(fir != nullptr && sec != nullptr && fir->val != sec->val)  return false;

    return func(fir->left , sec->right) && func(fir->right , sec->left);
}

bool isSymmetrical(TreeNode* pRoot) {
    // write code here
    TreeNode* fir = pRoot;
    TreeNode* sec = pRoot;
    return func(fir , sec);
}

