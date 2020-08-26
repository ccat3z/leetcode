/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (36.92%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    39.7K
 * Total Submissions: 107K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
 * 示例1:
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <array>
using namespace std;

// @lc code=start
class Solution {
public:
    array<int, 26> s1count;
    Solution() {
        fill(s1count.begin(), s1count.end(), 0);
    }
    bool checkInclusion(string s1, string s2) {
        for_each(s1.begin(), s1.end(), [&](char &c) { ++s1count[c - 'a']; });
        int i = 0;
        for (int j = 0; j < s2.size(); ++j) {
            char &c = s2[j];
            int &count = s1count[c - 'a'];
            if (count == 0 && valid(s1count)) return true;
            --count;

            if (count < 0) {
                do {
                    s1count[s2[i] - 'a'] += 1;
                    ++i;
                } while (count != 0);
            }
        }
        return valid(s1count);
    }
    bool valid(array<int, 26> t) {
        for (auto it = t.begin(); it != t.end(); ++it) {
            if (*it != 0) return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<tuple<string, string>> inputs = {
        make_tuple("ab", "eidba"),
        make_tuple("ab", "eidboaoo"),
        make_tuple("adc", "dcda")
    };
    for_each(inputs.begin(), inputs.end(), [&](tuple<string, string> &t){
        cout << Solution().checkInclusion(get<0>(t), get<1>(t)) << endl;
    });
    return 0;
}