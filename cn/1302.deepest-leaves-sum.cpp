/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 *
 * https://leetcode-cn.com/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (82.28%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    48.2K
 * Total Submissions: 56.4K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * 给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * 输出：15
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：19
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 10^4] 之间。
 * 1 
 * 
 * 
 */
#include <iostream>
#include "leetcode.h"
#include "prettyprint.h"
using namespace std;
using TreeNode = leetcode::TreeNode<int>;

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
    size_t max_dep = 0;
    int sum = 0;
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode *node, size_t dep) {
        if (node == nullptr) return;

        if (!node->left && !node->right) {
            if (dep == max_dep) {
                sum += node->val;
                return;
            } else if (dep > max_dep) {
                max_dep = dep;
                sum = node->val;
            }
            return;
        }

        dfs(node->left, dep+1);
        dfs(node->right, dep+1);
    }
};
// @lc code=end

int main() {
    auto *root = TreeNode::create(6,7,8,2,7,1,3,9,null,1,4,null,null,null,5);

    cout << Solution().deepestLeavesSum(root) << " " << root << endl;
    return 0;
}