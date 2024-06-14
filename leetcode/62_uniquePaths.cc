#include <vector>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp{};
    for(int i=0 ; i<m ; ++i) {
        dp.push_back(std::vector<int>(n));
    }

    // init
    for(int i=0 ; i<dp.size() ; ++i) {
        dp[i][0] = 1;
    }

    for(int i=0 ; i<dp[0].size() ; ++i) {
        dp[0][i] = 1;
    }

    for(int i=1 ; i<m ; ++i) {
        for(int j = 1 ; j<n ; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}