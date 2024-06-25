#include <cstdint>
#include <iostream>
#include <type_traits>
#include <vector>

int coinChange(std::vector<int> &coins, int amount) {
  std::vector<int> dp(amount + 1, INT32_MAX);
  dp[0] = 0;
  // dp[j] = min(dp[j-coins[i]] + 1 , dp[j])
  for (int i = 0; i < coins.size(); ++i) {
    for (int j = coins[i]; j <= amount; ++j) {
      if (dp[j - coins[i]] != INT32_MAX)
        dp[j] = std::min(dp[j - coins[i]] + 1, dp[j]);
    }
  }
  return dp[amount] == INT32_MAX ? -1 : dp[amount];
}