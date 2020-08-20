#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int user, relation;
    cin >> user >> relation;
    bitset<40000> uf_map[user + 1];
    for (int i = 0; i < relation; ++i) {
        int a, b;
        cin >> a >> b;
        uf_map[a][b] = 1;
        uf_map[b][a] = 1;
    }
    int query;
    cin >> query;

    for (int i = 0; i < query; ++i) {
        int a, b;
        cin >> a >> b;
        cout << (uf_map[a] & uf_map[b]).count() << endl;
    }
    return 0;
}