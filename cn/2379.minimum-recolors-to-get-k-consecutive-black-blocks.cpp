#include <string>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;

        int w = 0;
        int min_w = 200;

        for (; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++w;
            }
        }
        min_w = w;

        for (; i < blocks.size(); ++i) {
            if (blocks[i-k] == 'W') {
                --w;
            }
            if (blocks[i] == 'W') {
                ++w;
            }
            min_w = min(w, min_w);
        }

        return min_w;
    }
};

int main() {
    vector<tuple<string, int, int>> tests = {
        {"WBBWWBBWBW", 7, 3},
        {"WBWBBBW", 2, 0},
    };

    for (auto & [blocks, k, out] : tests) {
        cout << Solution().minimumRecolors(blocks, k) << " = " << out << endl;
    }

    return 0;
}