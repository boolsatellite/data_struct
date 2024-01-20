//
// Created by bools on 2024-01-20.
//

#include <string>
#include <iostream>


/*
 * LCS：求两个序列的最长公共子序列长度
 *
 * X: x1 , x2 , x3 ... xn
 * Y: y1 , y2 , y3 ... yn
 *
 * 如果：xn == ym
 * LCS(x[1...n],Y[1...m]) = LCS(X[1...n-1],Y[1...m]) + 1
 * 如果：xn != ym
 * LCS(x[1...n],Y[1...m]) = max{LCS(x[1...n],Y[1...m-1]) , LCS(x[1...n-1],Y[1...m])}
 * */

int LCS(std::string& str1, int i, std::string& str2, int j) {       //分治
    if(i < 0 || j < 0) return 0;

    if(str1[i] == str2[j]) {
        return LCS(str1 , i-1 , str2 , j-1) + 1;
    } else {
        int ret1 = LCS(str1 , i , str2 , j-1);
        int ret2 = LCS(str1 , i-1 , str2 , j);
        return std::max(ret1 , ret2);
    }
}

int main01() {
    std::string str1 = "helloworld";
    std::string str2 = "hlweord";

    int size = LCS(str1 , str1.size() -1 , str2 , str2.size() -1);
    std::cout << size <<std::endl;
}

int** dp;
int LCS01(std::string& str1 , int i , std::string& str2 , int j) {
    if(i < 0 || j < 0) {
        return 0;
    }

    if(str1[i] == str2[j]) {
        dp[i][j] = LCS01(str1 , i-1 , str2 , j-1);  //*(*(dp+j) + i)
        return dp[i][j];
    } else {
        int ret1 = LCS(str1 , i , str2 , j-1);
        int ret2 = LCS(str1 , i-1 , str2 , j);
        dp[i][j] = std::max(ret1 , ret2);
        return dp[i][j];
    }
}


int main() {
    std::string str1 = "helloworld";
    std::string str2 = "hlweord";

    const int n = str1.size();
    const int m = str2.size();
    dp = new int*[n];       //n行 m列
    for(int i=0 ; i<n ; i++) {
        dp[i] = new int[m];
    }

    int size = LCS01(str1 , n-1 , str2 , m-1);
    std::cout << size << std::endl;
}



