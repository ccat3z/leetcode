/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode-cn.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (42.17%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    41.4K
 * Total Submissions: 93.4K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你
 * 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
 * 
 * 如果你能使这个正方形，则返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: matchsticks = [1,1,2,2,2]
 * 输出: true
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: matchsticks = [3,3,3,3,4]
 * 输出: false
 * 解释: 不能用所有火柴拼成一个正方形。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= matchsticks.length <= 15
 * 1 <= matchsticks[i] <= 10^8
 * 
 * 
 */

// TODO: dp

#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        {
            int total = 0;
            for (auto &i : matchsticks) {
                total += i;
            }
            if (total % 4 != 0)
                return false;
            len = total / 4;
        }

        sort(matchsticks.begin(), matchsticks.end(), greater_equal<int>());
        return canFill(matchsticks, 0);
    }
private:
    int len;
    int edges[4] = {0};

    bool canFill(vector<int>& matchsticks, int i) {
        if (i == matchsticks.size()) return true;

        for (int e = 0; e < 4; ++e) {
            edges[e] += matchsticks[i];
            // cout << edges << endl;

            if (edges[e] <= len && canFill(matchsticks, i+1)) {
                return true;
            }

            edges[e] -= matchsticks[i];
            // cout << edges << endl;
        }

        return false;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, bool>> tests = {
        {{1,1,2,2,2}, true},
        {{3,3,3,3,4}, false},
    };

    for (auto &[matchsticks, res] : tests) {
        cout << Solution().makesquare(matchsticks) << " = " << res << endl;
    }
    return 0;
}