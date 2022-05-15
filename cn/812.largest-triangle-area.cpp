/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 *
 * https://leetcode-cn.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (63.54%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    27.7K
 * Total Submissions: 40.6K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
 * 
 * 
 * 示例:
 * 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * 输出: 2
 * 解释: 
 * 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
 * 
 * 
 * 
 * 
 * 注意: 
 * 
 * 
 * 3 <= points.length <= 50.
 * 不存在重复的点。
 * -50 <= points[i][j] <= 50.
 * 结果误差值在 10^-6 以内都认为是正确答案。
 * 
 * 
 */
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res;
        int a, b, c;
        int size = points.size();
        for (a = 0; a < size - 2; ++a) {
            for (b = a + 1; b < size - 1; ++b) {
                for (c = b + 1; c < size; ++c) {
                    int &x1 = points[a][0];
                    int &y1 = points[a][1];
                    int &x2 = points[b][0];
                    int &y2 = points[b][1];
                    int &x3 = points[c][0];
                    int &y3 = points[c][1];
                    double s = abs(0.5 * (
                          (x2 * y3 - x3 * y2)
                        - (x1 * y3 - x3 * y1)
                        + (x1 * y2 - x2 * y1)
                    ));
                    res = max(s, res);
                }
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << Solution().largestTriangleArea(points) << endl;
    return 0;
}