#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

//冒泡排序法
/*
相邻元素相互比较，每次比较将这一组最大或最小的元素沉底
*/
void bubble_sort(int arr[],int length)
{
    for(int i=0;i<length - 1;i++)  
    {
        bool flag = true;
        for(int j=0;j<length-i-1;j++)  
        //本元素与下一个元素进行比较，当轮到下标为length-1个时会与本轮的最后一个元素(下标为length)比较
        {
            
            if(arr[j] > arr[j+1])
            {
                int i = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = i;
                flag = false;
            }
        }
        if(flag == true) return;   //如果在某一趟中没有发生数据交换，说明元素的顺序已经排好了
    }
}
/*
冒泡排序是所有排序算法中效率最底下的，本质原因就是交换的次数太多

*/

int main()
{
    srand(time(0));
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i] = rand() %100;
    }
    bubble_sort(arr,10);
    for(int& i: arr)
    {
        cout<<i<<' ';
    }
}