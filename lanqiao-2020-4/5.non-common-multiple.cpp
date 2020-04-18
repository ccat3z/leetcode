#include <iostream>
#include <algorithm>
using namespace std;

// int ncm(int max_num, int *abc) {
//     int count = 0;

//     for (int i = 1; i <= max_num; ++i) {
//         int j;
//         for (j = 0; j < 3; ++j) {
//             if (i % abc[j] == 0) break;
//         }
//         if (j == 3) ++count;
//     }
//     return count;
// }

int ncm2(int max_num, int *abc) {
    int count = 0;
    int ref = 3;

    sort(abc, abc + ref);
    if (abc[2] % abc[1] == 0 || abc[2] % abc[0] == 0) {
        --ref;
    } else if (abc[1] % abc[0] == 0) {
        --ref;
        abc[1] = abc[2];
    }

    if (ref == 1) {
        return max_num - max_num / abc[0];
    }

    for (int i = 1; i <= max_num; ++i) {
        int j;
        for (j = 0; j < ref; ++j) {
            if (i % abc[j] == 0) break;
        }
        if (j == ref) ++count;
    }
    return count;
}

int main() {
    int max_num;
    int abc[3];
    
    cin >> max_num;
    cin >> abc[0] >> abc[1] >> abc[2];
    // cout << ncm(max_num, abc) << endl;
    cout << ncm2(max_num, abc) << endl;
    return 0;
}
