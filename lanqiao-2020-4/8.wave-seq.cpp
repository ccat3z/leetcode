#include <iostream>
#include <map>
#include <malloc.h>
using namespace std;

int *increase_cache;
int *decrease_cache;

int _wave(int prefix, bool increase, int size, int max_num);
int wave(int prefix, bool increase, int size, int max_num) {
    int *cache = increase ? increase_cache : decrease_cache;
    int &v = cache[(size - 1) * max_num + prefix - 1];
    if (v == 0) {
        v = _wave(prefix, increase, size, max_num);
        return v;
    } else {
        return v;
    }
}

int _wave(int prefix, bool increase, int size, int max_num) {
    int count = 0;

    int from, to;

    if (increase) {
        from = prefix + 1;
        to = max_num + 1;
    } else {
        from = 1;
        to = prefix;
    }

    if (size == 1) {
        return to - from;
    }

    for (int i = from; i < to; ++i) {
        count += wave(i, !increase, size - 1, max_num);
    }

    return count % 10000;
}

int main() {
    int size, max_num;
    cin >> size >> max_num;
    increase_cache = (int*) malloc(max_num * size * sizeof(int));
    decrease_cache = (int*) malloc(max_num * size * sizeof(int));
    
    cout << wave(0, true, size, max_num) << endl;
}