/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (34.51%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 30.2K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int length = nums.size();
        // [], [a]
        if (length <= 1) return length;

        // max lengths of subseq which ending in nums[i]
        // 1 3 2 4 length[3] = 3 (1 3 4, 1 2 4)
        vector<int> lengths(length); fill(lengths.begin(), lengths.end(), 1);
        // count of subseq which ending in nums[i]
        // 1 3 2 4 counts[3] = 2 (1 3 4, 1 2 4)
        vector<int> counts(length); fill(counts.begin(), counts.end(), 1);

        for (int b = 0; b < length; ++b) {
            for (int a = 0; a < b; ++a) {
                // 1 3 5 4 7
                //   a   b

                if (nums[a] >= nums[b]) continue;

                if (lengths[a] >= lengths[b]) {
                    lengths[b] = lengths[a]  + 1;
                    counts[b] = counts[a];
                } else if (lengths[a] + 1 == lengths[b]) {
                    counts[b] += counts[a];
                }
            }
        }

        int max_length = *max_element(lengths.begin(), lengths.end());
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            if (lengths[i] == max_length) {
                sum += counts[i];
            }
        }
        // cout << max_length << ',' << sum << endl;

        return sum;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> input = {
        {1,3,5,4,7},
        {2,2,2,2,2}
    };
    for (auto it = input.begin(); it != input.end(); ++it) {
        cout << Solution().findNumberOfLIS(*it) << endl;
    }
}
