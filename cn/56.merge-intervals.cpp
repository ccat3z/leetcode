/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.55%)
 * Likes:    545
 * Dislikes: 0
 * Total Accepted:    127.8K
 * Total Submissions: 298.8K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return intervals;
        }
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        auto it = intervals.begin();
        int from = (*it)[0], end = (*it)[1];
        it++;
        for (; it < intervals.end(); it++) {
            if ((*it)[0] <= end) {
                end = max(end, (*it)[1]);
            } else {
                result.push_back(vector<int>({from, end}));
                from = (*it)[0];
                end = (*it)[1];
            }
        }
        result.push_back(vector<int>({from, end}));
        return result;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> case1 = {{1,3},{2,6},{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> case2 = {{1,4},{4,5}};
    cout << Solution().merge(case1) << endl;
    cout << Solution().merge(case2) << endl;
}