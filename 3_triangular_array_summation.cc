//
// Created by bools on 2024-01-24.
//

/*给定一个三角形，找出自顶向下的最小路径。每一步只能移动到小一行中相邻的节点上
 *           【2】
 *        【3】 【4】
 *      【6】 【5】 【7】
 *    【4】 【1】 【8】 【3】
 * 自顶向下的最小路径和为 11 (2 + 3 + 5 + 1 = 11)
 * */

#include <vector>
#include <memory>
#include <iostream>

int main() {
    std::vector<std::vector<int>> v{{2} , {3 , 4},{6 , 5 , 7},{4 , 1 , 8 , 3}};
    //dp[i][j]:第i行第j列元素开始选择数字和的最小值
    int** dp = new int*[v.size()];
    for(int i=0 ; i<v.size() ; ++i) {
        dp[i] = new int[v[i].size()];
    }

    int n = v.size() -1;
    for(int i=0 ; i<v[3].size() ; ++i) {
        dp[n][i] = v[n][i];
    }

    for(int i=n-1 ; i>=0 ; --i) {
        for(int j=0 ; j<v[i].size() ; ++j) {
            dp[i][j] = std::min(dp[i+1][j] , dp[i+1][j+1]) + v[i][j];
        }
    }

    std::cout << dp[0][0] << std::endl;
}


