//
// Created by bools on 2024-01-15.
//
#include "vector"

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 1;
        int j = 1;
        while(j < nums.size()) {
            if(nums[j] > nums[j-1]) {
                nums[i++] = nums[j++];
            } else {
                j++;
            }
        }
        return i;
    }
};
