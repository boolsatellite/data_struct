//
// Created by bools on 1/02/2024.
//


#include <vector>
#include <queue>
#include <array>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int> > Print(TreeNode* pRoot) {
    // write code here
    std::queue<TreeNode*> queue;
    if(pRoot == nullptr) return {};

    bool flag = 0;
    queue.push(pRoot);
    int levleSize = 0;
    std::vector<std::vector<int>> ret;
    while(!queue.empty()) {
        int size = queue.size();
        std::vector<int> vi{};
        for(int i=0 ; i<size ; ++i) {
            TreeNode* node = queue.front();
            if(flag == 0) {
                vi.push_back(node->val);
            } else {
                vi.insert(vi.begin() , node->val);
            }
            queue.pop();
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
        flag = !flag;
        ret.push_back(vi);
    }
    return ret;
}