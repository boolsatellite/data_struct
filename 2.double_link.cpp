#include<iostream>
using namespace std;

class doubleLink
{      
public:
    doubleLink()
    {
        Node* node = new Node;
        head_ = node;
    }

    void insertHead(const int& val)
    {
        Node* p = new Node(val);
        p->next = head_->next;
        p->pre = head_;
        if(head_->next != nullptr)   //当只有头结点时
            head_->next->pre = p;    //在进行指针的连续访问时要注意访问空指针
        head_->next = p;
    }

    void insertTail(int val)
    {
        Node* node = new Node(val);
        Node* p = head_;
        while (p->next != nullptr)  //p指向尾节点
        {
            p = p->next;
        }
        node->pre = p;
        p->next = node;
    }

    void show()
    {
        Node* p = head_->next;
        while (p != nullptr)
        {
            cout<<p->data<<' ';
            p = p->next;
        }   
    }

    void removeOne(int val)
    {
        Node* p = head_->next;
        while (p != nullptr)
        {
            if(p->data == val)
            {
                p->pre->next = p->next;
                if(p->next != nullptr)
                    p->next->pre = p->pre;
                delete p;
                return;
            }
            p = p->next;
        }
        
    }

    ~doubleLink()
    {
        Node* p = head_;
        while (head_ != nullptr)
        {
            head_ = head_->next;
            delete p;
            p = head_;
        }        
    }

private:
    struct Node
    {
        Node(int val=0)
            :pre(nullptr)
            ,next(nullptr)
            ,data(val)
        {}
        Node* pre;
        Node* next;
        int data;
    };
    Node* head_;
};


int main()
{
    
}