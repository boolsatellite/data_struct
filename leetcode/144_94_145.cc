//
// Created by bools on 21/03/2024.
//

#include <vector>
#include <stack>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::stack<TreeNode*> s;

std::vector<int> preorderTraversal(TreeNode *root) {
    if(root == nullptr) return {};

    std::vector<int> result;
    s.push(root);
    while(!s.empty()) {
        TreeNode* node = s.top();
        result.push_back(node->val);
        s.pop();
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
    return result;
}

std::vector<int> inorderTraversal(TreeNode* root) {
    if(root == nullptr) return {};

    std::vector<int> result{};
    TreeNode* cur = root;
    while(cur) {
        s.push(cur);
        cur = cur->left;
    }
    while(!s.empty()) {
        TreeNode* top = s.top();
        s.pop();
        result.push_back(top->val);

        cur = top->right;
        while(cur) {
            s.push(cur->left);
            cur = cur->left;
        }
    }
    return result;
}


std::vector<int> postorderTraversal(TreeNode* root) {
    if(root == nullptr) return {};

    std::vector<int> result;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->val);

        if(node->left) s.push(node->left);
        if(node->right) s.push(node->right);

    }
    std::reverse(result.begin() , result.end());
    return result;
}

void order(TreeNode* cur, std::vector<std::vector<int>>& result, int depth) {
    if(cur == nullptr) return;

    if(result.size() == depth) {
        result.push_back({});
    }
    result[depth].push_back(cur->val);
    order(cur->left , result , depth + 1);
    order(cur->right, result , depth + 1);
}
