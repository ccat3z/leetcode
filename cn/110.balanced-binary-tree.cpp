/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (52.82%)
 * Likes:    404
 * Dislikes: 0
 * Total Accepted:    100.6K
 * Total Submissions: 190.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
 * 
 * 
 * 
 */
#include <iostream>
#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        return isBalancedDepth(root) >= 0;
    }
    int isBalancedDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int a, b;
        a = isBalancedDepth(root->left);
        if (a < 0) return -1;
        b = isBalancedDepth(root->right);
        if (b < 0) return -1;

        int d = abs(a - b);
        if (d > 1) return -1;

        return max(a, b) + 1;
    }
};
// @lc code=end

int main() {
    TreeNode t(0);
    t.left = new TreeNode(1);
    t.right = new TreeNode(2);
    t.right->right = new TreeNode(3);
    t.right->right->right = new TreeNode(3);
    cout << Solution().isBalanced(&t) << endl;
    return 0;
}

