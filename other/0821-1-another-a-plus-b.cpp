#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// a * 200 + b * 10 + c * 10 + c * 2 = n
vector<tuple<int, int>> solve(int n) {
    vector<tuple<int, int>> res;
    for (int a = 1; a < 10; ++a) {
        for (int c = 0; c < 10; ++c) {
            for (int b = 0; b < 10; ++b) {
                if (b == c) continue;
                int i1 = a*100 + b*10 + c;
                int i2 = a*100 + c*10 + c;
                if (i1 + i2 == n) {
                    res.push_back(make_tuple(i1, i2));
                }
            }
        }
    }
    return res;
}

int main() {
    for (int i = 1068; i <= 2000; ++i) {
        auto res = solve(i);
        if (res.size() > 0) {
            cout << i << ": " << res.size() << endl;
            for (auto it = res.begin(); it != res.end(); ++it) {
                cout << get<0>(*it) << ' ' << get<1>(*it) << endl;
            }
        }
    }
}