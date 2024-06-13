#include <algorithm>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> &cost) {
    std::vector<int> dp;
    dp.resize(cost.size()+1);         // 用于描述最小花费

    dp[0] = 0;
    dp[1] = 0;
    for(int i=2 ; i<=cost.size() ; i++) {
        dp[i] = std::min(dp[i-1] + cost[i-1] , dp[i-2] + cost[i-2]);
    }

    return dp[cost.size()];

}
