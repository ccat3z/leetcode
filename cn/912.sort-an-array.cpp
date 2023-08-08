#include <tuple>
#include <utility>
#include <vector>
#include "leetcode_helper.h"

using namespace std;
using namespace leetcode;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        if (!nums.empty()) sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return;

        std::swap(nums[rand() % (end - begin + 1) + begin], nums[end]);
        int lt = begin;
        int gt = end-1;
        for (int i = begin; i <= gt;) {
            if (nums[i] < nums[end]) {
                std::swap(nums[lt++], nums[i++]);
            } else if (nums[i] > nums[end]) {
                std::swap(nums[gt--], nums[i]);
            } else {
                ++i;
            }
        }
        // std::cerr << nums << ' ' << begin << ' ' << lt-1 << ' ' << gt+1 << ' ' << end << std::endl;
        std::swap(nums[gt+1], nums[end]);
        sort(nums, begin, lt-1);
        sort(nums, gt+1, end);
    }

    vector<int> _(const vector<int>& nums) {
        auto n = nums;
        return sortArray(n);
    }
};

int main() {
    LC_D(Solution::_);
    LC_T({5,2,3,1}, {1,2,3,5});
    LC_T({2,5,3,1}, {1,2,3,5});
    LC_T({}, {});
    LC_T({1}, {1});
    LC_T({2,3,1}, {1,2,3});
    LC_T({5,1,1,2,0,0},{0,0,1,1,2,5});
    LC_T({1,1,1},{1,1,1});
    return 0;
}
