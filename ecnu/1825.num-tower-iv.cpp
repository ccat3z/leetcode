#include <iostream>
#include <algorithm>
using namespace std;

int *last_level = new int[100];
int *current_level = new int[100];

int possible(int last_map, int num) {
    int result = 0;
    for (int i = 0; i < 10; ++i) {
        if (last_map & 1<<i) {
            result |= 1<<(num * i % 10);
        }
    }
    return result;
}

int main() {
    int group;
    cin >> group;
    for (int g = 0; g < group; ++g) {
        int level;
        cin >> level;

        int num; cin >> num;
        current_level[0] = possible(1<<1, num);
        for (int c = 2; c <= level; ++c) {
            swap(last_level, current_level);

            for (int i = 0; i < c; ++i) {
                int num; cin >> num;
                current_level[i] = 0;
                if (i - 1 >= 0) {
                    current_level[i] |= possible(last_level[i - 1], num);
                }
                if (i <= c - 2) {
                    current_level[i] |= possible(last_level[i], num);
                }
            }
        }

        for (int i = 0; i < level; ++i) {
            int &l = current_level[i];
            for (int i = 9; i >= 0; --i) {
                if (l & 1<<i) {
                    l = i;
                    break;
                }
            }
        }
        cout << *max_element(&current_level[0], &current_level[level]) << endl;
    }
}