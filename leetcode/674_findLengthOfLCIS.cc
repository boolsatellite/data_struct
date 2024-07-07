#include <vector>
using std::vector;

int findLengthOfLCIS(vector<int> &nums) {
  if(nums.size() <= 1) return 1;
  vector<int> dp(nums.size(), 0);
  int result = 0;
  dp[0] = 1;
  for (int i = 1; i < nums.size(); ++i) {
    nums[i] > nums[i - 1] ? dp[i] = dp[i - 1] + 1 : dp[i] = 1;
    if(dp[i] > result) result = dp[i];
  }
  return result;
}