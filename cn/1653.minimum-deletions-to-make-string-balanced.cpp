// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(const string & s) {
        int right_a = 0;
        int left_b = 0;
        for (auto & c : s)
            right_a += c == 'a';

        int min_del = left_b + right_a;

        for (auto & c : s) {
            if (c == 'a') {
                --right_a;
            } else {
                ++left_b;
            }

            min_del = min(min_del, left_b + right_a);
        }
        return min_del;
    }
};

int main() {
    vector<pair<string, int>> tests = {
        {"aababbab", 2},
        {"bbaaaaabb", 2},
    };

    for (auto & [s, out] : tests) {
        cout << Solution().minimumDeletions(s) << " = " << out << endl;
    }
    return 0;
}