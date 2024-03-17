//
// Created by bools on 2024-01-14.
//
#include <vector>
#include <algorithm>
#include <iostream>


class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        int right = nums.size();
        int left = 0;

        while (left <= right) {
            if(nums[left] == val) {
                nums[left] = nums[right--];
            } else {
                left++;
            }
        }
        return left;
    }
};