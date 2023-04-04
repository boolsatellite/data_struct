#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<memory>
using namespace std;

int main()
{
    vector<int> vec = {12,78,80,123,45,78};
    int max = vec[0];
    for(auto& i : vec)
    {
        if(i>max)
        {
            max = i;
        }
    }
    int *bitmap = new int[max/32 + 1]();
    unique_ptr<int> ptr(bitmap);

    //找第一个重复出现的元素
    for(auto key : vec)
    {
        int index = key / 32;   //第几个32
        int offset = key % 32;  //32中的第几个
        if(bitmap[index] & 1<<offset != 0)
        {
            cout<<key<<" 重复了"<<endl;
        }
        else
        {
            bitmap[index] = bitmap[index] | 1<<offset;
        }
    }
    cout<<"没有重复"<<endl;
}
