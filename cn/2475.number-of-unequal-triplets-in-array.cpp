// https://leetcode.cn/problems/number-of-unequal-triplets-in-array/

#include <vector>
#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int unequalTriplets(const vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
                        ++res;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    LC_D(Solution::unequalTriplets);
    LC_T({4,4,2,4,3}, 3);
    LC_T({1,1,1,1,1}, 0);
    return 0;
}