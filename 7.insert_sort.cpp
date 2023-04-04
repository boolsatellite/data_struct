#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//插入排序
//如果数据有序，那么插入排序法是所以排序算法中效率最高的
//在基础的排序算法中 插入排序 > 选择排序 > 冒泡排序
//插入排序法 不仅仅没有交换而且比较的次数也少


void insert_sort(int arr[],int length)
{
    for(int i=1;i<length;i++)    //从第1号元素开始，至最后一个元素都要插入到指定的位置
    {
        int t = arr[i];
        int j=i-1;
        for(;j>=0;j--)   //第i号元素之前的所以元素
        {     
          if(arr[j] >= t)
          {
            arr[j+1] = arr[j];  //如果第i号元素之前的元素小于第i号元素的话，就向后覆盖
          }
          else
            break;              //当找到第一个小于第i号元素时，结束循环
        }
        arr[j+1] = t;           //如果找到了小于第i号元素的下标，那么就再此元素后插入t
                                //如果没有找到就在第0号位置插入t
    }
}

int main()
{
    srand(time(0));
    int arr[] = {2,3,4,1};
    // for(int i=0;i<10;i++)
    // {
    //     arr[i] = rand() %100;
    // }

    insert_sort(arr,4);
    for(int& i: arr)
    {
        cout<<i<<' ';
    }
}
