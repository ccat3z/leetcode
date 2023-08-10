#include "leetcode_helper.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(const vector<vector<int>>& grid) {
        if (grid.size() == 1) return grid[0][0];

        std::vector<int> cache;
        auto line_size = grid[0].size();
        cache.reserve(line_size);
        for (int i = 0; i < line_size; ++i) cache.emplace_back(0);

        std::vector<int> cache_curr;
        for (auto & line : grid) {
            cache_curr.resize(line_size);
            for (int i = 0; i < line_size; ++i) {
                cache_curr[i] = 50000;
                for (int j = 0; j < line_size; ++j) {
                    if (i == j) continue;
                    cache_curr[i] = std::min(cache_curr[i], cache[j] + line[i]);
                }
            }
            cache = std::move(cache_curr);
        }

        int res = 50000;
        for (auto r : cache) res = std::min(res, r);
        return res;
    }
};

int main() {
    LC_D(Solution::minFallingPathSum);
    LC_T({{1,2,3},{4,5,6},{7,8,9}}, 13);
    LC_T({{7}}, 7);
    return 0;
}