/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 *
 * https://leetcode-cn.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
 *
 * algorithms
 * Hard (45.73%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 7.2K
 * Testcase Example:  '5\n[3,4,1,1,0,0]'
 *
 * 在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。
 * 
 * 花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。
 * 
 * 给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i
 * 处的水龙头，可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。
 * 
 * 请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：n = 5, ranges = [3,4,1,1,0,0]
 * 输出：1
 * 解释：
 * 点 0 处的水龙头可以灌溉区间 [-3,3]
 * 点 1 处的水龙头可以灌溉区间 [-3,5]
 * 点 2 处的水龙头可以灌溉区间 [1,3]
 * 点 3 处的水龙头可以灌溉区间 [2,4]
 * 点 4 处的水龙头可以灌溉区间 [4,4]
 * 点 5 处的水龙头可以灌溉区间 [5,5]
 * 只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 3, ranges = [0,0,0,0]
 * 输出：-1
 * 解释：即使打开所有水龙头，你也无法灌溉整个花园。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 7, ranges = [1,2,1,0,2,1,0,1]
 * 输出：3
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 8, ranges = [4,0,0,0,0,0,0,0,4]
 * 输出：2
 * 
 * 
 * 示例 5：
 * 
 * 输入：n = 8, ranges = [4,0,0,0,4,0,0,0,4]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * ranges.length == n + 1
 * 0 <= ranges[i] <= 100
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // ranges:  3:2
        //      r:  3:[1,5]
        //      f:  1:max(f[1], 5)
        vector<int> f(n + 1, 0);
        for (int i = 0; i < ranges.size(); ++i) {
            int s = max(0, i - ranges[i]);
            int e = min(n, i + ranges[i]);
            f[s] = max(f[s], e);
        }

        // 45. 跳跃游戏 II
        int used = 0;
        int filled = 0;
        int max_filled = 0;
        for (int i = 0; i < f.size(); ++i) {
            max_filled = max(max_filled, f[i]);
            if (i == filled) {
                // cout << max_filled << endl;
                if (max_filled <= filled) break;
                filled = max_filled;
                ++used;
            }
        }
        return filled >= n ? used : -1;
    }
};
// @lc code=end

int main() {
    tuple<int, int, int> t;
    vector<tuple<int, vector<int>>> inputs = {
        make_tuple(5, vector<int>({3,4,1,1,0,0})),          // 1
        make_tuple(3, vector<int>({0,0,0,0})),              // -1
        make_tuple(7, vector<int>({1,2,1,0,2,1,0,1})),      // 3
        make_tuple(8, vector<int>({4,0,0,0,0,0,0,0,4})),    // 2
        make_tuple(8, vector<int>({4,0,0,0,4,0,0,0,4})),    // 1
        make_tuple(9, vector<int>({0,5,0,3,3,3,1,4,0,4})),  // 2
        make_tuple(19, vector<int>({4,1,5,0,5,3,3,3,0,0,3,3,2,2,4,4,2,3,4,2}))
                                                            // 3
    };
    for (auto it = inputs.begin(); it != inputs.end(); ++it) {
        cout << Solution().minTaps(get<0>(*it), get<1>(*it)) << endl;
    }
    return 0;
}