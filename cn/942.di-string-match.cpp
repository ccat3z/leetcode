/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 *
 * https://leetcode-cn.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (73.44%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    40.9K
 * Total Submissions: 53.6K
 * Testcase Example:  '"IDID"'
 *
 * 由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:
 * 
 * 
 * 如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
 * 如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
 * 
 * 
 * 给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "IDID"
 * 输出：[0,4,1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "III"
 * 输出：[0,1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "DDI"
 * 输出：[3,2,0,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含字符 "I" 或 "D"
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res(s.size() + 1, 0);
        int minN = 0;
        int maxN = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'I') {
                res[i+1] = ++maxN;
            } else {
                res[i+1] = --minN;
            }
        }

        for (auto &n : res) {
            n += -minN;
        }
        
        return res;
    }
};
// @lc code=end

int main() {
    vector<string> tests = {
        "IDID",
        "III",
        "DDI"
    };
    for (auto &s : tests) {
        cout << Solution().diStringMatch(s) << endl;
    }
    return 0;
}