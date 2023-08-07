#include <type_traits>
#include <vector>
#include "leetcode_helper.h"

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }

    std::vector<char> _(const std::vector<char>& s) {
        auto s1 = s;
        reverseString(s1);
        return s1;
    }
};

int main() {
    LC_D(Solution::_);
    LC_T({'h','e','l','l','o'}, {'o','l','l','e','h'});
    LC_T({'h'}, {'h'});
    LC_T({}, {});
    LC_T({'a', 'b'}, {'b', 'a'});
    return 0;
}
