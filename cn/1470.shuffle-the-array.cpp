/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 *
 * https://leetcode-cn.com/problems/shuffle-the-array/description/
 *
 * algorithms
 * Easy (84.10%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    76.9K
 * Total Submissions: 90.5K
 * Testcase Example:  '[2,5,1,3,4,7]\n3'
 *
 * 给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。
 * 
 * 请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,5,1,3,4,7], n = 3
 * 输出：[2,3,5,4,1,7] 
 * 解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3,4,4,3,2,1], n = 4
 * 输出：[1,4,2,3,3,2,4,1]
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,1,2,2], n = 2
 * 输出：[1,2,1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 500
 * nums.length == 2n
 * 1 <= nums[i] <= 10^3
 * 
 * 
 */
#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int orig_flag = (1 << 10) - 1;
        for (int i = 0; i < n; ++i) {
            nums[2 * i] |= (nums[i] & orig_flag) << 10;
            nums[2 * i + 1] |= (nums[n + i] & orig_flag) << 10;
        }
        for (auto &num : nums) {
            num >>= 10;
        }
        return nums;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {2,5,1,3,4,7};
    cout << Solution().shuffle(nums, 3) << endl;
    return 0;
}