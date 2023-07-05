#include <initializer_list>
#include <iostream>
#include <list>
#include <ostream>
#include "leetcode_helper.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static ListNode *l(std::initializer_list<int> nums) {
    static std::list<ListNode> pool;

    ListNode head;
    ListNode *tail = &head;
    for (auto & num : nums) {
        tail = tail->next = &pool.emplace_back(num);
    }

    return head.next;
}

std::ostream &operator<<(std::ostream &o, ListNode *node) {
    o << "[";
    while (node) {
        o << node->val << ",";
        node = node->next;
    }
    o << "]";
    return o;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res;
        ListNode *tail = &res;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail = tail->next = list1;
                list1 = list1->next;
            } else {
                tail = tail->next = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            tail->next = list1;
        if (list2)
            tail->next = list2;
        return res.next;
    }
};

int main() {
    LC_D(Solution::mergeTwoLists);
    LC_T(l({1,2,4}), l({1,3,4}), l({1,1,2,3,4,4}));
    LC_T(l({}), l({}), l({}));
    LC_T(l({}), l({0}), l({0}));
    return 0;
}