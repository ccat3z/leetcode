// https://leetcode.cn/problems/h-index

#include <algorithm>
#include <functional>
#include <vector>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<>());

        int h = 0;
        for (int i = 0; i < citations.size() && i + 1 > h; ++i) {
            if (citations[i] >= i + 1) {
                h = i + 1;
            }
        }

        return h;
    }

    int _(const vector<int>& citations) {
        auto c = citations;
        return hIndex(c);
    }
};

int main() {
    LC_D(Solution::_);
    LC_T({3,0,6,1,5}, 3);
    LC_T({1,3,1}, 1);
    return 0;
}