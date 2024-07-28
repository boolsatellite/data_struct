#include "tree.h"
#include <cstddef>
#include <cstdint>

TreeNode *pre = nullptr;
int min_val = INT32_MAX;

void sub_getMinimumDifference(TreeNode *root) {
  if (root == nullptr) return ;
  sub_getMinimumDifference(root->left);
  if (pre != nullptr) {
    std::min(min_val, root->val - pre->val);
  }
  pre = root;
  sub_getMinimumDifference(root->right);
}

int getMinimumDifference(TreeNode* root) {
  sub_getMinimumDifference(root);
  return min_val;
}

