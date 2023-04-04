// BST 树
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#include <deque>
#include <functional>
#include <stack>
#include <deque>
using namespace std;

template <typename T, typename Compare = less<T>>
class BST_tree
{
struct Node;
public:
    BST_tree() { root_ = nullptr; } // 与链表不同，无头结点

	~BST_tree()
	{
        distory(root_);     //析构递归接口
	}
    

    // 节点的插入  非递归
    void n_insert(const T data)
    {
        if (root_ == nullptr)
        {
            root_ = new Node(data);
            return;
        }
        Node *father = nullptr;
        Node *cur = root_;
        while (cur != nullptr)
        {
            if (data == cur->data_)
                return;

            else if (!comp(data, cur->data_)) // 去右子树找
            {
                father = cur;
                cur = cur->right_;
            }
            else
            // 尽量写if else的表达,若全用if，在上一步就有改变cur的可能，若cur变为null在进行comp(data,cur->data_)时就会发生访问空指针的data_
            {
                father = cur;
                cur = cur->left_;
            }
        }

        if (comp(data, father->data_))
        {
            father->left_ = new Node(data);
        }
        else
        {
            father->right_ = new Node(data);
        }
    }

    void insert(const T &val)
    {
        root_ = insert(root_, val);
    }

    void remove(const T &val)
    {
        remove(root_, val);
    }

    bool query(const T &val)
    {
        return !(nullptr == query(root_, val));
    }

