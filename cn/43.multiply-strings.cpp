/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (42.61%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    86.5K
 * Total Submissions: 198.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 1 && num1[0] == '0') {
            return "0";
        }
        if (num2.size() == 1 && num2[0] == '0') {
            return "0";
        }
        string result(num1.size() + num2.size(), 0);
        // 4 3 2 1 0 <- i, j
        // 1 3 i 8 7 <- num1
        //     5 j 3 <- num2
        // ---------
        //         0
        for (int j = 0; j < num2.size(); ++j) {
            for (int i = 0; i < num1.size(); ++i) {
                int at = result.size() - j - i - 1;
                char num_i = num1[num1.size() - i - 1] - '0';
                char num_j = num2[num2.size() - j - 1] - '0';
                result[at] += num_i * num_j;
                while (result[at] > 9) {
                    char over = (result[at]) / (char) 10;
                    result[at] -= over * 10;
                    result[at - 1] += over;
                    --at;
                }
            }
        }
        for_each(result.begin(), result.end(), [](char &it) {
            it += '0';
        });
        if (result[0] == '0') {
            return result.substr(1);
        }
        return result;
    }
};
// @lc code=end

int main() {
    vector<pair<string, string>> cases = {
        {"2", "3"},
        {"123", "456"},
        {"9", "9"},
        {"99", "0"}
    };
    for (auto it = cases.begin(); it < cases.end(); ++it) {
        cout << Solution().multiply(it->first, it->second) << endl;
    }
    return 0;
}