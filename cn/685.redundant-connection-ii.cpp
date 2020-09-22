/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 *
 * https://leetcode-cn.com/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (35.27%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 33.3K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。
 * 
 * 输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N)
 * 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
 * 
 * 结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v
 * 的一个父节点。
 * 
 * 返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 * 
 * 示例 1:
 * 
 * 输入: [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 * 解释: 给定的有向图如下:
 * ⁠ 1
 * ⁠/ \
 * v   v
 * 2-->3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
 * 输出: [4,1]
 * 解释: 给定的有向图如下:
 * 5 <- 1 -> 2
 * ⁠    ^    |
 * ⁠    |    v
 * ⁠    4 <- 3
 * 
 * 
 * 注意:
 * 
 * 
 * 二维数组大小的在3到1000范围内。
 * 二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include "prettyprint.h"
using namespace std;

// REVIEW

// @lc code=start
class UnionFind {
public:
    int *f;
    UnionFind(int size) {
        f = new int[size];
        for (int i = 0; i < size; ++i) {
            f[i] = i;
        }
    }
    void uniona(int a, int b) {
        f[find(a)] = find(b);
    }
    int find(int a) {
        if (f[a] != a) {
            f[a] = find(f[a]);
        }
        return f[a];
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size() + 1);
        int parentof[edges.size() + 1];
        for (int i = 1; i <= edges.size(); ++i) parentof[i] = i;

        int a, b;
        int conflict_parent = -1, cycle = -1;
        for (int i = 0; i < edges.size(); ++i) {
            vector<int> &edge = edges[i];
            a = edge[0]; b = edge[1];
            if (parentof[b] != b) {
                conflict_parent = i;
            } else {
                parentof[b] = a;

                // a, b on a same tree
                if (uf.find(a) == uf.find(b)) {
                    cycle = i;
                } else {
                    uf.uniona(a, b);
                }
            }
        }

        if (conflict_parent < 0) {
            // no conflict parent
            // 1 <---+
            // |     |  <== cycle
            // v     |
            // 2 --> 3
            return edges[cycle];
        } else {
            // has conflict parent
            if (cycle >= 0) {
                // 0
                // | <= conflict_parent  1 has two parent
                // v
                // 1 <---+
                // | <== | <== cycle
                // v     |
                // 2 --> 3
                //   ^== cycle
                return {parentof[edges[conflict_parent][1]], edges[conflict_parent][1]};
            } else {
                // 0
                // |   3 has two parent
                // v
                // 1 ----+
                // |     |  <== conflict_parent
                // v     v
                // 2 --> 3
                //    ^== conflict_parent
                return edges[conflict_parent];
            }
        }
        return {0, 0};
    }
};
// @lc code=end

int main() {
    vector<vector<vector<int>>> inputs = {
        {{1,2}, {1,3}, {2,3}},
        {{1,2}, {2,3}, {3,4}, {4,1}, {1,5}},
    };
    for (auto i : inputs) {
        cout << Solution().findRedundantDirectedConnection(i) << endl;
    }
}