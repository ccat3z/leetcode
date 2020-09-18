/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (62.47%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    104.2K
 * Total Submissions: 161.5K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> comb;
    map<int, int> count;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto it : candidates) {
            count[it] += 1;
        }
        _combinationSum2(count.begin(), target);
        return res;
    }
    void _combinationSum2(map<int, int>::iterator start, int target) {
        if (target == 0) {
            res.emplace_back(comb);
            return;
        } else if (target < 0) {
            return;
        }

        for (; start != count.end(); ++start) {
            if (start->second == 0) continue;
            start->second--;
            comb.push_back(start->first);
            _combinationSum2(start, target - start->first);
            comb.pop_back();
            start->second++;
        }
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, int>> inputs = {
        {{10,1,2,7,6,1,5},8},
        {{2,5,2,1,2},5},
    };
    for (auto &t : inputs) {
        cout << Solution().combinationSum2(get<0>(t), get<1>(t)) << endl;
    }
}
