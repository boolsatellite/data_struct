#include <vector>
int maxUncrossedLines(const std::vector<int> &nums1, const std::vector<int> &nums2) {
// dp[i][j]    以 nums1[i-1] , nums2[j-1] 结尾的最大相交数(重复子序列)
  int result = 0;
  std::vector<std::vector<int>> dp(nums1.size()+1 , std::vector<int>(nums2.size()+1));
  //dp[i][i]
  for(int i=1 ; i<=nums1.size() ; ++i) {
    for(int j=1 ; j<=nums2.size() ; ++j) {
      if(nums1[i-1] == nums2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = std::max(dp[i-1][j] , dp[i][j-1]);
      }
      if(dp[i][j] > result) result = dp[i][j];
    }
  }
  return result;
}

int main() {
  maxUncrossedLines({3,3}, {3});
}