#include <vector>
#include <algorithm>

bool canPartition(std::vector<int> &nums) {
    int target = 0;
    for(auto i : nums) {
        target += i;
    }
    if(target % 2 != 0) return false;
    target /= 2;

    int size = nums.size();
    std::vector<int> dp(target + 1);

    // dp[j] = max( dp[j] , dp[j-weight(i) + value[i]] )
    for (int i=0; i<size; ++i) {            // 物品下标
        for(int j=target ; j>=nums[i] ; --j) {    // 背包容量
            dp[j] = std::max(dp[j] , dp[j-nums[i]] + nums[i]);
        }
    }
    if(dp[target] == target) return true;

    return false;
}