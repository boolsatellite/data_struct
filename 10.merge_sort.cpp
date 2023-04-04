// 归并排序
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void Merge(int arr[], int l, int m, int r,int*p)
{
    int idx = 0;
    int i = l;
    int j = m + 1;
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            p[idx++] = arr[i++];
        if (arr[i] > arr[j])
            p[idx++] = arr[j++];
    }
    while (i <= m)
    {
        p[idx++] = arr[i++];
    }
    while (j <= r)
    {
        p[idx++] = arr[j++];
    }

    for (int i, j = 0; i <= r; i++, j++)
    {
        arr[i] = p[j];
    }
    if(r-l+1 == 1) 
        delete p;
    if(r-l+1>1)
        delete[] p;
}

void merge_sort(int arr[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    int*p = new int[end-begin+1];
    Merge(arr, begin, mid, end,p);
    delete[] p;
}

int main()
{
    srand(time(0));
    int arr[5];
    for (int i = 0; i < 6; i++)
    {
        arr[i] = rand() % 100;
    }

    merge_sort(arr, 0, 6);
    for (int i : arr)
    {
        cout << i << " ";
    }
}
