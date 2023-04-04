#include <functional>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 堆排序

void siftDown(int arr[], int i, int size)
{
    int val = arr[i];
    while (i < (size) / 2)
    {
        int child = i * 2 + 1;
        if (child + 1 < size && arr[child + 1] > arr[child])
            child += 1;
            
        if (arr[child] > val)
        {
            arr[i] = arr[child];
            i = child;
        }
        else break;
    }
    arr[i] = val;
}

void HeapSort(int arr[], int size)
{
    int n = size - 1;
    // 从第一个非叶子节点开始调整
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        siftDown(arr, i, size);
    }
    //这样原始的元素就变成了一个大根堆

    //将堆顶元素与末尾元素交换，size-- 从堆顶再次下沉
    for(int i=n;i>0;i--)
    {
        int tem = arr[0];
        arr[0] = arr[i];
        arr[i] = tem;
        siftDown(arr,0,i);
    }
}


int main()
{
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    HeapSort(arr,10);
    for (int i : arr)
    {
        cout << i << " ";
    }
}