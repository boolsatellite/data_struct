//
// Created by bools on 15/02/2024.
//

#include <vector>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {

    }

};


void midOrder(TreeLinkNode* node , std::vector<TreeLinkNode*>& vec) {
        if(node == nullptr) return;

        midOrder(node->left , vec);
        vec.push_back(node);
        midOrder(node->right , vec);
}

TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    TreeLinkNode* srcNode = pNode;
    while(pNode->next != nullptr) {             //找根节点 ==>  pNode=root
        pNode = pNode->next;
    }
    std::vector<TreeLinkNode*> vec;
    midOrder(pNode , vec);
    for(int i=0 ; i<vec.size() - 1; ++i) {
        if(vec[i] == srcNode) {
            return vec[i+1];
        }
    }
    return nullptr;
}
