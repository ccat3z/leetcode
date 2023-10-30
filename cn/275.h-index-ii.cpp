// https://leetcode.cn/problems/h-index-ii

#include <algorithm>
#include <functional>
#include <vector>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int hIndex(const vector<int>& citations) {
        // find min i => (h = len - i) <= c[i]
        int l = 0, r = citations.size() - 1;

        int h = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            int hn = citations.size() - mid;
            if (hn <= citations[mid]) {
                h = hn;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return h;
    }
};

int main() {
    LC_D(Solution::hIndex);
    LC_T({0,1,3,5,6}, 3);
    LC_T({1,2,100}, 2);
    LC_T({1}, 1);
    return 0;
}