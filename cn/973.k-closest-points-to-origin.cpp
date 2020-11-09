/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 *
 * https://leetcode-cn.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (58.67%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 71K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * 我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
 * 
 * （这里，平面上两点之间的距离是欧几里德距离。）
 * 
 * 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[1,3],[-2,2]], K = 1
 * 输出：[[-2,2]]
 * 解释： 
 * (1, 3) 和原点之间的距离为 sqrt(10)，
 * (-2, 2) 和原点之间的距离为 sqrt(8)，
 * 由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
 * 我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
 * 输出：[[3,3],[-2,4]]
 * （答案 [[-2,4],[3,3]] 也会被接受。）
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 * 
 * 
 */
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> q;
        for (int i = 0; i < points.size(); ++i) {
            vector<int> &point = points[i];
            tuple<int, int> t = {point[0] * point[0] + point[1] * point[1], i};
            q.emplace(t);
        }
        while (K-- > 0) {
            res.emplace_back(points[get<1>(q.top())]);
            q.pop();
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<vector<int>>, int>> inputs = {
        {{{3,3},{5,-1},{-2,4}},2},
    };
    for (auto input : inputs) {
        cout << Solution().kClosest(get<0>(input), get<1>(input)) << endl;
    }
}