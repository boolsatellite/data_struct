//
// Created by bools on 22/03/2024.
//
#include <algorithm>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void func(std::vector<std::string>& result , std::vector<int>& tem , TreeNode* node) {
    if(node == nullptr) return;

    tem.push_back(node->val);

    if(node->left == nullptr && node->right == nullptr) {
        // tem => string => push_back
        std::string s{};
        for(auto i : tem) {
            s.push_back(i+'0');
            s += "->";
        }
        s.pop_back();               // >
        s.pop_back();               // -
        result.push_back(s);

        tem.pop_back();
    }
    if(node->left != nullptr) {
        func(result , tem , node->left);
        tem.pop_back();
    }
    if(node->right != nullptr) {
        func(result , tem , node->right);
        tem.pop_back();
    }

}

std::vector<std::string> binaryTreePaths(TreeNode* root) {

    std::vector<std::string> result;
    std::vector<int> tem;

    func(result , tem , root);
    return result;
}