/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 *
 * https://leetcode-cn.com/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (53.01%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 21.8K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * 给定一个表示分数加减运算的字符串 expression ，你需要返回一个字符串形式的计算结果。 
 * 
 * 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2
 * 应该被转换为 2/1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: expression = "-1/2+1/2"
 * 输出: "0/1"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: expression = "-1/2+1/2+1/3"
 * 输出: "1/3"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: expression = "1/3-1/2"
 * 输出: "-1/6"
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
 * 输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
 * 输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
 * 输入的分数个数范围是 [1,10]。
 * 最终结果的分子与分母保证是 32 位整数范围内的有效整数。
 * 
 * 
 */
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    struct frac {
        int a, b;
    };

    string fractionAddition(string expression) {
        frac res{0, 1};
        frac append;

        for (auto begin = expression.begin(); begin != expression.end();) {
            begin = parse(append, begin, expression.end());

            if (append.a == 0) {
                // cout << append.a << '/' << append.b << '=' << res.a << '/' << res.b << endl;
                continue;
            }
            if (res.a == 0) {
                res = append;
            } else {
                int b = lcm(res.b, append.b);
                res.a = (res.a * b / res.b) + (append.a * b / append.b);
                res.b = b;
            }

            // cout << append.a << '/' << append.b << '=' << res.a << '/' << res.b << endl;
        }

        int d = abs(gcd(res.a, res.b));
        res.a /= d;
        res.b /= d;

        stringstream ss;
        ss << res.a << '/' << res.b;
        return ss.str();
    }

    inline int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    inline int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    inline string::iterator parse(frac &f, string::iterator begin, string::iterator end) {
        if (begin == end) return begin;

        f.a = 0;
        f.b = 0;

        // [+-]?
        bool neg = false;
        switch (*begin) {
        case '+':
            begin++;
            break;
        case '-':
            neg = true;
            begin++;
            break;
        default:
            break;
        }

        // [0-9]*
        while ((begin != end) && ('0' <= *begin && *begin <= '9')) {
            f.a *= 10;
            f.a += *begin - '0';
            begin++;
        }
        if (neg) f.a = -f.a;

        // [/][0-9]*
        if (begin == end || *begin != '/') {
            f.b = 1;
            return begin;
        }
        begin++;

        while ((begin != end) && ('0' <= *begin && *begin <= '9')) {
            f.b *= 10;
            f.b += *begin - '0';
            begin++;
        }
        return begin;
    }
};
// @lc code=end

int main() {
    cout << Solution().fractionAddition("+1/2-9/10+1+0/2+0") << endl;
    cout << Solution().fractionAddition("") << endl;
    cout << Solution().fractionAddition("+1/2-10") << endl;
    return 0;
}