// 利用大根堆过滤top k小的数据；小根堆过滤前top k大的数据

/*
64  45  52  80  66  68  0   2   18  75
求出上面序列的最小的k个元素

首先将前 k 个元素，看作是一个大根堆进行排序（堆顶元素最大）
从k+1号元素开始与大根堆堆顶元素比较，如果小于堆顶元素就入堆
否则跳过继续判断第 k+2 个元素，直至判断完
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <time.h>
#include <map>
#include<unordered_map>
#include <functional>
using namespace std;

#if 0
int main()
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < 1000; i++)
    {
        vec.push_back(rand() % 10000);
    }

    // 求值最大的前5个元素
    priority_queue<int,vector<int>,greater<int>> minheap;
    for (int i = 0; i < 5; i++)
    {
        minheap.push(vec[i]);
    }
    for(int i=5;i<vec.size();i++)
    {
        if(minheap.top() < vec[i])
        {
            minheap.pop();
            minheap.push(vec[i]);                
        }
    }
    while (!minheap.empty())
    {
        cout<<minheap.top()<<"  ";
        minheap.pop();
    }
}

#endif

int main()
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < 1000; i++)
    {
        vec.push_back(rand() % 10000);
    }

    //统计重复次数最少的前三个元素
    unordered_map<int,int> map;
    for(auto key : vec)
    {
        map[key]++;
    }
    //放入大根堆时，需要存放 key-val
    using Type = pair<int,int>;
    using Comp = function<bool(const Type&,const Type&)>;
    priority_queue<Type,vector<Type>,Comp> maxheap
        (
            [](const Type& a,const Type&b)->bool{
                if(a.second < b.second)
                    return true;
                return false;
            }
        );
    
    auto it = map.begin();
    for(int i=0;i<3;i++)
    {
        maxheap.push(*(it++));
    }

    for(;it != map.end();++it)
    {
        if(maxheap.top().second > (*it).second)
        {
            maxheap.pop();
            maxheap.push(*it);
        }
    }
}
