#include <iostream>
#include <cmath>
#include <map>
using namespace std;

map<int, unsigned long long> cache;

unsigned long long seq(int last, int max) {
    int key = (last << 16) | max;
    if (cache[key] != 0) return cache[key];

    unsigned long long count = 1;

    for (int i = 1; i < max; ++i) {
        count += seq(i, abs(last - i));
    }

    count %= 10000;

    cache[key] = count;
    return count;
}

int main() {
    int i = 100;
    cin >> i;
    cout << seq(i, i) << endl;
    // for (int i = 1; i <= 1000; ++i) {
    //     cout << "case " << i << ": res=" << seq(i, i) << ";break;" << endl;
    // }
}