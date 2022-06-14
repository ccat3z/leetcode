/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 *
 * https://leetcode-cn.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (48.99%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    78.3K
 * Total Submissions: 145.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    // 0,0 0,1 0,2
    // 1,0 1,1 1,2
    // 2,0 2,1 2,2
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int size_x = mat.size();
        int size_y = mat[0].size();
        vector<int> res;
        res.reserve(size_x * size_y);

        for (int layer = 0; layer < (size_x * size_y); ++layer) {
            if (layer % 2 == 0) {
                int x = min(size_x-1, layer);
                int y = layer - x;

                for (; x >= 0 && y < size_y; --x, ++y) {
                    // cout << x << ' ' << y << endl;
                    res.emplace_back(mat[x][y]);
                }
            } else {
                int y = min(size_y-1, layer);
                int x = layer - y;

                for (; x < size_x && y >= 0; ++x, --y) {
                    // cout << y << ' ' << x << endl;
                    res.emplace_back(mat[x][y]);
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    // vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6}
    };
    cout << Solution().findDiagonalOrder(mat) << endl;
    return 0;
}