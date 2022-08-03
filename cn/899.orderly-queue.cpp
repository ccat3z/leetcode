/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 *
 * https://leetcode-cn.com/problems/orderly-queue/description/
 *
 * algorithms
 * Hard (54.41%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 22.7K
 * Testcase Example:  '"cba"\n1'
 *
 * 给定一个字符串 s 和一个整数 k 。你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾。
 *
 * 返回 在应用上述步骤的任意数量的移动后，字典上最小的字符串 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "cba", k = 1
 * 输出："acb"
 * 解释：
 * 在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
 * 在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "baaca", k = 3
 * 输出："aaabc"
 * 解释：
 * 在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
 * 在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= S.length <= 1000
 * s 只由小写字母组成。
 *
 *
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }

        int i = 0, j = 1, len = 0;
        while (i < s.size() && j < s.size() && len < s.size()) {
            auto &a = s[(i + len) % s.size()];
            auto &b = s[(j + len) % s.size()];
            if (a == b) {
                len++;
            } else {
                if (a > b) {
                    i += len + 1; // see https://oi-wiki.org/string/minimal-string/
                } else {
                    j += len + 1;
                }
                len = 0;
                if (i == j) {
                    i++;
                }
            }
        }
        i = min(i, j);
        string res;
        res.reserve(s.size());
        res.append(s.begin() + i, s.end());
        res.append(s.begin(), s.begin() + i);
        return res;
    }
};
// @lc code=end

int main()
{
    cout << Solution().orderlyQueue("cba", 1) << endl;
    cout << Solution().orderlyQueue("baaca", 3) << endl;
    cout << Solution().orderlyQueue("pyplrzxucp", 1) << endl;
    return 0;
}