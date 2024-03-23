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

// [ )
TreeNode* sub_buildTree(vector<int>& inorder , std::vector<int>::iterator i ,std::vector<int>::iterator j,
                        vector<int>& postorder , std::vector<int>::iterator m ,std::vector<int>::iterator n) {
    if(m == n) return nullptr;
    int curRootVal = *(n-1);
    TreeNode* node = new TreeNode(curRootVal);

    std::vector<int>::iterator it = std::find(i , j , curRootVal);
    int left = it - i;
    int right = (j - it) - 1;

    node->left = sub_buildTree(inorder , i , it , postorder , m , m + left);
    node->right = sub_buildTree(inorder , it+1 , j , postorder , m+left , n-1);

    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return sub_buildTree(inorder , inorder.begin() , inorder.end() , postorder , postorder.begin() , postorder.end());
}

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* resule = buildTree(inorder , postorder);
}



