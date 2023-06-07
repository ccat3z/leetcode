// https://leetcode.cn/problems/mice-and-cheese/

#include <functional>
#include <iterator>
#include <vector>
#include <numeric>
#include <queue>
#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    int miceAndCheese(const vector<int>& reward1, const vector<int>& reward2, int k) {
        if (k == reward1.size()) {
            return std::accumulate(reward1.begin(), reward1.end(), 0);
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> give_to_1_cost;
        std::priority_queue<int, std::vector<int>, std::greater<int>> give_to_2_cost;

        int k_actual = 0;
        int sum = 0;
        for (size_t i = 0; i < reward1.size(); ++i) {
            if (reward1[i] > reward2[i]) {
                sum += reward1[i];
                k_actual += 1;
                give_to_2_cost.push(reward1[i] - reward2[i]);
            } else {
                sum += reward2[i];
                give_to_1_cost.push(reward2[i] - reward1[i]);
            }
        }

        if (k_actual > k) {
            k_actual -= k;
            while (k_actual-- > 0) {
                sum -= give_to_2_cost.top();
                give_to_2_cost.pop();
            }
        } else {
            k_actual = k - k_actual;
            while (k_actual-- > 0) {
                sum -= give_to_1_cost.top();
                give_to_1_cost.pop();
            }
        }

        return sum;
    }
};

int main() {
    LC_D(Solution::miceAndCheese);
    LC_T({1,1,3,4},{4,4,1,1},2,15);
    LC_T({1,1,3,4},{4,4,1,1},1,15);
    LC_T({1,1},{1,1},2,2);
    return 0;
}