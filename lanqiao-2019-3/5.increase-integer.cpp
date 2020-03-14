#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int ns99[] = {9, 9, 9, 9, 9, 9, 9};

// s(pre, [n, ns]) = sum $ fmap [pre..n] $ p => s(p, ns)
int increase(int perfix, int *max_num, int size) {
    if (size == 1) {
        if (max_num[0] >= perfix) {
            return max_num[0] - perfix + 1;
        } else {
            return 0;
        }
    }

    int count = 0;
    for (int p = perfix; p <= *max_num; ++p) {
        if (p == *max_num) {
            count += increase(p, max_num + 1, size - 1);
        } else {
            count += increase(p, ns99, size - 1);
        }
    }
    return count;
}

int main() {
    string input;
    cin >> input;

    int max[input.size()];
    for (int i = 0; i < input.size(); ++i) max[i] = input[i] - '0';

    cout << increase(0, max, input.size()) - 1 << endl;
    return 0;
}
