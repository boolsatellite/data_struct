#include "tree.h"
#include <algorithm>
#include <queue>

vector<vector<int>> levelOrderBottom(TreeNode *root) {
  vector<vector<int>> result;
  std::queue<TreeNode*> que;
  if(root != nullptr) que.push(root);

  while(!que.empty()) {
    int size = que.size();
    vector<int> level;
    for(int i=0 ; i<size ; ++i) {
      TreeNode* tmp = que.front();
      level.push_back(tmp->val);
      que.pop();
      if(tmp->left) que.push(tmp->left);
      if(tmp->right) que.push(tmp->right);
    }
    result.push_back(level);
  }
  std::reverse(result.begin() , result.end());
  return result;
}