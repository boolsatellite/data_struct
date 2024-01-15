//
// Created by bools on 2024-01-15.
//

/*
                    f(5)
            f(4)             f(3)
        f(3)    f(2)    f(2)       f(1)

 */

#include "iostream"

uint64_t * dp;

uint64_t fabonacci(int n) {                  //n：斐波那契数列中的第几个，返回对应的值
    if(dp[n] != 0) return dp[n];

    if(n == 1 || n == 2) {
        dp[n] = 1;
        return 1;
    } else {
        dp[n] = fabonacci(n-1) + fabonacci(n-2);
        return dp[n];
    }
}

int main1() {
    int n = 200;
    dp = new uint64_t [n+1]();
    std::cout << fabonacci(n);
}

int main() {
    int n = 20;
    dp = new uint64_t[n + 1]();
    dp[1] = dp[2] = 1;
    for(int i=3 ; i<=n ; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}