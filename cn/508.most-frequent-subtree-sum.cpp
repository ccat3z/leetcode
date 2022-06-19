/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 *
 * https://leetcode-cn.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (68.33%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 34.5K
 * Testcase Example:  '[5,2,-3]'
 *
 * 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 * 
 * 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: root = [5,2,-3]
 * 输出: [2,-3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入: root = [5,2,-5]
 * 输出: [2]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <iostream>
#include <limits>
#include <algorithm>
#include "prettyprint.h"
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        calcSum(root);
        // cout << sums << endl;

        vector<int> res;
        for (auto &[sum, cnt] : sums) {
            if (cnt == max_cnt) {
                res.emplace_back(sum);
            }
        }

        return res;
    }

    int calcSum(TreeNode* node) {
        if (node == nullptr) return 0;

        node->val = node->val + calcSum(node->left) + calcSum(node->right);
        max_cnt = max(max_cnt, ++sums[node->val]);

        return node->val;
    }
private:
    int max_cnt = 0;
    unordered_map<int, int> sums;
};
// @lc code=end

int main() {
    TreeNode root = {5,2,-3};
    cout << Solution().findFrequentTreeSum(&root) << endl;

    return 0;
}
