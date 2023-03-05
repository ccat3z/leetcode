// https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/

#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        if (folder.size() == 0) return folder;

        vector<string> result;
        string prefix = "_";
        for (auto & path : folder) {
            if (path.size() < prefix.size() || memcmp(prefix.data(), path.data(), prefix.size()) != 0) {
                prefix = path;
                prefix.push_back('/');
                result.emplace_back(std::move(path));
            }
        }

        return result;
    }
};

ostream &operator<<(ostream &o, const vector<string> & str_vec) {
    bool first = true;
    o << "[";
    for (auto & s: str_vec) {
        if (first) first = false;
        else o << ", ";

        o << s;
    }
    o << "]";
}

int main() {
    vector<pair<vector<string>, vector<string>>> tests = {
        {{"/a","/a/b","/c/d","/c/d/e","/c/f"}, {"/a","/c/d","/c/f"}},
        {{"/a","/a/b/c","/a/b/d"}, {"/a"}},
        {{"/a/b/c","/a/b/ca","/a/b/d"}, {"/a/b/c","/a/b/ca","/a/b/d"}}
    };

    for (auto & [folders, out] : tests) {
        cout << folders << " -> " << Solution().removeSubfolders(folders) << " == " << out << endl;
    }

    return 0;
}