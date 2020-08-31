/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 *
 * https://leetcode-cn.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (32.30%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 62.3K
 * Testcase Example:  '"aacecaaa"'
 *
 * 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
 * 
 * 示例 1:
 * 
 * 输入: "aacecaaa"
 * 输出: "aaacecaaa"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "abcd"
 * 输出: "dcbabcd"
 * 
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1) return s;

        string p; p.reserve(s.size() * 2 - 1);
        p.push_back(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            p.push_back('#');
            p.push_back(s[i]);
        }


        // 0   1   2   3
        // a # b # b # a
        // 0 1 2 3 4 5 6  size=7
        int left = 0;
        int mid = p.size() / 2;
        vector<int> dp(mid + 1);
        int m = 0;
        for (int i = 0; i <= mid; ++i) {
            int &d = dp[i]; d = 0;

            if (i <= m + dp[m]) {
                d = min(dp[2 * m - i], (2 * m - i) - (m - dp[m]));
            }
            for (;i - d < 0 || p[i - d] != p[i + d];++d) {

            }
            while (true) {
                ++d;
                cout << i + d << ' ';
                if (i - d < 0 || p[i - d] != p[i + d]) {
                    --d;
                    break;
                }
                if (i - d == 0) {
                    left = i;
                }
                if (i + d > m + dp[m]) {
                    m = i;
                }
            }

            // cout << endl;
            // cout << vector<char>(p.begin(), p.begin() + i * 2 + 1)
            //      << ' ' << m
            //      << ' ' << i
            //      << endl;
            // cout << dp << endl;
        }

        int c = (p.size() - left * 2 - 1);
        c /= 2;
        string n = s.substr(s.size() - c, c);
        reverse(n.begin(), n.end());
        return n + s;
    }
};
// @lc code=end

int main() {
    vector<string> inputs = {
        "aacecaaa",
        "abcd",
        "",
        "aa",
        "aaa",
        "abb",
        "babbbabbaba",
        "aaaabbaa"
    };
    for_each(inputs.begin(), inputs.end(), [&](string &s) {
        cout << Solution().shortestPalindrome(s) << endl;
    });  
}