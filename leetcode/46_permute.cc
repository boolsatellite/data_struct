//
// Created by bools on 20/03/2024.
//

#include "vector"
using namespace std;

std::vector<std::vector<int>> result{};
std::vector<int> tem{};

void backTracing(std::vector<int>& nums , std::vector<int>& used) {
    if(tem.size() == nums.size()) {
        result.push_back(tem);
        return;
    }
    for(int i=0 ; i<nums.size() ; ++i) {
        if(used[i] == 1) {
            continue;
        }
        tem.push_back(nums[i]);
        used[i] = 1;
        backTracing(nums , used);
        used[i] = 0;
        tem.pop_back();
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    std::vector<int> used(nums.size());
    backTracing(nums , used);
    return result;
}