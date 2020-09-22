/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.72%)
 * Likes:    804
 * Dislikes: 0
 * Total Accepted:    154.5K
 * Total Submissions: 195.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1<<n); ++i) {
            vector<int> ve;
            for (int j = 0; j < n; ++j) {
                if ((i & (1<<j)) == (1<<j)) {
                    ve.push_back(nums[j]);
                }
            }
            res.emplace_back(ve);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> inputs = {1, 2, 3};
    cout << Solution().subsets(inputs) << endl;
}
