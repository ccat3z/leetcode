/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 *
 * https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (63.16%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 37.6K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * 给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
 * 
 * 请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,7,0,7,-8,null,null]
 * 输出：2
 * 解释：
 * 第 1 层各元素之和为 1，
 * 第 2 层各元素之和为 7 + 0 = 7，
 * 第 3 层各元素之和为 7 + -8 = -1，
 * 所以我们返回第 2 层的层号，它的层内元素之和最大。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在 [1, 10^4]范围内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */
#include "leetcode.h"
#include <iostream>
#include <limits>
#include <vector>
#include <memory>
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
    int maxLevelSum(TreeNode* root) {
        int sum_max = numeric_limits<int>::min();
        int max_layer = 1;

        vector<TreeNode *> layer = {root};
        int cur_layer = 1;

        while (!layer.empty()) {
            int sum = 0;
            vector<TreeNode *> next;
            for (auto & node : layer) {
                sum += node->val;
                
                if (node->left) {
                    next.emplace_back(node->left);
                }
                if (node->right) {
                    next.emplace_back(node->right);
                }
            }

            if (sum > sum_max) {
                max_layer = cur_layer;
                sum_max = sum;
            }

            cur_layer++;
            layer = move(next);
        }

        return max_layer;
    }
};
// @lc code=end

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    cout << Solution().maxLevelSum(root) << endl;
    return 0;
}