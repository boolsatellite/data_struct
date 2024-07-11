#include <string>
#include <vector>
int countSubstrings(std::string s) {
  std::vector<std::vector<bool>> dp(s.size(),
                                    std::vector<bool>(s.size(), false));
  int result = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    for (int j = i; j < s.size(); ++j) {
      if (s[i] == s[j]) {
        if (j - i <= 1) {
          dp[i][j] = true;
          result++;
        } else {
          if (dp[i + 1][j - 1] == true) {
            dp[i][j] = true;
            result++;
          } else {
            dp[i][j] = false;
          }
        }
      }
    }
  }
  return result;
}