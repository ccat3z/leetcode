#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int walkway(int total, vector<int> bad_stairs) {
    // d[i]: 走到第i阶时可行走法次数, i in [1,n]
    // d[i] = | i not bad = d[i - 3] + d[i - 2] + d[i - 1]
    //        | otherwise = 0
    int *d = new int[total + 3];
    d = d + 2;
    d[0] = 1; d[-1] = d[-2] = 0;

    sort(bad_stairs.begin(), bad_stairs.end());

    auto bad = bad_stairs.begin();
    for (int i = 1; i <= total; ++i) {
        if (bad != bad_stairs.end() && *bad == i) {
            ++bad;
            d[i] = 0;
            continue;
        }

        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    }
    return d[total];
}

int main() {
    int total, bad_size;
    cin >> total >> bad_size;
    vector<int> bad_stairs(bad_size);
    for (int i = 0; i < bad_size; ++i) {
        cin >> bad_stairs[i];
    }
    // return 0;
    cout << walkway(total, bad_stairs) << endl;
    return 0;
}