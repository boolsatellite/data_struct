#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 希尔排序法
// 实际就是分组进行插入排序，分组的意义是为了使数据在全局上趋于有序
// 当数据趋于有序时，插入排序法的效率是最高的

void Hill_sort(int arr[], int length)
{
    for (int gap = length / 2; gap > 0; gap/=2)
    {
        for (int i = gap; i < length; i++)
        {
            int t = arr[i];
            int j = i - gap;
            for (; j >= 0; j-=gap)
            {
                if (arr[j] > t)
                {
                    arr[j + gap] = arr[j];
                }
                else
                    break;
            }
            arr[j + gap] = t;
        }
    }
}

int main()
{
    srand(time(0));
    int arr[] = {2,4,1,6,9};
    // for(int i=0;i<10;i++)
    // {
    //     arr[i] = rand() %100;
    // }

    Hill_sort(arr,5);
    for(int& i: arr)
    {
        cout<<i<<' ';
    }
}
