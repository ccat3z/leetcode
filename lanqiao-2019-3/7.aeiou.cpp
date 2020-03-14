#include <iostream>
#include <string>
using namespace std;

bool is_aeiou(string& word) {
    bool need_aeiou = false;
    int section = 1;

    for (auto at = word.begin(); at != word.end() && section < 5; ++at) {
        switch (*at) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            if (!need_aeiou) {
                need_aeiou = true;
                section += 1;
            }
            break;
        default:
            if (need_aeiou) {
                need_aeiou = false;
                section += 1;
            }
            break;
        }
    }

    return section == 4;
}

int main() {
    string word;
    cin >> word;
    cout << (is_aeiou(word) ? "yes" : "no") << endl;
}