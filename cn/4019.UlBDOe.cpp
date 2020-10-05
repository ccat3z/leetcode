// https://leetcode-cn.com/problems/UlBDOe/

// rryyyyrrryyyrrr => 
// rrrrryyyyyyyrrr
//     a      b  n-1 
//
// N = len
// pre r i = count $ r in [0, i]
// pre y i = count $ y in [0, i]
// pre r i = (i + 1) - (pre y i)
// Y = pre y (N-1)
// changed a b = count $ y iN [0, a]     = (pre y a)
//             + count $ r iN [a+1, b]   = (pre r b) - (pre r a) = (b+1) - (pre y b) - (a+1) + (pre y a)
//             + count $ y iN [b+1, N-1] = (pre y (N-1)) - (pre y b) = Y - (pre y b)
//             = (2(pre y a) - a) - (2(pre y b) - b) + Y
//             = G(a) - G(b) + Y
//             = G(a) - G(b) + ((G(N-1) + (N-1))/2)
// G x = 2 * (pre y x) - x
// G x = G (x-1) + (2 * isYellow x) - 1
//     = G (x-1) + isYellow x ? 1 : -1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int i = 0;
        int Gi = leaves[i] == 'y' ? 2 : 0;
        int minGBeforeI = Gi;
        int maxDiffOfGbGa = -100;
        for (i = 1; i < leaves.size() - 1; ++i) {
            Gi += leaves[i] == 'y' ? 1 : -1;
            maxDiffOfGbGa = max(Gi - minGBeforeI, maxDiffOfGbGa);
            minGBeforeI = min(Gi, minGBeforeI);
        }
        Gi += leaves[i] == 'y' ? 1 : -1;
        return (Gi + leaves.size() - 1) / 2 - maxDiffOfGbGa;
    }
};

int main() {
    vector<string> inputs = {
        "rrryyyrryyyrr",
        "ryr",
        "yry",
    };
    for (auto s : inputs) {
        cout << Solution().minimumOperations(s) << endl;
    }
}