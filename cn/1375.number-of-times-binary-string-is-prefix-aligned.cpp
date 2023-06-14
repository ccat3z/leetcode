// https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/

#include <vector>
#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int numTimesAllBlue(const vector<int>& flips) {
        int g = 0;
        int res = 0;
        for (int i = 0; i < flips.size(); ++i) {
            g = max(g, flips[i]);
            if (g == i+1) res += 1;
        }
        return res;
    }
};

int main() {
    LC_D(Solution::numTimesAllBlue);
    LC_T({3,2,4,1,5}, 2);
    LC_T({4,1,2,3}, 1);

    return 0;
}