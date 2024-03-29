/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 *
 * https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (38.61%)
 * Likes:    378
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 66.9K
 * Testcase Example:  '13\n2'
 *
 * 给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 13, k = 2
 * 输出: 10
 * 解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 1, k = 1
 * 输出: 1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= k <= n <= 10^9
 * 
 * 
 */
// REVIEW
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }

    // let curr = 12. getSteps find count of [12 .. 12___ < n].
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }
};
// @lc code=end

int main() {
    cout << Solution().findKthNumber(24, 22) << endl;
    return 0;
}