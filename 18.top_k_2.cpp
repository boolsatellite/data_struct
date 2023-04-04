#include<iostream>
using namespace std;

int Partation(int arr[],int begin ,int end)
{
    int t = arr[0];
    int i = begin;
    int j = end;
    while (i < j)
    {
        while (i < j && arr[j] > t)
        {
            j--;
        }
        if (i < j && arr[j] < t)
        {
            arr[i] = arr[j];
            i++;
        }
        while (i < j && arr[i] < t)
        {
            i++;
        }
        if (i < j && arr[i] > t)
        {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = t;
    return i;
}

void Select(int arr[], int begin, int end)
{
    int k = 3;
    int pos = Partation(arr,begin,end);
    if(pos == k-1)
    {
        return;
    }
    if(pos > k-1)
    {
        Select(arr,begin,pos);
    }
    if(pos < k-1)
    {
        Select(arr,pos+1,end);
    }
}

int main()
{
    int arr[] = {64, 45, 52, 80, 66, 68, 0, 2, 18, 75};
    int size = sizeof(arr) / sizeof(arr[0]);

    //求最小的前3个
    Select(arr, 0, size - 1);

    for(int i=0;i<3;i++)
    {
        cout<<arr[i]<<" ";
    }
}