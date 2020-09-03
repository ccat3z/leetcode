/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (70.63%)
 * Likes:    577
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 96K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：4
 * 输出：[
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <bitset>
#include "prettyprint.h"
using namespace std;

// col+row    col-row
//   0 1 2 3     0  1  2  3
// 0 0 1 2 3  0  0  1  2  3
// 1 1 2 3 4  1 -1  0  1  2
// 2 2 3 4 5  2 -2 -1  0  1
// 3 3 4 5 6  3 -3 -2 -1  0

// @lc code=start
#define MAX_QUEENS (8)
class Solution {
public:
    vector<vector<string>> res;
    vector<int> queens;
    bitset<MAX_QUEENS> col;
    bitset<MAX_QUEENS> diagonal1;
    bitset<MAX_QUEENS> diagonal2;
    int size;
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        dfs();
        return res;
    }
    void push_res() {
        res.push_back(vector<string>());
        vector<string> &r = res[res.size() - 1];
        for (int i = 0; i < size; ++i) {
            string s(size, '.');
            s[queens[i]] = 'Q';
            r.push_back(s);
        }
    }
    void dfs() {
        int row = queens.size();
        if (row == size) {
            push_res();
        }
        for (int col = 0; col < size; ++col) {
            int d1 = row + col;
            int d2 = col - row + size - 1;
            if (
                this->col[col]
                || this->diagonal1[d1]
                || this->diagonal2[d2]
            ) continue;
            this->col[col] = this->diagonal1[d1] = this->diagonal2[d2] = true;
            queens.push_back(col);
            dfs();
            queens.pop_back();
            this->col[col] = this->diagonal1[d1] = this->diagonal2[d2] = false;
        }
    }
};
// @lc code=end

int main() {
    cout << Solution().solveNQueens(8) << endl;
}
