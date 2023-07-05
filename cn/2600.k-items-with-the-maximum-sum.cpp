#include "leetcode_helper.h"

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) {
            return k;
        } else if (k <= numOnes + numZeros) {
            return numOnes;
        } else {
            return numOnes - (k - numOnes - numZeros);
        }
    }
};

int main() {
    LC_D(Solution::kItemsWithMaximumSum);
    LC_T(3, 2, 0, 2, 2);
    LC_T(3, 2, 0, 4, 3);
    LC_T(6, 6, 6, 13, 5);
    return 0;
}