#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int (*nums)[3], int len) {
    int cost[3] = {0, 0, 0};
    int new_cost[3];

    for (int at = 1; at < len; ++at) {
        for (int x = 0; x < 3; ++x) new_cost[x] = 999999;

        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                new_cost[x] = min(new_cost[x], abs(nums[at][x] - nums[at - 1][y]) + cost[y]);
            }
        }

        for (int x = 0; x < 3; ++x) cost[x] = new_cost[x];
    }

    return min(min(cost[0], cost[1]), cost[3]);
}

int main() {
    int nums[][3] = {
        {5, 9, 5},
        {9, 7, 10},
        {5, 4, 9},
        {4, 10, 3},
        {4, 3, 3}
    };
    cout << solution(nums, 5) << endl;
}