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

// [ )
TreeNode* sub_constructMaximumBinaryTree(vector<int>& nums , int begin , int end) {
    if(begin == end) return nullptr;

    int max = INT_MIN;
    int pos = begin;
    for(int i = begin ; i< end ; ++i) {
        if(nums[i] > max) {
            pos = i;
            max = nums[i];
        }
    }

    TreeNode* node = new TreeNode(max);
    node->left = sub_constructMaximumBinaryTree(nums , begin , pos);
    node->right = sub_constructMaximumBinaryTree(nums , pos+1 , end);
    return node;

}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return sub_constructMaximumBinaryTree(nums , 0 , nums.size());
}
