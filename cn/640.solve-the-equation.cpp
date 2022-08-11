/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 *
 * https://leetcode-cn.com/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (42.67%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 73.3K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 * 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
 * 
 * 如果方程没有解，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
 * 
 * 题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: equation = "x+5-3+x=6+x-2"
 * 输出: "x=2"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: equation = "x=x"
 * 输出: "Infinite solutions"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: equation = "2x=x"
 * 输出: "x=0"
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 3 <= equation.length <= 1000
 * equation 只有一个 '='.
 * equation 方程由整数组成，其绝对值在 [0, 100] 范围内，不含前导零和变量 'x' 。 ​​​
 * 
 * 
 */
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        auto *it = equation.c_str();
        
        while(*(it = parseEquation(it, true)) != '=') {
            // cout << it << ' ' << x << ' ' << n << endl;
        }
        // cout << it << ' ' << x << ' ' << n << endl;
        it++;
        while(*(it = parseEquation(it, false)) != 0) {
            // cout << it << ' ' << x << ' ' << n << endl;
        }
        // cout << it << ' ' << x << ' ' << n << endl;

        if (x == 0 && n == 0) {
            return "Infinite solutions";
        } else if (x == 0 && n != 0) {
            return "No solution";
        }

        return "x=" + to_string(n / x);
    }

    inline const char *parseEquation(const char * it, bool left) {
        if (*it == 0) return it;
        if (*it == '=') return it;

        bool neg = false;
        if (*it == '-') {
            neg = true;
            it++;
        } else if (*it == '+') {
            neg = false;
            it++;
        }
        if (left) neg = !neg;

        size_t offset = 0;
        int num = 0;
        sscanf(it, "%d%n", &num, &offset);
        it += offset;
        
        if (*it == 'x') {
            if (offset == 0) num = 1;
            x += neg ? num : -num;
            it++;
            return it;
        } else {
            n += (neg ? -1 : 1) * num;
        }

        return it;
    }

    int x = 0;
    int n = 0;
};
// @lc code=end

int main() {
    vector<pair<string, string>> cases = {
        {"x+5-3+x=6+x-2", "x=2"},
        {"x=x", "Infinite solutions"},
        {"2x=x", "x=0"},
        {"x=x+2", "No solutions"}
    };
    for (auto &[eq, ans] : cases) {
        cout << Solution().solveEquation(eq) << " => " << ans << endl;
    }
    return 0;
}