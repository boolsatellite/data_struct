//
// Created by bools on 5/02/2024.
//

#include <vector>
#include <queue>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

std::vector<int> PrintFromTopToBottom1(TreeNode *root) {     //  采用队列
    if(root == nullptr) return {};
    std::queue<TreeNode*> queue;
    std::vector<int> vi;

    queue.push(root);
    while(!queue.empty()) {
        TreeNode* t = queue.front();
        queue.pop();
        if(t->left != nullptr) queue.push(t->left);
        if(t->right != nullptr) queue.push(t->right);
        vi.push_back(t->val);
    }
    return vi;
}

void traverse(TreeNode* root , std::vector<std::vector<int>>& tmp , int depth) {
    if(root == nullptr) return;

    if(tmp.size() < depth) {
        tmp.push_back(std::vector<int>{});
    }

    tmp[depth-1].push_back(root->val);
    traverse(root->left , tmp , depth+1);
    traverse(root->right , tmp , depth+1);
}

std::vector<int> PrintFromTopToBottom(TreeNode *root) {     //递归
    std::vector<std::vector<int>> tmp;
    std::vector<int> res;

    if(root == nullptr) return {};
    traverse(root , tmp , 1);

    for(auto& v : tmp) {
        for(auto & vi : v) {
            res.push_back(vi);
        }
    }
    return res;

}






