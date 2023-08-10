#include "leetcode_helper.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(const vector<vector<int>>& grid) {
        if (grid.size() == 1) return grid[0][0];

        int min = 0, min2 = 0, min_idx = -1;
        int curr_min, curr_min2, curr_min_idx;

        for (auto & line : grid) {
            curr_min = curr_min2 = 50000;
            for (int i = 0; i < line.size(); ++i) {
                int curr = (min_idx == i ? min2 : min) + line[i];
                if (curr < curr_min) {
                    curr_min2 = curr_min;
                    curr_min = curr;
                    curr_min_idx = i;
                } else if (curr < curr_min2) {
                    curr_min2 = curr;
                }
            }
            min = curr_min;
            min2 = curr_min2;
            min_idx = curr_min_idx;
        }

        return min;
    }
};

int main() {
    LC_D(Solution::minFallingPathSum);
    LC_T({{1,2,3},{4,5,6},{7,8,9}}, 13);
    LC_T({{7}}, 7);
    return 0;
}