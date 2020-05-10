/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (60.43%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    78.6K
 * Total Submissions: 124K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 * 
 * 
 */

#include <iostream>
#include "leetcode.h"
using namespace std;

typedef leetcode::TreeNode<int> TreeNode;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *node;
    int p;
    int q;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p->val;
        this->q = q->val;
        count_pq(root);
        return node;
    }

    int count_pq(TreeNode *root) {
        if (root == nullptr) return 0;

        int c = 0;
        if (root->val == p || root->val == q) {
            c += 1;
        }

        c += count_pq(root->left);
        if (node != nullptr) {
            return -1;
        }

        c += count_pq(root->right);
        if (node != nullptr) {
            return -1;
        }

        if (c == 2) {
            node = root;
        }

        return c;
    }
};
// @lc code=end

int main() {
    TreeNode tree(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, 7, 4)), new TreeNode(1, 0, 8));
    cout << Solution().lowestCommonAncestor(&tree, new TreeNode(5), new TreeNode(1))->val << endl;
    cout << Solution().lowestCommonAncestor(&tree, new TreeNode(5), new TreeNode(4))->val << endl;
    return 0;
}