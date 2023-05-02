// https://leetcode.cn/problems/powerful-integers/

#include "leetcode_helper.h"
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> set;

        int result;
        int v[2] = {1, 1};
        for (int i = 0; v[0] < bound ; i++) {
            v[1] = 1;
            for (int j = 0; ; j++) {
                result = v[0] + v[1];
                if (result > bound) break;
                set.emplace(result);

                if (y == 1) break;
                v[1] *= y;
            }

            if (x == 1) break;
            v[0] *= x;
        }

        return vector<int>(set.begin(), set.end());
    }
};

int main() {
    auto t = leetcode::make_tester(&Solution::powerfulIntegers);
    t({2, 1, 10, {2,3,5,9}});
    t({2, 3, 10, {2,3,4,5,7,9,10}});
    t({3, 5, 15, {2,4,6,8,10,14}});
    return 0;
}