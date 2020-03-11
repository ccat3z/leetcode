/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.23%)
 * Likes:    3274
 * Dislikes: 0
 * Total Accepted:    380K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        // map<char, int> record;
        int sub_str_start = 1;
        int record[256] = {};

        // cout << sizeof record << endl;

        for (int i = 0; i < s.size(); ++i) {
            int &last_record = record[s[i]];
            if (last_record != 0 && last_record >= sub_str_start) { // in substr
                sub_str_start = last_record + 1;
            }

            last_record = i + 1;
            max_len = max(max_len, i + 2 - sub_str_start);
        }
        
        return max_len;
    }
};
// @lc code=end

int main() {
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
    cout << Solution().lengthOfLongestSubstring("bbbbb") << endl;
    cout << Solution().lengthOfLongestSubstring("pwwkew") << endl;
    cout << Solution().lengthOfLongestSubstring("a") << endl;
    return 0;
}