#include <vector>
#include <string>

#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    vector<string> cache[8];
    vector<string> res;

    const vector<string> &gen(int n) {
        if (cache[n].size() > 0) {
            return cache[n];
        }

        if (n == 0) {
            cache[0].emplace_back("");
        } if (n == 1) {
            cache[1].emplace_back("()");
        } else {
            string buf;
            buf.resize(n * 2);
            // buf.assign(n * 2, '.');
            
            for (int inner = 0; inner < n; ++inner) {
                buf[0] = '(';
                buf[inner * 2 + 1] = ')';
                for (auto & seg_inner : gen(inner)) {
                    buf.replace(1, seg_inner.size(), seg_inner);
                    for (auto & seg_outter : gen(n - inner - 1)) {
                        buf.replace(inner * 2 + 2, seg_outter.size(), seg_outter);
                        cache[n].emplace_back(buf);
                    }
                }
            }
        }
        return cache[n];
    }

    vector<string> generateParenthesis(int n) {
        return gen(n);
    }
};

int main() {
    LC_D(Solution::generateParenthesis);
    LC_T(3, {"((()))","(()())","(())()","()(())","()()()"});
    LC_T(2, {"()()", "(())"});
    LC_T(1, {"()"});
    // LC_T(2, {});
    // LC_T(3, {});
    // LC_T(4, {});
    // LC_T(5, {});
    // LC_T(6, {});
    // LC_T(7, {});
    // LC_T(8, {});
    return 0;
}
