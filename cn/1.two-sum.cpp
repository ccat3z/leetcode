/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.77%)
 * Likes:    7817
 * Dislikes: 0
 * Total Accepted:    886.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

#include <vector>
#include <iostream>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        map<int, int> pos_map;
        map<int, int>::iterator another;

        for (int index = 0; index < nums.size(); index++) {
            if ((another = pos_map.find(target - nums[index])) != pos_map.end()) {
                result = { another -> second, index };
                break;
            }
            pos_map[nums[index]] = index;
        }
        return result;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto res = Solution().twoSum(nums, target);
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << ", ";
    }
}