// https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/

#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int max_profit = 0;
        int max_profit_rnd = -2;
        int total_profit = 0;

        int pending = 0;

        int rnd = 0;
        for (;;) {
            if (rnd < customers.size()) {
                pending += customers[rnd];
            } else if (pending == 0) {
                break;
            }

            if (pending > 4) {
                total_profit += 4 * boardingCost;
                pending -= 4;
            } else {
                total_profit += pending * boardingCost;
                pending = 0;
            }

            total_profit -= runningCost;

            if (total_profit > max_profit) {
                max_profit_rnd = rnd;
                max_profit = total_profit;
            }

            ++rnd;
        }

        return max_profit_rnd + 1;
    }
};

int main() {
    vector<tuple<vector<int>, int, int, int>> tests = {
        {{8,3},5,6,3},
        {{10,9,6},6,4,7},
        {{3,4,0,5,1},1,92,-1},
        {{2},2,4,-1},
    };

    for (auto & [customers, boardingCost, runningCost, out] : tests) {
        cout << Solution().minOperationsMaxProfit(customers, boardingCost, runningCost) << " = " << out << endl;
    }
    return 0;
}