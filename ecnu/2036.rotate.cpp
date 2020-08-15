// https://acm.ecnu.edu.cn/problem/2036/
#include <iostream>
using namespace std;

enum Pos {
    LEFT_TOP,
    RIGHT_TOP,
    RIGHT_BOTTOM,
    LEFT_BOTTOM
};

/*
LEFT_TOP
i = x + y * X
ox---->
y a b c 
v d e f

RIGHT_TOP
i = (X - y - 1) + x * X
<----yo
a b c x
d e f v

LEFT_BOTTOM
i = y + (Y - x - 1) * X
^ a b c 
x d e f
oy---->

RIGHT_BOTTOM
i = (X - x - 1) + (Y - y - 1) * X
a b c ^
d e f y
<----xo
*/
class Rect {
public:
    Rect(int x, int y): x(x), y(y) {
        data = new int[x * y];
    };
    friend istream &operator>>(istream &, Rect &);
    friend ostream &operator<<(ostream &, Rect &);
    int width() {
        switch (pos) {
        case RIGHT_BOTTOM:
        case LEFT_TOP: return x;
        case LEFT_BOTTOM:
        case RIGHT_TOP: return y;
        }
        return -1;
    };
    int height() {
        switch (pos) {
        case RIGHT_BOTTOM:
        case LEFT_TOP: return y;
        case LEFT_BOTTOM:
        case RIGHT_TOP: return x;
        }
        return -1;
    };
    int get(int x, int y) {
        switch (pos) {
        case LEFT_TOP: return data[x + this->x * y];
        case RIGHT_TOP: return data[this->x - y - 1 + this->x * x];
        case LEFT_BOTTOM: return data[y + (this->y - x - 1) * this->x];
        case RIGHT_BOTTOM: return data[(this->x - x - 1) + (this->y - y - 1) * this->x];
        }
        return -1;
    };
    void turn_left() { pos = (Pos) ((pos + 1) % 4); };
    void turn_right() { pos = (Pos) ((pos + 3) % 4); };
private:
    int x, y;
    int *data;
    Pos pos = LEFT_TOP;
};

istream &operator>>(istream &is, Rect &rect) {
    int total = rect.x * rect.y;
    for (int i = 0; i < total; ++i) {
        is >> rect.data[i];
    }
    return is;
}

ostream &operator<<(ostream &os, Rect &rect) {
    int width = rect.width(), height = rect.height();
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x != 0) os << ' ';
            os << rect.get(x, y);
        }
        os << endl;
    }
    return os;
}

int main() {
    int x, y, c, param;
    char cmd;
    cin >> x >> y;
    Rect rect(x, y);
    cin >> rect;
    cin >> c;
    while (c-- > 0) {
        cin >> cmd;
        switch (cmd) {
        case 'O':
            cout << rect;;
            break;
        case 'L':
            cin >> param;
            while (param--) rect.turn_left();
            break;
        case 'R':
            cin >> param;
            while (param--) rect.turn_right();
            break;
        }
    }
    return 0;
}