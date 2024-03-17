//
// Created by bools on 17/03/2024.
//

#include "vector"
using namespace std;

int search(vector<int>& nums, int target) {
    int i = 0;
    int j = nums.size() -1;

    while(i <= j) {
        int mid = (i + j) / 2;
        if(nums[mid] > target) {
            j = mid - 1;
        } else if(nums[mid] < target) {
            i = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}