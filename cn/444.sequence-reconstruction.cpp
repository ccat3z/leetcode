// https://leetcode.cn/problems/ur2n8P/
#include <vector>
#include <iostream>
#include <tuple>
#include <queue>
#include "prettyprint.h"
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        vector<int> inbounds(nums.size() + 1);
        vector<vector<int>> outbounds(nums.size() + 1);

        for (auto & seq : sequences) {
            for (int i = 0; i < seq.size() - 1; i++) {
                int &a = seq[i], &b = seq[i+1];
                inbounds[b]++;
                outbounds[a].emplace_back(b);
            }
        }
        // cout << inbounds << endl;

        int zero_inbound = -1;
        for (int i = 1; i < inbounds.size(); i++) {
            if (inbounds[i] == 0) {
                if (zero_inbound != -1) {
                    // cout << "!!" << i << ' ' << zero_inbound << endl;
                    return false;
                }

                zero_inbound = i;
            }
        }

        for (int i = 0; i < nums.size() && nums[i] == zero_inbound; i++) {
            for (int &next : outbounds[nums[i]]) {
                if (--inbounds[next] == 0) {
                    if (zero_inbound != nums[i]) {
                        // cout << "!!-" << endl;
                        return false;
                    }

                    zero_inbound = next;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<tuple<vector<int>, vector<vector<int>>, bool>> tests = {
        {
            {1,2,3},
            {{1,2},{1,3},{2,3}},
            true
        },
        {
            {1,2,3},
            {{1,2}},
            false
        }  
    };

    for (auto &[nums, sequences, res] : tests) {
        cout << Solution().sequenceReconstruction(nums, sequences) << '=' << res << endl;
    }
    return 0;
}