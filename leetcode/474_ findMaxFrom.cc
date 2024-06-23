#include <string>
#include <vector>

int findMaxForm(std::vector<std::string> &strs, int m, int n) {
  std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1 , 0));
  // dp[i][j] = max(dp[i][j] , dp[i-m][j-n] + value)

  for (int object = 0; object < strs.size(); ++object) {
    int x{}, y{};
    for (auto &i : strs[object]) { // 计算 0 1 的数量
      if (i == '0')
        x++;
      else
        y++;
    }

    for (int i = m; i >= x; --i) {   // 0
      for (int j = n; j >= y; --j) { // 1
        dp[i][j] = std::max(dp[i][j] , dp[i-x][j-y] + 1);
      }
    }
  }
  return dp[m][n];
}