/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 *
 * https://leetcode-cn.com/problems/special-positions-in-a-binary-matrix/description/
 *
 * algorithms
 * Easy (67.19%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    23.4K
 * Total Submissions: 33.7K
 * Testcase Example:  '[[1,0,0],[0,0,1],[1,0,0]]'
 *
 * 给你一个大小为 rows x cols 的矩阵 mat，其中 mat[i][j] 是 0 或 1，请返回 矩阵 mat 中特殊位置的数目 。
 * 
 * 特殊位置 定义：如果 mat[i][j] == 1 并且第 i 行和第 j 列中的所有其他元素均为 0（行和列的下标均 从 0 开始 ），则位置 (i,
 * j) 被称为特殊位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：mat = [[1,0,0],
 * [0,0,1],
 * [1,0,0]]
 * 输出：1
 * 解释：(1,2) 是一个特殊位置，因为 mat[1][2] == 1 且所处的行和列上所有其他元素都是 0
 * 
 * 
 * 示例 2：
 * 
 * 输入：mat = [[1,0,0],
 * [0,1,0],
 * [0,0,1]]
 * 输出：3
 * 解释：(0,0), (1,1) 和 (2,2) 都是特殊位置
 * 
 * 
 * 示例 3：
 * 
 * 输入：mat = [[0,0,0,1],
 * [1,0,0,0],
 * [0,1,1,0],
 * [0,0,0,0]]
 * 输出：2
 * 
 * 
 * 示例 4：
 * 
 * 输入：mat = [[0,0,0,0,0],
 * [1,0,0,0,0],
 * [0,1,0,0,0],
 * [0,0,1,0,0],
 * [0,0,0,1,1]]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == mat.length
 * cols == mat[i].length
 * 1 <= rows, cols <= 100
 * mat[i][j] 是 0 或 1
 * 
 * 
 */
#include <bitset>
#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<bitset<100>> rows;
        rows.reserve(mat.size());
        vector<bitset<100>> cols;
        cols.reserve(mat[0].size());

        for (int i = 0; i < mat.size(); i++) rows.emplace_back(row(mat, i));
        for (int i = 0; i < mat[0].size(); i++) cols.emplace_back(col(mat, i));

        // cout << rows << endl;
        // cout << cols << endl;

        bitset<100> row_mask; row_mask = ~row_mask;
        bitset<100> col_mask; col_mask = ~col_mask;
        int res = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) continue;

                row_mask[j] = col_mask[i] = false;

                // cout << "#" << i << j << endl;
                // cout << rows[i] << endl << row_mask << endl;
                // cout << cols[j] << endl << col_mask << endl;

                if ((rows[i] & row_mask).none() && (cols[j] & col_mask).none()) {
                    res++;
                }

                row_mask[j] = col_mask[i] = true;
            }
        }
        return res;
    }

    inline bitset<100> row(vector<vector<int>>& mat, int row) {
        bitset<100> rowbit;
        for (int i = 0; i < mat[row].size(); i++) {
            rowbit[i] = mat[row][i] == 1;
        }
        return rowbit;
    }

    inline bitset<100> col(vector<vector<int>>& mat, int col) {
        bitset<100> colbit;
        for (int i = 0; i < mat.size(); i++) {
            colbit[i] = mat[i][col] == 1;
        }
        return colbit;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> mat = {{1, 0, 0},
                               {0, 0, 1},
                               {1, 0, 0}};
    cout << Solution().numSpecial(mat) << endl;
    return 0;
}