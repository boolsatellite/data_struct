//
// Created by bools on 19/03/2024.
//
#include <set>
#include <map>
#include <unordered_set>
#include "vector"
using namespace std;

vector<vector<int>> res{};
vector<int> path{};

void backTracing(vector<int>& nums , int startIndex) {
    if(path.size() > 1) {
        res.push_back(path);
    }

    for(int i=startIndex ; i<nums.size() ; ++i) {
        unordered_set<int> set{};
        if(set.find(nums[i]) != set.end() || i>0 && nums[i] < path.back() && !path.empty()) {
            continue;
        }

        path.push_back(nums[i]);
        backTracing(nums , i+1);
        path.pop_back();
    }

}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    backTracing(nums , 0);
    return res;
}
