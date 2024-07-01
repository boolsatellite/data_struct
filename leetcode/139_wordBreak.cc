#include <string>
#include <vector>

bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::vector<unsigned char> dp(s.size()+1 , 0);
    for(int i=1 ; i<=s.size() ; ++i) {                   // bag
        for(int j=0 ; j<wordDict.size() ; ++j) {        // item
            if(i >= wordDict[j].size()) {              // 保证能容纳物品
                std::string tmp = s.substr(i-wordDict[j].size() , wordDict[j].size());                
                dp[i] = ((tmp == wordDict[j])  && dp[i-wordDict[j].size()] || dp[j]);
            }
        }
    }
    return dp[s.size()];
}