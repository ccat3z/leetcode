// https://leetcode.cn/problems/4ueAj6/
#include <iostream>
#include <initializer_list>
using namespace std;

class Node {
public:
    int val;
    Node* next = nullptr;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }

    static Node *create(initializer_list<int> list) {
        if (list.size() == 0) return nullptr;

        auto it = list.begin();
        Node *head = new Node(*it++);
        Node *tail = head;

        for (; it != list.end(); ++it) {
            tail->next = new Node(*it);
            tail = tail->next;
        }

        tail->next = head;

        return head;
    }
};

ostream &operator<<(ostream &os, Node *node) {
    if (node == nullptr) {
        return os << "[]";
    }

    os << '[';

    Node *head = node;
    os << head->val << ',';

    Node *next = head->next;
    for (; next != head; next = next->next) {
        if (next == nullptr) {
            os << "ERR!,";
            break;
        }
        os << next->val << ',';
    }

    os << ']';
    return os;
}

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node *head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node *prev = head, *curr = head->next;
        while (true) {
            if (curr == head) break;
            if (prev->val <= insertVal && insertVal <= curr->val) break;
            if (prev->val > curr->val) {
                if (prev->val <= insertVal || insertVal <= curr->val) {
                    break;
                }
            }

            prev = curr;
            curr = curr->next;
        }
        Node *insert = new Node(insertVal, curr);
        prev->next = insert;

        return head;
    }
};

int main() {
    Node *node = Node::create({3,5,1});
    cout << node << endl;

    cout << Solution().insert(node, 2) << endl;
    return 0;
}