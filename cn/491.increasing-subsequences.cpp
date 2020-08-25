/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 *
 * https://leetcode-cn.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (48.94%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 28.2K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
 * 
 * 示例:
 * 
 * 
 * 输入: [4, 6, 7, 7]
 * 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 说明:
 * 
 * 
 * 给定数组的长度不会超过15。
 * 数组中的整数范围是 [-100,100]。
 * 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> buf;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, -101, nums);
        return ans;
    }
    void dfs(int cur, int last, vector<int> &nums) {
        if (cur == nums.size()) {
            if (buf.size() >= 2) {
                ans.push_back(buf);
            }
            return;
        }
        if (nums[cur] >= last) {
            buf.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            buf.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> inputs = {
        {4,6,7,7}
    };
    vector<int> a = {1};
    cout << a << endl;
    vector<int> b = a;
    b.push_back(2);
    cout << b << endl;
    cout << a << endl;
    for (auto it = inputs.begin(); it != inputs.end(); ++it) {
        cout << Solution().findSubsequences(*it) << endl;
    }
    return 0;
}