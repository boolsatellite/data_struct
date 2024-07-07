#include <iostream>
#include <vector>

int lengthOfLIS(const std::vector<int> &nums) {
  if (nums.size() <= 1)
    return nums.size();
  std::vector<int> dp(nums.size(), 1);
  int result = 0;
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j])
        dp[i] = std::max(dp[i], dp[j] + 1);
    }
    if (dp[i] > result)
      result = dp[i]; // 取长的子序列
  }
  return result;
}

int main() { std::cout << lengthOfLIS({0}) << std::endl; }