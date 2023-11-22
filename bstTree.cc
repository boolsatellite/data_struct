#include "iostream"
#include "stack"
#include <assert.h>
#include <cmath>
#include "vector"
#include "map"
/*
 * BST插入节点：
 * BST为空 - 插入节点为root节点
 * BST不为空 - 从根节点开始比较，找到合适位置生成新节点，并将节点的地址写入父节点对于的地址域中
 * */


#include "functional"


template<typename T, typename Compare = std::less<T>>
class BSTree {
struct Node;
public:
    BSTree() : root_(nullptr) {}

    //非递归插入操作
    void n_insert(const T &val) {
        if (root_ == nullptr) {
            root_ = new Node(val);
            return;
        } else {
            Node *cur = root_;
            Node *parent = nullptr;
            while (cur != nullptr) {
                parent = cur;
                if (comp_(val, cur->data_)) {
                    cur = cur->left_;
                } else if (comp_(cur->data_, val)) {
                    cur = cur->right_;
                } else {                    //数据重复时不做操作
                    return;
                }
            }
            if (comp_(parent->data_, val)) {
                parent->right_ = new Node(val);
            } else {
                parent->left_ = new Node(val);
            }
        }
    }

    //递归插入
    void insert(const T &val) {
        insert(root_, val);
    }

