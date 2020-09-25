/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (69.28%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 76.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ostream &operator<<(ostream &out, TreeNode *node) {
    if (node == nullptr) {
        out << "NULL";
    } else {
        out << '(' << node->val << ',' << node->left << ',' << node->right << ')';
    }
    return out;
}

// @lc code=start
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return buildTree(inorder, 0, size-1, postorder, 0, size-1);
    }
    TreeNode* buildTree(vector<int>& inorder, int i0, int i1, vector<int>& postorder, int p0, int p1) {
        if (i0 > i1) return nullptr;
        TreeNode *node = new TreeNode(postorder[p1]);
        int m = i0;
        while (inorder[m] != node->val) ++m;
        int size = m-i0;
        node->left = buildTree(inorder, i0, m-1, postorder, p0, p0+size-1);
        node->right = buildTree(inorder, m+1, i1, postorder, p0+size, p1-1);
        return node;
    }
};
// @lc code=end

int main() {
    vector<int> in = {9,3,15,20,7};
    vector<int> post = {9,15,7,20,3};
    cout << Solution().buildTree(in, post) << endl;
    return 0;
}