// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for (int j = 1; j < grid[0].size(); ++j)
            grid[0][j] += grid[0][j-1];
        for (int i = 1; i < grid.size(); ++i)
            grid[i][0] += grid[i-1][0];

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid.back().back();
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout << Solution().maxValue(grid) << endl;

    return 0;
}