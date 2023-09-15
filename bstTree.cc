#include "iostream"

/*
 * BST插入节点：
 * BST为空 - 插入节点为root节点
 * BST不为空 - 从根节点开始比较，找到合适位置生成新节点，并将节点的地址写入父节点对于的地址域中
 * */

#include "functional"
template<typename T , typename Compare = std::less<T>>
class BSTree {
public:
    BSTree() :root_(nullptr) { }

    //非递归插入操作
    void n_insert(const T& val) {
        if(root_ == nullptr) {
            root_ = new Node(val);
            return;
        } else {
            Node* cur = root_;
            Node* parent = nullptr;
            while (cur != nullptr) {
                parent = cur;
                if(comp_( val , cur->data_ )) {
                    cur = cur->left_;
                } else if(comp_( cur->data_ , val)) {
                    cur = cur->right_;
                } else {                    //数据重复时不做操作
                    return;
                }
            }
            if(comp_(parent->data_ , val)) {
                parent->right_ = new Node(val);
            } else {
                parent->left_ = new Node(val);
            }
        }
    }

    // 非递归删除
    /* 1. 没有孩子节点        ->  父节点地址域设为nullptr
     * 2. 只有一个孩子节点     ->  将孩子写入父节点地址域
     * 3. 有两个孩子节点       ->  找待删除节点的前驱或者后继节点，用前驱或者后继节点将
     *                           待删除节点覆盖掉，然后删除前驱或者后继节点,从而转化为 情况 1 ，2
     */
    void n_remove(const T& val) {
        if(root_ == nullptr)
            return;
        Node* parent = nullptr;
        Node* cur = root_;
        while(cur != nullptr) {
            parent = cur;
            if(comp_(val , cur->data_)) {
                cur = cur->right_;
            } else if (comp_(cur->data_ , val)) {
                cur = cur->left_;
            } else {    //cur->data_ == val  找到待删除节点
                break;
            }
        }
        if(cur == nullptr) return;          //当待删除节点不存在时
        if(cur->left_ && cur->right_) {     //情况3
            parent = cur;
            Node* pre = cur->left_;
            while (pre->right_) {           //找前驱节点
                parent = pre;
                pre = pre->right_;
            }
            cur->data_ = pre->data_;
            cur = pre;
        }
        //情况 1 2
        Node* child = cur->left_;   //child指向cur有孩子的那一侧
        if(child == nullptr)
            child = cur->right_;
        if(parent == nullptr) {     //删除的节点是根节点
            root_ = child;
            delete cur;
        }
        else {
            if (parent->left_ == cur) {
                parent->left_ = child;
                delete cur;
            } else {
                parent->right_ = child;
                delete cur;
            }
        }
    }

    //非递归查询
    bool n_query(const T& val) {
        Node* cur = root_;
        while (cur != nullptr) {
            if(cur->data_ == val) return true;
            else if (comp_(cur->data_ , val )) {
                cur = cur->right_;
            } else {
                cur = cur->left_;
            }
        }
        return false;
    }



private:
    struct Node {       //节点结构体定义
        Node(T data=T{} , Node* left = nullptr , Node* right= nullptr)
            :data_(data) , left_(left) , right_(right) {}
        T data_;
        Node* left_;
        Node* right_;
    };

    Node* root_;        //BST树根节点
    Compare comp_;
};

int main() {

/*
    int arr[] = {58,24,67,0,34,62,69,5,41,64,78};
    BSTree<int> bsTree;
    for(int &i : arr) {
        bsTree.n_insert(i);
    }
*/



};