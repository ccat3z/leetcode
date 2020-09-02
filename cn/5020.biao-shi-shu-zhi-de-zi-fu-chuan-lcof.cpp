#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        auto it = s.begin();
        auto e = s.end();

        parseWhitespace(it, e);
        parseSign(it, e, '+', '-');
        int l = parseInt(it, e);
        if (parseSign(it, e, '.', '.')) {
            int j = parseInt(it, e);
            if (l == 0 && j == 0) return false;
            l += j + 1;
        }
        if (parseSign(it, e, 'e', 'E')) {
            if (l == 0) return false;
            parseSign(it, e, '+', '-');
            int j = parseInt(it, e);
            if (j == 0) return false;
            l += j + 1;
        }
        parseWhitespace(it, e);
        return it == e && l > 0;
    }
    bool parseSign(string::iterator &it, string::iterator &end, char a, char b) {
        if (it == end) return false;
        if (*it == a || *it == b) {
            it++;
            return true;
        }
        return false;
    }
    int parseInt(string::iterator &it, string::iterator &end) {
        int i = 0;
        while (it != end && ('0' <= *it && *it <= '9')) {
            ++i;
            it++;
        }
        return i;
    }
    void parseWhitespace(string::iterator &it, string::iterator &end) {
        while (it != end && *it == ' ') {
            it++;
        }
    }
};

int main() {
    vector<string> inputs = {
        "+100",
        "5e2",
        "-123",
        "3.1416",
        "-1E-16",
        "0123",
        "1",
        "1.",
        ".1",
        "  +.1 ",
        "0",
        "1.e2",
        "e1",
        "12e",
        "1a3.14",
        "1.2.3",
        "+-5",
        "12e+5.4",
        "1.2.3",
        "",
        ".",
    };
    for_each(inputs.begin(), inputs.end(), [&](string &i) {
        cout << Solution().isNumber(i) << ' ' << i << endl;
    });
    return 0;
}