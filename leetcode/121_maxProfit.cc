#include <algorithm>
#include <vector>
#include <iostream>

int maxProfit(const std::vector<int> &prices) {
    std::vector<std::vector<int>> dp(prices.size() , std::vector<int>(2));
    dp[0][1] = -prices[0];
    dp[0][0] = 0;

    for(int i=1 ; i<prices.size() ; ++i) {
        dp[i][0] = std::max(dp[i-1][0] , dp[i-1][1]+prices[i]);     // 不持有
        dp[i][1] = std::max(dp[i-1][1] , -prices[i]);     // 持有
        std::cout << "[0]:" << dp[i][0] << " [1]:" << dp[i][1] <<  "  price:" << prices[i] << std::endl;
    }
    return std::max(dp[prices.size()-1][0] , dp[prices.size()-1][1]);
}

int main() {
    maxProfit({7,1,5,3,6,4});
}