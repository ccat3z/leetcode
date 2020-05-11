/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (34.11%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 222.4K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (x == 1) return 1;

        if (n > 1) {
            double p = myPow(x, n / 2);
            p *= p;
            if (n % 2 != 0) p *= x;
            return p;
        }

        if (n < 0) {
            return myPow(1.0 / x, -n);
        }

        return 0;
    }
};
// @lc code=end

int main() {
    cout << Solution().myPow(2, 10) << endl;
    cout << Solution().myPow(2, -2) << endl;
}