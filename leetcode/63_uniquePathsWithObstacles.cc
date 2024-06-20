#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();                // 行
    int n = obstacleGrid[0].size();             // 列

    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    std::vector<std::vector<int>> dp(m,std::vector<int>(n));
    // init
    for(int i=0 ; i<m ; ++i) {
        if(obstacleGrid[i][0] == 0) {
            dp[i][0] = 1;
        } else {
            break;
        }
    } 

    for(int i=0 ; i<n ; ++i) {
        if(obstacleGrid[0][i] == 0) {
            dp[0][i] = 1;
        } else {
            break;
        }
    }

    // dp[i][i] = dp[i-1][j] + dp[i][j-1]
    for(int i=1 ; i<m ; ++i) {
        for(int j=1 ; j<n ; ++j) {
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}