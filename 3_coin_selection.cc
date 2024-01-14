//
// Created by bools on 2024-01-13.
//


/*硬币选择问题：
 * 有 1 ， 3 ， 5 面额的硬币，给定一个面值 11 ，
 * 问：组成给定面值所需要的最少硬币数量是多少？？？

 */


#include <iostream>
#include <algorithm>

/*
11:              1 + (10)                             3 + （8）                      5 + （6）
10:  1 + （9）    3 + （7）     5 + （5）
                                  8：  1 + （7）       3 +（5）     5 + （3）
                                                                  6:    1 + (5)      3 + (3)     5 + (1)
子问题 (3) (5) (7) 被重复求解
 */



int func1(int n) {                          //采用分治算法
    if (n == 1 || n == 3 || n == 5) {
        return 1;
    } else if (n == 2 || n == 4) {           //防止递归时 n 为负数
        return 2;
    } else {
        int n1 = func1(n - 1) + 1;
        int n2 = func1(n - 3) + 1;
        int n3 = func1(n - 5) + 1;
        return std::min({n1, n2, n3});
    }
}

int main1() {
    int n = 18;
    int num = func1(n);
    std::cout << num << std::endl;

}


const int n = 18;
int dp[n + 1] = {0};        //dp[n]:组成价值n需要的硬币最少数量

int func(int n) {          //动态规划求解
    if (dp[n] > 0) return dp[0];

    if (n == 1 || n == 3 || n == 5) {
        dp[n] = 1;
        return 1;
    } else if (n == 2 || n == 4) {
        dp[n] == 2;
        return 2;
    } else {
        int n1 = func(n - 1) + 1;
        int n2 = func1(n - 3) + 1;
        int n3 = func1(n - 5) + 1;
        int min = std::min({n1, n2, n3});
        dp[n] = min;
        return min;
    }
}

/*
 dp[0] = 0

 dp[1] = 1 + dp[1-1];

 dp[2] = 1 + dp[2-1] = 1 + dp[1]

 dp[3] = 1 + dp[3-1] = 1 + dp[2]
 dp[3] = 1 + dp[3-3] = 1 + dp[0]

 dp[4] = 1 + dp[4-1] = 1 + dp[3]
 dp[4] = 1 + dp[4-3] = 1 + dp[1]

 dp[5] = 1 + dp[5-1] = 1 + dp[4]
 dp[5] = 1 + dp[5-3] = 1 + dp[2]
 dp[5] = 1 + dp[5-5] = 1 + dp[0]
    只需令 dp[0]=0 就可以推导出 dp[n]
*/


int main() {                        //循环写法
    int v[] = {1, 3, 5};
    int c = 18;
    int *dp = new int[c + 1]();
    dp[0] = 0;

    for (int i = 1; i <= c; ++i) {
        int min = INT32_MAX;
        for (int j = 0; j < sizeof v / sizeof v[0]; ++j) {
            if(i >= v[j]) {
                int t = 1 + dp[i - v[j]];
                if (t < min) {
                    min = t;
                }
            }
        }
        dp[i] = min;
    }
    std::cout <<dp[11];

   // std::cout << func(n);
}
