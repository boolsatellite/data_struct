#include <pthread.h>
#include <vector>
#include <string>

int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<std::vector<int>> dp(text1.size()+1 , std::vector<int>(text2.size()+1));
    //dp[i][j] : test1 以 i-1 结束  ，  test2 以 j-1 结束 的最长公共子序列
    for(int i=1 ; i<=text1.size() ; ++i) {
        for(int j=1 ; j<=text2.size() ; ++j) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}