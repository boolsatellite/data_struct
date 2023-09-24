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

    //递归插入
    void insert(const T& val) {
        insert(root_ , val);
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

    //递归删除
    void remove(const T& val) {
        root_ = remove(root_ , val);
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


    void preOrder() {                   //递归前序遍历接口
        std::cout << "[递归] 前序遍历" ;
        preOrder(root_);
        std::cout << std::endl;
    }

    void inOrder() {            //递归中序遍历接口
        std:: cout << "[递归] 中序遍历" ;
        inOrder(root_);
        std::cout << std::endl;
    }

    void postOrder() {          //递归后序遍历接口
        std::cout <<"[递归] 后序遍历";
        postOrder(root_);
        std::cout << std::endl;
    }

    void levelOrder() {         //递归层序遍历接口
        std::cout <<"[递归]";
        int h = high();
        for( int i = 0 ; i < h ; i++) {
            levelOrder(root_ , i);
        }
    }

    bool query(const T& val) {
        return nullptr == query(root_ , val);
    }

    int high() {               //递归求层高接口
        return high(root_);
    }

    int num() {                 //递归求节点个数接口
        return num(root_);
    }
private:
    struct Node;

    Node* insert(Node* node , const T& val) {   //递归插入
        if(node == nullptr) {
            return new Node(val);
        }
        if(node->data_ > val) {
            node->right_ = insert(node->right_ , val);
        } else if(node->data_ < val){
            node->left_ = insert(node->left_ , val);
        } else {
            return node;
        }
        return node;
    }

    void preOrder(Node* node) {         //前序遍历递归
        if(node == nullptr) return;
        std::cout <<node->data_ <<" ";
        preOrder(node->left_);
        preOrder(node->right_);
    }

    void inOrder(Node* node) {          //中序遍历递归
        if (node == nullptr) return;
        inOrder(node->left_);
        std::cout << node->data_ <<" ";
        inOrder(node->right_);
    }

    void postOrder(Node* node) {         //后序遍历递归
        if (node == nullptr) return;
        postOrder(node->left_);
        postOrder(node->right_);
        std::cout << node->data_ <<" ";
    }

    int high(Node* node) {             //当前节点层高递归
        //当前节点的高度 = max(左子树高度 ， 右子树高度) + 1
        if(node == nullptr) return 0;
        //return level(node->left_) > level(node->right_) ? level(node->left_) +1 : level(node->right_) + 1;
        int left = level(node->left_);
        int right = level(node->right_);
        return left > right ? left+1 : right+1;
    }

    int num(Node* node) {            //递归求节点个数
        // 当前节点num = 左子树num + 右子树num + 1
        if(node == nullptr) return 0;
        int left = num(node->left_);
        int right = num(node->right_);
        return left > right ? left+1 : right+1;
    }

    void levelOrder(Node* node , int high) {    //层序遍历递归
        /*相当于是根左右，在根判断是否在当前层，若在则打印并return
         * */
        if( high == 0) {
            std::cout << node->data_ <<" ";
            return;
        }
        levelOrder(node->left_ , high-1);
        levelOrder(node->right_ , high-1);
    }

    Node* query(Node* node , const T& val) {
        if(node == nullptr) return nullptr;
        if(node->data_ == val)
            return node;
        else if(node->data_ < val) {
            return query(node->right_ , val);
        } else {
            return query(node->left_ , val);
        }
    }

    Node* remove(Node* node , const T&val) {
        if( node == nullptr) return nullptr;
        if(node->data_ == val) {        //情况三
            if(node->left_ && node->right_) {
                Node* pre = node->left_;
                while(pre->right_) {
                    pre = pre->right_;
                }
                node->data_ = pre->data_;
                node->left_ = remove(node->left_ , pre->data_);
            } else {
                if(node->left_ != nullptr) {
                    Node* t = node->left_;
                    delete(node);
                    return t;
                } else if(node->right_ != nullptr) {
                    Node* t = node->right_;
                    delete(node);
                    return t;
                } else {
                    delete(node);
                    return nullptr;
                }
            }
        } else if(node->data_ > val) {
            node->left_ = remove(node->left_, val);
        } else {
            node->right_ = remove(node->right_ , val);
        }
        return node;
    }

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

    int arr[] = {58,24,67,0,34,62,69,5,41,64,78};
    BSTree<int> bsTree;
    for(int &i : arr) {
        bsTree.n_insert(i);
    }
    bsTree.preOrder();
    bsTree.remove(58);
    bsTree.preOrder();

};