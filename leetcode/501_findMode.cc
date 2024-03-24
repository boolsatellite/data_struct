//
// Created by bools on 24/03/2024.
//

#include <vector>
#include <map>
#include <algorithm>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::map<int , int> findMode_map{};

void sub_finMode(TreeNode* node) {
    if(node == nullptr) return;
    sub_finMode(node->left);
    findMode_map[node->val]++;
    sub_finMode(node->right);
}


std::vector<int> findMode(TreeNode* root) {
    sub_finMode(root);
    std::vector<std::pair<int,int>> v(findMode_map.begin() , findMode_map.end());
    std::sort(v.begin() , v.end() ,
              [=](std::pair<int,int>& p1 , std::pair<int,int>& p2)->bool { return p1.second > p2.second;});
    std::pair<int,int> tem = v.front();
    std::vector<int> result{};
    for(auto & item : v) {
        if(item.second == tem.second) {
            result.push_back(item.first);
        }
    }
    return result;
}