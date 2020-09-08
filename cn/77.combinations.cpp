/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (74.45%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    87.2K
 * Total Submissions: 115.4K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
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
    vector<int> comb;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if (k == 0) return res;
        for (int i = 1; i <= k; ++i) comb.push_back(i);
        res.emplace_back(comb);
        if (n == k) return res;

        for (;;) {
            if (comb[0] == 1) {
                // 10001111  8 4 3 2 1
                // 10010111  8 5 3 2 1

                int i = 0;
                for (; i < k && comb[i] == i + 1; ++i);
                comb[i - 1]++;
                res.emplace_back(comb);
            } else {
                // 10001110  8 4 3 2
                // 10010011  8 5 2 1
                //
                // 11110000  8 7 6 5 = break

                int i0 = comb[0];
                int i = 0;
                for (; i < k && comb[i] == i + i0; ++i) {
                    comb[i] -= i0 - 1;
                }
                --i;
                comb[i] += i0;
                if (comb[i] > n) break;
                res.emplace_back(comb);
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<int, int>> inputs = {
        {4, 2},
    };
    for (auto &t : inputs) {
        cout << Solution().combine(get<0>(t), get<1>(t)) << endl;
    }
}