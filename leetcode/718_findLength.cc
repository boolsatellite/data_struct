#include <vector>
int findLength(std::vector<int> &nums1, std::vector<int> &nums2) {
    // dp[i][j] nums1以 i-1 结束 ， nums2 以 j-1 结束 重复的最大长度
    std::vector<std::vector<int>> dp(nums1.size()+1 , std::vector<int>(nums2.size()+1));
    int result = 0;
    for(int i=1 ; i<=nums1.size() ; ++i) {
        for(int j=1 ; j<=nums2.size() ; ++j) {
            if(nums1[i-1] == nums2[j-1]) {
                dp[i-1][j-1] += 1;
            }
            if(dp[i][j] > result) result = dp[i][j];
        }
    }
    return result;
}