    // 节点的删除 非递归
    /*
        理论：
        情况一：删除没有孩子的节点，直接将父节点对应的地址域置为空删除节点
        情况二：删除只有一个孩子的节点，将父节点对应的地址域置为孩子节点的地址，删除节点
        情况三：删除有两个孩子的节点，找待删除节点的前驱节点或者后继节点与待删除节点覆盖后，直接删除前驱节点或后继节点就可以了
    */
    void n_remove(const T data)
    {
        if (root_ == nullptr)
            return;
        Node *father = nullptr;
        Node cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == data) // 找到
            {
                break;
            }
            else if (comp(cur->data_, data)) // 去右子树
            {
                father = cur;
                cur = cur->right_;
            }
            else // 去左子树
            {
                father = cur;
                cur = cur->left_;
            }
        }
        if (cur->left_ != nullptr && cur->right_ != nullptr && cur != nullptr) // 将情况3转为情况1 2
        {
            // 找前驱节点
            Node *node = cur;
            father = cur;
            cur = cur->left_;
            while (cur->right_ != nullptr)
            {
                father = cur;
                cur = cur->right_;
            }
            node->data_ = cur->data_;
        }
        // 在此之后，cur指向节点均为只有一个孩子或没有孩子
        Node *child = cur->left_;
        if (child == nullptr) // 找到有孩子的节点，没有则为空
            child = cur->right_;

        if (father == nullptr) // 特殊情况，删除只有一个节点不为空的root节点，为了保证root不丢失
        {
            root_ = child;
        }
        else if (father->left_ == cur)
        {
            father->left_ = child;
        }
        else
        {
            father->right_ = child;
        }
        delete cur;
    }

    // 节点的查询  非递归
    bool n_find(T val)
    {
        Node *cur = root_;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
            {
                return true;
            }
            else if (comp(cur->data_, val))
            {
                cur = cur->right_;
            }
            else
            {
                cur = cur->left_;
            }
        }
        return false;
    }

    // 前序遍历接口 递归
    void preorder()
    {

        preorder(root_);
        cout << endl;
    }

    void n_preorder() // 前序遍历非递归 V L R
    {
        stack<Node *> s;
        s.push(root_);
        while (!s.empty())
        {
            Node *top = s.top();
            s.pop();
            cout << top->data_ << " ";
            if (top->right_ != nullptr)
            {
                s.push(top->right_);
            }
            if (top->left_ != nullptr)
            {
                s.push(top->left_);
            }
        }
    }

    // 中序遍历接口 递归
    void inorder()
    {
        inorder(root_);
        cout << endl;
    }

    void n_inorder()
    {
        stack<Node *> s;
        Node *cur = root_;

        while (!s.empty() || cur != nullptr)
        {
            if (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left_;
            }
            else
            {
                Node *top = s.top();
                s.pop();
                cout << top->data_ << " ";
                cur = top->right_;
            }
        }
    }

    // 后序遍历接口  递归
    void postorder()
    {
        postorder(root_);
        cout << endl;
    }

    // 后序遍历 非递归
    void n_postorder() // L R V 输出结果与 V R L 结果相反
    {
        stack<Node *> st1;
        stack<Node *> st2;
        st1.push(root_);
        while (!st1.empty())
        {
            Node *top = st1.top();
            st1.pop();
            st2.push(top);
            if (top->left_ != nullptr)
            {
                st1.push(top->left_);
            }
            if (top->right_ != nullptr)
            {
                st1.push(top->right_);
            }
        }
        while (!st2.empty())
        {
            Node *top = st2.top();
            cout << top->data_ << " ";
            st2.pop();
        }
        cout << endl;
    }

    // 层序遍历接口  递归
    void levelOrder()
    {
        int h = high();
        for (int i = 0; i < h; i++)
        {
            levelOrder(root_, i);
        }
    }

    void n_levelOrder()
    {
        queue<Node *> que;
        que.push(root_);
        while (!que.empty())
        {
            Node *top = que.front();
            que.pop();
            cout << top->data_ << " ";
            if (top->left_ != nullptr)
            {
                que.push(top->left_);
            }
            if (top->right_ != nullptr)
            {
                que.push(top->right_);
            }
        }
        cout << endl;
    }

    int high() // 树的高度 递归接口
    {
        return high(root_);
    }

    // 常见面试题

    // 1. BST树区间搜索问题,递归接口
    void findValues(vector<T> &vec, int i, int j)
    {
        findValues(root_, vec, i, j);
    }

    // 2. 判断一颗二叉树是否为BST树
    bool isBSTtree()
    {
        Node *pre = nullptr;
        return isBSTtree(root_, pre);
    }

    // 3. 判断二叉树子树问题
    bool isChild(BST_tree<T, Compare> &child)
    {
        if (child.root_ == nullptr)
        {
            return true;
        }

        Node *cur = root_;

        while (cur != nullptr)
        {
            if (cur->data_ == child.root_->data_)
            {
                break;
            }
            else if (comp(cur->data_, child.root_->data_))
            {
                cur = cur->right_;
            }
            else
            {
                cur = cur->left_;
            }
        }
        if (cur == nullptr)
        {
            return false;
        }
        else
        {
            isChildTree(cur, child->root_);
        }
    }

    // 4. 获取最近公共祖先节点
    bool getLCA( T val1, T val2)
    {
        Node * node = getLCA(root_,val1,val2);
        if(node == nullptr)
            return false;
        return true;
        // Node *cur = root_;
        // while (cur != nullptr)
        // {
        //     if (comp(cur->data_, val1) && comp(cur->data_, val2))
        //     {
        //         cur = cur->right_;
        //     }
        //     else if (comp(val1, cur->data_) && comp(val2, cur->data_))
        //     {
        //         cur = cur->left_;
        //     }
        //     else
        //     {
        //         cout << cur->data_ << endl;
        //         return cur;
        //     }
        // }
        // return nullptr;
    }

    // 5. 二叉树镜像翻转
    void mirror01()
    {
        mirror01(root_);
    }

    //6. 二叉树镜像对称
    bool mirror02()
    {
        return mirror02(root_->left_,root_->right_);

    }
    
    //7. 已知二叉树前序中序，重建二叉树
    Node* rebuild(T pre[],int i,int j,T in[],int m,int n)
    {
        root_ = rebuild(pre,i,j,in,i,j);
    }

    // 8. 判断二叉树是否为平衡树
    bool isBalance()
    {
        return isBalance(root_);
    }
    bool isBalance02()
    {
        int flag = 0;
        isBalance02(root_,0,flag);
        return flag;
    }

    // 9. 求中序遍历倒数第k个节点
    Node* getVal(int k)
    {
        int i = 1;
        return getVal(root_,k,i);
    }

private:
    struct Node // 节点定义
    {
        Node(T data = T())
            : left_(nullptr), right_(nullptr), data_(data)
        {
        }

        ~Node() =default;
        

        Node *left_;
        Node *right_;
        T data_;
    };

    Node *root_;
    Compare comp;

