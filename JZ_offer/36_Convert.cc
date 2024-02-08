//
// Created by bools on 7/02/2024.
//
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

TreeNode* head;
TreeNode* pre;

TreeNode* Convert(TreeNode* pRootOfTree) {
    if(pRootOfTree == nullptr) return nullptr;

    Convert(pRootOfTree->left);

    if(head == nullptr) {
        pre = pRootOfTree;
        head = pRootOfTree;
    } else {
        pRootOfTree->left = pre;
        pre->right = pRootOfTree;
        pre = pRootOfTree;
    }

    Convert(pRootOfTree->right);

    return head;
}