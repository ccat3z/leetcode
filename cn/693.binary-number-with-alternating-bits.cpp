/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 *
 * https://leetcode-cn.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (60.79%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 72.3K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 5
 * 输出：true
 * 解释：5 的二进制表示是：101
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 7
 * 输出：false
 * 解释：7 的二进制表示是：111.
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 11
 * 输出：false
 * 解释：11 的二进制表示是：1011.
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int flag = 1;
        bool last = (n & flag) == flag;
        while ((flag = flag << 1) <= n) {
            if (last == ((n & flag) == flag)) return false;
            last = !last;
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {5, 7, 11};
    for (auto num : nums) {
        cout << Solution().hasAlternatingBits(num) << ": " << num << endl;
    }
    return 0;
}