//
// Created by satellite on 2023-12-06.
//

/**
 * 红黑树定义：
 * 1. 每个节点都有颜色，不是红色就是黑色
 * 2. root必须是黑色
 * 3. 所有叶子节点都是黑色，叶子节点是NULL，不存储实际数据
 * 4. 每个红色节点必须有两个黑色节点，或者说每个叶子节点到根节点的所有路径上不能有连续的红色节点
 * 5. 从任一节点到其每个叶子节点的搜友简单路径都包含相同数目的黑色节点
 */


/**
 * 红黑树插入：
 *  1. 空树：插入节点为黑色root
 *  2. 树非空：插入节点尽量为红色，若父节点是黑色，则插入完成
 *     若父节点是红色，则要进行插入调整(根据uncle节点的颜色)
 *
 */

class RBtree {
public:
    enum class Color {BLACK, RED};

    RBtree() : root_(nullptr) { }

private:
    struct Node;
    Node* root_;

    void leftRotate(Node* node) {                   //左旋转
        Node* child = node->right_;
        child->parent_ = node->parent_;
        if(node->parent_ == nullptr) {  //node 是 root_
            root_ = child;
        } else {                        //node 不为 root_
            if(node->parent_->left_ == node) {      //node 在其父节点的左侧
                node->parent_->left_ = child;
            } else {                                //node 在其父节点的右侧
                node->parent_->right_ = child;
            }
        }
        node->right_ = child->left_;
        if(child->left_ != nullptr) {
            child->left_->parent_ = node;
        }
        child->left_ = node;
        node->parent_ = child;
    }

    void rightRotate(Node* node) {
         Node* child = node->left_;
         if(node->parent_ == nullptr) {         //node 是 root_
             root_ = child;
         } else {
             if(node->parent_->left_ == node) {
                 node->parent_->left_ = child;
             } else {
                 node->parent_->right_ = node;
             }
             child->parent_ = node->parent_;
             node->left_= child->right_;
             if(child->right_ != nullptr) {
                 child->right_->parent_ = node;
             }
             child->right_ = node;
             node->parent_ = child;

         }
    }


    Color Color(Node* node) const {
        return node == nullptr ?  Color::BLACK : Color::RED;
    }

    void setColor(Node* node , enum Color color) {
        node->color_ = color;
    }

    Node* left(Node* node) {
        return node->left_;
    }

    Node* right(Node* node) {
        return node->right_;
    }

    Node* parent(Node* node) {
        return node->parent_;
    }


    struct Node {
        Node(int data = 0,
             Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr, enum Color color = Color::BLACK)
                :data_(data), left_(left), right_(right), parent_(parent), color_(color) {}

        int data_;
        Node *left_;
        Node *right_;
        Node *parent_;
        enum Color color_;
    };
};









