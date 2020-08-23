/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 *
 * https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (46.89%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 35.4K
 * Testcase Example:  '5\n7'
 *
 * 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
 * 
 * 示例 1: 
 * 
 * 输入: [5,7]
 * 输出: 4
 * 
 * 示例 2:
 * 
 * 输入: [0,1]
 * 输出: 0
 * 
 */
#include <iostream>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n &= (n - 1);
        }
        return n;
    }
};
// @lc code=end

int rangeBitwiseAnd2(int m, int n) {
    int res = m;
    for (int i = m; i >= 0 && i <= n; ++i) {
        res &= i;
    }
    return res;
}

int main() {
    int a = 2147483646, b = 2147483647;
    cout << Solution().rangeBitwiseAnd(a, b) << endl;
    cout << rangeBitwiseAnd2(a, b) << endl;
}