//
// Created by bools on 19/02/2024.
//
#include "vector"
#include "queue"


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int> > Print1(TreeNode* pRoot) {
    // write code here
    if(pRoot == nullptr) return {};

    std::vector<std::vector<int>> vvi{};
    std::queue<TreeNode*> queue;
    queue.push(pRoot);

    while(!queue.empty()) {
        int n = queue.size();
        std::vector<int> vi{};
        for(int i=0 ; i<n ; ++i) {
            TreeNode* node = queue.front();
            vi.push_back(node->val);
            queue.pop();
            if(node->left != nullptr) queue.push(node->left);
            if(node->right != nullptr) queue.push(node->right);
        }
        vvi.push_back(vi);
    }
    return vvi;
}

void func(std::vector<std::vector<int>>& vvi , TreeNode* root , int depth) {
    if(root == nullptr) return;

    if(vvi.size() < depth) {
        vvi.emplace_back();
    }
    vvi[depth -1].push_back(root->val);
    func(vvi , root->left , depth+1);
    func(vvi , root->right , depth+1);
}


std::vector<std::vector<int>> Print(TreeNode* pRoot) {
    std::vector<std::vector<int>> vvi{};
    func(vvi , pRoot , 1);
    return vvi;
}