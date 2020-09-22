/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (62.90%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    62.5K
 * Total Submissions: 97.7K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 
 * 
 * 例如：
 * 
 * 输入: 原始二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 * 
 * 
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ostream &operator<<(ostream &out, TreeNode *node) {
    if (node == nullptr) {
        out << "null";
    } else {
        out << '(' << node->val << ',' << node->left << ',' << node->right << ')';
    }
    return out;
}

// @lc code=start

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode *tree = root;

        // pre node of root
        TreeNode *pre;
        while (root != nullptr) {
            if (root->right == nullptr) {
                // nothing on right, visit left tree
                root->val = sum += root->val;
                root = root->left;
            } else {
                // find pre node
                pre = root->right;
                while (pre->left != nullptr && pre->left != root) {
                    pre = pre->left;
                }

                if (pre->left == nullptr) {
                    // visit root at first time
                    pre->left = root;
                    root = root->right;
                } else {
                    // visit root at second time
                    pre->left = nullptr;
                    // right tree has been visited, visit left tree
                    root->val = sum += root->val;
                    root = root->left;
                }
            }
        }

        return tree;
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    cout << Solution().convertBST(root) << endl;
}