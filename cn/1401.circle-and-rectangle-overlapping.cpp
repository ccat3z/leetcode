/*
 * @lc app=leetcode.cn id=1401 lang=cpp
 *
 * [1401] 圆和矩形是否有重叠
 *
 * https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/description/
 *
 * algorithms
 * Medium (36.73%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 5.9K
 * Testcase Example:  '1\n0\n0\n1\n-1\n3\n1'
 *
 * 给你一个以 (radius, x_center, y_center) 表示的圆和一个与坐标轴平行的矩形 (x1, y1, x2, y2)，其中 (x1,
 * y1) 是矩形左下角的坐标，(x2, y2) 是右上角的坐标。
 * 
 * 如果圆和矩形有重叠的部分，请你返回 True ，否则返回 False 。
 * 
 * 换句话说，请你检测是否 存在 点 (xi, yi) ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
 * 输出：true
 * 解释：圆和矩形有公共点 (1,0) 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= radius <= 2000
 * -10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
 * x1 < x2
 * y1 < y2
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//
//            x2
//       +----+ y2
//       |    |
//    y1 +----+
//      x1    
//

// @lc code=start
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x_anchor = x_center, y_anchor = y_center;
        if (x_anchor < x1) x_anchor = x1; 
        else if (x_anchor > x2) x_anchor = x2;
        if (y_anchor < y1) y_anchor = y1;
        else if (y_anchor > y2) y_anchor = y2;
        // cout << x_anchor << ' ' << y_anchor << endl;
        x_anchor -= x_center;
        y_anchor -= y_center;
        // cout << x_anchor << ' ' << y_anchor << endl;
        int d = sqrt(x_anchor * x_anchor + y_anchor * y_anchor);
        return d <= radius;
    }
};
// @lc code=end

int main() {
    vector<int*> as = {
        new int[7]{1, 0, 0, 1, -1, 3, 1},
        new int[7]{1, 0, 0, -1, 0, 0, -1},
        new int[7]{1, 1, 1, 1, -3, 2, -1},
        new int[7]{2, 1, 2, 5, 8, 6, 12}
    };
    for (auto it = as.begin(); it != as.end(); ++it) {
        cout << Solution().checkOverlap((*it)[0], (*it)[1], (*it)[2], (*it)[3], (*it)[4], (*it)[5], (*it)[6]) << endl;
    }
    return 0;
}