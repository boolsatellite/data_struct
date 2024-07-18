#include <cstddef>
#include <type_traits>
#include <vector>
#include "tree.h"
using std::vector;



void order(TreeNode* cur , std::vector<std::vector<int>>& result , int depth) {
  if(cur == nullptr) return;

  if(result.size() == depth) result.push_back(std::vector<int>{});
  result[depth].push_back(cur->val);
  order(cur->left, result, depth+1);
  order(cur->right, result, depth+1);
}

vector<vector<int>> levelOrder(TreeNode *root) {
  std::vector<std::vector<int>> result;
  order(root, result , 0);
  return result;
}