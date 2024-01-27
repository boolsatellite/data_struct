//
// Created by bools on 2024-01-21.
//

// 0-1 背包问题

#include <algorithm>
#include <iostream>

/* 0 - 1 背包问题：有一组物品，其重量分别为 w1 ， w2 ， w3 .。。 wn 其价值分别为 v1 ， v2  v3 ..。 vn
 * 现有一个背包，其容量为 C , 问：怎样将物品装入背包才能使价值最大化
 *
 * dp(i,j) : 所选物品范围在 i ... n , 背包容量为 j ，背包所容纳的最大价值
 *
 * 状态转移方程：
 * i == n 只考虑一个物品 wn
 *      wn > j : 第n个物品无法放入背包 dp[n][j] = 0
 *      wn <=j : 第n和物品可以放入背包 dp[n][j] = vn
 *
 * i , i+1 , i+2 , n 是可选的
 *      wi > j : 说明第 i 个物品无法装入背包 dp[i][j] = dp[i+1][j]
 *      wi <=j : 说明第 i 个物品可以装入背包 dp[i][j] = MAX(dp[i+1][j] , vi + dp[i+1][j-wi])
 *
 */


void backStrace(int w[], int v[], int n, int c, int **dp, int row, int column) {
    int bestv = 0;
    for (int i = 0; i < n; i++) {
        //if(dp[i][c] != dp[i+1][c]) {        //*((int*)dp + column*i + c)
        if (*(int *) dp + column * i + c != *((int *) dp + column * (i + 1) + c)) {
            std::cout << w[i] << " ";
            bestv += v[i];
            c -= w[i];
        }
    }
    if (*((int *) dp + (n * column) + c) > 0) {
        bestv += v[n];
        std::cout << w[n] << " ";
    }

}


int main() {
    int w[] = {8, 6, 4, 2, 5};
    int v[] = {6, 4, 7, 8, 6};
    const int n = sizeof(w) / sizeof(w[0]) - 1;
    const int c = 12;

    int dp[n + 1][c + 1]{};

    for (int j = 1; j <= c; ++j) {
        if (w[n] > j) {      //无法容纳
            dp[n][j] = 0;
        } else {
            dp[n][j] = v[n];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= c; ++j) {
            if (w[i] > j) {          //无法容纳
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = std::max(dp[i + 1][j], v[i] + dp[i + 1][j - w[i]]);
            }
        }
    }
    backStrace(w, v, n, c, reinterpret_cast<int **>(&dp), n + 1, c + 1);

/*
    for(int i=0 ; i <=n ; ++i) {
        for(int j=0 ; j<c ; ++j) {
            std::cout << dp[i][j] << "  ";
        }
        std::cout << std::endl;
    }
*/


}

/*
(8,6)   0  0  8  8  8  8  15  15  15  15  15  21
(6,4)   0  0  8  8  8  8  15  15  15  15  15  21
(4,7)   0  0  8  8  8  8  15  15  15  15  15  21
(2,8)   0  0  8  8  8  8  8   14  14  14  14  14
(5,6)   0  0  0  0  0  6  6   6   6   6   6   6

*/


