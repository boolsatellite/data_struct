//
// Created by bools on 6/01/2024.
//

//在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、
// 同一列或同一斜线上，问一共有多少种摆法。

#include <algorithm>
#include <iostream>

bool judge(int* arr , int i) {
    for(int k=0 ; k < i ; ++k) {
        if(std::abs(i - k) == std::abs(arr[i] - arr[k])) {      //位于同一列
            return false;
        }
    }
    return true;
}
int count = 0;

void func(int arr[] , int i , int length) {
    if(i == length) {
        count++;
        for(int j=0 ; j<length ; ++j) {
            std::cout << arr[j] <<" ";
        }
        std::cout << std::endl;
    } else {
        for(int k=i ; k < length ; k++) {
            std::swap(arr[i] , arr[k]);
            if(judge(arr , i)) {
                func(arr , i+1 , length);
            }
            std::swap(arr[k] , arr[i]);
        }
    }
}

int main() {
    //把 arr 数组的下标当作行，下标对应的元素的值当作列
    int arr[] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
    int n = 8;
    func(arr , 0 , n);

    std::cout << std::endl << count;
}

