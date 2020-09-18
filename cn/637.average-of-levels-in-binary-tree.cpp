/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (65.01%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    46.6K
 * Total Submissions: 67.8K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出：[3, 14.5, 11]
 * 解释：
 * 第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 节点值的范围在32位有符号整数范围内。
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr) return res;

        queue<tuple<int, TreeNode *>> q;
        q.emplace(make_tuple(0, root));

        int in_level = 0;
        double total = 0;
        int size = 0;
        while (!q.empty()) {
            int plevel; TreeNode *parent;
            tie(plevel, parent) = q.front(); q.pop();

            if (plevel != in_level) {
                res.push_back(total / size);
                in_level = plevel;
                total = 0;
                size = 0;
            }
            total += parent->val; ++size;
            
            if (parent->left != nullptr) q.emplace(make_tuple(plevel+1, parent->left));
            if (parent->right != nullptr) q.emplace(make_tuple(plevel+1, parent->right));
        }
        if (size != 0) {
            res.push_back(total / size);
        }

        return res;
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << Solution().averageOfLevels(root) << endl;
    cout << Solution().averageOfLevels(nullptr) << endl;
}