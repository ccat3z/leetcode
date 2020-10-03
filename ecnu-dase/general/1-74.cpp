#include <stdio.h>
using namespace std;

int main() {
    int year, time;
    scanf("%d %d", &year, &time);
    int base = year >= 5 ? 50 : 30;
    float res = time * base;
    res += (time <= 40 ? 0 : time - 40) * 0.5 * base;
    printf("%.2f\n", res);
    return 0;
}