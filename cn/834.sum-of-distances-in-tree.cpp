/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 *
 * https://leetcode-cn.com/problems/sum-of-distances-in-tree/description/
 *
 * algorithms
 * Hard (33.98%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 11.2K
 * Testcase Example:  '6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]'
 *
 * 给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。
 * 
 * 第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。
 * 
 * 返回一个表示节点 i 与其他所有节点距离之和的列表 ans。
 * 
 * 示例 1:
 * 
 * 
 * 输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
 * 输出: [8,12,6,10,10,10]
 * 解释: 
 * 如下为给定的树的示意图：
 * ⁠ 0
 * ⁠/ \
 * 1   2
 * ⁠  /|\
 * ⁠ 3 4 5
 * 
 * 我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
 * 也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
 * 
 * 
 * 说明: 1 <= N <= 10000
 * 
 */
#include <vector>
#include <iostream>
#include <tuple>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> res;
    vector<vector<int>> graph;
    vector<int> dp;
    vector<int> sz;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        int len = edges.size() + 1;
        graph.resize(len);
        dp.resize(len);
        sz.resize(len);
        res.resize(len);
        for (vector<int> &edge : edges) {
            int &u = edge[0], &v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        prepare(0, -1);
        asroot(0, -1);
        return res;
    }
    void prepare(int node, int parent) {
        dp[node] = 0;
        sz[node] = 0;
        for (int &child : graph[node]) {
            if (child == parent) continue; 
            prepare(child, node);
            dp[node] += dp[child] + sz[child] + 1;
            sz[node] += sz[child] + 1;
        }
    }
    void asroot(int node, int parent) {
        if (parent != -1) {
            dp[parent] -= dp[node] + sz[node] + 1;
            sz[parent] -= sz[node] + 1;
            dp[node] += dp[parent] + sz[parent] + 1;
            sz[node] += sz[parent] + 1;
        }

        res[node] = dp[node];

        for (int &child : graph[node]) {
            if (child == parent) continue;
            asroot(child, node);
        }

        if (parent != -1) {
            sz[node] -= sz[parent] + 1;
            dp[node] -= dp[parent] + sz[parent] + 1;
            sz[parent] += sz[node] + 1;
            dp[parent] += dp[node] + sz[node] + 1;
        }
    }
};
// @lc code=end

int main() {
    vector<tuple<int, vector<vector<int>>>> inputs = {
        {6, {{0,1},{0,2},{2,3},{2,4},{2,5}}},
    };
    for (auto i : inputs) {
        cout << Solution().sumOfDistancesInTree(get<0>(i), get<1>(i)) << endl;
    }
    return 0;
}