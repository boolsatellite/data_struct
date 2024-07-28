#include "tree.h"

TreeNode *pre = nullptr;

TreeNode *convertBST(TreeNode *root) {
  if (root == nullptr)
    return nullptr;
  auto right = convertBST(root->right);
  if (pre != nullptr) {
    root->val += pre->val;
  }
  pre = root;
  auto left = convertBST(root->left);

  return root;
}