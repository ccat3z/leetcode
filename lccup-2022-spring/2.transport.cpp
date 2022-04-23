#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <queue>
#include "prettyprint.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> group;
    queue<tuple<int, int, int>> next_group;
    int size_x, size_y;
    int end_x, end_y;

    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        size_x = matrix.size();
        size_y = matrix[0].size();
        end_x = end[0];
        end_y = end[1];

        for (int i = 0; i < size_x; ++i) {
            group.emplace_back(size_y, numeric_limits<int>::max());
        }
        group[start[0]][start[1]] = 0;

        next_group.emplace(start[0], start[1], 0);

        while (!next_group.empty()) {
            auto [x, y, expect] = next_group.front(); next_group.pop();
            if (group[x][y] != expect) continue;
            // cout << x << ' ' << y << ' ' << expect << endl;
            if (mark_group(matrix, x, y)) {
                return group[end_x][end_y];
            }
            // for (int i = 0; i < size_x; ++i) {
            //     for (int j = 0; j < size_y; ++j) {
            //         cout << group[i][j] << ' ';
            //     }
            //     cout << endl;
            // }
        }

        return 0;
    }

    void fill_or_push(int x, int y, int fill_group, bool push) {
        // cout << '#' << x << ' ' << y << endl;
        if (0 <= x && x < size_x && 0 <= y && y < size_y) {
            if (group[x][y] < fill_group) return;

            group[x][y] = fill_group;
            if (push) {
                next_group.emplace(x, y, fill_group);
            }
        }
    }

    bool mark_group(vector<string> &matrix, int x, int y) {
        int cur_group = group[x][y];
        bool is_first = true;

        while (0 <= x && x < size_x && 0 <= y && y < size_y) {
            char &direct = matrix[x][y];

            if (is_first) {
                is_first = false;
            } else {
                // loop
                if (group[x][y] <= cur_group) {
                    break;
                }
                group[x][y] = cur_group;
            }

            if (x == end_x && y == end_y) {
                return true;
            }

            // cout << '!' << x << ' ' << y << endl;
            fill_or_push(x, y - 1, cur_group + 1, direct != '<');
            fill_or_push(x, y + 1, cur_group + 1, direct != '>');
            fill_or_push(x - 1, y, cur_group + 1, direct != '^');
            fill_or_push(x + 1, y, cur_group + 1, direct != 'v');

            switch (direct) {
                case '<': y--; break;
                case '>': y++; break;
                case '^': x--; break;
                case 'v': x++; break;
            }
        }
        return false;
    }
};

int main() {
    vector<tuple<vector<string>, int, int, int, int, int>> cases = {
        make_tuple(vector<string>{">>v","v^<","<><"}, 0, 1, 2, 0, 1),
        make_tuple(vector<string>{">^^>","<^v>","^v^<"}, 0, 0, 1, 3, 3),
        make_tuple(vector<string>{">>v",">>v","^<<"}, 0, 0, 1, 1, 0)
    };
    for (auto &[matrix, sx, sy, ex, ey, res] : cases) {
        vector<int> start = {sx, sy};
        vector<int> end = {ex, ey};
        cout << Solution().conveyorBelt(matrix, start, end)
             << " expect=" << res
             << " matrix=" << matrix
             << " start=" << start
             << " end=" << end
             << endl;
    }
    return 0;
}