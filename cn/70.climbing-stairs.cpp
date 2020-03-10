/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (48.04%)
 * Likes:    869
 * Dislikes: 0
 * Total Accepted:    147.6K
 * Total Submissions: 307.2K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // climb(c) = climb(c - 1) + climb(c - 2) 
        if (n < 3) return n;
        int climb[n + 1];
        climb[1] = 1; climb[2] = 2;
        for (int c = 3; c <= n; ++c) {
            climb[c] = climb[c - 1] + climb[c - 2];
        }
        return climb[n];
    }
};
// @lc code=end

int main() {
    cout << Solution().climbStairs(4) << endl;
    return 0;
}