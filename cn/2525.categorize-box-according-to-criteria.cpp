#include <cstdint>
#include <string>
#include "leetcode_helper.h"

using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        uint8_t flag = 0;

        if (length >= 10'000 || width >= 10'000 || height >= 10'000) {
            flag |= 1;
        } else if ((uint64_t) length * width * height >= 1'000'000'000) {
            flag |= 1;
        }

        if (mass >= 100) {
            flag |= 2;
        }

        switch (flag) {
            case 0:
                return "Neither";
            case 1:
                return "Bulky";
            case 2:
                return "Heavy";
            case 3:
                return "Both";
            default:
                return "Unreachable";
        }
    }
};

int main() {
    LC_D(Solution::categorizeBox);
    LC_T(1000, 35, 700, 300, "Heavy");
    LC_T(200, 50, 800, 50, "Neither");
    return 0;
}