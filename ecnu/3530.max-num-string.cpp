#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int size; cin >> size;
    string ss[size];

    for (int i = 0; i < size; ++i) {
        cin >> ss[i];
    }

    sort(&ss[0], &ss[size], [](const string &a, const string &b) {
        int size_a = a.size();
        int size_b = b.size();
        int s = max(size_a, size_b);
        for (int i = 0; i < s; ++i) {
            if (a[i % size_a] != b[i % size_b]) {
                return a[i % size_a] > b[i % size_b];
            }
        }
        return true;
    });

    for (int i = 0; i < size; ++i) {
        cout << ss[i];
    }
    cout << endl;
    return 0;
}