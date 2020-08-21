/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include <algorithm>
using namespace std;

#define NULL nullptr

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// @lc code=start
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        int r = 1000000;
        if (root->left != nullptr) {
            r = min(r, minDepth(root->left) + 1);
        }
        if (root->right != nullptr) {
            r = min(r, minDepth(root->right) + 1);
        }
        return r;
    }
};
// @lc code=end

int main() {}