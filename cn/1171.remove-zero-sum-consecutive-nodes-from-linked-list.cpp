#include <initializer_list>
#include <ostream>
#include <list>
#include <tuple>
#include <unordered_map>
#include "leetcode_helper.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode* create(std::initializer_list<int> nums) {
        static std::list<ListNode> pool;

        pool.emplace_back();
        ListNode *head = nullptr;
        ListNode *node = nullptr;

        for (auto & num : nums) {
            pool.emplace_back();
            if (!head) {
                node = &pool.back();
                head = node;
                node->val = num; 
            } else {
                node->next = &pool.back();
                node = node->next;
                node->val = num;
            }
        }

        return head;
    }
};

std::ostream &operator<<(std::ostream &o, ListNode * node) {
    o << "[";
    while (node != nullptr) {
        o << node->val << ",";
        node = node->next;
    }
    o << "]";

    return o;
}

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode fake_head;
        fake_head.next = head;

        // Sum -> Most right node
        std::unordered_map<int, ListNode*> idx;
        int sum = 0;
        for (auto node = &fake_head; node; node = node->next) {
            sum += node->val;
            idx[sum] = node;
        }
        sum = 0;
        for (auto node = &fake_head; node; node = node->next) {
            sum += node->val;
            node->next = idx[sum]->next;
        }
        return fake_head.next;
    }
};

int main() {
    LC_D(Solution::removeZeroSumSublists);
    LC_T(ListNode::create({1, 2}), ListNode::create({1, 2}));
    LC_T(ListNode::create({1,2,3,-3,4}), ListNode::create({1,2,4}));
    LC_T(ListNode::create({1,2,3,-3,4}), ListNode::create({1,2,4}));
    LC_T(ListNode::create({1,2,3,-3,-2}), ListNode::create({1}));
    return 0;
}