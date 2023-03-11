// https://leetcode.cn/problems/find-longest-subarray-lcci/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> index;
        index[0] = 0;

        int max_len = 0;
        int a = 0;

        int sum = 0;
        for (int i = 0; i < array.size(); ++i) {
            sum += array[i].data()[0] < 'A' ? -1 : 1;

            auto it = index.find(sum);
            if (it != index.end()) {
                int len = i - it->second + 1;
                if (len > max_len) {
                    max_len = len;
                    a = it->second;
                }
            } else {
                index[sum] = i + 1;
            }
        }

        return vector<string>(array.begin() + a, array.begin() + a + max_len);
    }
};

ostream &operator<<(ostream &o, const vector<string> & v) {
    o << "[";
    for (const auto & s: v) {
        o << s << ",";
    }
    o << "]";
    return o;
}

int main() {
    vector<pair<vector<string>, vector<string>>> tests = {
        {{"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"}, {"A","1","B","C","D","2","3","4","E","5","F","G","6","7"}},
        {{"A", "A"}, {}},
        {{"A", "1"}, {"A", "1"}}
    };
    for (auto & [in, out] : tests) {
        cout << Solution().findLongestSubarray(in) << ", " << out << endl;
    }
    return 0;
}