    // 非递归删除
    /* 1. 没有孩子节点        ->  父节点地址域设为nullptr
     * 2. 只有一个孩子节点     ->  将孩子写入父节点地址域
     * 3. 有两个孩子节点       ->  找待删除节点的前驱或者后继节点，用前驱或者后继节点将
     *                           待删除节点覆盖掉，然后删除前驱或者后继节点,从而转化为 情况 1 ，2
     */
    void n_remove(const T &val) {
        if (root_ == nullptr)
            return;
        Node *parent = nullptr;
        Node *cur = root_;
        while (cur != nullptr) {
            parent = cur;
            if (comp_(val, cur->data_)) {
                cur = cur->right_;
            } else if (comp_(cur->data_, val)) {
                cur = cur->left_;
            } else {    //cur->data_ == val  找到待删除节点
                break;
            }
        }
        if (cur == nullptr) return;          //当待删除节点不存在时
        if (cur->left_ && cur->right_) {     //情况3
            parent = cur;
            Node *pre = cur->left_;
            while (pre->right_) {           //找前驱节点
                parent = pre;
                pre = pre->right_;
            }
            cur->data_ = pre->data_;
            cur = pre;
        }
        //情况 1 2
        Node *child = cur->left_;   //child指向cur有孩子的那一侧
        if (child == nullptr)
            child = cur->right_;
        if (parent == nullptr) {     //删除的节点是根节点
            root_ = child;
            delete cur;
        } else {
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
    void remove(const T &val) {
        root_ = remove(root_, val);
    }


    //非递归查询
    bool n_query(const T &val) {
        Node *cur = root_;
        while (cur != nullptr) {
            if (cur->data_ == val) return true;
            else if (comp_(cur->data_, val)) {
                cur = cur->right_;
            } else {
                cur = cur->left_;
            }
        }
        return false;
    }


    void preOrder() {                   //递归前序遍历接口
        std::cout << "[递归]  前序遍历    ";
        preOrder(root_);
        std::cout << std::endl;
    }

    void inOrder() {            //递归中序遍历接口
        std::cout << "[递归] 中序遍历";
        inOrder(root_);
        std::cout << std::endl;
    }

    void postOrder() {          //递归后序遍历接口
        std::cout << "[递归] 后序遍历";
        postOrder(root_);
        std::cout << std::endl;
    }

    void levelOrder() {         //递归层序遍历接口
        std::cout << "[递归]";
        int h = high();
        for (int i = 0; i < h; i++) {
            levelOrder(root_, i);
        }
    }

    bool query(const T &val) {
        return nullptr == query(root_, val);
    }

    int high() {               //递归求层高接口
        return high(root_);
    }

    int num() {                 //递归求节点个数接口
        return num(root_);
    }

    void n_preOrder() {
        if (root_ == nullptr) return;
        std::cout << "[非递归] 前序遍历" << "   ";
        std::stack<Node *> s;
        s.push(root_);
        while (!s.empty()) {
            Node *top = s.top();
            s.pop();
            std::cout << top->data_ << " ";

            if (top->right_ != nullptr) s.push(top->right_);
            if (top->left_ != nullptr) s.push(top->left_);
        }
        std::cout << std::endl;
    }

    void n_inOrder() {         //非递归中序遍历
        if (root_ == nullptr) return;
        std::cout << "[非递归] 中序遍历" << "   ";
        std::stack<Node *> s;
        Node *cur = root_;
        while (cur != nullptr) {
            s.push(cur);
            cur = cur->left_;
        }
        while (!s.empty()) {
            Node *top = s.top();
            s.pop();
            std::cout << top->data_ << " ";
            cur = top->right_;
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left_;
            }
        }
        std::cout << std::endl;
    }

    void n_postOrder() {            //非递归后序遍历
        if (root_ == nullptr) return;
        std::cout << "[非递归] 后序遍历" << " ";
        std::stack<Node *> s1, s2;      //V R L
        s1.push(root_);
        while (!s1.empty()) {
            Node *cur = s1.top();
            s1.pop();
            s2.push(cur);
            if (cur->left_ != nullptr) {
                s1.push(cur->left_);
            }
            if (cur->right_ != nullptr) {
                s1.push(cur->right_);
            }
        }
        while (!s2.empty()) {
            Node *top = s2.top();
            s2.pop();
            std::cout << top->data_ << " ";
        }
        std::cout << std::endl;
    }

    void findValues(std::vector<T> &vec, int i, int j) {      //查找位于(i,j)之间的元素并存放在vec中 ,递归接口
        if (root_ == nullptr) assert(0);
        findValues(root_, vec, i, j);
    }

    bool isBSTtrr() {                                       //判断二叉树是否为二叉树
        Node *pre = nullptr;
        return isBSTtrr(root_, pre);
    }

    bool isChildTree(const BSTree<T> &bst) {                //子树问题
        if (bst.root_ == nullptr) return true;
        Node *cur = root_;
        while (cur != nullptr) {
            if (cur->data_ == bst.root_->data_) break;
            else if (cur->data_ > bst.root_->data_) {
                cur = cur->left_;
            } else {
                cur = cur->right_;
            }
            if (cur == nullptr) return false;
            return isChildTree(cur, bst.root_);
        }
    }

    Node* getLCA(T a , T b) {                 //最近公共祖先节点
        Node* cur = root_;
        while(cur != nullptr) {
            if(a < cur->data_ && b < cur->data_) {
                cur = cur->left_;
            } else if ( a > cur->data_ && b > cur->data_) {
                cur = cur->right_;
            } else {
                return cur;
            }
        }
        return nullptr;
    }

    void mirror01() {       //将二叉树镜像反转
         mirror01(root_);
    }

    bool mirror02() {       //判断二叉树的镜像对称
        if(root_ == nullptr) return true;
        return mirror02(root_->left_ , root_->right_);
    }

    Node* rebuild(int pre[] , int i , int j , int in[] , int m , int n) {   //根据前序中序重建bst树
        if(i > j || m > n) return nullptr;
        //创建当前子树根节点
        Node* node = new Node(pre[i]);
        for(int k=m ; k <= n ; k++) {
            if(pre[i] == in[k]) {
                node->left_ = rebuild(pre , i+1 , i+k-m , in , m , k -1 );
                node->right_ = rebuild(pre , i+k-m+1 , j , in , k+1 , n);
            }
        }
    }

    bool isBalance() {                                          //判断二叉树是否为平衡树
        bool flag;
        isBalance1(root_ , 0 , flag);
        return flag;
        //return isBalance(root_);
    }

    Node* getVal(int k) {                                         //求中序倒数第k个节点
        int i = 1;              //用于计数
        Node* node = getVal(root_ , k , std::move(i));
        if(node == nullptr) {
            throw "error k";
        }
        else return node;
    }

private:

    Node* getVal(Node *node, int k , int&& i) {
        if (node == nullptr)
            return nullptr;

        Node* left = getVal(node->right_, k , std::move(i)); // R
        if (left != nullptr)
            return left;
        // V
        if (i++ == k) // 在VRL的顺序下，找到正数第k个元素
        {
            return node;
        }
        return getVal(node->left_, k , std::move(i)); // L
    }

    int isBalance1(Node* node , int level , bool &flag) {       //返回节点高度，level形参用于记录当前节点高度值，flag用于记录是否平衡
        if (node == nullptr) return level;
        int left = isBalance1(node->left_ , level + 1 , flag);
        int right = isBalance1(node->right_ , level + 1 , flag);
        if (abs(left - right > 1)) flag = false;                //节点失衡
        return [=](int l , int r){
            if(l >= r) return l;
            else return r;
        };
    }

    bool isBalance(Node* node) {
        if(node == nullptr) return true;
        if(!isBalance(node->left_)) return false;
        if(!isBalance(node->right_)) return false;

        int left = high(node->left_);
        int right = high(node->right_);

        return abs(left - right) <= 1;
    }

    bool mirror02(Node* node1 , Node* node2) {
        if(node1 == nullptr && node2 == nullptr) {
            return true;
        }
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }
        if(node1->data_ != node2->data_) {
            return false;
        }
        return mirror02(node1->left_ , node1->right_) && mirror02(node2->left_ , node2->right_);
    }

    void mirror01(Node* node) {
        if(node == nullptr) return;
        Node* tem = node->left_;        //交换子树
        node->left_ = node->right_;
        node->right_ = tem;
        mirror01(node->left_);
        mirror01(node->right_);
    }