private:
    Node *insert(Node *node, const T &val) // 插入递归实现
    {
        if (node == nullptr) // 递归结束，找到插入val的位置，生成新节点返回节点地址
        {
            Node *n = new Node(val);
            return n;
        }
        if (node->data_ == val)
            return node;
        else if (comp(node->data_, val))
        {
            Node *n = insert(node->right_, val);
            node->right_ = n;
        }
        else
        {
            Node *n = insert(node->left_, val);
            node->left_ = n;
        }
        return node;
    }

    Node *remove(Node *node, const T &val) // 递归删除实现
    {
        if (node == nullptr)
            return nullptr;

        if (node->data_ == val)
        {
            if (node->left_ != nullptr && node->right_ != nullptr)
            {
                Node *cur = node->left_;
                while (cur->right_ != nullptr)
                {
                    cur = cur->right_;
                }
                node->data_ = cur->data_;
                node->left_ = remove(node->left_, cur->data_);
            }
            else
            {
                if (node->left_ != nullptr)
                {
                    Node *l = node->left_;
                    delete node;
                    return l;
                }
                else if (node->right_ != nullptr)
                {
                    Node *r = node->right_;
                    delete node;
                    return r;
                }
                else
                {
                    return nullptr;
                }
            }
        }
        else if (comp(node->data_, val))
        {
            node->right_ = remove(node->right_, val);
        }
        else
        {
            node->left_ = remove(node->left_, val);
        }
        return node;
    }

    Node *query(Node *node, const T &val) // 递归查询实现
    {
        if (node == nullptr)
            return nullptr;
        if (node->data_ == val)
            return node;
        else if (comp(node->data_, val))
        {
            query(node->right_, val);
        }
        else
        {
            query(node->left_, val);
        }
    }

    void preorder(Node *cur) // 前序遍历实现
    {
        if (cur == nullptr)
            return;
        cout << cur->data_ << " ";
        preorder(cur->left_);
        preorder(cur->right_);
    }

    void inorder(Node *cur) // 中序遍历实现
    {
        if (cur == nullptr)
            return;
        inorder(cur->left_);
        cout << cur->data_ << " ";
        inorder(cur->right_);
    }

    void postorder(Node *cur) // 后续遍历实现
    {
        if (cur == nullptr)
            return;
        postorder(cur->left_);
        postorder(cur->right_);
        cout << cur->data_ << " ";
    }

    void levelOrder(Node *cur, int h) // 层序遍历中，第h层的实现
    {
        if (cur == nullptr || h < 0)
            return;
        if (h == 0)
            cout << cur->data_ << " ";
        levelOrder(cur->left_, h - 1);
        levelOrder(cur->right_, h - 1);
    }

    int high(Node *node) // 树的高度
    {
        if (node == nullptr)
            return 0;
        int l = high(node->left_);
        int r = high(node->right_);
        return l > r ? l + 1 : r + 1;
    }

    int number(Node *node) // 树的节点数
    {
        if (node == nullptr)
            return 0;
        int l = number(node->left_);
        int r = number(node->right_);
        return l + r + 1;
    }

    // 1. BST树区间搜索问题,递归接口 实现
    void findValues(Node *node, vector<T> &vec, int i, int j)
    {
        if (node == nullptr)
            return;

        if (node->data_ > i) // 当前节点小于i时没有必要再遍历左子树了，那么只有再当前节点大于i的情况下遍历左子树才有意义
            findValues(node->left_, vec, i, j);

        if (node->data_ > i && node->data_ < j)
            vec.push_back(node->data_);

        if (node->data_ < j) // 当前节点大于j时没有必要在遍历右子树了，那么只有在当前节点小于j的情况遍历右子树才有意义
            findValues(node->right_, vec, i, j);
    }

    // 2. 判断一颗二叉树是否为BST树 实现
    bool isBSTtree(Node *node, Node *&pre) // 只能传引用
    {
        if (node == nullptr)
        {
            return true;
        }

        if (!isBSTtree(node->left_, pre))
        {
            return false;
        }

        if (pre != nullptr)
        {
            if (comp(node->data_, pre->data_))
            {
                return false;
            }
            pre = node;
        }

        if (!isBSTtree(node->right_, pre))
        {
            return false;
        }
        return true;
    }

    bool isChildTree(Node *father, Node *child)
    {
        if (father == nullptr)
            return false;
        if (child == nullptr)
            return true;
        if (father->data_ != child->data_)
            return false;

        if (isChild(father->left_, child->left_) == false)
        {
            return false;
        }
        if (isChild(father->right_, child->right_) == false)
        {
            return false;
        }
        // return isChild(father->left_,child->left_) && isChild(father->right_,child->right_);
        return true;
    }


    // 4. 获取最近公共祖先节点  实现
    Node *getLCA(Node* node,T val1, T val2)
    {
        if(node == nullptr )
            return nullptr;

        if(comp(node->data_,val1) && comp(node->data_,val2))
        {
            return getLCA(node->right_,val1,val2);
        }

        else if(comp(val1,node->data_) && comp(val2,node->data_))
        {
            return getLCA(node->left_,val1,val2);
        }
        else
        {
            return node;
        }
    }

    // 5. BST树镜像翻转
    void mirror01(Node* node)
    {
        if(node == nullptr)
            return;
        Node* tem = node->left_;
        node->left_ = node->right_;
        node->right_ = tem;
        mirror01(node->left_);
        mirror01(node->right_);
    }

    //6. 镜像对称实现
    bool mirror02(Node* l,Node* r)
    {
        if((l == nullptr && r != nullptr) || (l != nullptr && r == nullptr))
            return false;
        if(l == nullptr && r == nullptr)
            return true;
        if(l->data_ != r->data_)
            return false;
        
        if(!mirror02(l->left_,r->right_))
        {
            return false;
        }
        if(!mirror02(l->right_,r->left_))
        {
            return false;
        }
        return true;
        
//        return mirror02(l->left_,r->right_) && mirror02(l->right_,r->left_);
    }
    
    //7. 已知二叉树前序中序，重建二叉树实现
    Node* _rebuild(T pre[],int i,int j,T in[],int m,int n)
    {
        if(i > j || m > n)
        {
            return nullptr;
        }

        Node* node = new Node(pre[i]);
        for(int k=m;k<=n;k++)
        {
            if(pre[i] == in[k])
            {
                node->left_ = _rebuild(pre,i+1,i+k-m,in,m,k-1);
                node->right_ = _rebuild(pre,i+k-m+1,j,in,k+1,n);
                return node;
            }
        }
        return node;
    }

    //8. 判断二叉树是否为平衡树
    bool isBalance(Node* node)
    {
        if(node == nullptr)
            return true;
        if(!isBalance(node->left_))
        {
            return false;
        }
        if(!isBalance(node->right_))
        {
            return false;
        }
        int left = high(node->left_);
        int right = high(node->right_);\
        if(abs(left - right) <= 1)
        {
            return true;
        }
    }

    bool isBalance02(Node* node,int level,int& flag)
    {
        if(node == nullptr)
            return level;
        int left = isBalance02(node->left_,level+1,flag);
        int right = isBalance02(node->right_,level+1,flag);
        flag = true;
        if(abs(left-right) >= 1)
            flag = false;
        return max(left,right);
    }
    // 9. 求中序遍历倒数第k个节点
    Node* getVal(Node* node, int k,int& i)
    {
        // R V L        
        if(node == nullptr)
            return nullptr;

        Node* p =  getVal(node->right_,k,i);
        if(p != nullptr)
            return p;
        if(k != i)
        {
            i++;
        }
        else
        {
            return node;
        }
        return getVal(node->left_,k,i);
    }

    void distory(Node* node)
    {
        if(node->left_ != nullptr)
            distory(node->left_);
        if(node->right_!= nullptr)
            distory(node->right_);
        delete node;
        node = nullptr;
    }
};

int main()
{
    int arr[] = {58, 24, 67, 0, 34, 62, 69, 5, 41, 64, 78};
    BST_tree<int> bst;
    for (auto &i : arr)
        bst.n_insert(i);

    //cout<<bst.getLCA(34, 62)<<endl;
    //bst.mirror01();
    //bst.inorder();
    
    return 0;
}