#include <string>
#include <vector>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int countSeniors(const vector<string>& details) {
        int res = 0;
        for (auto & detail : details) {
            if (detail[11] > '6' || (detail[11] == '6' && detail[12] > '0')) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    LC_D(Solution::countSeniors);
    LC_T({"7868190130M7522","5303914400F9211","9273338290F4010"}, 2);
    LC_T({"1313579440F2036","2921522980M5644"}, 0);

    return 0;
}