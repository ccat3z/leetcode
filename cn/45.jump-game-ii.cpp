/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (33.39%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 99.3K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 示例:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 说明:
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        const int m = nums.size();
        if (m == 1) return 0;

        int can_jump_max = min(m - 1, nums[0]);
        int max_reach = 0;
        int used_step = 0;

        for (int i = 0; i < m; ++i) {
            if (can_jump_max >= m - 1) break;

            max_reach = max(max_reach, i + nums[i]);

            if (i == can_jump_max) {
                ++used_step;
                can_jump_max = max_reach;
            }
            // cout << i << ' ' << can_jump_max << endl;
        }
        return ++used_step;
    }

    // int jump2(vector<int>& nums) {
    //     const int m = nums.size();

    //     // init reach map
    //     int reach[m];
    //     for (int i = 0; i < m; ++i) reach[i] = -1;
    //     reach[0] = 0;

    //     for (int i = 0; i < m && reach[m - 1] == -1; ++i) {
    //         int can_reach = min(m - 1, i + nums[i]);
    //         int step = reach[i] + 1;

    //         while (reach[can_reach] == -1) reach[can_reach--] = step;
    //     }
    //     return reach[m - 1];
    // }
};
// @lc code=end

int main() {
    vector<int> nums;

    nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout << Solution().jump(nums) << endl;
    nums = {2,3,1,1,4};
    cout << Solution().jump(nums) << endl;
    nums = {1,2};
    cout << Solution().jump(nums) << endl;
    nums = {0};
    cout << Solution().jump(nums) << endl;
    return 0;
}