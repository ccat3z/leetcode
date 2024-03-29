/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 *
 * https://leetcode-cn.com/problems/duplicate-zeros/description/
 *
 * algorithms
 * Easy (58.26%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 74.8K
 * Testcase Example:  '[1,0,2,3,0,4,5,0]'
 *
 * 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
 * 
 * 注意：请不要在超过该数组长度的位置写入元素。
 * 
 * 要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,0,2,3,0,4,5,0]
 * 输出：null
 * 解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,2,3]
 * 输出：null
 * 解释：调用函数后，输入的数组将被修改为：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10000
 * 0 <= arr[i] <= 9
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
    void duplicateZeros(vector<int>& arr) {
        int last, put;
        bool dup_last_zero = false;
        for (last = 0, put = 0; ; ++last) {
            if (++put == arr.size()) break;

            if (arr[last] == 0) {
                if (++put == arr.size()) {
                    dup_last_zero = true;
                    break;
                }
            }
        }

        for (int i = arr.size() - 1; last < i; --i, --last) {
            arr[i] = arr[last];
            if (arr[last] == 0) {
                if (i == arr.size() - 1 && !dup_last_zero) {
                    continue;
                }
                arr[--i] = 0;
            }
        }
    }
};
// @lc code=end

int main() {
    vector<int> arr = {1,0,2,0,3};
    // vector<int> arr = {1,2,0,3};
    Solution().duplicateZeros(arr);
    cout << arr << endl;
    return 0;
}