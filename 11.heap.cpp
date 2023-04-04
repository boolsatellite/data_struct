// 一个数组可以看作是一个完全二叉树
// 将首元素看作是根节点，
// arr[] = {1,2,3,4,5,6,7,8};
// 根节点为    1            下标为                                   0
//        2         3       下表为                 0*2+1=1                         0*2+2=2
//    4      5   6     7    下标为         1*2+1=3         1*2+2=4        2*2+1-5             2*2+2=6
//  8                       下标为 3*2+1=7
// 将一个数组看作二叉树。将首元素看作根节点，每层元素下标j与其对应的根节点的下标i对应的关系为 j=i*2+1(左节点) j=i*2+2  (右节点)
// 满足 0 <= i <= (n-1)/2，n代表最后一个元素的下标。
// 如果arr[i] <= arr[2 * i+1] && arr[i] <= arr[2 * i+2]，就是小根堆
// 如果arr[i] >= arr[2 * i+1] && arr[i] >= arr[2 * i+2]，就是大根堆
// 优先级队列实现：
#include <functional>
#include<time.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
class PriorityQueue
{
public:
    using Comp = function<bool(int, int)>;
    PriorityQueue(int cap = 20, Comp comp = greater<int>())
        : size_(0)
        , cap_(cap)
        , comp_(comp)
    {
        que_ = new int[cap_];
    }

    PriorityQueue(Comp comp)
        : size_(0)
        , cap_(20)
        , comp_(comp)
    {
        que_ = new int[cap_];
    }

    ~PriorityQueue()
    {
        delete[]que_;
        que_ = nullptr;
    }

public:
    // 入堆操作
    void push(int val)
    {
        // 判断扩容
        if (size_ == cap_)
        {
            int* p = new int[2 * cap_];
            memcpy(p, que_, cap_ * sizeof(int));
            delete[]que_;
            que_ = p;
            cap_ *= 2;
        }

        if (size_ == 0)
        {
            // 只有一个元素，不用进行堆的上浮调整
            que_[size_] = val;
        }
        else
        {
            // 堆里面有多个元素，需要进行上浮调整
            siftUp(size_, val);
        }
        size_++;
    }

    // 出堆操作
    void pop()
    {
        if (size_ == 0)
            throw "container is empty!";

        size_--;
        if (size_ > 0)
        {
            // 删除堆顶元素，还有剩余的元素，要进行堆的下沉调整
            siftDown(0, que_[size_]);
        }
    }

    bool empty() const { return size_ == 0; }

    int top() const 
    { 
        if (size_ == 0)
            throw "container is empty!";
        return que_[0];
    }

    int size() const { return size_; }

private:
    // 入堆上浮调整 O(logn)   O(1)
    void siftUp(int i, int val)
    {
        while (i > 0) // 最多计算到根节点(0号位)
        {
            int father = (i - 1) / 2;
            if (comp_(val, que_[father]))
            {
                que_[i] = que_[father];
                i = father;
            }
            else
            {
                break;
            }
        }
        // 把val放到i的位置
        que_[i] = val;
    }
    // 出堆下沉调整 O(logn)    O(1)
    void siftDown(int i, int val)
    {
        // i下沉不能超过最后一个有孩子的节点
        while (i <= (size_ -1 -1)/ 2)
        {
            int child = 2 * i + 1; // 第i个节点的左孩子
            if (child + 1 < size_ && comp_(que_[child + 1], que_[child]))
            {
                // 如果i节点右孩子的值大于左孩子, child记录右孩子的下标
                child = child + 1; 
            }

            if (comp_(que_[child], val))
            {
                que_[i] = que_[child];
                i = child;
            }
            else
            {
                break; // 已经满足堆的性质，提前结束
            }
        }
        que_[i] = val;
    }
private:
    int* que_;  // 指向动态扩容的数组
    int size_;  // 数组元素的个数
    int cap_;   // 数组的总空间大小
    Comp comp_; // 比较器对象
};

int main()
{
    // PriorityQueue que; // 基于大根堆实现的优先级队列

    // 基于小根堆实现的优先级队列
    PriorityQueue que([](int a, int b) {return a < b; });
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        que.push(rand() % 100);
    }

    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
}










// {
//     using Comp = function<bool(int, int)>;
//
// public:
//     priorityQueue(int cap, Comp comp = greater<int>())
//         : end_(0), cap_(cap), comp_(comp)
//     {
//         que_ = new int[cap];
//     }
//     ~priorityQueue()
//     {
//         delete[] que_;
//     }
//     void push(int val)
//     {
//         if (end_ == 0)
//             que_[0] = val;
//         else
//         {
//             siftUp(end_, val);
//             end_++;
//         }
//     }
//     void pop()
//     {
//         if (end_ == 0)
//             throw "is empty";
//         else
//         {
//             end_--;
//             siftDown(0, que_[end_]);
//         }
//     }
// private:
//     int *que_;
//     int end_;
//     int cap_;
//     Comp comp_;
//     void siftUp(int i, int val) // 上浮
//     {
//         if (end_ == cap_) // 扩容
//         {
//             int *tem = new int[cap_ * 2];
//             memcpy(tem, que_, sizeof(int) * cap_);
//             delete[] tem;
//             que_ = tem;
//         }
//         int father = (i - 1) / 2;
//         while (i > 0)
//         {
//             if (comp_(que_[father], val))
//             {
//                 que_[i] = que_[father];
//                 i = father;
//             }
//             else break;
//         }
//         que_[i] = val;
//     }
//     void siftDown(int i, int val)
//     {
//         int child = i * 2 + 1; // 左孩子
//         if (child + 1 < end_ - 1 && comp_(que_[child + 1],que_[child]))
//         {
//             child = child + 1;
//         }
//         while (i < (end_ - 1 - 1) / 2)
//         {
//             if (que_[child] < val)
//             {
//                 que_[i] = que_[child];
//                 i = child;
//             }
//             else break;
//         }
//         que_[i] = val;
//     }
// };