// https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/

#include <array>
#include <bits/utility.h>
#include <ostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include "leetcode_helper.h"

using namespace std;

class TreeAncestor {
public:
    // n 2^j parent = (n 2^(j-1) parent) 2^(j-1) parent
    std::vector<std::array<int, 16>> tree;

    TreeAncestor(int n, vector<int>& parent) {
        tree.resize(n);

        for (auto & n : tree) {
            for (auto & a : n) {
                a = -1;
            }
        }

        // fill j = 0;
        for (int i = 0; i < parent.size(); ++i) tree[i][0] = parent[i];

        // fill j >= 1
        for (int j = 1; j < tree[0].size(); j++) {
            for (int i = 0; i < n; i++) {
                if (tree[i][j - 1] != -1) {
                    tree[i][j] = tree[tree[i][j-1]][j-1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < tree[0].size(); j++) {
            if (((k >> j) & 1) == 1) {
                node = tree[node][j];

                if (node == -1) return -1;
            }
        }

        return node;
    }
};

struct Solution {
    std::vector<int> test(const std::tuple<int, std::vector<int>> &ctor, const std::vector<std::tuple<int, int>> &gets) {
        auto [n, parent] = ctor;
        TreeAncestor ta(n, parent);

        std::vector<int> res;
        for (const auto & [node, k] : gets) {
            res.emplace_back(ta.getKthAncestor(node, k));
        }

        return res;
    }
};

int main() {
    LC_D(Solution::test);
    LC_T({7,{-1,0,0,1,1,2,2}}, {{3,1},{5,2},{6,3}}, {1,0,-1});

    return 0;
}