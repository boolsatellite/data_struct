#include <vector>

int maxProfit(std::vector<int> &prices) {
  std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(4, 0));
  dp[0][0] = -prices[0];    dp[0][2] = -prices[0];
  for (int i = 1; i < prices.size(); ++i) {
    dp[i][0] = std::max(dp[i-1][0] , -prices[i]);
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    dp[i][2] = std::max(dp[i - i][2], dp[i - 1][1] - prices[i]);
    dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
  }
  return dp[prices.size()-1][3];
}