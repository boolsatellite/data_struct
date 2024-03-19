//
// Created by bools on 19/03/2024.
//
#include "vector"
using namespace std ;

std::vector<std::vector<int>> result{};
std::vector<int> tem{};

void backTracing(std::vector<int>& nums , int startIndex) {
    result.push_back(tem);

    if(startIndex == nums.size()) {
        return;
    }

    for(int i=startIndex ; i<nums.size() ; ++i) {

        tem.push_back(nums[i]);
        backTracing(nums , i+1);
        tem.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    backTracing(nums , 0);
    return result;
}