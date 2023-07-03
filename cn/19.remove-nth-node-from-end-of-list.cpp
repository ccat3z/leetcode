#include "leetcode_helper.h"
#include <initializer_list>
#include <ostream>
#include <list>

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
    ListNode* removeNthFromEnd(ListNode* node, int n) {
        ListNode head(-1, node);
        ListNode *will_del = &head;
        ListNode *detect_tail = &head;

        while (n-- >= 0) {
            detect_tail = detect_tail->next;
        }

        while (detect_tail != nullptr) {
            detect_tail = detect_tail->next;
            will_del = will_del->next;
        }

        // std::cerr << will_del << std::endl;
        will_del->next = will_del->next->next;

        return head.next;
    }
};

int main() {
    LC_D(Solution::removeNthFromEnd);
    LC_T(l({1, 2, 3, 4, 5}), 2, l({1, 2, 3, 5}));
    LC_T(l({1}), 1, l({}));
    LC_T(l({1, 2}), 1, l({1}));
    return 0;
}