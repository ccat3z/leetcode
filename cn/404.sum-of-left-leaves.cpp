/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (55.39%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    57.2K
 * Total Submissions: 102.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 
 */

#include <iostream>
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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return sum;
        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                sum += root->left->val;
            }
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << Solution().sumOfLeftLeaves(root) << endl;
}