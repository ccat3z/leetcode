/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 *
 * https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (76.92%)
 * Likes:    488
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 100.5K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 * 
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL
 * 的节点将直接作为新二叉树的节点。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * 输出: 
 * 合并后的树:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 注意: 合并必须从两个树的根节点开始。
 * 
 * 
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ostream &operator<<(ostream &out, TreeNode *tree) {
    if (tree == nullptr) {
        out << "null";
        return out;
    }

    out << '(' << tree->val;
    out << ',' << tree->left;
    out << ',' << tree->right;
    out << ')';
    return out;
}

// @lc code=start
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        merge(t1, t2);
        return t1;
    }
    void merge(TreeNode *&t1, TreeNode *&t2) {
        if (t1 == t2) return;
        if (t1 == nullptr) {
            t1 = t2;
        } else if (t2 == nullptr) {
            t2 = t1;
        } else {
            t1->val += t2->val;
            t2->val = t1->val;
        }

        merge(t1->left, t2->left);
        merge(t1->right, t2->right);
    }
};
// @lc code=end

int main() {
    TreeNode *a = new TreeNode(1);
    a->left = new TreeNode(3);
    a->right = new TreeNode(2);
    a->left->left = new TreeNode(5);

    TreeNode *b = new TreeNode(2);
    b->left = new TreeNode(1);
    b->left->right = new TreeNode(4);
    b->right = new TreeNode(3);
    b->right->right = new TreeNode(7);

    cout << Solution().mergeTrees(a, b) << endl;
}