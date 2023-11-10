// https://leetcode.cn/problems/successful-pairs-of-spells-and-potions

#include <algorithm>
#include <cmath>
#include <vector>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());

        std::sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); ++i) {
            long long need = success / spells[i] + (success % spells[i] != 0);
            auto found = std::lower_bound(potions.begin(), potions.end(), need);

            if (found == potions.end()) {
                res[i] = 0;
            } else {
                res[i] = potions.size() - (found - potions.begin());
            }
        }

        return res;
    }

    vector<int> _(const vector<int>& spells, const vector<int>& potions, long long success) {
        auto s = spells;
        auto p = potions;
        return successfulPairs(s, p, success);
    }
};

int main() {
    LC_D(Solution::_);
    LC_T({5,1,3}, {1,2,3,4,5}, 7, {4,0,3});
    LC_T({3,1,2}, {8,5,8}, 16, {2,0,2});
    return 0;
}
