#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

vector<int> intersection_(vector<int> &nums1, vector<int> &nums2) {
    std::vector<int> result;
    std::multiset<int> hash_set(nums1.begin(), nums1.end());
    for (auto it = nums2.begin(); it != nums2.end(); ++it) {
        auto hash_it = hash_set.find(*it);
        if (hash_it != hash_set.end()) {
            result.push_back(*it);
            hash_set.erase(hash_it); // 删除找到的元素以避免重复
        }
    }
    return result;
}