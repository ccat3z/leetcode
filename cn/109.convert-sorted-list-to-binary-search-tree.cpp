/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (73.32%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    55.4K
 * Total Submissions: 73K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        for (ListNode *n = head; n != nullptr; n = n->next) ++length;
        return fillChild(head, 0, length - 1);
    }
    TreeNode *fillChild(ListNode *&head, int from, int to) {
        // cout << from << ' ' << to << endl;
        TreeNode *parent = new TreeNode();
        if (from > to) return nullptr;
        int mid = (from + to) / 2;
        parent->left = fillChild(head, from, mid - 1);
        // cout << from << ' ' << to  << ' ' << head->val << endl;
        parent->val = head->val;
        head = head->next;
        parent->right = fillChild(head, mid + 1, to);
        return parent;
    }
private:
    vector<TreeNode *> nodes;
};
// @lc code=end

int main() {
    vector<int> example = {-10,-3,0,5,9};
    ListNode *last = nullptr;
    for (auto n = example.rbegin(); n != example.rend(); ++n) {
        ListNode *l = new ListNode(*n);
        l->next = last;
        last = l;
    }
    TreeNode *node = Solution().sortedListToBST(last);
    return 0;
}