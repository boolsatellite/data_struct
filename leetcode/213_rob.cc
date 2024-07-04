#include <vector>
int rob(std::vector<int> &nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return std::max(nums[0] , nums[1]);
    int first = 0;
    std::vector<int> dp(nums.size() , 0);
    // dp[i] = max( dp[i-1] , nums[i]+dp[i-2] )
    dp[0] = nums[0];
    dp[1] = std::max(nums[0] , nums[1]);
    for(int i=2 ; i<nums.size()-1 ; ++i) {
        dp[i] = std::max(dp[i-1] , nums[i]+dp[i-2]);
    }
    first = dp[nums.size()-2];
    
    dp[1] = nums[1];
    dp[2] = std::max(nums[1] , nums[2]);
    for(int i=3 ; i<nums.size() ; ++i) {
        dp[i] = std::max(dp[i-1] , nums[i]+dp[i-2]);
    }
    
    return std::max(first , dp[nums.size()-1]);

}