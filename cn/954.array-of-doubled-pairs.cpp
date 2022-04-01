/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 *
 * https://leetcode-cn.com/problems/array-of-doubled-pairs/description/
 *
 * algorithms
 * Medium (30.77%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 82.8K
 * Testcase Example:  '[3,1,3,6]'
 *
 * 给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，都有 arr[2 *
 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [3,1,3,6]
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [2,1,2,6]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：arr = [4,-2,2,-4]
 * 输出：true
 * 解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= arr.length <= 3 * 10^4
 * arr.length 是偶数
 * -10^5 <= arr[i] <= 10^5
 * 
 * 
 */
// REVIEW
#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) {
            ++cnt[x];
        }
        if (cnt[0] % 2) {
            return false;
        }

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &c : cnt) {
            vals.push_back(c.first);
        }
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) {
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, bool>> cases = {
        make_tuple(vector<int>{3, 1, 3, 6}, false),
        make_tuple(vector<int>{2, 1, 2, 6}, false),
        make_tuple(vector<int>{4, -2, 2, -4}, true),
    };
    for (auto &c : cases) {
        auto &arr = get<0>(c);
        auto &ans = get<1>(c);
        cout << Solution().canReorderDoubled(arr) << " = " << ans << ' ' << arr << endl;
    }
    return 0;
}
