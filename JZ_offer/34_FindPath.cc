//
// Created by bools on 6/02/2024.
//

#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> path;
std::vector<std::vector<int>> ret;

void func(TreeNode* root , int target) {
    // write code here
    if(root == nullptr) return;
    path.push_back(root->val);
    target -= root->val;
    if(root->left == nullptr && root->right == nullptr && target == 0) {
        // 满足
        ret.push_back(path);
    }

    func(root->left , target);
    func(root->right , target);
    path.pop_back();
}


std::vector<std::vector<int> > FindPath(TreeNode* root, int target) {
    func(root , target);
    return ret;
}

