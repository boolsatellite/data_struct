//
// Created by satellite on 2023-11-23.
//
#include <cmath>
#include <algorithm>


//template<typename T>
class AVLTree {

public:
    AVLTree() : root_(nullptr) {}

    void insert(int val) {
        root_ = insert(root_, val);     //由于旋转会导致root_可能变化,故每次插入都要更新
    }

    void remove(int val) {
        root_ = remove(root_, val);
    }


private:
    struct Node {
        Node(int data = int())
                : data_(data), left_(nullptr), right_(nullptr), hight_(1) {}

        int data_;
        struct Node *left_;
        struct Node *right_;
        int hight_;
    };

    Node *remove(Node *node, const int &val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->data_ > val) {
            node->left_ = remove(node->left_, val);
            //失衡调整
            if(hight(node->right_) - hight(node->left_) > 1) {
                if(hight(node->right_->right_) - hight(node->right_->left_)) {
                    node = leftRotate(node);
                } else {
                    node = rightBlance(node);
                }
            }
        } else if (node->data_ < val) {
            node->right_ = remove(node->right_, val);
            if(hight(node->left_) - hight(node->right_) > 1) {
                if(hight(node->left_->left_) - hight(node->left_->right_)) {
                    node = rightRotate(node);
                } else {
                    node = leftBlance(node);
                }
            }
        } else {    //node->data == val
            if(node->left_ != nullptr && node->right_ != nullptr) {     //先处理两个孩子的情况,为了避免节点失衡，删除节点高的子树
                if (hight(node->left_) >= hight(node->right_)) {        //左子树高删除前驱
                    Node *pre = node->left_;
                    while (pre->right_) {
                        pre = pre->right_;
                    }
                    node->data_ = pre->data_;
                    node->left_ = remove(node->left_, pre->data_);

                } else {                                                //右子树高删除后继
                    Node *post = node->right_;
                    while (post->left_) {
                        post = post->left_;
                    }
                    node->data_ = post->data_;
                    node->right_ = remove(node->right_, post->data_);
                }
            } else {                                                    //只有一个节点不为空或全为空
                Node* child = node->left_;
                if(child == nullptr) {
                    child = node->right_;
                }
                delete node;
                return child;
            }
        }
        node->hight_ = std::max(hight(node->left_) , hight(node->right_)) + 1;
        return node;
    }

    Node *insert(Node *node, const int &val) {
        if (node == nullptr) {      // 递归结束，找到插入的位置了
            return new Node(val);
        }

        if (node->data_ > val) {
            node->left_ = insert(node->left_, val);
            // 添加1 在递归回溯时判断节点是否失衡  node的左子树太高 node失衡了
            if (hight(node->left_) - hight(node->right_) > 1) {
                if (hight(node->left_->left_) >= hight(node->left_->right_)) {
                    // 节点失衡，由于左孩子的左子树太高
                    node = rightRotate(node);
                } else {
                    // 节点失衡，由于左孩子的右子树太高
                    node = leftBlance(node);
                }
            }
        } else if (node->data_ < val) {
            node->right_ = insert(node->right_, val);
            // 添加2 在递归回溯时判断节点是否失衡  node的右子树太高 node失衡了
            if (hight(node->right_) - hight(node->left_) > 1) {
                if (hight(node->right_->right_) >= hight(node->right_->left_)) {
                    // 节点失衡，由于右孩子的右子树太高
                    node = leftRotate(node);
                } else {
                    // 节点失衡，由于右孩子的左子树太高
                    node = rightBlance(node);
                }
            }
        } else { ; // 找到相同节点了，不用再往下递归了，直接向上回溯
        }

        // 添加3 因为子树中增加了新的节点  在递归回溯时检测更新节点高度
        node->hight_ = std::max(hight(node->left_), hight(node->right_)) + 1;

        return node;
    }

    int hight(Node *node) {             //返回节点高度值
        if (node == nullptr) {
            return 0;
        } else {
            return node->hight_;
        }
    }

    //右旋转
    Node *rightRotate(Node *node) {     //以node为轴右旋转，并将新的根节点返回
        Node *child = node->left_;
        node->left_ = child->right_;
        child->right_ = node;
        //高度更新
        node->hight_ = [&]() -> int {
            return
                    hight(node->left_) >= hight(node->right_) ?
                    hight(node->left_) : hight(node->right_);
        }() + 1;
        child->hight_ = [&]() -> int {
            return
                    hight(child->left_) >= hight(child->right_) ?
                    hight(child->left_) : hight(child->right_);
        }() + 1;
        return child;
    }

    //左旋转
    Node *leftRotate(Node *node) {
        Node *child = node->right_;
        node->right_ = child->left_;
        child->left_ = node;
        node->hight_ = [&]() -> int {
            return
                    hight(node->left_) >= hight(node->right_) ?
                    hight(node->left_) : hight(node->right_);
        }() + 1;
        child->hight_ = [&]() -> int {
            return
                    hight(child->left_) >= hight(child->right_) ?
                    hight(child->left_) : hight(child->right_);
        }() + 1;
        return child;
    }

    //右平衡
    Node *rightBlance(Node *node) {
        node->right_ = rightRotate(node->right_);
        return leftRotate(node);
    }

    //左平衡
    Node *leftBlance(Node *node) {
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);
    }

    Node *root_;
};

int main() {
    AVLTree avlTree{};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i: arr) {
        avlTree.insert(i);
    }

    avlTree.remove(4);

}
