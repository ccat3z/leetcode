/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 *
 * https://leetcode-cn.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (54.69%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 28.9K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和
 * values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj
 * = ? 的结果作为答案。
 * 
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
 * 
 * 
 * 
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * 解释：
 * 条件：a / b = 2.0, b / c = 3.0
 * 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
 * queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * 输出：[3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * 输出：[0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * equations[i].length == 2
 * 1 i.length, Bi.length 
 * values.length == equations.length
 * 0.0 < values[i] 
 * 1 
 * queries[i].length == 2
 * 1 j.length, Dj.length 
 * Ai, Bi, Cj, Dj 由小写英文字母与数字组成
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <bitset>
#include "prettyprint.h"
using namespace std;

// @lc code=start
#define MAX_KEYS (20)
class Solution {
public:
    map<string, short> keys;
    int key_max = -1;
    inline int get_key(const string &a) {
        if (keys.find(a) == keys.end()) {
            keys[a] = ++key_max;
        }
        return keys[a];
    }

    double graph[MAX_KEYS][MAX_KEYS];
    Solution() {
        fill(&graph[0][0], &graph[MAX_KEYS - 1][MAX_KEYS], -1);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;

        // fill graph
        int eq_len = equations.size();
        for (int i = 0; i < eq_len; ++i) {
            vector<string> &eq = equations[i];
            double &v = values[i];
            graph[get_key(eq[0])][get_key(eq[1])] = v;
            graph[get_key(eq[1])][get_key(eq[0])] = 1/v;
        }

        // calc query
        double result;
        for (auto query : queries) {
            res.emplace_back(this->query(query[0], query[1]));
        }
        return res;
    }

    bitset<MAX_KEYS> visited;
    double query(const string &a, const string &b) {
        if (keys.find(a) == keys.end() || keys.find(b) == keys.end()) {
            return -1;
        }

        visited.reset();
        return _query(keys[a], keys[b]);
    }
    double _query(int a, int b) {
        if (a == b) return 1;
        visited[a] = 1;

        for (int i = 0; i < MAX_KEYS; ++i) {
            int n = (i + b) % MAX_KEYS;
            if (visited[n]) continue;

            auto &v_a_n = graph[a][n];
            if (v_a_n == -1) continue;
            double v_n_b = _query(n, b);
            if (v_n_b != -1) {
                graph[a][b] = v_a_n * v_n_b;
                return graph[a][b];
            }
        }

        return -1;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<vector<string>>, vector<double>, vector<vector<string>>>> inputs = {
        {
            {{"a","b"},{"b","c"}}, {2.0,3.0},
            {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}}
        },
        {
            {{"a","b"},{"b","c"},{"bc","cd"}}, {1.5,2.5,5.0},
            {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}}
        },
        {
            {{"a","b"}}, {0.5},
            {{"a","b"},{"b","a"},{"a","c"},{"x","y"}}
        },
        {
            {{"a","e"},{"b","e"}}, {4.0,3.0},
            {{"a","b"},{"e","e"},{"x","x"}}
        },
        {
            {{"a","b"},{"b","c"},{"bc","cd"}}, {1.5,2.5,5.0},
            {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}}
        }
    };
    
    for (auto it : inputs) {
        cout << Solution().calcEquation(get<0>(it), get<1>(it), get<2>(it)) << endl;
    }
}