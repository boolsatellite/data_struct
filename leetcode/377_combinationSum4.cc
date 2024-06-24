#include <vector>
#include <iostream>

int combinationSum4(const std::vector<int> &nums, int target) {
    std::vector<int> dp(target+1);
    dp[0] = 1;
    for(int i=1 ; i<=target ; ++i) {                 // 背包
        for(int j=0 ; j<nums.size() ; ++j) {         // 物品
            if(i >= nums[j])
                dp[i] += dp[i - nums[j]];
        }
    }
    return dp[target];
}

int main() {
    std::cout << combinationSum4({1,2,3}, 4);
}