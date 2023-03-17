// https://leetcode.cn/problems/count-subarrays-with-median-k/

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

void print_record(int *record) {
    cout << "[";
    for (int i = -5; i < 5; ++i) {
        cout << record[i] << ",";
    }
    cout << "]";
}

class Solution {
public:
    int countSubarrays(const vector<int>& nums, int k) {
        int record[nums.size() * 4];
        memset(record, 0, nums.size() * 4 * sizeof(int));

        int *odd_record = record + nums.size();
        int *even_record = record + 3 * nums.size();

        size_t pos = 0;
        for (; pos < nums.size() && nums[pos] != k; ++pos);
        if (pos == nums.size()) return 0;

        int cnt = 0;
        for (int i = pos; i >= 0; --i) {
            if (nums[i] < k) ++cnt;
            else if (nums[i] > k) --cnt;

            ++(i % 2 ? odd_record : even_record)[cnt];

            // print_record(odd_record);
            // print_record(even_record);
            // cout << endl;
        }

        cnt = 0;
        int res = 0;
        for (int i = pos; i < nums.size(); ++i) {
            if (nums[i] > k) ++cnt;
            else if (nums[i] < k) --cnt;

            res += (i % 2 ? even_record : odd_record)[cnt-1];
            res += (i % 2 ? odd_record : even_record)[cnt];
        }
        
        return res;
    }
};

int main() {
    cout << Solution().countSubarrays({3,2,1,4,5}, 4) << endl;
    cout << Solution().countSubarrays({2,3,1}, 3) << endl;
    return 0;
}