/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (62.39%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    37.5K
 * Total Submissions: 59.9K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 输入："aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串长度不会超过 1000 。
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int d = 0; i - d >= 0 && i + d < s.size(); ++d) {
                if (s[i - d] != s[i + d]) break;
                ++count;
            }
            for (int d = 0; i - d >= 0 && i + d + 1 < s.size(); ++d) {
                if (s[i - d] != s[i + d + 1]) break;
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

int main() {
    vector<string> inputs = {
        "abc",
        "aaa"
    };

    for_each(inputs.begin(), inputs.end(), [](string &s) {
        cout << Solution().countSubstrings(s) << endl;
    });
}