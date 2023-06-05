// https://leetcode.cn/problems/apply-operations-to-an-array/

#include <vector>
#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    vector<int> applyOperations(const vector<int>& nums) {
        vector<int> res = nums;
        size_t i;

        for (i = 0; i < res.size() - 1; ++i) {
            if (res[i] == res[i+1]) {
                res[i] *= 2;
                res[i+1] = 0;
            }
        }

        i = 0;
        for (const auto & num : res) {
            if (num != 0) {
                res[i++] = num;
            }
        }
        for (; i < res.size(); ++i) {
            res[i] = 0;
        }

        return res;
    }
};

int main() {
    LC_D(Solution::applyOperations);
    LC_T({1,2,2,1,1,0}, {1,4,2,0,0,0});
    LC_T({0, 1}, {1, 0});
}