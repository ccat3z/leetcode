/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (28.97%)
 * Likes:    2647
 * Dislikes: 0
 * Total Accepted:    339.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = len-1;
            if (nums[i] + nums[i+1] + nums[i+2] > 0) continue;
            if (nums[i] + nums[len-2] + nums[len-1] < 0) continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j+1] == nums[j]) ++j; ++j;
                    while (j < k && nums[k] == nums[k-1]) --k; --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            } 
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> inputs = {
        {-1, 0, 1, 2, -1, -4},
    };
    for (auto nums : inputs) {
        cout << Solution().threeSum(nums) << endl;
    }
}