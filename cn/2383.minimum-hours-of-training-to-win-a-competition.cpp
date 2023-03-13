// https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, const vector<int>& energy, const vector<int>& experience) {
        int eng = initialEnergy;
        for (int i = 0; i < energy.size(); ++i) {
            eng -= energy[i];
        }

        int exp = initialExperience;
        int min_exp = initialExperience;
        for (int i = 0; i < energy.size(); ++i) {
            if (exp <= experience[i]) {
                min_exp = min(min_exp, exp - experience[i]);
            }
            exp += experience[i];
        }

        return - min(eng, 0) - min(min_exp, 0) + (eng <= 0) + (min_exp <= 0);
    }
};

int main() {
    cout << Solution().minNumberOfHours(5, 3, vector<int>{1,4,3,2}, vector<int>{2,6,3,1}) << endl;
    cout << Solution().minNumberOfHours(2, 4, vector<int>{1}, vector<int>{3}) << endl;
    return 0;
}