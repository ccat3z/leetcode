// TODO: https://acm.ecnu.edu.cn/problem/3340/

#include <stdio.h>
#include <numeric>
using namespace std;


// n = 3, m = 2
// 2 2
// 8 3
// 9 4

int mgcd_1(int **matrix, int n, int m) {
    int gcd_of[n][m][n][m];
    
    return 0;
}

int mgcd_2(int **matrix, int n, int m) {
    return 0;
}

int main() {
    int type, group;
    scanf("%d %d", &type, &group);

    for (int g = 0; g < group; ++g) {
        int n, m;
        scanf("%d", &n, &m);
        int *matrix[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf(
            "Case %d: %d",
            g + 1,
            type == 1 ? mgcd_1(matrix, n, m) : mgcd_2(matrix, n, m)
        );
    }
    return 0;
}