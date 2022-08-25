/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 *
 * https://leetcode-cn.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (45.64%)
 * Likes:    386
 * Dislikes: 0
 * Total Accepted:    56.7K
 * Total Submissions: 119.4K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 * 
 * 整数 a 比整数 b 更接近 x 需要满足：
 * 
 * 
 * |a - x| < |b - x| 或者
 * |a - x| == |b - x| 且 a < b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [1,2,3,4,5], k = 4, x = -1
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr 按 升序 排列
 * -10^4 <= arr[i], x <= 10^4
 * 
 * 
 */
#include <vector>
#include <tuple>
#include <iostream>
#include <queue>
#include <cmath>
#include "prettyprint.h"
using namespace std;
// TODO: binary search

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        queue<int> q;

        for (auto &num : arr) {
            if (q.size() < k) {
                q.emplace(num);
                continue;
            }

            int dis_a = abs(num - x);
            int dis_b = abs(q.front() - x);
            if ((dis_a < dis_b) || (dis_a == dis_b && num < q.front())) {
                q.pop();
                q.emplace(num);
                continue;
            }

            if (num > x) break;
        }

        vector<int> res;
        res.reserve(k);
        while (!q.empty()) {
            res.emplace_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, int, int, vector<int>>> cases = {
        {{1,2,3,4,5},4,3,{1,2,3,4}},
        {{1,2,3,4,5},4,-1,{1,2,3,4}}
    };

    for (auto &[arr, k, x, res] : cases) {
        cout << Solution().findClosestElements(arr, k, x) << " = " << res << endl;
    }

    return 0;
}