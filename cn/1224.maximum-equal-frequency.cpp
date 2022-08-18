/*
 * @lc app=leetcode.cn id=1224 lang=cpp
 *
 * [1224] 最大相等频率
 *
 * https://leetcode-cn.com/problems/maximum-equal-frequency/description/
 *
 * algorithms
 * Hard (32.83%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 30.1K
 * Testcase Example:  '[2,2,1,1,5,3,3,5]'
 *
 * 给你一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回该前缀的长度：
 * 
 * 
 * 从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。
 * 
 * 
 * 如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,2,1,1,5,3,3,5]
 * 输出：7
 * 解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到
 * [2,2,1,1,3,3]，里面每个数字都出现了两次。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
 * 输出：13
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        map<int, int> counters;
        int res = 0;
        int max_count = 0;
        int top1_size = 0;
        int top2_size = 0;
        int cnt1_size = 0;

        for (int i = 0; i < nums.size(); i++) {
            auto &num = nums[i];
            auto &counter = counters[num];

            // new num
            if (counter == 0) {
                if (max_count == 0) {
                    top1_size++;
                } else if (max_count == 1) {
                    top2_size++;
                }
            }

            counter++;
            if (counter > max_count) {
                max_count = counter;
                top2_size = top1_size - 1;
                top1_size = 1;
            } else if (counter == max_count) {
                top1_size++;
                top2_size--;
            } else if (counter == max_count - 1) {
                top2_size++;
            }

            if (counter == 2) {
                cnt1_size--;
            } else if (counter == 1) {
                cnt1_size++;
            }

            if (top1_size == counters.size() - 1 && cnt1_size == 1) { // 3, 3, 3, 1, 3
                res = i+1;
            } else if (top2_size == counters.size() - 1 && top1_size == 1) { // 2, 2, 2, 3, 2
                res = i+1;
            } else if (top1_size == counters.size() && max_count == 1) { // 1, 1, 1, 1
                res = i+1;
            }

            // cout << i << ':' << top1_size << ' ' << top2_size << " " << counters << " ";
            // if (res == i+1) {
            //     cout << '#';
            // }
            // cout << endl;
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, int>> cases = {
        {{2,2,1,1,5,3,3,5}, 7},
        {{1,1,1,2,2,2,3,3,3,4,4,4,5}, 13},
        {vector<int>{}, 0},
        {{1}, 1},
        {{1,2}, 2},
        {{1,1,1,2,2,2,3,3,3}, 7}
    };
    for (auto &[nums, res] : cases) {
        cout << Solution().maxEqualFreq(nums) << " = " << res << ", " << nums << endl;
    }
    return 0;
}