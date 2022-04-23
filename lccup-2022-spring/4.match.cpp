#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <bitset>
#include "prettyprint.h"
using namespace std;

// TODO
class Solution {
public:
    int size;
    bool composeCube(vector<vector<string>>& shapes) {
        size = shapes[0].size();

        for (auto &shape : shapes) {
            // emptry center
            for (int i = 1; i < size - 1; ++i) {
                for (int j = 1; j < size - 1; ++j) {
                    if (!getFlag(shape, 0, i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;

        for (int r = 0; r < 8; ++r) {
            if (dfs(shapes, 0, r, bitset<6>(0))) {
                return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<string>> &shapes, int shape_idx, int rotate, bitset<6> used) {
        return false;
    }

    bool getFlag(vector<string> &shape, int rotate, int x, int y) {
        int rx, ry;
        switch (rotate) {
            case 0: rx = x; ry = y; break;
            case 1: ry = x; rx = y; break;
            case 2: rx = y; ry = size - x - 1; break;
            case 3: ry = y; rx = size - x - 1; break;
            case 4: rx = size - x - 1; ry = size - y - 1; break;
            case 5: ry = size - x - 1; rx = size - y - 1; break;
            case 6: rx = size - y - 1; ry = x; break;
            case 7: ry = size - y - 1; rx = x; break;
        }
        return shape[rx][ry] == '1';
    }
};

int main() {
    vector<tuple<vector<vector<string>>, bool>> cases = {
        make_tuple(vector<vector<string>>{
            {{"000","110","000"},{"110","011","000"},{"110","011","110"},{"000","010","111"},{"011","111","011"},{"011","010","000"}}
        }, true),
        make_tuple(vector<vector<string>>{
            {{"101","111","000"},{"000","010","111"},{"010","011","000"},{"010","111","010"},{"101","111","010"},{"000","010","011"}}
        }, false)
    };
    for (auto &[shapes, res] : cases) {
        cout << Solution().composeCube(shapes) << '=' << res << ' ' << shapes << endl;
    }
    return 0;
}