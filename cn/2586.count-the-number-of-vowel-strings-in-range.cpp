// https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range

#include <vector>
#include <string>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int vowelStrings(const vector<string>& words, int left, int right) {
        int res = 0;
        
        for (int i = left; i <= right; ++i) {
            auto & word = words[i];
            if ((
                word.front() == 'a' ||
                word.front() == 'e' ||
                word.front() == 'i' ||
                word.front() == 'o' ||
                word.front() == 'u'
            ) && (
                word.back() == 'a' ||
                word.back() == 'e' ||
                word.back() == 'i' ||
                word.back() == 'o' ||
                word.back() == 'u'
            )) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    LC_D(Solution::vowelStrings);
    LC_T({"are","amy","u"}, 0, 2, 2);
    LC_T({"hey","aeo","mu","ooo","artro"}, 1, 4, 3);
    return 0;
}
