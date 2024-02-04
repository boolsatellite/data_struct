//
// Created by bools on 4/02/2024.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

bool isChild(TreeNode* p1 , TreeNode* p2) {

    if(p2 == nullptr) return true;
    if(p1 == nullptr) return false;
    if(p1->val != p2->val) return false;

    return isChild(p1->left , p2->left) && isChild(p1->right , p2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

    if(pRoot1 == nullptr || pRoot2 == nullptr) return false;

    if(pRoot1->val == pRoot2->val) {
        if(isChild(pRoot1 , pRoot2)) {
            return true;
        }
        //return false;
    }

    return HasSubtree(pRoot1->left , pRoot2) || HasSubtree(pRoot1->right , pRoot2);

}