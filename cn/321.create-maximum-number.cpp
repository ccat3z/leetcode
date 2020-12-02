/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 *
 * https://leetcode-cn.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (30.90%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 24.8K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n)
 * 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
 * 
 * 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
 * 
 * 说明: 请尽可能地优化你算法的时间和空间复杂度。
 * 
 * 示例 1:
 * 
 * 输入:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * 输出:
 * [9, 8, 6, 5, 3]
 * 
 * 示例 2:
 * 
 * 输入:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * 输出:
 * [6, 7, 6, 0, 4]
 * 
 * 示例 3:
 * 
 * 输入:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * 输出:
 * [9, 8, 9]
 * 
 */

// TODO: 没做出来

#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
private:
    int ***cache;
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        cache = new int**[nums1.size()+1];
        for_each(cache, cache + nums1.size() +1, [&](int **&it) {
            it = new int*[nums2.size() + 1];

            for_each(it, it + nums2.size() + 1, [&](int *&jt) {
                jt = new int[k+1];

                fill(jt, jt+k+1, -2);
            });
        });

        int res = findMax(nums1, 0, nums2, 0, k);

        vector<int> v(k);
        while (k--) {
            v[k] = res % 10;
            res /= 10;
        }
        return v;
    }

    // f [i1..] [i2..] k =
    //   max:
    //     f [i1+1..] [i2..] k-1 * 10 + n1[i1]
    //     f [i1+1..] [i2..] k
    //     f [i1..] [i2+1..] k-1 * 10 + n2[i2]
    //     f [i1..] [i2+1..] k
    int findMax(vector<int> &nums1, int i1, vector<int> &nums2, int i2, int k) {
        if (k == 0) {
            return 0;
        }

        int &res = cache[i1][i2][k];
        if (res != -2) return res;
        else res = -1;

        int sub;

        if (i1 < nums1.size()) {
            sub = findMax(nums1, i1+1, nums2, i2, k-1);
            if (sub >= 0) res = max(res, ((int) pow(10, k-1)) * nums1[i1] + sub);
            sub = findMax(nums1, i1+1, nums2, i2, k);
            if (sub >= 0) res = max(res, sub);
        }

        if (i2 < nums2.size()) {
            sub = findMax(nums1, i1, nums2, i2+1, k-1);
            if (sub >= 0) res = max(res, ((int) pow(10, k-1)) * nums2[i2] + sub);
            sub = findMax(nums1, i1, nums2, i2+1, k);
            if (sub >= 0) res = max(res, sub);
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, vector<int>, int>> inputs = {
        {{3,4,6,5}, {9,1,2,5,8,3}, 5},
        {{6,7}, {6,0,4}, 5},
        {{3,9}, {8,9}, 3},
        {{}, {}, 0},
    };

    for (auto i : inputs) {
        cout << Solution().maxNumber(get<0>(i), get<1>(i), get<2>(i)) << endl;
    }
    return 0;
}