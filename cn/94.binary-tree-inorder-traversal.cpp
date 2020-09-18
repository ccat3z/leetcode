/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (72.48%)
 * Likes:    714
 * Dislikes: 0
 * Total Accepted:    267.2K
 * Total Submissions: 363K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;


// REVIEW: Morris 中序遍历


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; TreeNode *pre;
        while (root != nullptr) {
            if (root->left == nullptr) {
                // nothing on left
                res.push_back(root->val);
                root = root->right;
            } else {
                //     1
                //   2  3
                //  4 5 <- pre of 1
                // find pre
                pre = root->left;
                while (pre->right != nullptr && pre->right != root) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    // first occ
                    pre->right = root;
                    root = root->left;
                } else {
                    // second occ
                    pre->right = nullptr;
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cout << Solution().inorderTraversal(root) << endl;
    return 0;
}