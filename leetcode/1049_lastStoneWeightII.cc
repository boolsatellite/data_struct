#include <vector>

int lastStoneWeightII(std::vector<int> &stones) {
    int sum = 0;
    for(auto i : stones) sum += i;

    int target = sum / 2;
    std::vector<int> dp(target+1 , 0);
    for(int i=0 ; i<stones.size() ; ++i) {
        for(int j=target ; j>=stones[i] ; --j) {
            dp[j] = std::max(dp[j] , dp[j-stones[i]] + stones[i]);
        }
    }
    int optimal_size = dp[target];
    return sum - (2 * optimal_size);
}