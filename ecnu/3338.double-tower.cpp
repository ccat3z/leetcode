// https://acm.ecnu.edu.cn/problem/3338/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int sumof(vector<int> &nums) {
    int s = 0;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        s += *it;
    }
    return s;
}

inline bool valid(int *nums, int size, int index) {
    if (index < 0) return false;
    if (index >= size) return false;
    return nums[index] >= 0;
}

int maxHeight(vector<int> &nums) {
    int maxResult = sumof(nums) / 2 + 1;
    // 1  <- {last,current}_heights[2] = 3
    // 2
    // 2  1
    int *last_heights = new int[maxResult];
    int *current_heights = new int[maxResult];

    fill(current_heights, current_heights + maxResult, -1);
    current_heights[0] = 0;
    current_heights[nums[0]] = nums[0];
    
    for_each(nums.begin() + 1, nums.end(), [&](int &num) {
        swap(last_heights, current_heights);
        for (int diff = 0; diff < maxResult; ++diff) {
            current_heights[diff] = -1;
            // 不放
            // .
            // . .
            // . .
            if (valid(last_heights, maxResult, diff))
                current_heights[diff] = last_heights[diff];
            // 放低塔上但没超过
            // .
            // . +
            // . .
            if (valid(last_heights, maxResult, diff + num))
                current_heights[diff] = max(current_heights[diff], last_heights[diff + num]);
            // 放低塔上并且超过了
            //   +
            // . +
            // . .
            if (valid(last_heights, maxResult, num - diff))
                current_heights[diff] = max(current_heights[diff], last_heights[num - diff] + diff);
            // 放高塔上
            // +
            // .
            // . .
            if (valid(last_heights, maxResult, diff - num))
                current_heights[diff] = max(current_heights[diff], last_heights[diff - num] + num);
        }
    });

    return current_heights[0];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << maxHeight(nums) << endl;
    return 0;
}