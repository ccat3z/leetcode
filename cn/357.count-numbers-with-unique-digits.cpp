/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 *
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (52.21%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    34.2K
 * Total Submissions: 62.4K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10^n^ 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：91
 * 解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 0
 * 输出：1
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 8
 * 
 * 
 */
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int cnt = 0;

        cnt += countNumbersWithUniqueDigitsStartsWithNot0(n);
        while (n-- > 1) {
            cnt += countNumbersWithUniqueDigitsStartsWithNot0(n);
        }
        cnt += 1;
        return cnt;
    }

    int countNumbersWithUniqueDigitsStartsWithNot0(int n) {
        if (n == 0) return 0;

        int cnt = 9;
        int choice = 9;
        while (n-- > 1) {
            cnt *= choice--;
        }
        return cnt;
    }
};
// @lc code=end

int main() {
    vector<pair<int, int>> cases = {
        {2, 91},
        {0, 1},
    };
    for (auto c : cases) {
        cout << Solution().countNumbersWithUniqueDigits(c.first) << " = " << c.second << endl;
    }
    return 0;
}