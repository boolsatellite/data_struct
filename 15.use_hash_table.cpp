#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<stdlib.h>
#include<vector>
#include<time.h>
using namespace std;


int main()
{
    //模拟问题，vector中存放这原始数据
    vector<int> vec;
    srand(time(0));
    for(int i=0;i<10000;i++)
    {
        vec.push_back(rand()%10000);
    }
    //找第一个出现重复的数字
    unordered_set<int> s1;
    for(auto i:vec)
    {
        auto it = s1.find(i);
        if(it == s1.end())
        {
            s1.insert(i);
        }
        else
        {
            cout<<"key "<<i<<endl;
            break;
        }
    }

    //找所有出现重复的数字
    unordered_map<int,int> m1;
    for(int i : vec)
    {
        auto it = m1.find(i);
        if(it == m1.end())
        {
            m1.emplace(i,1);
        }
        else
        {
            it->second+=1;
        }
    }


    for(auto& i : m1)
    {
        if(i.second > 1)
        {
            cout<<"key:"<<i.first<<"val:"<<i.second<<endl;
        }
    }
}