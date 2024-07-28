#include "tree.h"

TreeNode *sub_sortedArrayToBST(vector<int> &nums , int left , int right) {
  int mid = (left + right) / 2;
  auto node = new TreeNode(nums[mid]);
  node->left = sub_sortedArrayToBST(nums, left, mid-1);
  node->right = sub_sortedArrayToBST(nums, mid+1, right);
  return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
  return sub_sortedArrayToBST(nums, 0, nums.size()-1);
}