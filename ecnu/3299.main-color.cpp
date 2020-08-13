// https://acm.ecnu.edu.cn/problem/3299/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void colors(int *nums, int length, int *color_count) {
    for (int i = 0; i < length; ++i) {
        color_count[i] = 0;
    }
    
    int color_count_from_i[length];
    for (int i = 0; i < length; ++i) {
        for (int a = 0; a < length; ++a) {
            color_count_from_i[a] = 0;
        }
        int max_color_i_to_j = 0;
        for (int j = i; j < length; ++j) {
            int color_at_j = nums[j] - 1;
            color_count_from_i[color_at_j] += 1;
            if (color_count_from_i[color_at_j] > color_count_from_i[max_color_i_to_j]) {
                max_color_i_to_j = color_at_j;
            } else if (color_count_from_i[color_at_j] == color_count_from_i[max_color_i_to_j]) {
                if (color_at_j < max_color_i_to_j) {
                    max_color_i_to_j = color_at_j;
                }
            }
            // cout << i << '-' << j << ':' << max_color_i_to_j + 1 << endl;
            color_count[max_color_i_to_j] += 1;
        }
    }
}

int main() {
    int count;
    int nums[5000];
    int color[5000];
    while (cin >> count) {
        for (int i = 0; i < count; ++i) {
            cin >> nums[i];
        }
        colors(nums, count, color);
        cout << color[0];
        for (int i = 1; i < count; ++i) {
            cout << ' ' << color[i];
        }
        cout << endl;
    }
}