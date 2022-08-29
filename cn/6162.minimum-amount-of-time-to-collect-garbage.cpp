// https://leetcode.cn/contest/weekly-contest-308/problems/minimum-amount-of-time-to-collect-garbage/
#include <vector>
#include <string>
#include <iostream>
#include "prettyprint.h"
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time[3] = {0};
        int end[3] = {0};

        for (int i = 0; i < garbage.size(); i++) {
            auto &items = garbage[i];
            for (auto &item : items) {
                switch (item) {
                    case 'M': time[0]++; end[0] = i; break;
                    case 'G': time[1]++; end[1] = i; break;
                    case 'P': time[2]++; end[2] = i; break;
                }
            }
        }

        int cost_total = 0;
        for (auto &cost : travel) {
            cost = (cost_total += cost);
        }

        int res = 0;
        for (int i = 0; i < 3; i++) {
            res += time[i];
            if (end[i] != 0) {
                res += travel[end[i] - 1];
            }
        }
        return res;
    }
};

int main() {
    vector<string> garbage = {"MMM","PGM","GP"};
    vector<int> travel = {3,10};
    cout << Solution().garbageCollection(garbage, travel) << endl;
    return 0;
}