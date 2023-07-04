#include "leetcode_helper.h"
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
using namespace leetcode;

class Solution {
public:
    int _matrixSum(const vector<vector<int>>& nums) {
        auto n = nums;
        return matrixSum(n);   
    }

    int matrixSum(vector<vector<int>>& nums) {
        for (auto & line : nums) {
            std::sort(line.begin(), line.end(), std::greater<int>());
        }

        auto rows = nums.size();
        auto cols = nums[0].size();

        int res = 0;
        int col_max = 0;
        for (int i = 0; i < cols; ++i) {   
            for (int j = 0; j < rows; ++j) {
                col_max = std::max(nums[j][i], col_max);
            }
            // std::cerr << col_max << std::endl;
            res += col_max;
            col_max = 0;
        }

        return res;
    }
};

int main() {
    LC_D(Solution::_matrixSum);
    LC_T({{7,2,1},{6,4,2},{6,5,3},{3,2,1}}, 15);
    LC_T({{1}}, 1);
    return 0;
}