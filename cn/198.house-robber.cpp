/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (43.28%)
 * Likes:    665
 * Dislikes: 0
 * Total Accepted:    82.5K
 * Total Submissions: 190.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        // maxV[at] = max(maxV[no_skip], nums[at] + maxV[skip])
        int max_skip = nums[0];
        int max_no_skip = nums[0] > nums[1] ? 0 : nums[1];
        int max_now = 0;

        for (int at = 2; at < nums.size(); ++at) {
            if (max_no_skip > max_skip + nums[at]) {
                max_now = max_no_skip;

                max_skip = max_no_skip;
                max_no_skip = 0;
            } else {
                max_now = max_skip + nums[at];

                max_skip = max(max_no_skip, max_skip);
                max_no_skip = max_now;
            }
        }

        return max_now;
    }

    // int rob2(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;
    //     if (nums.size() == 1) return nums[0];
    //     if (nums.size() == 2) return max(nums[0], nums[1]);

    //     // maxV[at] = maxV[at - 1].rob_last ? max(maxV[at - 1], nums[at] + maxV[at - 2]) : maxV[at - 1]
    //     pair<int, bool> maxV[nums.size()];
    //     maxV[0].first = nums[0], maxV[0].second = true;

    //     if (nums[0] > nums[1]) {
    //         maxV[1].first = nums[0];
    //         maxV[1].second = false;
    //     } else {
    //         maxV[1].first = nums[1];
    //         maxV[1].second = true;
    //     }

    //     for (int at = 2; at < nums.size(); ++at) {
    //         if (maxV[at - 1].second) {
    //             if (maxV[at - 1].first > nums[at] + maxV[at - 2].first) {
    //                 maxV[at].first = maxV[at - 1].first;
    //                 maxV[at].second = false;
    //             } else {
    //                 maxV[at].first = nums[at] + maxV[at - 2].first;
    //                 maxV[at].second = true;
    //             }
    //         } else {
    //             maxV[at].first = nums[at] + maxV[at - 1].first;
    //             maxV[at].second = true;
    //         }
    //     }

    //     return maxV[nums.size() - 1].first;
    // }
};
// @lc code=end

int main() {
    vector<int> example = {1,2,3,1};
    cout << Solution().rob(example) << ' ';
    example = {2,1,1,2};
    cout << Solution().rob(example) << ' ';
    example = {2,7,9,3,1};
    cout << Solution().rob(example) << endl;
    return 0;
}