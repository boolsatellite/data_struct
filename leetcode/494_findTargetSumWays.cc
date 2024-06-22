#include <cmath>
#include <vector>

int findTargetSumWays(std::vector<int> &nums, int target) {   // 装满背包有多少种方法
  /**
   * left = right = target
   * left + right = sum;
   * left = (target + sum) / 2
   */
  int sum = 0;
  for (auto i : nums) sum += i;
  if(std::abs(target) > sum) return 0;
  if((target + sum) % 2 == 1) return 0; 
  int left = (target + sum) / 2;

  std::vector<int> dp(left + 1);
  dp[0] = 1;
  // dp[j] = sum(dp[j-nums[i]])
  for(int i=0 ; i<nums.size() ; ++i) {
    for(int j=left ; j>=nums[i] ; --j) {
      dp[j] += dp[j-nums[i]];
    }
  }
  return dp[left];
}