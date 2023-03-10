// TODO: https://leetcode.cn/problems/make-sum-divisible-by-p/solution/shi-shu-zu-he-neng-bei-p-zheng-chu-by-le-dob9/

#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <numeric>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total_acc = 0;
        for (auto & n : nums) {
            total_acc = (total_acc + n) % p;
        }
        if (total_acc == 0) return 0;

        unordered_map<int, int> mod_min_del;

        // sum [0..i] % p
        int left_acc = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            mod_min_del[left_acc] = i;
            left_acc = (left_acc + nums[i]) % p;
            int require_acc = (left_acc - total_acc + p) % p;

            auto it = mod_min_del.find(require_acc);
            if (it != mod_min_del.end()) {
                ans = min(ans, i - it->second + 1);
            }
        }

        return ans == nums.size() ? -1 : ans;
    }
};

int main() {
    vector<tuple<vector<int>, int, int>> tests = {
        {{3,1,4,2},6,1},
        {{6,3,5,2},9,2},
        {{1,2,3},3,0},
        {{1,2,3},7,-1},
    };

    for (auto & [nums, p, out] : tests) {
        cout << Solution().minSubarray(nums, p) << ", " << out << endl;
    }
    return 0;
}