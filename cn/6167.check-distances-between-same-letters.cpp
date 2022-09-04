// https://leetcode.cn/contest/weekly-contest-309/problems/check-distances-between-same-letters/

#include <string>
#include <vector>
#include <iostream>
#include <array>
#include "prettyprint.h"
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        // array<bool, 26> vised;
        bool vised[26] = {};
        
        for (int i = 0; i < s.size(); i++) {
            char &c = s[i];
            int &dis = distance[c - 'a'];
            bool &vis = vised[c - 'a'];
            if (!vis) {
                dis += i + 1;
                vis = true;
            } else {
                if (dis != i) return false;
            }
        }

        // cout << distance << endl;

        return true;
    }
};

int main() {
    string s = "abaccb";
    vector<int> distance = {1,3,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << Solution().checkDistances(s, distance) << endl;
    return 0;
}