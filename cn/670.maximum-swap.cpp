/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 *
 * https://leetcode-cn.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (45.94%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    42.5K
 * Total Submissions: 89.8K
 * Testcase Example:  '2736'
 *
 * 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
 * 
 * 示例 1 :
 * 
 * 
 * 输入: 2736
 * 输出: 7236
 * 解释: 交换数字2和数字7。
 * 
 * 
 * 示例 2 :
 * 
 * 
 * 输入: 9973
 * 输出: 9973
 * 解释: 不需要交换。
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数字的范围是 [0, 10^8]
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        int a = 0, b = 0;
        int max_n = get_n(num, 0);
        int max_i = 0;

        for (int i = 1; ; i++) {
            int n = get_n(num, i);
            if (n < 0) break;

            if (n > max_n) {
                max_n = n;
                max_i = i;
            } else if (n < max_n) {
                a = i;
                b = max_i;
            }
        }

        int n_a = get_n(num, a);
        int n_b = get_n(num, b);
        if (a != b) {
            set_n(num, a, n_b);
            set_n(num, b, n_a);
        }

        return num;
    }

    int get_n(int num, int i) {
        if (i && num < pow10(i)) return -1;
        return (num % pow10(i+1)) / pow10(i);
    }

    void set_n(int &num, int i, int n) {
        num -= get_n(num, i) * pow10(i);
        num += n * pow10(i);
    }

    static int pow10(int n) noexcept {
        switch (n) {
            case 0: return 1;
            case 1: return 10;
            case 2: return 100;
            case 3: return 1000;
            case 4: return 10000;
            case 5: return 100000;
            case 6: return 1000000;
            case 7: return 10000000;
            case 8: return 100000000;
            case 9: return 1000000000;
        }
        return -1;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {0, 1, 2736, 9973};
    for (auto & num : nums) {
        cout << "# " << num << endl;
        cout << Solution().maximumSwap(num) << " <<<" << endl;
    }
    return 0;
}

