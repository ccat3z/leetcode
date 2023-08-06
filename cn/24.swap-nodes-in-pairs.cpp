// https://leetcode.cn/problems/swap-nodes-in-pairs/

#include "leetcode_helper.h"
#include <initializer_list>
#include <list>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode *create(std::initializer_list<int> list) {
        static std::list<ListNode> pool;
        ListNode head;
        ListNode *tail = &head;

        for (auto i : list) {
            tail->next = &pool.emplace_back(i);
            tail = tail->next;
        }

        return head.next;
    }
};

std::ostream &operator<<(std::ostream & os, const ListNode * node) {
    os << "[";
    while (node) {
        os << node->val << ',';
        node = node->next;
    }
    os << "]";
    return os;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* node) {
        ListNode head(0, node);
        ListNode *prev, *a, *b;
        
        prev = &head;
        while (prev) {
            a = prev->next;
            if (!a) return head.next;
            b = a->next;
            if (!b) return head.next;

            a->next = b->next;
            b->next = a;
            prev->next = b;

            prev = a;
        }

        return head.next;
    }
};

int main() {
    LC_D(Solution::swapPairs);
    LC_T(ListNode::create({1,2,3,4}), ListNode::create({2,1,3,4}));
    LC_T(ListNode::create({}), ListNode::create({}));
    LC_T(ListNode::create({1}), ListNode::create({1}));
    return 0;
}