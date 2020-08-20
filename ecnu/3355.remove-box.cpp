#include <iostream>
#include <vector>
using namespace std;

int cache[100][100][100] = {0};

// 1 2 2 1 2 (3 3) 2 2
//   ^     ^  2
int score(int *boxes, int from, int to, int follow) {
    int &result = cache[from][to][follow];
    if (result != 0) return result;
    if (from > to) return 0;

    // 1 2 2 1 [2 [3 3] 2 2]
    //   ^      ^
    result = score(boxes, from, to - 1, 0) + (follow + 1) * (follow + 1); 

    // 1 2 2 [1] 2 [3 3] 2 2
    //   ^ i     ^   
    for (int i = from; i < to; ++i) {
        if (boxes[i] == boxes[to]) {
            result = max(result, score(boxes, from, i, follow + 1) + score(boxes, i + 1, to - 1, 0));
        }
    }
    return result;
}

int main() {
    int n; cin >> n;
    int boxes[n];
    for (int i = 0; i < n; ++i) cin >> boxes[i];
    cout << score(boxes, 0, n - 1, 0) << endl;
    return 0;
}