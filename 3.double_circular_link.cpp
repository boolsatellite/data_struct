#include<iostream>
using namespace std;

class double_circular_link
{
public:
    double_circular_link(int val)
    {
        head_ = new Node;
        head_->next_ = head_;
        head_->pre_ = head_;
    }

    ~double_circular_link()
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            p->next_->pre_ = head_;
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
        head_ = nullptr;
    }

    void insertHead(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_->next_;
        node->pre_ = head_;
        head_->next_->pre_ = node;
        head_->next_ = node;
    }

    void insertTail(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_;
        node->pre_ = head_->pre_;
        head_->pre_ = node;
        head_->pre_->next_ = node;
    }

    void removeOne(int val)
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            if(p->data_ == val)
            {
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
                delete p;
                return;
            }
            else
            {
                p = p->next_;
            }
        }
    }
private:
    struct Node
    {
        Node(int val = 0)
            :next_(nullptr)
            ,pre_(nullptr)
            ,data_(val)
            {}

        Node* next_;
        Node* pre_;
        int data_;
    };
    Node* head_;
};


int main()
{
    
}