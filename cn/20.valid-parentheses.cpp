/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (42.15%)
 * Likes:    1790
 * Dislikes: 0
 * Total Accepted:    378.5K
 * Total Submissions: 885.2K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto it = s.begin(); it != s.end(); ++it) {
            switch (*it) {
                case '(':
                case '[':
                case '{':
                    st.push(*it);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') {
                        return false;
                    }
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') {
                        return false;
                    }
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{') {
                        return false;
                    }
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};
// @lc code=end

int main() {
    vector<string> cases = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}"
    };
    for (auto it = cases.begin(); it != cases.end(); ++it) {
        cout << Solution().isValid(*it) << endl;
    }
}