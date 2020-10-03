#include <iostream>
#include <string>
using namespace std;

inline bool isint(string &a) {
    for (char &c : a) {
        if (c < '0' || '9' < c) {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b;
    bool wrong = false;
    cin >> a >> b;
    if (!isint(a)) {
        wrong = true;
        a = "?";
    }
    if (!isint(b)) {
        wrong = true;
        b = "?";
    }
    cout << a << " + " << b << " = ";
    if (wrong) {
        cout << "?";
    } else {
        cout << stoi(a) + stoi(b);
    }
    cout << endl;
    return 0;
}