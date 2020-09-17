/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (69.46%)
 * Likes:    906
 * Dislikes: 0
 * Total Accepted:    152.8K
 * Total Submissions: 215.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <tuple>
// #include <unordered_map>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> comb;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        _combinationSum(candidates, target);
        return res;
    }
    void _combinationSum(vector<int>& candidates, int target) {
        if (target == 0) {
            res.emplace_back(comb);
            return;
        }
        if (target < 0) return;
        for (int i : candidates) {
            if (comb.size() >= 1 && i < comb[comb.size() - 1]) continue;
            comb.emplace_back(i);
            _combinationSum(candidates, target - i);
            comb.pop_back();
        }
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, int>> inputs = {
        {{2,3,6,7},7},
        {{2,3,5},8},
    };
    for (auto &t : inputs) {
        cout << Solution().combinationSum(get<0>(t), get<1>(t)) << endl;
    }
}