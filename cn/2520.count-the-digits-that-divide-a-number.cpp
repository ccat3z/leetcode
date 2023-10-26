#include "leetcode_helper.h"

class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int res = 0;
        while (n > 0) {
            int t = n % 10;
            if (num % t == 0) ++res;
            n /= 10;
        }
        return res;
    }
};

int main() {
    LC_D(Solution::countDigits);
    LC_T(7, 1);
    LC_T(121, 2);
    LC_T(1248, 4);
    return 0;
}