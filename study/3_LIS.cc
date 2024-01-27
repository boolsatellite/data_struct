//
// Created by bools on 2024-01-17.
//

/*
 * LIS 问题：求序列的最长非降（升序）子序列长度
 *
 * 输入：5 3 4 1 8 7 9
 * 输出：3 4 7 9
 *
 * dp[i] 以第i个元素结尾的非降子序列长度
 * dp[0] = 1
 * dp[1] = max{1 , 1 + dp[0](arr[0] <= arr[1])} _
 * dp[2] = max{1+dp[0](arr[0] <= arr[2]) , 1+dp[1](arr[1] <= arr[2])}
 *
 * dp[i] = max{1+dp[j](arr[j] <= arr[i])}
 */


#include <iostream>

void func(int arr[] , int length) {
    int maxval = 0;
    int* dp = new int[length]();
    dp[0] = 1;
    for(int i=1 ; i<length ; ++i) {
        dp[i] = 1;
        for(int j=0 ; j<i ; ++j) {                          //i=1 j=0 dp[1]=1
            if(arr[i] >= arr[j] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j] + 1;
                if(dp[i] > maxval) maxval = dp[i];
            }
        }
    }
    std::cout << maxval << std::endl;
}

int main() {
    int arr[] = {5 ,3 ,4, 1, 8, 7, 9};
    func(arr , sizeof(arr) / sizeof(arr[0]));
}


