// https://leetcode.cn/problems/search-in-rotated-sorted-array/?envType=featured-list&envId=2cktkvj
#include <algorithm>
#include <vector>
#include <iostream>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        return divide(nums, 0, nums.size() - 1, target);
    }

    int divide(const vector<int>& nums, int begin, int end, int target) {
        if (begin == end) {
            if (nums[begin] == target) return begin;
            else return -1;
        }

        auto mid = (begin + end) / 2;
        if (nums[begin] > nums[mid]) {
            // [.......0.|] [.....]
            if (nums[mid+1] <= target && target <= nums[end]) {
                return divide(nums, mid+1, end, target);
            } else {
                return divide(nums, begin, mid, target);
            }
        } else if (nums[mid] > nums[end]) {
            // [.....|] [.0......]
            if (nums[begin] <= target && target <= nums[mid]) {
                return divide(nums, begin, mid, target);
            } else {
                return divide(nums, mid+1, end, target);
            }
        } else {
            // [.....|] [.....]
            if (target <= nums[mid]) {
                return divide(nums, begin, mid, target);
            } else {
                return divide(nums, mid+1, end, target);
            }
        }
    }
};

int main() {
    LC_D(Solution::search);
    LC_T({4,5,6,7,0,1,2}, 0, 4);
    LC_T({4,5,6,7,0,1,2}, 3, -1);
    LC_T({0}, 0, 0);
    return 0;
}
