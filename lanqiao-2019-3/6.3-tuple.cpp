#include <iostream>
#include <vector>
#include <map>
using namespace std;

int increase_tuple(vector<int> &nums) {
    int count = 0;
    int increased = 1;
    map<int, int> num_index;
    map<int, bool> num_second_min;

    throw "not implement";
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; ++i) cin >> nums[i];

    cout << increase_tuple(nums) << endl;
}