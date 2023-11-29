//
// Created by satellite on 2023-11-23.
//


template<typename T>
class AVLTree {

public:


private:
    struct Node {
        Node(T data = T())
                : data_(data), left_(nullptr), right_(nullptr) {}

        T data_;
        struct Node *left_;
        struct Node *right_;
        int hight_;
    };

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
            hight(node->left_) >= hight(node->right_) ?
            hight(node->left_) : hight(node->right_);
        };
        child->hight_ = [&]() -> int {
            hight(child->left_) >= hight(child->right_) ?
            hight(child->left_) : hight(child->right_);
        };
        return child;
    }

    //左旋转
    void leftRotate(Node *node) {
        Node *child = node->right_;
        node->right_ = child->left_;
        child->left_ = node;
        node->hight_ = [&]() -> int {
            hight(node->left_) >= hight(node->right_) ?
            hight(node->left_) : hight(node->right_);
        };
        child->hight_ = [&]() -> int {
            hight(child->left_) >= hight(child->right_) ?
            hight(child->left_) : hight(child->right_);
        };
        return child;
    }

    //右平衡
    Node* rightBlance(Node* node) {
        node->right_ = rightRotate(node->right_);
        return leftRotate(node);
    }

    //左平衡
    Node* leftBlance(Node* node) {
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);
    }

    Node *root_;
};

