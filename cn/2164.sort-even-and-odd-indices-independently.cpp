/*
 * @lc app=leetcode.cn id=2164 lang=cpp
 *
 * [2164] 对奇偶下标分别排序
 *
 * https://leetcode-cn.com/problems/sort-even-and-odd-indices-independently/description/
 *
 * algorithms
 * Easy (70.00%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 12.9K
 * Testcase Example:  '[4,1,2,3]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。根据下述规则重排 nums 中的值：
 * 
 * 
 * 按 非递增 顺序排列 nums 奇数下标 上的所有值。
 * 
 * 
 * 举个例子，如果排序前 nums = [4,1,2,3] ，对奇数下标的值排序后变为 [4,3,2,1] 。奇数下标 1 和 3
 * 的值按照非递增顺序重排。
 * 
 * 
 * 按 非递减 顺序排列 nums 偶数下标 上的所有值。
 * 
 * 举个例子，如果排序前 nums = [4,1,2,3] ，对偶数下标的值排序后变为 [2,1,4,3] 。偶数下标 0 和 2
 * 的值按照非递减顺序重排。
 * 
 * 
 * 
 * 
 * 返回重排 nums 的值之后形成的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,1,2,3]
 * 输出：[2,3,4,1]
 * 解释：
 * 首先，按非递增顺序重排奇数下标（1 和 3）的值。
 * 所以，nums 从 [4,1,2,3] 变为 [4,3,2,1] 。
 * 然后，按非递减顺序重排偶数下标（0 和 2）的值。
 * 所以，nums 从 [4,1,2,3] 变为 [2,3,4,1] 。
 * 因此，重排之后形成的数组是 [2,3,4,1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,1]
 * 输出：[2,1]
 * 解释：
 * 由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
 * 形成的结果数组是 [2,1] ，和初始数组一样。 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        odd.reserve(nums.size() / 2);
        vector<int> even;
        even.reserve(nums.size() / 2);

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                odd.emplace_back(nums[i]);
            } else {
                even.emplace_back(nums[i]);
            }
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end(), [](const int &a, const int &b) -> bool { return a > b; });

        for (int i = 0; i < odd.size(); i++) {
            nums[i * 2] = odd[i]; 
        }
        for (int i = 0; i < even.size(); i++) {
            nums[i * 2 + 1] = even[i]; 
        }

        return nums;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {4,1,2,3};
    cout << Solution().sortEvenOdd(nums) << endl;
    return 0;
}