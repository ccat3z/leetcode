/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (45.05%)
 * Likes:    889
 * Dislikes: 0
 * Total Accepted:    128.7K
 * Total Submissions: 285.7K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
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
    vector<int> d;
    // find max num which < n
    int find_index(int n, int begin, int end) {
        if (begin == end) {
            if (d[begin] < n) return begin;
            return begin - 1;
        }

        int mid = (begin + end) / 2;
        // 1 3 5 9 10 find(2)
        // 1 3 ^ 9 10
        if (n <= d[mid]) return find_index(n, begin, mid);
        else return find_index(n, mid + 1, end);
    }
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        d.push_back(nums[0]);
        int f;
        for_each(nums.begin()+1, nums.end(), [&](int &i) {
            f = find_index(i, 0, d.size() - 1);
            if (f == d.size() - 1) {
                d.push_back(i);
            } else {
                d[f+1] = i;
            }
            // cout << d << endl;
        });
        
        return d.size();
    }
};
// @lc code=end

int main() {
    vector<int> input({10,9,2,5,3,7,101,18});
    cout << Solution().lengthOfLIS(input) << endl;
    return 0;
}