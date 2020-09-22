/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (42.34%)
 * Likes:    619
 * Dislikes: 0
 * Total Accepted:    109.9K
 * Total Submissions: 252.3K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <tuple>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int row;
    int col;
    int len;
    string word;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        this->word = word;
        len = word.size();
        for (int x = 0; x < col; ++x) {
            for (int y = 0; y < row; ++y) {
                if (find(board, x, y, 0)) return true;
            }
        }
        return false;
    }
    bool find(vector<vector<char>>& board, int x, int y, int i) {
        // no more string
        if (i == len) return true;

        // overflow
        if (x < 0 || col <= x) return false;
        if (y < 0 || row <= y) return false;

        // not match
        if (board[y][x] != word[i]) return false;

        board[y][x] = 0;
        if (find(board, x-1, y, i+1)) return true;
        if (find(board, x+1, y, i+1)) return true;
        if (find(board, x, y-1, i+1)) return true;
        if (find(board, x, y+1, i+1)) return true;
        board[y][x] = word[i];

        return false;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<vector<char>>, string>> inputs = {
        make_tuple(vector<vector<char>>({
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'},
        }), "ABCCED"),
        make_tuple(vector<vector<char>>({
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'},
        }), "SEE"),
        make_tuple(vector<vector<char>>({
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'},
        }), "ABCB"),
    };
    for (auto args : inputs) {
        cout << Solution().exist(get<0>(args), get<1>(args)) << endl;
    }
}