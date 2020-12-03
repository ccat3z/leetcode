/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (34.75%)
 * Likes:    514
 * Dislikes: 0
 * Total Accepted:    92.7K
 * Total Submissions: 255.2K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 5 * 10^6
 * 
 * 
 */
// TODO: 埃氏筛, 线性筛

#include <iostream>
#include <vector>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> primes = {2};
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        for (int i = 3; i < n; i+=2) {

            bool is_prime = true;
            for (int &p : primes) {
                if (p * p > i) break;
                if (i % p == 0) {
                    is_prime = false;
                    break;
                }
            }

            if (is_prime) primes.emplace_back(i);
        }

        return primes.size();
    }
};
// @lc code=end

int main() {
    vector<int> nums = {10, 0, 1};
    for (auto n : nums) {
        cout << Solution().countPrimes(n) << endl;
    }
    return 0;
}