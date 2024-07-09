#include <vector>
int maxSubArray(const std::vector<int> &nums) {
    std::vector<int> dp(nums.size() , 0);
    dp[0] = nums[0];
    for(int i=1 ; i<nums.size() ; ++i) {
        dp[i] = std::max(nums[i] , dp[i-1]+nums[i]);
    }
    return dp[nums.size()-1];
}

int main() {
    maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
}