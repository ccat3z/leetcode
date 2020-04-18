#include <iostream>
#include <cmath>
#include <malloc.h>
#include <algorithm>
#include <iomanip>
using namespace std;

double min_cost(double **costs, int size) {
    bool visted[size];
    fill(visted, visted + size, false);
    visted[0] = true;

    double min_to[size];
    for (int i = 0; i < size; ++i) min_to[i] = costs[0][i];

    int last = 0;

    for (int i = 0; i < size; ++i) {
        int min_to_index = -1;
        for (int j = 0; j < size; ++j) {
            if (!visted[j]) {
                if (min_to_index == -1 || min_to[min_to_index] > min_to[j]) {
                    min_to_index = j;
                }
            }
        }
        visted[min_to_index] = true;
        if (min_to_index == -1) break;
        last = min_to_index;

        for (int j = 0; j < size; ++j) {
            if (!visted[j]) {
                if (min_to[min_to_index] + costs[min_to_index][j] < min_to[j]) {
                    min_to[j] = min_to[min_to_index] + costs[min_to_index][j];
                }
            }
        }
    }
    return min_to[last];
}

int main() {
    int size;
    cin >> size;
    int cor[size][3];
    double *cost[size];
    for (int i = 0; i < size; ++i) {
        int &x_1 = cor[i][0];
        int &y_1 = cor[i][1];
        int &h_1 = cor[i][2];

        cin >> x_1 >> y_1 >> h_1;

        cost[i] = (double *) malloc(size * sizeof(double));
        cost[i][i] = 0;
        for (int j = 0; j < i; ++j) {
            int &x_2 = cor[j][0];
            int &y_2 = cor[j][1];
            int &h_2 = cor[j][2];

            cost[j][i] = sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2))+(h_1-h_2)*(h_1-h_2);
            cost[i][j] = cost[j][i];
        }
    }
    cout << fixed << setprecision(2) << min_cost(cost, size) << endl;
    return 0;
}