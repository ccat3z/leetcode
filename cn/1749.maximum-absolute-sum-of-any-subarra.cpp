// https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/

#include "leetcode_helper.h"
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxAbsoluteSum(const std::vector<int>& nums) {
        int min_slice = nums[0], max_slice = nums[0];
        int min_prefix = nums[0], max_prefix = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            min_prefix = std::min(nums[i], min_prefix + nums[i]);
            min_slice = std::min(min_slice, min_prefix);

            max_prefix = std::max(nums[i], max_prefix + nums[i]);
            max_slice = std::max(max_slice, max_prefix);
        }

        if (min_slice > 0) return max_slice;
        else return std::max(-min_slice, max_slice);
    }
};

int main() {
    LC_D(Solution::maxAbsoluteSum);
    LC_T({1,-3,2,3,-4}, 5);
    LC_T({2,-5,1,-4,3,-2}, 8);

    return 0;
}
