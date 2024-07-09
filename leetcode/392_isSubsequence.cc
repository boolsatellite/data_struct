#include <string>
#include <vector>
bool isSubsequence(std::string s, std::string t) {
  std::vector<std::vector<unsigned char>> dp(s.size()+1 , std::vector<unsigned char>(t.size()+1));
  int max_len = 0;
  for(int i=1 ; i<=s.size() ; ++i) {
    for(int j=1 ; j<=t.size() ; ++j) {
      if(s[i-1] == t[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = std::max(dp[i-1][j] , dp[i][j-1]);
      }
      if(dp[i][j] > max_len) max_len = dp[i][j];
    }
  }
  return s.size() == max_len;
}