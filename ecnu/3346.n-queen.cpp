#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int queens[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> queens[i][0] >> queens[i][1];
    }
    int row[n];
    int col[n];
    int lt_rb[2 * n - 1];
    int rt_lb[2 * n - 1];
    fill(row, row + n, 0);
    fill(col, col + n, 0);
    fill(lt_rb, lt_rb + 2 * n - 1, 0);
    fill(rt_lb, rt_lb + 2 * n - 1, 0);

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int &x = queens[i][0];
        int &y = queens[i][1];
        count += row[x - 1]++;
        count += col[y - 1]++;
        count += lt_rb[x - y + n - 1]++;
        count += rt_lb[x + y - 2]++;
    }
    cout << count << endl;
    return 0;
}