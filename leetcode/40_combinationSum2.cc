//
// Created by bools on 19/03/2024.
//
#include <algorithm>
#include "vector"
using namespace std;


std::vector<std::vector<int>> res;
std::vector<int> tem;

void backTracing(std::vector<int>& candidates , int target , int sum , int startIndex , std::vector<int>& used) {
     if(sum == target) {
         res.push_back(tem);
         return;
     }
     if(sum > target) return;

     for(int i=startIndex ; i<candidates.size(); ++i) {
         if(i>0 && candidates[i] == candidates[i-1] && used[i-1] == 0) {
             continue;
         }

         used[i] = 1;
         tem.push_back(candidates[i]);
         backTracing(candidates , target , sum+candidates[i] , i+1 , used);
         tem.pop_back();
         used[i] = 0;
     }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::vector<int> used(candidates.size());
    sort(candidates.begin() , candidates.end());
    backTracing(candidates , target , 0 , 0 , used);

    return res;
}