/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 *
 * https://leetcode-cn.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (44.16%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 55.6K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * 给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。
 * 
 * 点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。
 * 
 * 一个 有效的正方形 有四条等边和四个等角(90度角)。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
 * 输出：false
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * p1.length == p2.length == p3.length == p4.length == 2
 * -10^4 <= xi, yi <= 10^4
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (_validSquare(p1, p2, p3, p4)) return true;

        swap(p2, p3);
        if (_validSquare(p1, p2, p3, p4)) return true;

        swap(p2, p4);
        if (_validSquare(p1, p2, p3, p4)) return true;

        return false;
    }

    bool _validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1[0] + p2[0] != p3[0] + p4[0] || p1[1] + p2[1] != p3[1] + p4[1]) return false;
        if (distance2(p1, p2) != distance2(p3, p4)) return false;

        double a1 = atan2(p1[0] - p2[0], p1[1] - p2[1]) / M_PI;
        double a2 = atan2(p3[0] - p4[0], p3[1] - p4[1]) / M_PI;
        if (a1 < a2) swap(a1, a2);

        double ad = a1 - a2;
        if (ad > 1) ad -= 1;
        ad -= 0.5;
        ad = abs(ad);
        if (ad > 0.00001)
            return false;
        
        return true;
    }

    inline int distance2(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
// @lc code=end

int main() {
    vector<vector<int>> p = {
        {0,0},
        {1,1},
        {1,0},
        {0,1},
    };
    cout << Solution().validSquare(p[0], p[1], p[2], p[3]) << endl;

    return 0;
}