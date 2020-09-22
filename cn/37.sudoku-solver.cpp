/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (62.32%)
 * Likes:    646
 * Dislikes: 0
 * Total Accepted:    56.9K
 * Total Submissions: 85.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * 提示：
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */
#include <vector>
#include "prettyprint.h"
#include <iostream>
#include <bitset>
using namespace std;

// @lc code=start
struct State {
    bitset<9> rows[9];
    bitset<9> cols[9];
    bitset<9> blks[9];
    void filled(int x, int y, int n) {
        rows[x][n-1] = cols[y][n-1] = blks[y / 3 * 3 + x / 3][n-1] = 1;
    }
    void removed(int x, int y, int n) {
        rows[x][n-1] = cols[y][n-1] = blks[y / 3 * 3 + x / 3][n-1] = 0;
    }
    bool can_fill(int x, int y, int n) {
        return rows[x][n-1] == 0 &&
            cols[y][n-1] == 0 &&
            blks[y / 3 * 3 + x / 3][n-1] == 0;
    }
};

class Solution {
public:
    State state;
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    state.filled(i, j, board[i][j]  - '0');
                } 
            }
        }
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, int x, int y) {
        char &at = board[x][y];
        if (y == 9) return true;
        int nx = (x + 1) % 9;
        int ny = x == 8 ? y + 1 : y;

        if (at != '.') {
            if (dfs(board, nx, ny)) return true;
        } else {
            for (int i = 1; i <= 9; ++i) {
                if (state.can_fill(x, y, i)) {
                    state.filled(x, y, i);
                    board[x][y] = i + '0';
                    if (dfs(board, nx, ny)) return true;
                    board[x][y] = '.';
                    state.removed(x, y, i);
                }
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    vector<vector<vector<char>>> boards = {
        {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}},
    };
    for (auto board : boards) {
        Solution().solveSudoku(board);
        cout << board << endl;
    }
}

