// https://leetcode.cn/problems/split-two-strings-to-make-palindrome/

#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        if (a.size() <= 1) return true;

        int prefix_size[2] = { calc_prefix_size(a), calc_prefix_size(b) };
        if (prefix_size[0] < prefix_size[1]) swap(prefix_size[0], prefix_size[1]);
        
        int i;
        for (i = 0; i < prefix_size[0] && a[i] == b[b.size() - i - 1]; ++i) {
            if (i == prefix_size[1] - 1) return true;
        }
        if (i == prefix_size[0]) return true;

        for (i = 0; i < prefix_size[0] && b[i] == a[a.size() - i - 1]; ++i) {
            if (i == prefix_size[1] - 1) return true;
        }
        return i == prefix_size[0];
    }

    int calc_prefix_size(const string &a) {
        int pre_idx = a.size() / 2 - 1;
        int suf_idx = a.size() - pre_idx - 1;

        while (pre_idx >= 0 && a[pre_idx] == a[suf_idx]) {
            --pre_idx;
            ++suf_idx;
        }

        return pre_idx + 1;
    }
};

int main() {
    vector<tuple<string, string, bool>> tests = {
        {"x", "y", true},
        {"abdef", "fecab", true},
        {"ulacfd", "jizalu", true},
        {"abdee", "fecab", false},
        {
            "pvhmupgqeltozftlmfjjde",
            "yjgpzbezspnnpszebzmhvp",
            true
        },
    };

    for (auto & [a, b, res] : tests) {
        cout << Solution().checkPalindromeFormation(a, b) << " = " << res << endl;
    }

    return 0;
}