#include <limits>
#include <vector>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(const vector<int>& nums) {
        int xor_all = 0;
        for (const auto & n : nums)
            xor_all ^= n;

        std::vector<int> res(2, 0);
        int flag = xor_all == std::numeric_limits<int>::min() ?  xor_all : (xor_all & -xor_all);
        for (const auto & n : nums) {
            if ((n & flag) == flag) {
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }

        return res;
    }
};

int main() {
    LC_D(Solution::singleNumber);
    LC_T({1,2,1,3,2,5}, {3,5});
    LC_T({-1,0}, {-1,0});
    LC_T({0,1}, {1,0});
    LC_T({1,1,0,-2147483648}, {0,-2147483648});
    return 0;
}