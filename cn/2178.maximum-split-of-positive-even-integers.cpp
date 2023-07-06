// https://leetcode.cn/problems/maximum-split-of-positive-even-integers/

#include <vector>

#include "leetcode_helper.h"

class Solution {
public:
    std::vector<long long> maximumEvenSplit(long long finalSum) {
        std::vector<long long> res;
        if (finalSum % 2 == 1) return res;

        long long remain = finalSum / 2;
        long long n = 1;

        for (; n <= remain; ++n) {
            res.emplace_back(n * 2);
            remain -= n;
        }
        res.back() += remain * 2;

        return res;
    }
};

int main() {
    LC_D(Solution::maximumEvenSplit);
    LC_T(2, {2});
    LC_T(12, {2,4,6});
    LC_T(7, {});
    LC_T(28, {2,4,6,16});
    return 0;
}