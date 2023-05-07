// https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include "leetcode_helper.h"
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(const vector<int>& time) {
        int div[60] = {0};
        int res = 0;

        for (size_t i = 0; i < time.size(); ++i) {
            int mod = time[i] % 60;
            res += div[(60 - mod) % 60];
            ++div[mod];
        }

        return res;
    }
};

int main() {
    LC_D(numPairsDivisibleBy60);
    LC_T({30,20,150,100,40}, 3);
    LC_T({60,60,60}, 3);

    return 0;
}