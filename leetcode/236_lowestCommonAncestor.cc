#include "tree.h"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if(root == nullptr) return nullptr;
  if(root == p || root == q) return root;

  auto left = lowestCommonAncestor(root->left, p, q);
  auto right = lowestCommonAncestor(root->right, p, q);
  if(left == nullptr) return right;
  if(right == nullptr) return left;
  return root;
}