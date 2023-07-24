#include <vector>
#include <algorithm>

#include "leetcode_helper.h"

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            {
                int sum = nums[i] + nums[i+1] + nums[i+2];
                if (sum > target) {
                    if (std::abs(target - sum) < std::abs(target - res))
                        res = sum;
                    break;
                }

                sum = nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1];
                if (sum < target) {
                    if (std::abs(target - sum) < std::abs(target - res))
                        res = sum;
                    continue;
                }
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                  return target;
                if (std::abs(target - sum) < std::abs(target - res))
                  res = sum;

                if (sum > target) {
                    do {
                        --k;
                    } while (k >= 0 && nums[k] == nums[k+1]);
                } else {
                    do {
                        ++j;
                    } while (j < nums.size() && nums[j-1] == nums[j]);
                }
            }
        }

        return res;
    }

    int t(const std::vector<int> &nums, int target) {
        auto n = nums;
        return threeSumClosest(n, target);
    }
};

int main() {
    LC_D(Solution::t);
    LC_T({-1,2,1,-4}, 1, 2);
    LC_T({0,0,0}, 1, 0);
    LC_T({4,0,5,-5,3,3,0,-4,-5}, -2, -2);
    return 0;
}