#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string loop_block(int a, int b) {
    vector<char> nums;
    int appear_at[b]; fill(appear_at, appear_at + b, -1);

    appear_at[a % b] = 0;
    a = (a % b) * 10;
    for (int i = 1;; ++i) {
        // cout << a << '%' << b << endl;
        int r = a % b;
        nums.push_back(a / b + '0');
        
        if (appear_at[r] != -1) {
            return string(nums.begin() + appear_at[r], nums.end());
        }

        appear_at[r] = i;
        a = r * 10;
    }

    return "0";
}

int main() {
    int a, b;
    while (!cin.eof()) {
        if (!(cin >> a)) return 0;
        cin.ignore(1);
        if (!(cin >> b)) return 0;
        cout << loop_block(a, b) << endl;
    }
    return 0;
}