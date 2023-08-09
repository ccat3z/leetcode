// https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

#include "leetcode_helper.h"
#include <cmath>

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n > 0) {
            int x = n % 10;
            product *= x;
            sum += x;

            n = n / 10;
        }

        return product - sum;
    }
};

int main() {
    LC_D(Solution::subtractProductAndSum);
    LC_T(234, 15);
    LC_T(4421, 21);
    LC_T(1, 0);
    LC_T(114, -2);
    return 0;
}