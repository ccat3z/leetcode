// https://acm.ecnu.edu.cn/problem/3746/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define MOD (1000000007)
#define MAX_KEY_NUM (1000000)
typedef unsigned long num;

// i ^ n % p
num modpow(num i, num n) {
    if (n == 0) return 1;
    if (n == -1) n = MOD - 2;
    num res = modpow(i, n / 2);
    res = res * res % MOD;
    if (n % 2) {
        res = res * i % MOD;
    }
    return res;
}

num solution(int count, vector<int> &choice) {
    sort(choice.begin(), choice.end());
    num c = 1;
    int res = choice[count - 1] * c;
    for (int i = count; i < choice.size(); ++i) {
        c = c * i % MOD * modpow(i - count + 1, -1) % MOD;
        res = (res + choice[i] * c) % MOD;
    }
    return res;
}

int main() {
    int group;
    cin >> group;
    for (int g = 0; g < group; ++g) {
        int total, count;
        cin >> total >> count;
        vector<int> choice(total);
        for (int i = 0; i < total; ++i) {
            cin >> choice[i];
        }
        cout << solution(count, choice) << endl;
    }
}