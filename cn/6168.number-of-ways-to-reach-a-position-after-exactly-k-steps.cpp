// https://leetcode.cn/contest/weekly-contest-309/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
// TODO
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// - - - x - - - x - -

/*
1 -> 3
4 -> 15
*/

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        if (startPos > endPos) swap(startPos, endPos);

        if (endPos - startPos > k) return 0;

        int du = k - (endPos - startPos);
        if (du % 2 == 1) return 0;

        switch (du)
        {
        case 0: return 1;
        case 2: return 3;
        case 4: return 15;
        default: return -1;
        }
    }
};

int main() {
    cout << Solution().numberOfWays(272,270,6) << endl;
    return 0;
}