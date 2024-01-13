//
// Created by bools on 2024-01-13.
//

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) {
            return;
        }
        if (m == 0) {
            nums1 = nums2;
        }
        // m n 为个数
        std::vector<int> x;
        x.reserve(m + n);
        int i = 0;
        int j = 0;
        //存放到x中
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                x.push_back(nums1[i++]);
            } else {
                x.push_back(nums2[j++]);
            }
        }
        while(i < m) {
            x.push_back(nums1[i++]);
        }
        while(j < n) {
            x.push_back(nums2[j++]);
        }
        nums1 = x;
    }
};