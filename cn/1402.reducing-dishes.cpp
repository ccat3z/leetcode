#include <algorithm>
#include <functional>
#include <vector>

#include "leetcode_helper.h"

using namespace std;

std::ostream &operator<<(std::ostream &o, std::vector<int> vec) {
    o << "[";
    for (auto & n : vec) {
        o << n << ",";
    }
    o << "]";
    return o;
}

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());

        int add = 0;
        int sum = 0;
        int max_sum = 0;
        for (auto n : satisfaction) {
            add += n;
            sum += add;
            max_sum = std::max(max_sum, sum);
        }
        return max_sum;
    }

    int _(const vector<int>& satisfaction) {
        auto s = satisfaction;
        return maxSatisfaction(s);
    }
};

int main() {
    LC_D(Solution::_);
    LC_T({-1,-8,0,5,-9}, 14);
    LC_T({4,3,2}, 20);
    LC_T({-1,-4,-5}, 0);
    return 0;
}