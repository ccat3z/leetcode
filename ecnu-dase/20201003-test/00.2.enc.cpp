#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int pad;
    cin >> pad >> str;
    for (char &c : str) {
        c = (c - 'a' + pad) % 26 + 'a';
    }
    cout << str << endl;
    return 0;
}