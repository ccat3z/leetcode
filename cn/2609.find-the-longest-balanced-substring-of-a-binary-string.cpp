// https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string
#include <algorithm>
#include <string>

#include "leetcode_helper.h"

class Solution {
public:
    int findTheLongestBalancedSubstring(std::string s) {
        int pos = 0;
        int res = 0;

        while (pos < s.size()) {
            int len0 = 0, len1 = 0;

            while (pos < s.size() && s[pos] == '0') {
                ++len0;
                ++pos;
            }

            while (pos < s.size() && s[pos] == '1') {
                ++len1;
                ++pos;
            }

            res = std::max(std::min(len0, len1)*2, res);
        }

        return res;
    }
};

int main() {
    LC_D(Solution::findTheLongestBalancedSubstring);
    LC_T("01000111", 6);
    LC_T("00111", 4);
    LC_T("111", 0);
    LC_T("001", 2);
    return 0;
}