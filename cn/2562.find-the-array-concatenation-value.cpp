// https://leetcode.cn/problems/find-the-array-concatenation-value/

#include <vector>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(const vector<int>& nums) {
        long long res = 0;

        int a = 0, b = nums.size() - 1;
        for (; a < b; ++a, --b) {
            const int & n1 = nums[a];
            const int & n2 = nums[b];
            int multi = 10;
            while (((double) n2) / ((double) multi) >= 1) {
                multi *= 10;
            }
            // std::cerr << multi << std::endl; 
            res += n1 * multi + n2;
        }

        if (a == b) {
            res += nums[a];
        }

        return res;
    }
};

int main() {
    LC_D(Solution::findTheArrayConcVal);
    LC_T({7,52,2,4}, 596);
    LC_T({5,14,13,8,12}, 673);
    LC_T({1,10},110);

    return 0;
}