/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (45.43%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    30.7K
 * Total Submissions: 63.1K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
class Solution {
public:
    int maxN = 1;
    int current = 0;
    int n = 0;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        walk(root);
        next();
        return res;
    }
    inline void next() {
        if (n == maxN) {
            res.push_back(current);
        } else if (n > maxN) {
            res.clear();
            res.push_back(current);
            maxN = n;
        }
    }
    void walk(TreeNode *root) {
        if (root == nullptr) return;

        walk(root->left);
        if (root->val == current) {
            ++n;
        } else {
            next();
            current = root->val;
            n = 1;
        }
        walk(root->right);
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    cout << Solution().findMode(root) << endl;
}