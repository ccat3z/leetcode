#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string &a, string &b) {
    int longest = 0;
    // a: ...abaaa...
    //   1      ^ 10
    // b: ...cdaaa...
    //   1      ^ 20
    // common_le[10][20] = 2
    // common_le[xa][xb] = | a[xa] == b[xb] = common_le[xa - 1][xb - 1] + 1
    //                     | otherwise      = 0
    int len_a = a.size(), len_b = b.size();
    int *common_le[2];
    common_le[0] = new int[len_b + 1];
    common_le[1] = new int[len_b + 1];
    fill(&common_le[0][0], &common_le[0][len_b + 1], 0);

    for (int xa = 1; xa <= len_a; ++xa) {
        for (int xb = 1; xb <= xa && xb <= len_b; ++xb) {
            int &cl = common_le[1][xb];
            if (a[xa - 1] == b[xb - 1]) {
                cl = common_le[0][xb - 1] + 1;
            } else {
                cl = 0;
            }
            // cout << xa << ' ' << xb << ' ' << cl << endl;
            longest = max(cl, longest);
        }
        swap(common_le[0], common_le[1]);
    }
    return longest;
}

int main() {
    string a, b;
    cin >> a >> b;
    int res = lcs(a, b);
    cout << res << endl;
    return 0;
}