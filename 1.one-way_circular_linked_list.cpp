#include<ctime>
#include<iostream>
using namespace std;

//单向循环链表
class link
{
public:
    link()
    {
        head_ = new Node;
        tail_ = head_;
        head_->next_ = head_;
    }

    ~link()
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
    }

    void insertHead(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
        if(node->next_ == head_)
        {
            tail_ = node;
        }
    }

    void insertTail(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_;
        tail_->next_ = node;
        tail_ = node;
    }

    void removeOne(int val)
    {
        Node* p = head_;
        Node* q = head_->next_;
        while (q != head_)
        {
            if(q->data_ == val)
            {
                p->next_ = q->next_;
                delete q;
                if(p->next_ == head_)
                tail_ = p;
                break;
            }
            else
            { 
                p = p->next_;
                q = q->next_;
            }
        }
    }

    bool Find(int val) const
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            if(p->data_ == val)
                return true;
             p = p->next_;
        }
    return false;        
    }

    void show() const
    {
        Node* p = head_->next_;
        while(p != head_)
        {
            cout<<p->data_<<' ';
            p = p->next_;
        }       
    }

private:
    struct Node
    {
        Node(int val = 0)
        {
            next_ = nullptr;
            data_ = val;
        }
        Node* next_;
        int data_;
    };
    
    Node* head_;
    Node* tail_;
};

int main()
{
    srand(time(0));
    link link;
    for(int i=0;i<10;i++)
    {
        link.insertHead(rand() % 100);
    }
    link.show();
}
