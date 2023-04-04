#include<iostream>

//二分搜索非递归实现

int* dichotomous_seach(int *arr,int length,int val)  //假设数组元素从小到大
{
    int first  = 0;
    int last = length - 1;
    while (first <= last)   //循环条件要注意
    {
        int middle = (first + last)/2;
        if(val > arr[middle])
        {
            first = middle + 1;
        }
        else if(val < arr[middle])
        {
            last = middle - 1;
        }
        else
            return arr + middle;
    }
    return nullptr;
}
/*
时间复杂度分析：
二分搜索的各个情况写出来就是一个 二叉搜索树，
搜索的时间与树的层数成正比
所以，只需计算层数与数据规模的关系即可
假设树的每一层都是满的：
设，树的高度为 L  数据规模为 n
有：n = 2^L - 1  ==> L = logn   顾时间复杂度为 logn
*/

//二分搜索的递归实现
int dichotomous_seach_(int *arr,int i,int j,int val)  //假设数组元素从小到大
{
    if(i > j) return -1;

    if(arr[(i+j)/2] == val) 
        return (i+j)/2;
    if(arr[(i+j)/2] > val)
        dichotomous_seach_(arr,i,(i+j)/2-1,val);
    if(arr[(i+j)/2] < val)
        dichotomous_seach_(arr,(i+j)/2+1,j,val);
}


int main()
{
    int arr[] = {12,34,35,39,45,57,59};
    int *p = dichotomous_seach(arr,sizeof(arr)/sizeof(arr[0]),34);
    std::cout<<(*p)<<std::endl;
}

