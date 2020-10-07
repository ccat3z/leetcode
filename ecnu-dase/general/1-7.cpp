#include <iostream>
#include <vector>
using namespace std;

vector<int> ss = {2};

void fill_ss(int end) {
    for (int i = 3; i <= end; ++i) {
        bool is_s = true;
        for (int &s : ss) {
            if (i % s == 0) {
                is_s = false;
                break;
            }
        }
        if (is_s) ss.emplace_back(i);
    }
}

template <typename T>
ostream &operator<<(ostream &o, vector<T> &v) {
    cout << '[';
    bool first = true;
    for (T &t : v) {
        if (first) first = false;
        else cout << ',';
        cout << t;
    }
    cout << ']';
    return o;
}

void print_eq(int num) {
    cout << num << "=";
    auto it = ss.begin();
    bool first = true;
    while (it != ss.end() && num != 0) {
        if (num % (*it) == 0) {
            num /= *it;
            if (first) first = false;
            else cout << '*';
            cout << *it;
        } else {
            ++it;
        }
    }
    cout << endl;
}

int main() {
    int from, end;
    cin >> from >> end;
    fill_ss(end);
    cout << ss << endl;

    for (int num = from; num <= end; ++num) {
        print_eq(num);
    }
    return 0;
}