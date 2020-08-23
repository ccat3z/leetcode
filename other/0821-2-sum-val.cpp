#include <iostream>
#include <algorithm>
using namespace std;

int f(int t) {
    int as = t / 10;
    int a = t % 10;
    if (as == 0) return a;
    return max(f(as) + a, f(as - 1) + a + 10);
}

int main() {
    cout << f(35) << endl;
}