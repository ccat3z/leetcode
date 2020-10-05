/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (38.21%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    119.4K
 * Total Submissions: 307.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <tuple>
#include <map>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() == 0) return res;
        int len = nums.size();
        int sum, i, j, k, l;
        sort(nums.begin(), nums.end());
        for (i = 0; i < len-3; ++i) {
            // skip same num
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (j = i+1; j < len-2; ++j) {
                // skip same num
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                k = j+1, l = len-1;

                // skip
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) continue;
                if (nums[i] + nums[j] + nums[len-2] + nums[len-1] < target) continue;

                while (k < l) {
                    sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        // next diff nums[k]
                        while (k < l && nums[k+1] == nums[k]) ++k; ++k;
                        // pre diff nums[l]
                        while (k < l && nums[l-1] == nums[l]) --l; --l;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, int>> inputs = {
        {{1, 0, -1, 0, -2, 2}, 0},
    };
    for (auto t : inputs) {
        cout << Solution().fourSum(get<0>(t), get<1>(t)) << endl;
    }
}