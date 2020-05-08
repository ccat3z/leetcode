/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    46.8K
 * Total Submissions: 112K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        const int width = matrix[0].size();
        int *ms[2];
        ms[0] = new int[width + 1];
        ms[1] = new int[width + 1];


        fill(&ms[0][0], &ms[0][width + 1], 0);
        ms[1][0] = 0;

        int maxS = 0;
        for (auto line = matrix.begin(); line != matrix.end(); ++line) {
            for (int i = 1; i <= width; ++i) {
                if ((*line)[i - 1] == '1') {
                    // 4 5
                    // 3 1
                    ms[1][i] = min(ms[0][i - 1], min(ms[1][i - 1], ms[0][i])) + 1;
                } else {
                    ms[1][i] = 0;
                }
                maxS = max(ms[1][i], maxS);
            }
            swap(ms[0], ms[1]);
        }

        return maxS * maxS;
    }
};
// @lc code=end

int main() {
    vector<vector<char>> m;
    m.push_back(vector<char>({'1', '0', '1', '0', '0'}));
    m.push_back(vector<char>({'1', '0', '1', '1', '1'}));
    m.push_back(vector<char>({'1', '1', '1', '1', '1'}));
    m.push_back(vector<char>({'1', '0', '0', '1', '0'}));
    cout << Solution().maximalSquare(m) << endl;
    return 0;

}