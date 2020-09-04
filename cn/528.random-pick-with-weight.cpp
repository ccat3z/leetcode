/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 *
 * https://leetcode-cn.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (44.57%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 7.7K
 * Testcase Example:  '["Solution","pickIndex"]\r\n[[[1]],[]]\r'
 *
 * 给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标
 * i，选取下标 i 的概率与 w[i] 成正比。
 * 
 * 
 * 
 * 
 * 例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1
 * + 3) = 0.75（即，75%）。
 * 
 * 也就是说，选取下标 i 的概率为 w[i] / sum(w) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * 输出：
 * [null,0]
 * 解释：
 * Solution solution = new Solution([1]);
 * solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。
 * 
 * 示例 2：
 * 
 * 输入：
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * 输出：
 * [null,1,1,1,1,0]
 * 解释：
 * Solution solution = new Solution([1, 3]);
 * solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
 * solution.pickIndex(); // 返回 1
 * solution.pickIndex(); // 返回 1
 * solution.pickIndex(); // 返回 1
 * solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。
 * 
 * 由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
 * [null,1,1,1,1,0]
 * [null,1,1,1,1,1]
 * [null,1,1,1,0,0]
 * [null,1,1,1,0,1]
 * [null,1,0,1,0,0]
 * ......
 * 诸若此类。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex 将被调用不超过 10000 次
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    // w       1      3      5
    // step [0, 1) [1, 4) [4, 9)
    // i       0      1      2
    vector<int> step;
    int max;

    Solution(vector<int>& w) {
        step.reserve(w.size());
        step.push_back(w[0]);
        for (int i = 1; i < w.size(); ++i) {
            step.push_back(step[i - 1] + w[i]);
        }
        max = step[step.size() - 1];
        srand(time(NULL));
    }

    int find(int n, int a, int b) {
        if (a == b) return a;

        int m = (a + b) / 2;
        if (n < step[m]) {
            return find(n, a, m);
        } else {
            return find(n, m + 1, b);
        }
    }
    
    int pickIndex() {
        int r = rand() % max;
        return find(r, 0, step.size() - 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

int main() {
    vector<vector<int>> inputs = {
        {1},
        {1,3},
        {1, 1000, 1000}
    };
    for_each(inputs.begin(), inputs.end(), [&] (vector<int> &i) {
        Solution s(i);
        cout << s.pickIndex() << endl;
    });
}
