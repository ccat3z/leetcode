/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.63%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    54.1K
 * Total Submissions: 73.5K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

#include <vector>
#include <iostream>
#include <tuple>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> comb;
    vector<vector<int>> combinationSum3(int k, int n) {
        _combinationSum3(k, n);
        return res;
    }
    void _combinationSum3(int k, int n) {
        if (n < 0) return;
        else if (n == 0) {
            if (k == 0) res.emplace_back(comb);
            return;
        }

        for (int i = (comb.size() == 0) ? 1 : (comb[comb.size() - 1]+1); i <= 9; ++i) {
            comb.push_back(i);
            _combinationSum3(k-1, n-i);
            comb.pop_back();
        }
    }
};
// @lc code=end

int main() {
    vector<tuple<int, int>> inputs = {
        {3,7},
        {3,9},
    };
    for (auto i : inputs) {
        cout << Solution().combinationSum3(get<0>(i), get<1>(i)) << endl;
    }
    return 0;
}