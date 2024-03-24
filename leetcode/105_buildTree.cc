//
// Created by bools on 23/03/2024.
//
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
 [3,9 ,20,15,7]             pre

 [9,3 ,15,20,7]             in
    ^
 */

// [ )
TreeNode* sub_buildTree(vector<int>& preorder , std::vector<int>::iterator i , std::vector<int>::iterator j,
                        vector<int>& inorder , std::vector<int>::iterator m ,std::vector<int>::iterator n) {
    if(i == j) return nullptr;
    TreeNode* node = new TreeNode(*i);

    auto iterator = std::find(inorder.begin() , inorder.end() , *i);

    int left = iterator - m;

    node->left = sub_buildTree(preorder , i+1 , (i + left) + 1 , inorder , m , iterator);
    node->right = sub_buildTree(preorder , i+left+1 , j , inorder , iterator+1 , n);

    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return sub_buildTree(preorder , preorder.begin() , preorder.end() , inorder , inorder.begin() , inorder.end());
}