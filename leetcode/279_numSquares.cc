#include <cstdint>
#include <vector>
#include <type_traits>

int numSquares(int n) {
    std::vector<int> dp(n+1 , INT32_MAX);
    dp[0] = 0;

    for(int i=1 ; i*i<=n ; ++i) {
        for(int j=i*i ; j<=n ; ++j) {
            dp[j] = std::min(dp[j] , dp[j-i*i]+1);
        }
    }

    return dp[n];

    //dp[j] = min(dp[j] , dp[j-i*i] + 1)
}