/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.78%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    83.7K
 * Total Submissions: 137.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
#include <iostream>
#include <vector>
#include "prettyprint.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
inline bool is_leaf(TreeNode *root) {
    return root->left == nullptr && root->right == nullptr;
}
class Solution {
public:
    vector<vector<int>> res;
    vector<int> comb;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        p(root, sum);
        return res;
    }
    void p(TreeNode *root, int sum) {
        if (root == nullptr) return;
        comb.push_back(root->val);
        sum -= root->val;

        if (is_leaf(root)) {
            if (sum == 0) {
                res.emplace_back(comb);
            }
        } else {
            p(root->left, sum);
            p(root->right, sum);
        }

        comb.pop_back();
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    cout << Solution().pathSum(root, 22) << endl;
}