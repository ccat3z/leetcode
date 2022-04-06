/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 *
 * https://leetcode-cn.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (38.39%)
 * Likes:    571
 * Dislikes: 0
 * Total Accepted:    37.3K
 * Total Submissions: 90.6K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * 树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
 * 
 * 给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges
 * 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
 * 
 * 可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为
 * 最小高度树 。
 * 
 * 请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。
 * 树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, edges = [[1,0],[1,2],[1,3]]
 * 输出：[1]
 * 解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
 * 输出：[3,4]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2 * 10^4
 * edges.length == n - 1
 * 0 <= ai, bi < n
 * ai != bi
 * 所有 (ai, bi) 互不相同
 * 给定的输入 保证 是一棵树，并且 不会有重复的边
 * 
 * 
 */
// REVIEW
#include <vector>
#include <iostream>
#include <queue>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int findLongestNode(int n, vector<int> &parent, vector<vector<int>> &near) {
        vector<bool> vis(near.size(), false);
        queue<int> q; q.push(n);
        vis[n] = true;
        parent[n] = -1;

        int node;

        while (!q.empty()) {
            int layer_size = q.size();

            for (int i = 0; i < layer_size; ++i) {
                node = q.front(); q.pop();
                // cout << node << endl;
                for (auto &child : near[node]) {
                    if (vis[child]) {
                        continue;
                    }

                    vis[child] = true;
                    parent[child] = node;
                    q.push(child);
                }
            }

            // cout << "---" << endl;
        }

        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> near(n);
        for (auto &edge : edges) {
            near[edge[0]].push_back(edge[1]);
            near[edge[1]].push_back(edge[0]);
        }
        vector<int> parent(n);

        int x = findLongestNode(0, parent, near);
        int y = findLongestNode(x, parent, near);
        // cout << x << ' ' << y << endl;

        vector<int> path;
        path.push_back(y);
        while (parent[y] != -1) {
            path.push_back(parent[y]);
            y = parent[y];
        }
        // cout << path << endl;

        if (path.size() % 2 == 0) {
            return {path[path.size() / 2 - 1], path[path.size() / 2]};
        } else {
            return {path[path.size() / 2]};
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    int n = 6;
    cout << Solution().findMinHeightTrees(n, edges) << endl;
    return 0;
}