    bool isChildTree(Node *cur, Node *child) {          //判断子树递归
        if (cur == nullptr && child == nullptr) return true;
        if (cur == nullptr) return false;
        if (child == nullptr) return true;

        if(cur->data_ != child->data_) return false;

        return isChildTree(cur->left_ , child->right_) && isChildTree(cur->right_ , child->right_);
    }

    bool isBSTree(Node *node, Node *&pre) {
        if (node == nullptr) return true;               //在递归处理中主要判断使递归结束的条件
        if (isBSTtrr(node->left_, pre) == false) return false;

        if (pre != nullptr) {
            if (pre->data_ > node->data_) return false;
        }
        pre = node;

        if (isBSTtrr(node->right_, pre) == false) return false;
        return true;
    }

    void findValues(Node *node, std::vector<T> &vec, int i, int j) {      //查找位于(i,j)之间的元素并存放在vec中 递归实现
        //采用中序遍历为升序的思想
        if (node == nullptr) return;
        if (node->data_ > i) {
            findValues(node->left_, vec, i, j);
        }
        if (node->data_ >= i && node->data_ <= j) {
            vec.push_back(node->data_);
        }
        if (node->data_ < j) {
            findValues(node->right_, vec, i, j);
        }
    }

    Node *insert(Node *node, const T &val) {   //递归插入
        if (node == nullptr) {
            return new Node(val);
        }
        if (node->data_ > val) {
            node->right_ = insert(node->right_, val);
        } else if (node->data_ < val) {
            node->left_ = insert(node->left_, val);
        } else {
            return node;
        }
        return node;
    }

    void preOrder(Node *node) {         //前序遍历递归
        if (node == nullptr) return;
        std::cout << node->data_ << " ";
        preOrder(node->left_);
        preOrder(node->right_);
    }

    void inOrder(Node *node) {          //中序遍历递归
        if (node == nullptr) return;
        inOrder(node->left_);
        std::cout << node->data_ << " ";
        inOrder(node->right_);
    }

    void postOrder(Node *node) {         //后序遍历递归
        if (node == nullptr) return;
        postOrder(node->left_);
        postOrder(node->right_);
        std::cout << node->data_ << " ";
    }

    int high(Node *node) {             //当前节点层高递归
        //当前节点的高度 = max(左子树高度 ， 右子树高度) + 1
        if (node == nullptr) return 0;
        //return level(node->left_) > level(node->right_) ? level(node->left_) +1 : level(node->right_) + 1;
        int left = level(node->left_);
        int right = level(node->right_);
        return left > right ? left + 1 : right + 1;
    }

    int num(Node *node) {            //递归求节点个数
        // 当前节点num = 左子树num + 右子树num + 1
        if (node == nullptr) return 0;
        int left = num(node->left_);
        int right = num(node->right_);
        return left > right ? left + 1 : right + 1;
    }

    void levelOrder(Node *node, int high) {    //层序遍历递归
        /*相当于是根左右，在根判断是否在当前层，若在则打印并return
         * */
        if (high == 0) {
            std::cout << node->data_ << " ";
            return;
        }
        levelOrder(node->left_, high - 1);
        levelOrder(node->right_, high - 1);
    }

    Node *query(Node *node, const T &val) {
        if (node == nullptr) return nullptr;
        if (node->data_ == val)
            return node;
        else if (node->data_ < val) {
            return query(node->right_, val);
        } else {
            return query(node->left_, val);
        }
    }

    Node *remove(Node *node, const T &val) {
        if (node == nullptr) return nullptr;
        if (node->data_ == val) {        //情况三
            if (node->left_ && node->right_) {
                Node *pre = node->left_;
                while (pre->right_) {
                    pre = pre->right_;
                }
                node->data_ = pre->data_;
                node->left_ = remove(node->left_, pre->data_);
            } else {
                if (node->left_ != nullptr) {
                    Node *t = node->left_;
                    delete (node);
                    return t;
                } else if (node->right_ != nullptr) {
                    Node *t = node->right_;
                    delete (node);
                    return t;
                } else {
                    delete (node);
                    return nullptr;
                }
            }
        } else if (node->data_ > val) {
            node->left_ = remove(node->left_, val);
        } else {
            node->right_ = remove(node->right_, val);
        }
        return node;
    }

    struct Node {       //节点结构体定义
        Node(T data = T{}, Node *left = nullptr, Node *right = nullptr)
                : data_(data), left_(left), right_(right) {}

        T data_;
        Node *left_;
        Node *right_;
    };

    Node *root_;        //BST树根节点
    Compare comp_;
};


int main() {

    int arr[] = {58, 24, 67, 0, 34, 62, 69, 5, 41, 64, 78};
    BSTree<int> bsTree;
    for (int &i: arr) {
        bsTree.n_insert(i);
    }

    bsTree.inOrder();
    std::vector<int> vi;

    std::cout << bsTree.getVal(3)->data_ << std::endl;

    bsTree.mirror01();
    bsTree.inOrder();

    std::map<int , std::string> map{};
};