// https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>&& rowSum, vector<int>&& colSum) {
        return restoreMatrix(rowSum, colSum);
    }

    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> res;
        res.reserve(rowSum.size());
        for (int i = 0; i < rowSum.size(); ++i) {
            res.emplace_back();
            res.back().resize(colSum.size());

            for (int j = 0; j < colSum.size(); ++j) {
                auto & cell = res[i][j];
                cell = min(rowSum[i], colSum[j]);
                rowSum[i] -= cell;
                colSum[j] -= cell;
            }
        }

        return res;
    }
};

template <typename T>
ostream &operator<<(ostream &o, vector<T> vec) {
    cout << "[";
    for (auto & e : vec) {
        cout << e << ",";
    }
    cout << "]";

    return o;
}

int main() {
    cout << Solution().restoreMatrix({3,8}, {4,7}) << endl;
    cout << Solution().restoreMatrix({5,7,10}, {8,6,8}) << endl;
    cout << Solution().restoreMatrix({14,9}, {6,9,8}) << endl;

    return 0;
}