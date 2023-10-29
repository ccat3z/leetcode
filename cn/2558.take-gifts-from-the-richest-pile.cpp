// https://leetcode.cn/problems/take-gifts-from-the-richest-pile

#include <cmath>
#include <vector>
#include <queue>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    long long pickGifts(const vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());

        while (k--) {
            auto g = q.top();
            q.pop();
            q.push((int) std::sqrt(g));
        }

        long long res = 0;
        while (!q.empty()) {
            res += q.top();
            q.pop();
        }

        return res;
    }
};

int main() {
    LC_D(Solution::pickGifts);
    LC_T({25,64,9,4,100}, 4, 29);
    LC_T({1,1,1,1}, 4, 4);
    return 0;
}