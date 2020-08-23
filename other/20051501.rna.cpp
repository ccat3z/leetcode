#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../cn/leetcode.h"

using namespace std;
typedef leetcode::TreeNode<char> TreeNode;

// ... [begin, p, end) ...
TreeNode *rna_search(vector<int> ws, int begin, int end) {
    if (begin == end) return nullptr;

    int p;
    int min = ws[end - 1] - ws[begin - 1];
    for (int i = begin; i < end; ++i) {
        int left = ws[i - 1] - ws[begin - 1];
        int right = ws[end - 1] - ws[i];
        int diff = abs(left - right);
        if (diff <= min) {
            p = i;
            min = diff;
        }
    }
    return new TreeNode(p + 'A' - 1, rna_search(ws, begin, p), rna_search(ws, p + 1, end));
}

// ws: 累加表
TreeNode *rna_search(vector<int> ws) {
    return rna_search(ws, 1, ws.size());
}

int main() {
    vector<int> ws = {0, 8, 2, 3, 4, 9, 3, 2, 6, 7, 1, 1, 4};
    for (auto it = ws.begin() + 1; it != ws.end(); ++it) {
        *it = *(it - 1) + *it;
        // cout << *it << ' ';
    }
    auto tree = rna_search(ws);
    cout << tree << endl;
    delete tree;
    return 0;
}