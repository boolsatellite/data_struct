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



TreeNode* sub_lowestCommonAncestor(TreeNode* node , TreeNode* p, TreeNode* q) {
    if(node == nullptr) return nullptr;
    if(node == p || node == q) return node;

    TreeNode* left = sub_lowestCommonAncestor(node->left , p , q);
    TreeNode* right = sub_lowestCommonAncestor(node->right , p , q);

    if(left == nullptr) return right;
    else if(right == nullptr) return left;
    else return node;

    /*
                 1
             2        3
          4    5    6     7
     */

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return sub_lowestCommonAncestor(root , p , q);
}
