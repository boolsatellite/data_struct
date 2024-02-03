//
// Created by bools on 3/02/2024.
//

#include "vector"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* rebuild(std::vector<int>& pre, int i, int j, std::vector<int>& order,
                  int m, int n) {         // i j m n 均为下标
    if (i > j || m > n) return nullptr;

    TreeNode* node = new TreeNode(pre[i]);
    //在order中寻找
    int t = m;              //t 是下标
    for (; t <= n ; ++t) {
        if (order[t] == pre[i]) {
            break;
        }
    }
    node->left = rebuild(pre, i + 1, t - m + i, order, m, t - 1);
    node->right = rebuild(pre, i + t - m + 1, j, order, t + 1, n);

    return node;
}


TreeNode* reConstructBinaryTree(std::vector<int>& preOrder,
                                std::vector<int>& vinOrder) {

    return rebuild(preOrder, 0, preOrder.size() - 1, vinOrder, 0, vinOrder.size() - 1);

}