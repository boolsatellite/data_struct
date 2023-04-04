#include<iostream>
#include<cmath>
#include<functional>
using namespace std;

template<typename T>
class AVLTree
{
public:
    AVLTree():root_(nullptr) {}
    ~AVLTree()
    {
        distory(root_);
    }

    // 节点的插入接口
    void insert(const T& val)
    {
        root_ = insert(root_,val);
    }

    //节点删除操作
    void remove(const T& val)
    {
        Node* father = nullptr;
        root_ = remove(root_,val);
    }


private:
    struct Node
    {
        Node(T data)
            :data_(data)
            ,left_(nullptr)
            ,right_(nullptr)
            ,high_(1)
        {}

        ~Node() = default;

        T data_;
        Node* left_;
        Node* right_;     
        int high_;   
    };
    
    int high(Node* node)
    {
        return node == nullptr ? 0 : node->high_;
    }
    //右旋转操作，左孩子的左子树太高了
    Node* rightRotate(Node* node)
    {
        //旋转
        Node* child = node->left_;
        node->left_ = child->right_;
        child->right_ = node;

        //更新高度
        node->high_ = max(high(child->left_),high(child->left_));
        child->high_ = max(high(child->left_),high(child->left_));

        return child; 
    }

    Node* leftRotate(Node* node)
    {
        //旋转
        Node* child = node->right_;
        node->right_ = child->left_;
        child->left_ = node;
        //更新高度
        node->high_ = max(high(child->left_),high(child->left_));
        child->high_ = max(high(child->left_),high(child->left_));
        return child;
    }
    
    //左平衡
    Node* leftlBalance(Node* node)
    {
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);   
    }

    //右平衡
    Node* rightBalance(Node* node)
    {
        node->right_ = rightRotate(node->right_);
        return leftlBalance(node);
    }
    Node* root_;

    void distory(Node* node)
    {
        if(node == nullptr) return;
        distory(node->left_);
        distory(node->right_);
        delete node;
    }

    //节点插入递归接口实现
    Node* insert(Node* node,const T &val)
    {
        if(node == nullptr)
        {
            return new Node(val);
        }

        if(node->data_ == val)  //找到相同节点返回 当前节点
        {
            return node;
        }
        else if(node->data_ > val)
        {
            node->left_ = insert(node->left_,val);

            if( high(node->left_) - high(node->right_) > 1)   //左子树高于右子树
            {
                //左孩子的左子树高于右子树
                if(high(node->left_->left_) - high(node->left_->right_) >= 1)
                {
                    node = rightRotate(node);  //右旋转
                }
                else
                {
                    node = rightBalance(node);
                }
            }
        }
        else
        {
            node->right_ = insert(node->right_,val);

            if( high(node->right_) - high(node->left_) > 1)
            {
                //右孩子的右子树高
               if(high(node->right_->right_) - high(node->right_->left_))
               {
                    node = leftRotate(node);  //左旋转
               } 
               else
               {
                    node = leftlBalance(node);
               }
            }
        }
        node->high_ = max(high(node->left_) , high(node->right_)) + 1;
        return node;
    }

    Node* remove(Node* node,const T& val)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
         if(node->data_ == val)
        {
            if(node->left_ != nullptr && node->right_ != nullptr)
            {
                //为了避免删除节点造成节点失衡，采用谁高删除谁
                if(high(node->left_) > high(node->right_))
                {
                    //删除前驱节点
                    Node* pre = node->left_;
                    while (pre->right_ != nullptr)
                    {
                        pre = pre->right_;   
                    }
                    node->data_ = pre->data_;
                    node->left_ =  remove(node->left_,pre->data_);
                }
                else
                {
                    //删除后继节点
                    Node* post = node->right_;
                    while (post->left_ != nullptr)
                    {
                        post = post->left_;   
                    }
                    node->data_ = post->data_;
                    node->right_ = remove(node->right_,post->data_);
                }
            }
            else
            {
                if(node->left_ != nullptr)
                {
                    Node* left = node->left_;
                    delete node;
                    return left;
                    
                }
                else if(node->right_ != nullptr)
                {
                    Node* right = node->right_;
                    delete node;
                    return right;
                }
                else
                {
                    return nullptr
                }
            }
         }
         else if(node->data_ > val)
         {
            node->left_ = remove(node->left_,val);
            if(high(node->right_) - high(node->left_) > 1)  //失衡
            {
                if(high(node->right_->right) >= high(node->right_->left_))
                {
                    leftRotate(node);
                }
                else
                {
                    leftlBalance(node);
                }
            }
         }
         else
         {
            node->right_ = remove(node->right_,val);
            if(high(node->left_) - high(node->high_) > 1)
            {
                if(high(node->left_->left_) >= high(node->left_->right_) )
                {
                    rightRotate(node);
                }
                else
                {
                    rightBalance(node);
                }
            }
         }
        node->high_ = max(high(node->left_),high(node->right_)) + 1;
        return node;
    }
};

int main()
{
    AVLTree<int> avl;
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    for(auto& i : arr)
    {
        avl.insert(i);
    }

}