/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.83%)
 * Likes:    1837
 * Dislikes: 0
 * Total Accepted:    200.5K
 * Total Submissions: 695.5K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    // TODO: try Manacher Algorithm
    string longestPalindrome(string s) {
        // is_pa(s, from, to) => max filter (is_pa(s, from+1, {x}) && s[from] == s[to]) {x: from,...,to}
        if (s.size() == 0) return s;

        int max_record_index = s.size() - 1;
        int max_record_length = 1;
        int is_pa[s.size()][s.size()];
        for (int sub_length = 1; sub_length <= s.size(); ++sub_length) {
            for (int from = 0; from <= s.size() - sub_length; ++from) {
                int to = from + sub_length - 1;
                int &length = is_pa[from][to];
                if (sub_length == 1) // "a"
                    length = 1;
                else if (sub_length == 2 && s[from] == s[to]) // "aa"
                    length = 2;
                else if (s[from] == s[to]) { // "a...a"
                    if (is_pa[from + 1][to - 1] > 0) {
                        length = to - from + 1;
                    } else {
                        length = 0;
                    }
                } else {
                    length = 0;
                }

                // cout << s.substr(from, sub_length) << ": " << length << endl;

                if (length > max_record_length) {
                    max_record_index = from;
                    max_record_length = length;
                }
            }
        }

        return s.substr(max_record_index, max_record_length);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    cout << Solution().longestPalindrome("babab") << endl;
    return 0;
}

