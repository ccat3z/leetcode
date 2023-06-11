// https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/

#include "leetcode_helper.h"
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int f(const string& s) {
        char min_c = 'z' + 1;
        int res = 0;

        for (const auto & c : s) {
            if (c < min_c) {
                min_c = c;
                res = 0;
            } else if (c > min_c) {
                continue;
            }

            ++res;
        }

        return res;
    }

    vector<int> numSmallerByFrequency(const vector<string>& queries, const vector<string>& words) {
        vector<int> ans;

        vector<int> w;
        for (auto &word : words) {
            w.emplace_back(f(word));
        }
        std::sort(w.begin(), w.end());

        for (auto &query : queries) {
            auto it = std::upper_bound(w.begin(), w.end(), f(query));
            if (it == w.end()) ans.emplace_back(0);
            else ans.emplace_back(w.size() - (it - w.begin()));
        }

        return ans;
    }
};

int main() {
    LC_D(Solution::numSmallerByFrequency);
    LC_T({"cbd"}, {"zaaaz"}, {1});
    LC_T({"bbb","cc"}, {"a","aa","aaa","aaaa"}, {1,2});

    return 0;

}