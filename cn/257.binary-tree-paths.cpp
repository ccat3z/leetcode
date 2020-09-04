/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (64.68%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    62.8K
 * Total Submissions: 95.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */
#include <string>
#include <vector>
#include <iostream>
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }
    void dfs(TreeNode* node, string path) {
        if (node == nullptr) return;
        path += "->" + to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(path.substr(2));
        } else {
            dfs(node->left, path);
            dfs(node->right, path);
        }
        path.pop_back();
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    cout << Solution().binaryTreePaths(root) << endl;
    return 0;
}