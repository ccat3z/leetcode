/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.61%)
 * Likes:    1698
 * Dislikes: 0
 * Total Accepted:    175.7K
 * Total Submissions: 354K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            max_sum = max(nums[i], max_sum);
        }
        return max_sum;
    }
};
// @lc code=end

int main() {
    auto example = vector<int>({-2,1,-3,4,-1,2,1,-5,4});
    cout << Solution().maxSubArray(example) << endl;
    return 0;
}