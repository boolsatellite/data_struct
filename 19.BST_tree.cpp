// 二叉搜索树 BST树

// 二分搜索算法在逻辑上就是在搜索一颗BST树(Binary Search Tree)
// 把满足 左孩子 < 父节点 < 右孩子 的二叉树称为BST树
#include <queue>
#include <functional>
#include <stack>
#include <iostream>
using namespace std;

template <typename T, typename Compare = less<T>>
class BSTree
{
public:
    BSTree() : root(nullptr) {}

    void insert(T val) // 非递归插入操作
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }

        Node *cur = root;
        Node *father = nullptr;
        while (cur != nullptr)
        {
            if (cur->data_ == val)
                return;

            else if (!comp(cur->data_, val)) // cur->data >= val,排除了=
            {
                father = cur;
                cur = cur->left_;
            }
            else // cur->data < val
            {
                father = cur;
                cur = cur->right_;
            }
        }
        if (comp(val, father->data_))
        {
            father->left_ = new Node(val);
        }
        else
        {
            father->right_ = new Node(val);
        }
    }

    void n_insert(T val) // 递归插入操作
    {
        root = n_insert(root, val);
    }

    /*
    BST树删除节点：
    1.删除没有孩子的节点，父节点中指向孩子节点的指针置为nullptr
    2.删除有一个孩子的节点，父节点中指向这个节点的指针置为孩子节点的地址
    3.删除的节点有两个孩子
        找待删除的节点的前驱节点(或者后继节点)，用前驱或者后继节点的值
        把待删除节点的值覆盖掉，然后直接删除前驱或后继就可以了，前驱节点和后继节点
        都是只有一个孩子，或者没有孩子，这样就转化为了第一二种情况了

        前驱节点：当前节点左子树中的最大值
        后继节点：当前节点右子树中值的最小值
    */
    void remove(const T &val) // 删除节点
    {
        if (root == nullptr)
            return;

        Node *p = root;
        Node *father = nullptr;
        while (p != nullptr)
        {
            if (p->data_ == val) // 找到要删除的节点
            {
                break;
            }
            else if (!comp(p->data_, val))
            {
                father = p;
                p = p->left_;
            }
            else
            {
                father = p;
                p = p->right_;
            }
        }

        if (p == nullptr) // 没有找到
            return;

        if (p->left_ != nullptr && p->right_ != nullptr) // 第三种情况
        {
            // 找前驱
            Node *pre = p->left_;
            while (pre->right_ != nullptr)
            {
                father = pre;
                pre = pre->right_;
            }
            p->data_ = pre->data_;
            p = pre;
        } // 将第三种情况转为第一种或第二种

        Node *child = p->left_; // 使child指向不为空的节点
        if (child == nullptr)
            child = p->right_;

        if (father == nullptr) // 特殊情况，只有根节点和一个叶子节点
            root = child;

        else if (father->left_ == p)
        {
            father->left_ = child;
        }
        else
        {
            father->right_ = child;
        }
        delete p;
    }

    void n_remove(const T &val) // 递归删除节点
    {
        root = n_remove(root, val);
    }

    bool find(T val)
    {
        Node *ptr = root;
        while (ptr != nullptr)
        {
            if (ptr->data_ == val)
            {
                return 1;
            }
            else if (comp(ptr->data_, val))
            {
                ptr = ptr->right_;
            }
            else
            {
                ptr = ptr->left_;
            }
        }
        return 0;
    }

    // 递归查询
    bool n_find(const T &val)
    {
        return nullptr != n_find(root, val);
    }

    // 前序遍历递归
    void preOrder()
    {
        // 由于用户无法操作root，因此需要封装一个接口
        preOrder(root);
    }

    // 非递归前序遍历
    void n_preOrder()
    {
        stack<Node *> s;
        if (root == nullptr)
            return;
        s.push(root);
        while (!s.empty())
        {
            Node *top = s.top();
            s.pop();
            cout << top->data_ << " ";
            if (top->right_ != nullptr)
                s.push(top->right_);
            if (top->left_ != nullptr)
                s.push(top->left_);
        }
    }

    // 中序遍历递归算法。对于BST树中，中序遍历是一个从小到大的过程
    void inOrder()
    {
        inOrder(root);
    }

    // 中序遍历非递归
    void n_inorder()
    {
        if (root == nullptr)
            return;
        Node *cur = root;
        stack<Node *> s;

        /*
        while (cur != nullptr)
        {
            s.push(cur);
            cur = cur->left_;
        }

        while (!s.empty())
        {
            Node *top = s.top();
            s.pop();
            cout << top->data_ << " ";
            if (top->right_ != nullptr)
            {
                cur = top->right_;
                while (cur != nullptr)
                {
                    s.push(cur);
                    cur = cur->left_;
                }
            }
        }
        */

        // 优化后：
        while (cur != nullptr || !s.empty())
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

    // 后序遍历递归
    void postOrder()
    {
        postOrder(root);
    }

    // 后续非递归
    void n_postOrder()
    {
        stack<Node *> s1;
        stack<Node *> s2;
        s1.push(root);
        while (!s1.empty())
        {
            Node *top = s1.top();
            s1.pop();
            s2.push(top);
            if (top->left_ != nullptr)
            {
                s1.push(top->left_);
            }
            if (top->right_ != nullptr)
            {
                s1.push(top->right_);
            }
        }
        while (!s2.empty())
        {
            Node *top = s2.top();
            s2.pop();
            cout << top->data_ << " ";
        }
    }

    // 层序遍历递归算法
    void levalOrder()
    {
        int h = high();
        for (int i = 0; i < h; ++i)
        {
            levalOrder(root, i);
        }
    }

    // 层序遍历非递归
    void n_levalOrder()
    {
        queue<T *> q;
        q.push(root);
        while (!q.empty())
        {
            Node*front = q.front();
            q.pop();
            cout << front->data_ << " ";
            if (front->left_ != nullptr)
                q.push(front->left_);
            if (front->right_ != nullptr)
                q.push(front->right_);
        }
    }

    // 递归求高度
    int high()
    {
        return high(root);
    }

    // 递归求节点个数
    int number()
    {
        return number(root);
    }

private:
    struct Node
    {
        Node(T data = T())
            // 零构造，再不传入参数时，如果是普通类型就置为0，若为类类型就调用默认构造函数
            : data_(data), left_(nullptr), right_(nullptr)
        {
        }

        T data_;
        Node *left_;
        Node *right_;
    };

private:
    Node *n_insert(Node *node, T val)
    {
        if (node == nullptr)
        {
            // 递归结束，找到新节点插入的位置返回新节点的地址
            return new Node(val);
        }

        if (node->data_ == val)
            return node;
        else if (comp(node->data_, val))
        {
            node->right_ = n_insert(node->right_, val);
            return node;
        }
        else
        {
            node->left_ = n_insert(node->left_, val);
            return node;
        }
        return node;
    }

    Node *n_remove(Node *node, T val)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data_ == val)
        {
            // 找到要删除的节点
            // 第3种情况
            if (node->left_ != nullptr && node->right_ != nullptr)
            {
                // 找前驱
                Node *pre = node->left_;
                while (pre->right_ != nullptr)
                {
                    pre = pre->right_;
                }
                node->data_ = pre->data_;
                // 删除pre指向的节点
                node->left_ = n_remove(node->left_, pre->data_);
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
                    delete node;
                    return nullptr;
                }
            }
        }
        else if (comp(node->data_, val))
        {
            node->right_ = n_remove(node->right_, val);
        }
        else
        {
            node->left_ = n_remove(node->left_, val);
        }
        return node;
    }

    Node *n_find(Node *node, T val)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data_ == val)
        {
            return node;
        }
        else if (comp(node->data_, val))
        {
            return n_find(node->right_, val);
        }
        else
        {
            return n_find(node->left_, val);
        }
    }

    void preOrder(Node *ptr)
    {
        if (ptr == nullptr)
            return;
        cout << "V:" << ptr->data_ << endl;
        preOrder(ptr->left_);
        preOrder(ptr->right_);
    }

    void inOrder(Node *ptr)
    {
        if (ptr == nullptr)
            return;
        inOrder(ptr->left_);
        cout << "V:" << ptr->data_ << " ";
        inOrder(ptr->right_);
    }

    void postOrder(Node *ptr)
    {
        if (ptr == nullptr)
            return;
        inOrder(ptr->left_);
        inOrder(ptr->right_);
        cout << "V:" << ptr->data_ << " ";
    }
    void levalOrder(Node *node, int i)
    {
        if (node == nullptr)
            return; // 防止节点只有一个孩子时，访问空指针

        if (i == 0)
        {
            cout << node->data_ << " ";
            return;
        }

        levalOrder(node->left_, i - 1);
        levalOrder(node->right_, i - 1);
    }

    int high(Node *node)
    {
        if (node == nullptr)
            return 0;
        int left = high(node->left_);
        int right = high(node->right_);
        return left > right ? left + 1 : right + 1;
    }

    int number(Node *node)
    {
        if (node == nullptr)
            return 0;
        int leftChild = number(node->left_);
        int rightChild = number(node->right_);
        return leftChild + leftChild + 1;
    }

private:
    Node *root;
    Compare comp;
};

int main()
{
    int ar[] = {58, 24, 67, 0, 34, 62, 69, 5, 41, 64, 78};
    BSTree<int> bst;
    for (int v : ar)
    {
        // bst.n_insert(v);
        bst.n_insert(v);
    }
    bst.n_postOrder();

    // cout << bst.n_find(11);
}