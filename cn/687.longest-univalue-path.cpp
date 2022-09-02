/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 *
 * https://leetcode-cn.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (44.66%)
 * Likes:    635
 * Dislikes: 0
 * Total Accepted:    55.9K
 * Total Submissions: 121.4K
 * Testcase Example:  '[5,4,5,1,1,null,5]'
 *
 * 给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。
 * 
 * 两个节点之间的路径长度 由它们之间的边数表示。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：root = [5,4,5,1,1,5]
 * 输出：2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入：root = [1,4,5,4,4,5]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 树的节点数的范围是 [0, 10^4] 
 * -1000 <= Node.val <= 1000
 * 树的深度将不超过 1000 
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include "leetcode.h"
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
    int max_edge = 0;
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return max_edge;
    }

    int dfs(TreeNode* root) {
        int left_same = -1;
        if (root->left) {
            if (root->left->val == root->val) {
                left_same = dfs(root->left);
            } else {
                dfs(root->left);
            }
        }

        int right_same = -1;
        if (root->right) {
            if (root->right->val == root->val) {
                right_same = dfs(root->right);
            } else {
                dfs(root->right);
            }
        }

        max_edge = max(max_edge, left_same + right_same + 2);
        return max(left_same, right_same) + 1;
    }
};
// @lc code=end

int main() {
    vector<pair<TreeNode *, int>> cases = {
        {TreeNode::create(5,4,5,1,1,5), 2},
        {TreeNode::create(1,4,5,4,4,5), 2},
        {TreeNode::create(), 0},
        {TreeNode::create(1,null,1,1,1,1,1,1), 4}
    };
    for (auto &[root, res] : cases) {
        cout << Solution().longestUnivaluePath(root) << " = " << res << " # " << root << endl;
    }
    return 0;
}
