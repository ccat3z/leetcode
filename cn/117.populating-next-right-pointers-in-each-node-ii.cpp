/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 *
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (50.93%)
 * Likes:    222
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 62.6K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * 给定一个二叉树
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 
 * 初始状态下，所有 next 指针都被设置为 NULL。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,7]
 * 输出：[1,#,2,3,#,4,5,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数小于 6000
 * -100 <= node.val <= 100
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

ostream &operator<<(ostream &o, Node *node) {
    if (node == nullptr) return o;
    return o << '(' << node->val
      << '[' << (node->next != nullptr ? node->next->val : -1) << ']'
      << ',' << node->left
      << ',' << node->right
      << ')';
}

// @lc code=start
class Solution {
public:
    inline void h(Node *&nextStart, Node *&chlid, Node *&last) {
        if (chlid == nullptr) return;
        if (nextStart == nullptr) nextStart = chlid;
        if (last != nullptr) {
            last->next = chlid;
        }
        last = chlid;
    }
    Node* connect(Node* root) {
        Node *start = root;
        Node *nextStart = nullptr;
        Node *last = nullptr;
        while (start != nullptr) {
            for (Node *cur = start; cur != nullptr; cur = cur->next) {
                h(nextStart, cur->left, last);
                h(nextStart, cur->right, last);
            }
            start = nextStart;
            last = nullptr;
            nextStart = nullptr;
        }
        return root;
    }
};
// @lc code=end

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    cout << Solution().connect(root) << endl;
}