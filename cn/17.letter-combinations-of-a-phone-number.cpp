/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.25%)
 * Likes:    857
 * Dislikes: 0
 * Total Accepted:    156.6K
 * Total Submissions: 285.1K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    string digits;
    vector<string> res;
    unordered_map<int, string> dict = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;

        this->digits = digits;
        dfs(0, "");
        return res;
    }
    void dfs(int i, string prefix) {
        if (i == digits.size()) res.push_back(prefix);
        string m = dict[digits[i] - '0'];
        for_each(m.begin(), m.end(), [&](char &it) {
            dfs(i + 1, prefix + it);
        });
    }
};
// @lc code=end

int main() {
    cout << Solution().letterCombinations("") << endl;
    return 0;
}