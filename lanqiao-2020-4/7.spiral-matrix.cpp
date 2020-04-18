#include <iostream>
using namespace std;

int value_of(int width, int height, int tx, int ty) {
    int x = 0, y = 1;
    int max = width * height;
    int dir = 0;
    int num = 0;

    int old_x, old_y, diff;
    for (int step = 0;; ++step) {
        old_x = x; old_y = y;
        switch (dir) {
        case 0:
            if (y == ty && x < tx) return num + tx - x;

            diff = width - (step / 2);
            x += diff;
            break;
        case 1:
            if (x == tx && y < ty) return num + ty - y;

            diff = height - (step / 2) - 1;
            y += diff;
            break;
        case 2:
            if (y == ty && tx < x) return num + x - tx;

            diff = width - (step / 2);
            x -= diff;
            break;
        case 3:
            if (x == tx && ty < y) return num + y - ty;

            diff = height - (step / 2) - 1;
            y -= diff;
            break;
        }
        num += diff;

        // cout << x << " " << y << " " << num << endl;
        dir = (dir + 1) % 4;

        if (old_x == x && old_y == y) break;
    }
    return 0;
}

int main() {
    int width, height, tx, ty;
    cin >> height >> width >> ty >> tx;
    cout << value_of(width, height, tx, ty) << endl;
    return 0;
}