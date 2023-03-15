// https://leetcode.cn/problems/maximal-network-rank/

#include <vector>
#include <iostream>
#include <tuple>
#include <bitset>
#include <array>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &o, vector<int> &vec) {
    o << "[";
    for (auto &i : vec) {
        o << i << ",";
    }
    o << "]";
    return o;
}

class Solution {
public:
    int maximalNetworkRank(int n, const vector<vector<int>>& roads) {
        if (roads.size() == 0) return 0;

        vector<bitset<100>> edges;
        vector<int> near;
        edges.resize(n);
        near.resize(n);
        
        for (auto & road : roads) {
            edges[road[0]][road[1]] = true;
            edges[road[1]][road[0]] = true;
            ++near[road[0]];
            ++near[road[1]];
        }

        int max1 = near[0];
        vector<int> max1i = {0};
        int max2 = 0;
        vector<int> max2i;
        for (int i = 1; i < n; i++) {
            if (near[i] > max1) {
                max2 = max1;
                max2i = std::move(max1i);

                max1 = near[i];
                max1i.clear();
                max1i.emplace_back(i);
            } else if (near[i] == max1) {
                max1i.emplace_back(i);
            } else if (near[i] > max2) {
                max2 = near[i];
                max2i.clear();
                max2i.emplace_back(i);
            } else if (near[i] == max2) {
                max2i.emplace_back(i);
            }
            
            // cout << max1i << ", " << max2i << endl;
        }

        if (max1i.size() > 1) {
            for (int i = 0; i < max1i.size(); ++i) {
                for (int j = i + 1; j < max1i.size(); ++j) {
                    // cout << max1i[i] << "$" << max1i[j] << " " << near[max1i[i]] + near[max1i[j]] - edges[max1i[i]][max1i[j]] << endl;
                    if (!edges[max1i[i]][max1i[j]]) return max1 + max1;
                }
            }

            return max1 + max1 - 1;
        }

        for (int i : max1i) {
            for (int j : max2i) {
                // cout << i << "#" << j << " " << near[i] + near[j] - edges[i][j] << endl;
                if (!edges[i][j]) return max1 + max2;
            }
        }

        return max1 + max2 - 1;

        // int res = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         // cout << i << "-" << j << " " << near[i] + near[j] - edges[i][j] << endl;
        //         res = max(near[i] + near[j] - edges[i][j], res);
        //     }
        // }
        // return res;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, int>> tests = {
        {4, {{0,1},{0,3},{1,2},{1,3}}, 4},
        {5, {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}}, 5},
        {8, {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}}, 5},
        {2, {{1,0}}, 1}
    };

    for (auto & [n, roads, ans] : tests) {
        cout << Solution().maximalNetworkRank(n, roads) << " = " << ans << endl;
    }
    
    return 0;
}