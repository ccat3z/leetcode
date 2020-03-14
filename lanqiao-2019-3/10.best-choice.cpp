#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> best_choice(vector<pair<int, int>>& choices, int size) {
    vector<int> result(size);
    sort(choices.begin(), choices.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
    sort(choices.begin(), choices.begin() + size,  [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    for (int i = 0; i < size; ++i) {
        result[i] = choices[i].first;
    }
    return result;
}

int main() {
    int choices_size, result_size;
    cin >> choices_size >> result_size;

    vector<pair<int, int>> choices(choices_size);
    for (int i = 0; i < choices_size; ++i) {
        choices[i] = pair<int, int>();
        cin >> choices[i].first;
        choices[i].second = i;
    }

    auto result = best_choice(choices, result_size);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}