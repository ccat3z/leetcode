/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (48.50%)
 * Likes:    800
 * Dislikes: 0
 * Total Accepted:    161.8K
 * Total Submissions: 333K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//i0     +6      +6
// 0     6       12
//i1 +4 +2  +4   +2
// 1   5 7    11 13
//i2 +2  +4  +2  +4
// 2 4   8 10    14
//i3     +6      +6
// 3     9       15

//         +8
// 0       8
//      +6
// 1     7
// 2   6
// 3 5
// 4

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        for (int row = 0; row < numRows; ++row) {
            int a = (numRows - 1 - row) * 2, b = row * 2;
            int i = row;
            if (i < s.length()) res.push_back(s[i]);
            else continue;
            for (;;) {
                if (a != 0) {
                    i += a;
                    if (i < s.length()) res.push_back(s[i]);
                    else break;
                }
                if (b != 0) {
                    i += b;
                    if (i < s.length()) res.push_back(s[i]);
                    else break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    cout << Solution().convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
