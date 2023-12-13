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

    void insert(int val) {
        if(root_ == nullptr) {
            root_ = new Node(val);
            return;
        }

        Node* parent = nullptr;
        Node* cur = root_;
        while(cur != nullptr) {
            if(cur->data_ > val) {
                parent = cur;
                cur = cur->left_;
            } else if(cur->data_ < val) {
                parent = cur;
                cur = cur->right_;
            } else {
                return;
            }
        }

        Node* node = new Node(val , parent, nullptr , nullptr , Color::RED);    //生成父节点为parent的红色节点
        if(parent->data_ > val)
            parent->left_ = node;
        else parent->right_ = node;

        if(Color(parent) == Color::RED) {                                      //当父节点的颜色为红色，需要调整
            fixAfterInsert(node);
        }
    }

private:
    struct Node;
    Node* root_;

    void fixAfterInsert(Node *pNode) {
        while(Color(parent(pNode)) == Color::RED) {     //当前红色节点的父节点为红色开始调整，由于新插入节点为红色，故使用while
            if(left(parent(parent(pNode))) == parent(pNode)) {      //插入节点位于爷爷节点的左子树
                Node* uncle = right(parent(parent(pNode)));
                if(Color(uncle) == Color::RED) {                    //叔叔节点为红色
                    setColor(parent(pNode) , Color::BLACK);
                    setColor(parent(parent(pNode)) , Color::RED);
                    setColor(left(parent(parent(pNode))) , Color::BLACK);
                    pNode = parent(parent(pNode));                  //讲pNode指向爷爷节点，重新判断
                    continue;
                } else {
                    if(right(parent(pNode)) == pNode) {
                        pNode = parent(pNode);
                        leftRotate(pNode);
                    }

                    setColor(parent(pNode) , Color::BLACK);
                    setColor(parent(parent(pNode)) , Color::RED);
                    rightRotate(parent(parent(pNode)));
                    break;
                }
            } else {                                                //插入节点位于爷爷节点的左子树
                Node* uncle = left(parent(parent(pNode)));
                if(Color(uncle) == Color::RED) {                    //叔叔节点为红色
                    setColor(parent(pNode) , Color::BLACK);
                    setColor(parent(parent(pNode)) , Color::RED);
                    setColor(left(parent(parent(pNode))) , Color::BLACK);
                    pNode = parent(parent(pNode));                  //讲pNode指向爷爷节点，重新判断
                    continue;
                } else {
                    if(left(parent(pNode)) == pNode) {
                        pNode = parent(pNode);
                        rightRotate(pNode);
                    }

                    setColor(parent(pNode) , Color::BLACK);
                    setColor(parent(parent(pNode)) , Color::RED);
                    leftRotate(parent(parent(pNode)));
                    break;
                }
            }
        }
        setColor(root_ , Color::BLACK);                             //防止向上调整时将root_置为红色
    }



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
        return node == nullptr ?  Color::BLACK : node->color_;
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

int main() {
    RBtree rBtree;
    for(int i=1 ; i < 10 ; ++i) {
        rBtree.insert(i);
    }
}









