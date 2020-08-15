/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 *
 * https://leetcode-cn.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (44.63%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 31.2K
 * Testcase Example:  '[[1,2]]'
 *
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
 * 
 * 注意:
 * 
 * 
 * 可以认为区间的终点总是大于它的起点。
 * 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [ [1,2], [2,3], [3,4], [1,3] ]
 * 
 * 输出: 1
 * 
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [ [1,2], [1,2], [1,2] ]
 * 
 * 输出: 2
 * 
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [ [1,2], [2,3] ]
 * 
 * 输出: 0
 * 
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 * 
 * 
 */
// REVIEW
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){ return a[0] < b[0]; });

        int size = intervals.size();
        int max[size]; // 前index个block最大选择数量

        for (int i = 0; i < size; ++i) {
            max[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (intervals[j][1] <= intervals[i][0]) {
                    max[i] = std::max(max[i], max[j] + 1);
                }
            }
        }

        return size - max[size - 1];
    }
};
// @lc code=end

int main() {
    vector<vector<int>> ins;
    ins.push_back(vector<int>({1, 2}));
    ins.push_back(vector<int>({2, 3}));
    ins.push_back(vector<int>({3, 4}));
    // ins.push_back(vector<int>({1, 3}));
    cout << Solution().eraseOverlapIntervals(ins) << endl;
    return 0;
}