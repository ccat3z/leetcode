/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 *
 * https://leetcode-cn.com/problems/height-checker/description/
 *
 * algorithms
 * Easy (75.70%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    53.3K
 * Total Submissions: 67.2K
 * Testcase Example:  '[1,1,4,2,1,3]'
 *
 * 学校打算为全体学生拍一张年度纪念照。根据要求，学生需要按照 非递减 的高度顺序排成一行。
 * 
 * 排序后的高度情况用整数数组 expected 表示，其中 expected[i] 是预计排在这一行中第 i 位的学生的高度（下标从 0 开始）。
 * 
 * 给你一个整数数组 heights ，表示 当前学生站位 的高度情况。heights[i] 是这一行中第 i 位学生的高度（下标从 0 开始）。
 * 
 * 返回满足 heights[i] != expected[i] 的 下标数量 。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：heights = [1,1,4,2,1,3]
 * 输出：3 
 * 解释：
 * 高度：[1,1,4,2,1,3]
 * 预期：[1,1,1,2,3,4]
 * 下标 2 、4 、5 处的学生高度不匹配。
 * 
 * 示例 2：
 * 
 * 
 * 输入：heights = [5,1,2,3,4]
 * 输出：5
 * 解释：
 * 高度：[5,1,2,3,4]
 * 预期：[1,2,3,4,5]
 * 所有下标的对应学生高度都不匹配。
 * 
 * 示例 3：
 * 
 * 
 * 输入：heights = [1,2,3,4,5]
 * 输出：0
 * 解释：
 * 高度：[1,2,3,4,5]
 * 预期：[1,2,3,4,5]
 * 所有下标的对应学生高度都匹配。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= heights.length <= 100
 * 1 <= heights[i] <= 100
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
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());

        // cout << heights << endl;
        // cout << expected << endl;

        int diff = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) ++diff;
        }
        
        return diff;
    }
};
// @lc code=end

int main() {
    vector<int> heights = {1,1,4,2,1,3};
    cout << Solution().heightChecker(heights) << endl;
    return 0;
}