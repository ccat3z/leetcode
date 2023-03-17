// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>&& nums, vector<int>&& queries) {
        return answerQueries(nums, queries);
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        auto it = nums.begin();
        for (++it; it != nums.end(); ++it)
            *it += *(it - 1);

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto & query : queries) {
            auto it = upper_bound(nums.begin(), nums.end(), query);
            ans.emplace_back(it - nums.begin());
        }

        return ans;
    }
};

ostream &operator<<(ostream &o, vector<int> vec) {
    o << "[";
    for (auto & e : vec) {
        o << e << ",";
    }
    o << "]";
    return o;
}

int main() {
    cout << Solution().answerQueries({4,5,2,1}, {3,10,21}) << endl;
    cout << Solution().answerQueries({2,3,4,5}, {1}) << endl;
    
    return 0;
}