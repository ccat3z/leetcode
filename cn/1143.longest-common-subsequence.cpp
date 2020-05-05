/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (58.71%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    19.5K
 * Total Submissions: 32.9K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 * 
 * 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde"
 * 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
 * 
 * 若这两个字符串没有公共子序列，则返回 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入：text1 = "abcde", text2 = "ace" 
 * 输出：3  
 * 解释：最长公共子序列是 "ace"，它的长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc"，它的长度为 3。
 * 
 * 
 * 示例 3:
 * 
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * 输入的字符串只含有小写英文字符。
 * 
 * 
 */
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int *lcs[2];
        lcs[0] = new int[1001];
        lcs[1] = new int[1001];

        fill(lcs[0], lcs[0] + 1001, 0);
        lcs[1][0] = 0;

        int len1 = text1.length(), len2 = text2.length();

        for (int x = 1; x <= len1; ++x) {
            for (int y = 1; y <= len2; ++y) {
                if (text1[x - 1] == text2[y - 1]) {
                    lcs[1][y] = lcs[0][y - 1] + 1;
                } else {
                    lcs[1][y] = max(lcs[0][y], lcs[1][y - 1]);
                }
            }
            swap(lcs[0], lcs[1]);
        }

        return lcs[0][len2];
    }
};
// @lc code=end

int main() {
    cout << Solution().longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}
