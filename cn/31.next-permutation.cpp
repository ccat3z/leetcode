// https://leetcode.cn/problems/next-permutation

#include <algorithm>
#include <vector>

#include "leetcode_helper.h"

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int head = nums.size() - 2;
        for (; head >= 0; --head) {
            if (nums[head] < nums[head+1]) break;
        }

        if (head >= 0) {
            for (int next_head = nums.size() - 1; next_head > head; --next_head) {
                if (nums[next_head] > nums[head]) {
                    std::swap(nums[head], nums[next_head]);
                    break;
                }
            }
        }

        std::reverse(nums.begin() + head + 1, nums.end());
        // std::sort(nums.begin() + head + 1, nums.end());
    }

    std::vector<int> w(const std::vector<int>& nums) {
        auto res = nums;
        nextPermutation(res);
        return res;
    }
};

/*
1 - 2 - 3
  - 3 - 2
2 - 1 - 3
  - 3 - 1
3 - 1 - 2
  - 2 - 1

1 - 2 - 3 - 4
      - 4 - 3
  - 3 - 2 - 4
      - 4 - 2
  - 4 - 2 - 3
      - 3 - 2

1 - 1 - 5
  - 5 - 1
5 - 1 - 1
*/

int main() {
    LC_D(Solution::w);
    LC_T({1}, {1});
    LC_T({1,2}, {2,1});
    LC_T({1,2,3}, {1,3,2});
    LC_T({3,2,1}, {1,2,3});
    LC_T({1,1,5}, {1,5,1});
    LC_T({1,5,1}, {5,1,1});
    LC_T({2,4,3,1}, {3,1,2,4});
    return 0;
}