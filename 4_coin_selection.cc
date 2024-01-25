//
// Created by bools on 2024-01-25.
//

/*硬币选择问题：
 * 有 1 ， 3 ， 5 面额的硬币，给定一个面值 11 ，
 * 问：组成给定面值所需要的最少硬币数量是多少？？？
 */

#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {1 , 3 , 5};
    int length = sizeof arr / sizeof arr[0];
    int c = 11;
    std::sort(arr , arr + length , [](int a , int b)->bool {return a > b;});

    int idx = 0;
    int cnt = 0;
    while(c > 0) {
        if(c >= arr[idx]) {
            c -= arr[idx];
            cnt++;
        } else {
            idx++;
        }
    }
    std::cout << cnt << std::endl;
}




