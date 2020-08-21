/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (36.87%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 27K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 示例:
 * 
 * 输入: 13
 * 输出: 6 
 * 解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;

// xxx1: 1 11 21 31 ... 151 [160] 161 [169]
//       1 2  3  4      15       15+1
// n / 10 + n % 10 >= 1
// xx1x: 10-19 110-119 ... 1510-1519 [1600] 1610-[1618]
//        10     20          150              150+9
// n / 100 * 10 + min(max(n % 100 - 10 + 1, 0), 10)
// x1xx: 100-199 2100-2199 ... 15100-15299 [16000] 16100-[16170]
//         100     200            15000             15000 + 71
// n / 1000 * 100 + min(max(n % 1000 - 100 + 1, 0), 100)
// xNxx: xNxx / 10^i * 10^(i - 1) + min(max(xNxx % 10^i - 10^(i-1) + 1, 0), 10^(i-1))
//  ^ i

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        long sum = 0, add = 1;
        long p10i = 10;
        long p10i1 = 1;
        for (; add != 0; p10i *= 10, p10i1 *= 10) {
            add = n / p10i * p10i1 + min(max(n % p10i - p10i1 + 1, 0l), p10i1);
            sum += add;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    cout << Solution().countDigitOne(824883294) << endl;
}