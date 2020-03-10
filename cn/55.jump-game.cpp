/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode-cn.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (38.26%)
 * Likes:    493
 * Dislikes: 0
 * Total Accepted:    67.3K
 * Total Submissions: 175.8K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个位置。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: true
 * 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,1,0,4]
 * 输出: false
 * 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int want = -1;
        for (auto it = nums.rbegin() + 1; it != nums.rend(); ++it) {
            // cout << "want: " << want << " < " << *it << endl; 
            if (*it == 0 && want == -1) {
                want = 2;
            } else if (want != -1) {
                if (*it < want) {
                    ++want;
                } else {
                    want = -1;
                }
            }
        }
        return want == -1;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {3,2,1,0,4};
    cout << Solution().canJump(nums) << endl;
    nums = {2,3,1,1,4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}