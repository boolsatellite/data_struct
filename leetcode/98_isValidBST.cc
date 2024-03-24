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

long long max = LONG_LONG_MIN;

bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;

    int leftFlag = isValidBST(root->left);

    if(root->val > ::max) {
        ::max = root->val;
    } else {
        return false;
    }
    int rightFlag = isValidBST(root->right);
    return leftFlag && rightFlag;
}


