#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//选择排序法
/*
效率较高与冒泡排序，但是不可以优化
*/

void select_sort(int arr[],int length)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(arr[i] > arr[j])
            {
                int tem = arr[j];
                arr[j] = arr[i];
                arr[i] = tem;
            }
        }
    }
}

int main()
{
    srand(time(0));
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i] = rand() %100;
    }
    select_sort(arr,10);
    for(int& i: arr)
    {
        cout<<i<<' ';
    }
}