/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (66.24%)
 * Likes:    296
 * Dislikes: 0
 * Total Accepted:    80K
 * Total Submissions: 120.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "prettyprint.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution {
public:
    int depth(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> res(d);

        if (d == 0) return res;

        queue<TreeNode *> nodes;
        nodes.push(root);
        int a = 1, b = 0;

        TreeNode *at;
        int level = d - 1;
        while (!nodes.empty()) {
            at = nodes.front(); nodes.pop(); --a;
            res[level].push_back(at->val);
            if (at->left != nullptr) {
                nodes.push(at->left);
                ++b;
            }
            if (at->right != nullptr) {
                nodes.push(at->right);
                ++b;
            }
            if (a == 0) { a = b; b = 0; --level; }
        }
        

        return res;
    }
};
// @lc code=end

int main() {
    TreeNode *n = new TreeNode(3);
    n->left = new TreeNode(9);
    n->right = new TreeNode(20);
    n->right->left = new TreeNode(15);
    n->right->right = new TreeNode(15);
    cout << Solution().levelOrderBottom(n) << endl;
}

