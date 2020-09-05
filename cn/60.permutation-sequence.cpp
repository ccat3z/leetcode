/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (49.08%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    54.4K
 * Total Submissions: 107.7K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

//  p   i[n] = \ (k % n!) / (n-1)! /
// 123  000   0 0 0
// 132  010   1 1 0
// 213  100   2 0 0
// 231  110   3 1 0
// 312  200   4 0 0
// 321  210   5 1 0

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res; res.reserve(n);
        bitset<10> used;

        int fa = 1;
        for (int i = 1; i <= n; fa *= i++);
        int fa_1 = fa / n;

        for (int i = n; i >= 1; --i) {
            int index = ((k - 1) % fa) / fa_1;
            for (int j = 1; j <= 9; ++j) {
                if (used[j]) continue;
                if (index == 0) {
                    used[j] = true;
                    res.push_back(j + '0');
                    break;
                }
                --index;
            }
            fa /= i;
            if (i != 1) fa_1 /= i - 1;
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<int, int>> inputs = {
        make_tuple(3, 3),
        make_tuple(4, 9),
        make_tuple(1, 1),
    };
    for_each(inputs.begin(), inputs.end(), [&](tuple<int, int> &t) {
        cout << Solution().getPermutation(get<0>(t), get<1>(t)) << endl;
    });
}