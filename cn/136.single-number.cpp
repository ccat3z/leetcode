/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (65.69%)
 * Likes:    1266
 * Dislikes: 0
 * Total Accepted:    212.4K
 * Total Submissions: 309.9K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            b ^= *it;
        }
        return b;
    }
};
// @lc code=end

int main() {
    vector<int> v = {4, 1, 2, 1, 2};
    cout << Solution().singleNumber(v) << endl;
    return 0;
}