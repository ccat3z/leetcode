#include <iostream>
#include <array>
#include <map>
#include <vector>
using namespace std;

class Solution {
    public:
        array<int, 2> coins(vector<int>& values, int target) {
            map<int, int> max_coins_num = {{0, 0}};
            map<int, int> min_coins_num = {{0, 0}};
            vector<int>::iterator value_it;

            for (int small_target = 1; small_target <= target; small_target++) {
                int &_max = max_coins_num[small_target] = -1, &_min = min_coins_num[small_target] = -1;
                for (value_it = values.begin(); value_it != values.end(); value_it++) {
                    if (*value_it > small_target) continue; // too much

                    int max_need = max_coins_num[small_target - *value_it] + 1;
                    int min_need = min_coins_num[small_target - *value_it] + 1;
                    _max = _max == -1 ? max_need : max(max_need, _max);
                    _min = _min == -1 ? min_need : min(min_need, _min);
                }
            }

            return array<int, 2>({max_coins_num[target], min_coins_num[target]});
        }
};

int main() {
    vector<int> values = {3, 5, 10, 20, 100};
    auto res = Solution().coins(values, 500);

    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}