/*
 * @lc app=leetcode.cn id=780 lang=cpp
 *
 * [780] 到达终点
 *
 * https://leetcode-cn.com/problems/reaching-points/description/
 *
 * algorithms
 * Hard (29.46%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 40.6K
 * Testcase Example:  '1\n1\n3\n5'
 *
 * 给定四个整数 sx , sy ，tx 和 ty，如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，则返回 true，否则返回
 * false。
 * 
 * 从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: sx = 1, sy = 1, tx = 3, ty = 5
 * 输出: true
 * 解释:
 * 可以通过以下一系列转换从起点转换到终点：
 * (1, 1) -> (1, 2)
 * (1, 2) -> (3, 2)
 * (3, 2) -> (3, 5)
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: sx = 1, sy = 1, tx = 2, ty = 2 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: sx = 1, sy = 1, tx = 1, ty = 1 
 * 输出: true
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= sx, sy, tx, ty <= 10^9
 * 
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        int step;
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;

            if (tx == ty) {
                return false;
            }

            if (tx < ty) {
                swap(sx, sy);
                swap(tx, ty);
            }

            step = ty;
            if (step <= sy) {
                step = (sy / step + 1) * step;
            }
            if (step <= sx) {
                step = (sx / step + 1) * step;
            }

            if (tx / step > 1) {
                tx %= step;
                tx += step;
            } else {
                tx -= ty;
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    cout << Solution().reachingPoints(1, 1, 3, 5) << endl;
    cout << Solution().reachingPoints(1, 1, 2, 2) << endl;
    cout << Solution().reachingPoints(1, 1, 1, 1) << endl;
    cout << Solution().reachingPoints(9, 10, 9, 19) << endl;
    cout << Solution().reachingPoints(10, 5, 15, 5) << endl;
    cout << Solution().reachingPoints(1, 6, 11, 10) << endl;
    return 0;
}
