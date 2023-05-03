// https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/

#include "leetcode_helper.h"
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 3 != 0) return false;

        vector<bool> stack;
        stack.reserve(s.size() / 3);
        for (auto & c: s) {
            switch (c) {
                case 'a':
                    stack.emplace_back(0);
                    break;
                case 'b':
                    if (stack.empty() || stack.back() != 0) return false;
                    stack.back() = 1;
                    break;
                case 'c':
                    if (stack.empty() || stack.back() != 1) return false;
                    stack.pop_back();
                    break;
            }
        }
        return stack.empty();
    }
};

int main() {
    LC_D(isValid);
    LC_T("aabcbc", true);
    LC_T("abcabcababcc", true);
    LC_T("abccba", false);
    LC_T("", true);
    LC_T("aabbcc", false);
    LC_T("bca", false);
    return 0;
}