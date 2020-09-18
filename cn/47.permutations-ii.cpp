/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (59.58%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    93.6K
 * Total Submissions: 154.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
#include <vector>
#include <iostream>
#include <map>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    map<int, int> count;
    vector<int> comb;
    int size;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        size = nums.size();
        if (size == 0) return res;
        for (int n : nums) { count[n]++; }
        p();
        return res;
    }
    void p() {
        if (comb.size() == size) res.emplace_back(comb);

        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second == 0) continue;

            it->second--;
            comb.push_back(it->first);
            p();
            comb.pop_back();
            it->second++;
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> inputs = {
        {1,1,2},
        {},
    };
    for (auto t : inputs) {
        cout << Solution().permuteUnique(t) << endl;
    }
    return 0;
}