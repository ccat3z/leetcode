#include <iostream>
#include <list>

#include "leetcode_helper.h"
#define LOCAL_TEST

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static std::list<ListNode> pool;
ListNode *l(std::initializer_list<int> nums) {
    ListNode head;
    ListNode *tail = &head;

    for (auto num : nums) {
        tail->next = &pool.emplace_back(num);
        tail = tail->next;
    }

    return head.next;
}

std::ostream &operator<<(std::ostream &o, const ListNode *node) {
    o << "[";
    while (node != nullptr) {
        o << node->val;
        node = node->next;
        if (node)
            o << ',';
    }
    o << "]";
    return o;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto *a = reverse(l1);
        auto *b = reverse(l2);
        ListNode *head = nullptr;

        int overflow = 0;
        while (a || b) {
            auto v1 = a ? a->val : 0;
            auto v2 = b ? b->val : 0;
#ifdef LOCAL_TEST
            head = &pool.emplace_back(v1 + v2 + overflow, head);
#else
            head = new ListNode(v1 + v2 + overflow, head);
#endif
            overflow = head->val / 10;
            head->val %= 10;

            if (a) a = a->next;
            if (b) b = b->next;
        }

        if (overflow > 0) {
#ifdef LOCAL_TEST
            head = &pool.emplace_back(overflow, head);
#else
            head = new ListNode(overflow, head);
#endif

        }

        return head;
    }

    ListNode* reverse(ListNode *head) {
        ListNode *curr = nullptr;
        ListNode *next = head;

        while (next) {
            ListNode *pre = curr;
            curr = next;
            next = next->next;
            curr->next = pre;
        }

        return curr;
    }
};

int main() {
    LC_D(Solution::addTwoNumbers);
    LC_T(l({7,2,4,3}), l({5,6,4}), l({7,8,0,7}));
    LC_T(l({2,4,3}), l({5,6,4}), l({8,0,7}));
    LC_T(l({0}), l({0}), l({0}));
    LC_T(l({5}), l({5}), l({1,0}));

    return 0;
}