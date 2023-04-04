#include<iostream>
#include<cmath>

template<typename T>
class AVL_tree
{
public:
    AVL_tree():root_(nullptr){}

    //AVL树的插入操作
    void insert(const T& val)
    {
        root_ = insert(root_,val);
    }

    //AVL树的删除操作
    void remove(const T& val)
    {
        remove(root_,val);
    }

private:

struct Node;

    int high(Node* node)
    {
        return node==nullptr ? 0 : node->high_;   
    }
    //右旋转操作：
    Node* rightRotate(Node* node)
    {
        Node* child = node->left_;
        node->left_ = child->right_;
        child->right_ = node;
        node->high_ = std::max(high(node->left_),high(node->right_)) + 1;
        child->high_ = std::max(high(child->left_),high(child->right_)) + 1;
        return child;
    }
    //左旋转操作
    Node* leftRotate(Node* node)
    {
        Node* child = node->right_;
        node->right_ = child->left_;
        child->left_ = node;
        node->high_ = std::max(high(node->left_),high(node->right_)) +1;
        child->high_ = std::max(high(child->left_),high(child->right_)) + 1;
        return child;
    }
    //右平衡
    Node* rightBlance(Node* node)
    {
        node->right_ = rightRotate(node->right_);
        return leftRotate(node);
    }
    //左平衡
    Node* leftBlance(Node* node)
    {
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);
    }

struct Node
{
    Node(T data = T())
        :data_(data)
        ,left_(nullptr)
        ,right_(nullptr)
        ,high_(1)
        {}

    T data_;
    Node* left_;
    Node* right_;
    int high_;
};

    Node* root_;

    Node* insert(Node* node,const T& val)
    {
        if(node == nullptr)
        {
            return new Node(val);
        }

        if(node->data_ > val)
        {
            node->left_ = insert(node->left_,val);  //往当前节点的左子树插入，可能造成当前节点的左子树太高了           
            //回溯的过程中：
            if(high(node->left_) - high(node->right_) > 1)  //插入可能导致节点失衡，故需要旋转
            {
                if(high(node->left_->left_) >= high(node->left_->right_))
                {
                    node = rightRotate(node);
                }
                else
                {
                    node = leftBlance(node);
                }
            }
            //由于插入和旋转导致树高度变化，故需更新高度
            node->high_ = std::max(high(node->left_) , high(node->right_)) + 1;
        }
        else if(node->data_ < val)
        {
            node->right_ = insert(node->right_,val);

            //回溯的过程中
            if(high(node->right_) - high(node->left_) > 1)
            {
                if(high(node->right_->right_) >= high(node->right_->left_))
                {
                    node = leftRotate(node);
                }
                else
                {
                    node = rightBlance(node);
                }
            }
            node->high_ = std::max(high(node->left_) , high(node->right_)) + 1;
        }
        
        else
        {
            return node;
        }

        //node->high_ = std::max(high(node->left_) , high(node->right_)) + 1;
        return node;
    }

    //删除操作递归接口实现
    Node* remove(Node* node,const T& val)
    {
        if(node == nullptr)   //当node为空时说明没有找到，返回空节点
            return nullptr;
    
        if(node->data_ > val)
        {
            node->left_ = remove(node->left_,val);
            //删除左子树上的节点可能导致右子树太高了
            if(high(node->right_) - high(node->left_) >1)  //节点失衡
            {
                if(high(node->right_->right_ >= node->right_->left_))
                {
                    node = leftRotate(node);
                }
                else
                {
                    node = rightBlance(node);
                }
            }
        }
        else if(node->data_ < val)
        {
            node->right_ = remove(node->right_,val);
            //删除右子树节点可能导致左子树太高了
            if(high(node->left_) - high(node->right_) > 1)  //节点失衡
            {
                if(high(node->left_->left_) > high(node->left_->right_))
                {
                    node = rightRotate(node);
                }
                else
                {
                    node = leftBlance(node);
                }
            }

        }
        else  //找到要删除的节点
        {
            //先处理有两个孩子的情况
            if(node->left_ != nullptr && node->right_ != nullptr)
            {
                //为了防止删除节点影响当前node树的平衡性，采用删除node较高的子树
                if(high(node->left_) >= high(node->right_))
                {
                    //删除前驱节点
                    Node* pre = node->left_;
                    while (pre->right_ != nullptr)
                    {
                        pre = pre->right_;   
                    }
                    node->data_ = pre->data_;
                    node->left_ = remove(node->left_,pre->data_);  //删除前驱节点
                }
                else
                {
                    Node* post = node->right_;
                    while (post->left_ != nullptr)
                    {
                        post = post->left_;   
                    }
                    node->data_  =post->data_;
                    node->right_ = remove(node->right_,post->data_);  //删除后继节点
                }
            }
            else
            {
            //处理有一个孩子或者没有孩子的情况
                Node* child = node->left_;
                if(child == nullptr)
                    child = node->right_;  //child指向不为空的孩子，若孩子为空child为空
                delete node;
                return child;
            }
        }
        node->high_ = max(high(node->left_) , high(node->right_)) + 1;
        return node;
    }
};


int main()
{
    AVL_tree<int> avl;
    for(int i=1;i<=5;i++)
    {
        avl.insert(i);
    }

}