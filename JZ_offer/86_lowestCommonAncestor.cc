#include <vector>

//
// Created by bools on 20/02/2024.
//
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool flag = false;

void dfs(std::vector<int>& vi , TreeNode* root , int o) {
    if(flag || root == nullptr) {
        return;
    }

    vi.push_back(root->val);
    if(root->val == o) {
        flag = true;
        return;
    }
    dfs(vi , root->left , o);
    dfs(vi , root->right , o);
    if(flag) return;
    vi.pop_back();
}

int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    // write code here
    std::vector<int> v1;
    std::vector<int> v2;

    dfs(v1 , root , o1);
    flag = false;
    dfs(v2 , root , o2);

    int ret = root->val;
    for (int i=0 ; i<v1.size() && i<v2.size() ; ++i) {
        if(v1[i] == v2[i]) {
            ret = v1[i];
        } else {
            break;
        }
    }
    return ret;
}