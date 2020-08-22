/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 *
 * https://leetcode-cn.com/problems/24-game/description/
 *
 * algorithms
 * Hard (44.57%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    16.5K
 * Total Submissions: 30.4K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
 * 
 * 示例 1:
 * 
 * 输入: [4, 1, 8, 7]
 * 输出: True
 * 解释: (8-4) * (7-1) = 24
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 1, 2]
 * 输出: False
 * 
 * 
 * 注意:
 * 
 * 
 * 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
 * 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1
 * 是不允许的。
 * 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> dnums(4);
        for (int i = 0; i < 4; ++i) {
            dnums[i] = nums[i];
        }
        return judgePoint24(dnums);
    }
    bool judgePoint24(vector<double>& nums) {
        int s = nums.size();
        if (s == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }

        vector<double> sub_nums(s - 1);
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < s; ++j) {
                if (i == j) continue;
                double &a = nums[i], &b = nums[j];
                for (int k = 0, n = 0; k < s; ++k) {
                    if (k != i && k != j) sub_nums[n++] = nums[k];
                }
                sub_nums[s - 2] = a + b;
                if (judgePoint24(sub_nums)) return true;
                sub_nums[s - 2] = a - b;
                if (judgePoint24(sub_nums)) return true;
                sub_nums[s - 2] = a * b;
                if (judgePoint24(sub_nums)) return true;
                if (b != 0) {
                    sub_nums[s - 2] = a / b;
                    if (judgePoint24(sub_nums)) return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {3, 3, 8, 8};
    cout << Solution().judgePoint24(nums) << endl;
    return 0;
}