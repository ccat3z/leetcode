// https://leetcode.cn/contest/weekly-contest-309/problems/longest-nice-subarray/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    inline bool can_append(int & container, int & num) {
        return ((~num) & container) == container;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int container = nums[0];
        int first = 0;
        int max_size = 1;

        for (int i = 1; i < nums.size(); i++) {
            auto & num = nums[i];

            while (!can_append(container, num)) {
                container &= ~nums[first];
                first++;
            }
            container |= num;
            // cout << container << ":" << first << " -> " << i << endl;

            max_size = max(max_size, i - first + 1);
        }
        
        return max_size;
    }
};

int main() {
    vector<vector<int>> cases = {
        {1,3,8,48,10},
        {3,1,5,11,13},
        {744437702,379056602,145555074,392756761,560864007,934981918,113312475,1090,16384,33,217313281,117883195,978927664}
    };

    for (auto &nums : cases) {
        cout << Solution().longestNiceSubarray(nums) << endl;
    }

    return 0;
}