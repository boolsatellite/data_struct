//
// Created by bools on 2024-01-14.
//
#include <vector>
#include <algorithm>
#include <iostream>


class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int>::iterator it = std::remove(nums.begin(), nums.end(),val);
        return nums.size();
        /*
        nums.erase(it , nums.end());
        return nums.size();
         */
    }
};