// https://acm.ecnu.edu.cn/problem/3747/
// TODO:

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
using namespace std;


class Node {
public:
    Node(int index) : index(index) {};
    int index;
    Node *right = nullptr;
    Node *left = nullptr;
    Node *leftest() {
        if (left == nullptr) return this;
        else return left->leftest();
    }
    Node *rightest() {
        if (right == nullptr) return this;
        else return right->rightest();
    }
};

Node *nodes[1000001];

class List {
public:
    // move list <Node *> to left of <Node *>
    queue<tuple<Node *, Node *>> adjust;
    List(int size) : size(size) {
        fill(&nodes[1], &nodes[size + 1], nullptr);
    };
    void insert(int before, int after) {
        Node *&a = nodes[before];
        Node *&b = nodes[after];
        if (a == nullptr) a = new Node(before);
        if (b == nullptr) b = new Node(after);

        if (a->right != nullptr || b->left != nullptr) {
            adjust.push(tuple<Node *, Node *>(a, b));
        } else {
            a->right = b;
            b->left = a;
        }
    };
    ~List() {
        for_each(&nodes[0], &nodes[1000000], [](Node *&node) {
            if (node != nullptr) {
                delete node;
            }
        });
    };
private:
    int size;
};

vector<pair<int, int>> check(int (*relations)[2], int node_size) {
    vector<pair<int, int>> result;
    List list(node_size);
    for (int i = 0; i < node_size - 1; ++i) {
        list.insert(relations[i][0], relations[i][1]);
    }

    while (!list.adjust.empty()) {
        Node *a,*b,*a_end,*b_begin;
        tie(a, b) = list.adjust.front();
        cout << a->index << b->index << endl;
        a_end = a->rightest();
        b_begin = b->leftest();
        a_end->right = b_begin;
        b_begin->left = a_end;
        list.adjust.pop();
        result.push_back(pair<int, int>(a_end->index, b_begin->index));
    }

    return result;
}

int main() {
    int group, count;
    cin >> group;
    for (int g = 1; g <= group; ++g) {
        cin >> count;
        int relations[count - 1][2];
        for (int i = 0; i < count - 1; ++i) {
            cin >> relations[i][0] >>  relations[i][1];
        }
        vector<pair<int, int>> result = check(relations, count);
        cout << "Case " << g << ": " << result.size() << endl;
        for (auto it = result.begin(); it != result.end(); ++it) {
            cout << it->first << ' ' << it->second << endl;
        }
    }
}