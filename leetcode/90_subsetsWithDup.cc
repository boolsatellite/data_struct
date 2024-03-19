//
// Created by bools on 19/03/2024.
//
#include <algorithm>
#include "vector"
using namespace std;

std::vector<std::vector<int>> res{};
std::vector<int> tem{};

void backStracing(std::vector<int>& nums , int startIndex , std::vector<int>& used) {
    res.push_back(tem);

    if(startIndex == nums.size()) return;

    for(int i=startIndex ; i<nums.size() ; ++i) {
        if(i>0 && nums[i] == nums[i-1] && used[i-1] == 0) {
            continue;
        }

        used[i] = 1;
        tem.push_back(nums[i]);
        backStracing(nums , i+1 , used);
        tem.pop_back();
        used[i] = 0;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin() , nums.end());
    std::vector<int> used(nums.size());
    backStracing(nums , 0 , used);

    return res;

}