//
// Created by bools on 17/03/2024.
//

#include "vector"
using namespace std;


vector<int> vi = {1 , 2 , 3 , 4 , 5 , 6 ,7 , 8 , 9};
vector<vector<int>> ret;
int g_sum;

void lookBack(int sum , int k , int startIndex , vector<int>& tem) {
    if(g_sum > sum) return;

    if(tem.size() == k) {
        if(g_sum == sum) ret.push_back(tem);
        return;
    }

    for(int i=startIndex ; i<vi.size() ; ++i) {
        g_sum += vi[i];
        tem.push_back(vi[i]);
        lookBack(sum , k , i+1 , tem);
        tem.pop_back();
        g_sum -= vi[i];
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    std::vector<int> tem;
    lookBack(n , k , 0 , tem);
    return ret;
}
