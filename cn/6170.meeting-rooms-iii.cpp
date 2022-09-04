// https://leetcode.cn/contest/weekly-contest-309/problems/meeting-rooms-iii/
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include "prettyprint.h"

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<unsigned int> free_time(n, 0);
        vector<unsigned int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());

        for (auto &meeting : meetings) {
            int begin = meeting[0];
            int end = meeting[1];

            int room = 0;
            for (; room < n && !(free_time[room] <= begin); room++);

            if (room == n) {
                room = min_element(free_time.begin(), free_time.end()) - free_time.begin();
                free_time[room] = end + (free_time[room] - begin);
            } else {
                free_time[room] = end;
            }

            cnt[room] += 1;
            // cout << free_time << cnt << endl;
        }

        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};

int main() {
    vector<tuple<
        int,
        vector<vector<int>>,
        int
    >> cases = {
        {
            2,
            {{0,10},{1,5},{2,7},{3,4}},
            0
        },
        {
            3,
            {{1,20},{2,10},{3,5},{4,9},{6,8}},
            1
        }
    };

    for (auto &[n, meetings, res] : cases) {
        cout << "# " << n << ", " << meetings << endl;
        cout << Solution().mostBooked(n, meetings) << " == " << res << endl;
    }
    return 0;
}