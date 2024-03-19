//
// Created by bools on 19/03/2024.
//

#include "vector"
using namespace std;

vector<vector<int>> vec{};
vector<int> tem;

void backtracking(const std::vector<int>& candidates , int target , int sum , int startIndex) {
    if(sum == target) {
        vec.push_back(tem);
        return;
    }
    if(sum > target) return;
    for(int i=startIndex ; i<candidates.size() ; ++i) {
        tem.push_back(candidates[i]);
        backtracking(candidates , target , sum + candidates[i], i);
        tem.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    backtracking(candidates , target , 0 , 0);
    return vec;
}
