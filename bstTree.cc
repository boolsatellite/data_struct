#include "iostream"

/*
 * BST插入节点：
 * BST为空 - 插入节点为root节点
 * BST不为空 - 从根节点开始比较，找到合适位置生成新节点，并将节点的地址写入父节点对于的地址域中
 * */

#include "functional"
template<typename T , typename Compare = std::less<T>>
class BSTree{
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
                if(!comp_( cur->data_ , val)) {
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
}