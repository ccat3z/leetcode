/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 *
 * https://leetcode-cn.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (77.19%)
 * Likes:    314
 * Dislikes: 0
 * Total Accepted:    69.2K
 * Total Submissions: 89.5K
 * Testcase Example:  '1\n4'
 *
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 * 
 * 给出两个整数 x 和 y，计算它们之间的汉明距离。
 * 
 * 注意：
 * 0 ≤ x, y < 2^31.
 * 
 * 示例:
 * 
 * 
 * 输入: x = 1, y = 4
 * 
 * 输出: 2
 * 
 * 解释:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * 上面的箭头指出了对应二进制位不同的位置。
 * 
 * 
 */
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int res = 0;
        while (n) {
            n &= n - 1;
            ++res;
        }
        return res;
    }
};
// @lc code=end

int main() {
    cout << Solution().hammingDistance(1, 4) << endl;
}