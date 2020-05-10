#include <iostream>
#include <cmath>
using namespace std;

// 1 10 100 1000 10000 100000
//
// (1 + n) * n / 2 = right]
// n^2 + n - 2r = 0
// n = (-1 +- sqrt(1^2 + 4 * 2r)) / 2

int main() {
    ios::sync_with_stdio(false);
    int size;
    cin >> size;
    double buf;
    while (size--) {
        cin >> buf;
        buf = (-1 + sqrt(1 + 4 * 2 * (buf - 1))) / 2;
        cout << (buf - (long long) buf == 0) << endl;
    }
    return 0;
}