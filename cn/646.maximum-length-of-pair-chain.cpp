/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 *
 * https://leetcode-cn.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (58.12%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    40K
 * Total Submissions: 66.6K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * 给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
 * 
 * 现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
 * 
 * 给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：[[1,2], [2,3], [3,4]]
 * 输出：2
 * 解释：最长的数对链是 [1,2] -> [3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给出数对的个数在 [1, 1000] 范围内。
 * 
 * 
 */
// TODO: Review

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[1] < b[1];
        });

        int curr = INT32_MIN;
        int res = 0;

        for (auto &pair : pairs) {
            if (curr < pair[0]) {
                curr = pair[1];
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<pair<vector<vector<int>>, int>> cases = {
        {{{1,2}, {3,4}, {2,3}}, 2},
        {{{7,9},{4,5},{7,9},{-7,-1},{0,10},{3,10},{3,6},{2,3}}, 4}
    };

    for (auto & [pairs, res] : cases) {
        cout << "# " << pairs << endl;
        cout << Solution().findLongestChain(pairs) << " = " << res << endl;
    }

    return 0;
}