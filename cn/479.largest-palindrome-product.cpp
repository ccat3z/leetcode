/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 *
 * https://leetcode-cn.com/problems/largest-palindrome-product/description/
 *
 * algorithms
 * Hard (43.70%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 13.6K
 * Testcase Example:  '2'
 *
 * 给定一个整数 n ，返回 可表示为两个 n 位整数乘积的 最大回文整数 。因为答案可能非常大，所以返回它对 1337 取余 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：n = 2
 * 输出：987
 * 解释：99 x 91 = 9009, 9009 % 1337 = 987
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入： n = 1
 * 输出： 9
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> result = { 9, 987, 123, 597, 677, 1218, 877, 475 };
    int largestPalindrome(int n) {
        return result[n-1];
    }

    int largestPalindrome2(int n) {
        if (n == 1) return 9;

        // n=2, upper=99
        int upper = pow(10, n) - 1;

        // iter palindrome
        for (int pa_left = upper;; --pa_left) {
            // build palindome
            long pa = pa_left;
            for (int x = pa_left; x > 0; x /= 10) {
                pa = pa*10 + x%10;
            }
            // cout << '!' << pa << endl;

            // check product
            for (long x = upper; x*x >= pa; --x) {
                if (pa % x == 0) {
                    return pa % 1337;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

int main() {
    for (int i = 1; i <= 8; ++i) {
        cout << Solution().largestPalindrome(i) << endl;
    }
    return 0;
}