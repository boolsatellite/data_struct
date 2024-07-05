#include <vector>
#include <iostream>

int maxProfit(const std::vector<int> &prices) {
  std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2));
  // [0] 持有    [1] 不持有
  // dp[i][0] = max(dp[i-1][0] , dp[i-1][1] - prices[i])
  // dp[1][1] = max(dp[i-1][1] , dp[i-1][0] + prices[i])
  dp[0][0] = -prices[0];
  dp[0][1] = 0;
  for (int i = 1; i < dp.size(); ++i) {
    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  }
  return std::max(dp[prices.size()-1][0] , dp[prices.size()-1][1]);
}