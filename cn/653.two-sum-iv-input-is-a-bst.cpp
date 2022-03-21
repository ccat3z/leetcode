/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (60.52%)
 * Likes:    352
 * Dislikes: 0
 * Total Accepted:    67.8K
 * Total Submissions: 109.3K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 9
 * 输出: true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 28
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是  [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root 为二叉搜索树
 * -10^5 <= k <= 10^5
 * 
 * 
 */
#include <iostream>
#include <queue>
#include <set>
#include "prettyprint.h"
#include "leetcode.h"

using namespace std;
typedef leetcode::TreeNode<int> TreeNode;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode *> q; q.push(root);
        set<int> s;
        TreeNode *n;

        while (!q.empty()) {
            n = q.front(); q.pop();
            if (s.find(k - n->val) != s.end()) {
                return true;
            }

            s.insert(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }

        return false;
    }
};
// @lc code=end

int main() {
    TreeNode tr(5, new TreeNode(3, 2, 4), new TreeNode(6, nullptr, 7));
    cout << Solution().findTarget(&tr, 28) << endl;
    return 0;
}