#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// 快速排序
// 思想：
// 选取一个基准数，将小于基准数的移动到左边，大于基准数的移动到右边
// 然后对基准数左边右边的序列继续进行这样的操作，直到整个序列变得有序
int Partation(int arr[], int l, int r)
{
    int val = arr[l];
    while (l < r)
    {
        while (arr[r] > val && l < r)
        {
            r--;
        }
        if (l < r)
        {
            arr[l] = arr[r];
            l++;
        }
        while (arr[l] < val && l < r)
        {
            l++;
        }
        if (l < r)
        {
            arr[r] = arr[l];
            r--;
        }
    }
    arr[l] = val;
    return l;
}

void Quick_sort(int arr[], int begin, int end)
{
    if (begin >= end) // 递归结束的条件
        return;
    // 在 begin 和 end 区间中 进行一次快排分割处理
    int pos = Partation(arr, begin, end); // 返回基准数

    Quick_sort(arr, begin, pos - 1);
    Quick_sort(arr, pos + 1, end);
}

void quick_sort(int arr[], int size)
{
    Quick_sort(arr, 0, size - 1);
}


int main()
{
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    quick_sort(arr, 10);
    for (int i : arr)
    {
        cout << i << " ";
    }
}