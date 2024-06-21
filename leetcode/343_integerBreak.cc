#include <algorithm>
#include <vector>
#include <iostream>

int integerBreak(int n) {
    std::vector<int> dp(n+1);
    //  init
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    /**
     * @brief dp 数组含义
     * dp[i] 的最大值
     */
    for(int i=3 ; i<=n ; ++i) {
        int max = -1;
        for(int j=1 ; j<i ; ++j) {
            int currentMax = std::max((j * (i-j)) , j * dp[i-j]);
            std::cout << "currentMax = " << currentMax << " i = " << i << " j = " << j << std::endl;
            max = currentMax > max ? currentMax : max;    //1 * dp[2] 
            std::cout << "max = " << max << std::endl;
            //dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
            std::cout << std::endl;
        }
        dp[i] = max;
    }
    return dp[n];
}

int main() {
    std::cout << integerBreak(4) << std::endl;
}