// https://leetcode.cn/problems/number-of-unequal-triplets-in-array/

#include <unordered_map>
#include <vector>
#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int unequalTriplets(const vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnts;

        for (auto &n : nums) {
            ++cnts[n];
        }

        int i = 0;
        for (auto &[n, cnt] : cnts) {
            res += i * cnt * (nums.size() - cnt - i);
            i += cnt;
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