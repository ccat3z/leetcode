// https://leetcode.cn/contest/weekly-contest-308/problems/build-a-matrix-with-conditions/
// TODO

#include <vector>
#include <iostream>
#include <tuple>
#include <map>
#include <queue>
#include "prettyprint.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<vector<int>> res;
        res.reserve(k);
        for (int i = 0; i < k; i++) res.emplace_back(k, 0);
        return res;
    }

    vector<int> topo(int k, vector<vector<int>> &conds) {
        map<int, vector<int>> graph;
        for (auto cond : conds) {
            graph[cond[0]].emplace_back(cond[1]);
        }

        queue<int> zero;
        for (int i = 1; i <= k; i++) {
            if (graph.find(i) == graph.end()) {
                zero.emplace(i);
            }
        }

        vector<int> res;
        int calced = 0;
        while (!zero.empty()) {
            res.emplace_back(zero.top());
        }
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, vector<vector<int>>>> cases = {
        {
            3,
            {{1,2},{3,2}},
            {{2,1},{3,2}}
        },
        {
            3,
            {{1,2},{2,3},{3,1},{2,3}},
            {{2,1}}
        }
    };

    for (auto &[k, row, col] : cases) {
        cout << Solution().buildMatrix(k, row, col) << endl;
    }
    return 0;
}