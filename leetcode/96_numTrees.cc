#include <vector>
#include <iostream>

int numTrees(int n) {
    std::vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
   // dp[2] = 2;

    for(int i=2 ; i<=n ; ++i) {
        // dp[i] = dp[0] * dp[i] + dp[1] * dp[i-1] + dp[2] * dp[i-2] + ... + 
        int sum = 0;
        for(int j=0 ; j<=i-1 ; ++j) {
            sum += dp[j] * dp[i-j-1]; 
        }
        dp[i] = sum;
    }
    return dp[n];
}