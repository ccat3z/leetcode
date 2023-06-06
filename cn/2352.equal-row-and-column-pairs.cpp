// https://leetcode.cn/problems/equal-row-and-column-pairs/

#include <vector>
#include "leetcode_helper.h"
using namespace std;

class Solution {
public:
    int equalPairs(const vector<vector<int>>& grid) {
        auto n = grid.size();
        int res = 0;

        for (size_t r = 0; r < n; ++r) {
            for (size_t c = 0; c < n; ++c) {
                size_t i;
                for (i = 0; i < n && grid[r][i] == grid[i][c]; ++i);
                if (i == n) ++res;
            }
        }
        
        return res;
    }
};

int main() {
    LC_D(Solution::equalPairs);
    LC_T({{3,2,1},{1,7,6},{2,7,7}}, 1);
    LC_T({{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}}, 3);
    return 0;
}