#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    vector<int> smallestMissingValueSubtree(const vector<int>& parents, const vector<int>& nums) {
        std::vector<std::vector<int>> children(parents.size());
        for (int i = 0; i < parents.size(); ++i) {
            if (parents[i] == -1) continue;
            children[parents[i]].emplace_back(i);
        }

        std::unordered_set<int> has;
        std::vector<bool> vised(parents.size());
        std::function<void (int)> dfs = [&](int node) {
            if (vised[node]) {
                return;
            }
            vised[node] = true;

            has.emplace(nums[node]);
            for (auto c : children[node]) {
                dfs(c);
            }
        };

        // Find num==1
        int node = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                node = i;
                break;
            }
        }

        vector<int> res(parents.size(), 1);
        int miss = 1;
        while (node != -1) {
            dfs(node);

            while (has.contains(miss)) {
                ++miss;
            }
            res[node] = miss;

            node = parents[node];
        }
        return res;
    }
};

int main() {
    LC_D(Solution::smallestMissingValueSubtree);
    LC_T({-1,0,0,2}, {1,2,3,4}, {5,1,1,1});
    LC_T({-1,0,1,0,3,3}, {5,4,6,2,1,3}, {7,1,1,4,2,1});
    LC_T({-1,2,3,0,2,4,1}, {2,3,4,5,6,7,8}, {1,1,1,1,1,1,1});
    return 0;
}