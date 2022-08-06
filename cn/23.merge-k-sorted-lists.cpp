/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (56.59%)
 * Likes:    2093
 * Dislikes: 0
 * Total Accepted:    516.3K
 * Total Submissions: 903.6K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <initializer_list>
#include <queue>
#include "prettyprint.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    template <typename it> ListNode(it begin, it end) {
        if (begin == end) return;
        val = *begin++;
        if (begin != end) {
            next = new ListNode(begin, end);
        }
    }
    ListNode(initializer_list<int> list) : ListNode(list.begin(), list.end()) {
    }
};

ostream &operator<<(ostream &os, const ListNode *node) {
    os << '[';
    while (node != nullptr) {
        os << node->val << ',';
        node = node->next;
    }
    os << ']';
    return os;
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode *&a, ListNode *&b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> q(comp);
        for (auto &list : lists) {
            if (list) q.emplace(list);
        }

        ListNode *head = nullptr;
        if (q.empty()) return head;

        head = q.top();
        q.pop();
        if (head->next) {
            q.push(head->next);
        }

        auto *prev = head;
        while (!q.empty()) {
            prev->next = q.top();
            q.pop();

            prev = prev->next;
            if (prev->next) {
                q.push(prev->next);
            }
        }

        return head;
    }
};
// @lc code=end

int main() {
    vector<ListNode> lists = {
        {1,4,5},
        {1,3,4},
        {2,6}
    };
    vector<ListNode *> lists_ptr;
    for (auto &list : lists) lists_ptr.emplace_back(&list);

    // cout << lists_ptr << endl;
    cout << Solution().mergeKLists(lists_ptr) << endl;
    return 0;
}