// https://leetcode.cn/problems/reverse-nodes-in-k-group/
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


// Pass ASan
static std::list<ListNode> pool;
static ListNode* new_list(std::initializer_list<int> nums) {
    ListNode *head = nullptr;
    ListNode *next = nullptr;

    for (auto & num : nums) {
        pool.emplace_back();
        if (!head) {
            head = &pool.back();
            next = head;
        } else {
            next->next = &pool.back();
            next = next->next;
        }
        next->val = num;
    }

    return head;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode res;

        ListNode *last_group = &res;
        ListNode *k_head = nullptr;
        ListNode *k_tail = nullptr;
        int k_len = 0;

        while (head) {
            if (!k_head) {
                k_head = head;
            }
            k_len += 1;

            if (k_len == k) {
                k_tail = head->next;
                head = head->next;

                last_group->next = reverseImpl(k_head, k_tail);
                last_group = k_head;

                k_head = nullptr;
                k_tail = nullptr;
                k_len = 0;
            } else {
                head = head->next;
            }
        }

        return res.next;
    }

    // reverse [head, tail)
    ListNode *reverseImpl(ListNode *head, ListNode *tail) {
        if (head == tail) return head;

        ListNode *a = tail;
        ListNode *b = head;

        while (b != tail) {
            ListNode *pending = b->next;
            b->next = a;
            a = b;
            b = pending;
        }

        std::cerr << a->val << std::endl;
        return a;
    }
};

int main() {
    LC_D(Solution::reverseKGroup);
    LC_T(new_list({1,2,3,4,5}), 2, new_list({2,1,4,3,5}));
    LC_T(new_list({1,2,3,4,5}), 1, new_list({1,2,3,4,5}));
    LC_T(new_list({1,2,3,4,5}), 3, new_list({3,2,1,4,5}));
    return 0;
}