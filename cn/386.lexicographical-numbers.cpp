/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 *
 * https://leetcode-cn.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (75.23%)
 * Likes:    296
 * Dislikes: 0
 * Total Accepted:    38.5K
 * Total Submissions: 50.6K
 * Testcase Example:  '13'
 *
 * 给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
 * 
 * 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 13
 * 输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 2
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 5 * 10^4
 * 
 * 
 */
#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        fill(n, 0, res, 1);
        return res;
    }

    void fill(int n, int base, vector<int> &res, int start = 0) {
        cout << base << endl;
        int num;
        for (int i = start; i <= 9; ++i) {
            num = base * 10 + i;
            if (num > n) break;
            res.emplace_back(num);
            fill(n, num, res);
        }
    }
};
// @lc code=end

int main() {
    cout << Solution().lexicalOrder(100) << endl;
    return 0;
}