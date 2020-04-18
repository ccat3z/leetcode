#include <iostream>
using namespace std;

int main() {
    char str[100];
    cin >> str;
    for (int i = 0; str[i] != 0; ++i) {
        str[i] += 3;
        if (str[i] > 'z') str[i] -= 26;
    }
    cout << str << endl;
}