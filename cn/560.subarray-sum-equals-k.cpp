/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.20%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    40.6K
 * Total Submissions: 91.7K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

// TODO

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int begin = 0, end = 0;
        int size = nums.size();
        int count = 0;

        // [begin, end]
        for (int sum = nums[0]; begin != size && end != size;) {
            cout << begin << ',' << end << '=' << sum << endl;

            if (sum == k) {
                ++count;
            } else if (sum > k) {
                // k = 1 => ... [10] a b ... -> ... 10 [a] b ...
                if (begin == end) {
                    begin = end + 1;
                    end += 1;
                    // end of list
                    if (end == size) break;
                    sum = nums[end];
                // k = 2 => ... [2, 1] a b ... -> ... [1] a b ...
                } else {
                    sum = sum - nums[begin];
                    begin += 1;
                }
                continue;
            }

            // extend window
            if (end != size - 1) {
                ++end;
                sum += nums[end];
            } else {
                sum -= nums[begin];
                ++begin;
            }
        }
        return count;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << Solution().subarraySum(nums, k) << endl;
    return 0;
}