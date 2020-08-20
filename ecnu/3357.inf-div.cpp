#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

// 0 1  2   3           k
// 0 1 1+d 1+2d ... 1+(k-1)*d
int main() {
    int d, k;
    cin >> d >> k;

    k = min(100 - d, k);
    double result = 0;
    for (int i = k - 1; i >= 0; --i) {
        result = 1 + i * d + (result > 0 ? (1 / result) : 0);
        // printf("%.12lf\n", 1 / result);
    }
    result = 1 / result;
    printf("%.12lf\n", result);
}