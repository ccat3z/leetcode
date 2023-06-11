// TODO: https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares/

#include "leetcode_helper.h"

class Solution {
public:
    int tilingRectangle(int n, int m) {
        int res = 0;
        while (n != 0 && m != 0) {
            if (n > m) n -= m;
            else m -= n;
            ++res;
        }
        return res;
    }
};

int main() {
    LC_D(Solution::tilingRectangle);
    LC_T(2, 3, 3);
    LC_T(5, 8, 5);
    LC_T(11, 13, 6);
    return 0;
}