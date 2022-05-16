// https://leetcode.cn/problems/successor-lcci/

#include <iostream>
#include <cassert>
#include "leetcode.h"
using namespace std;

typedef leetcode::TreeNode<int> TreeNode;

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
public:
    TreeNode* pre = nullptr;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        assert(root != nullptr);

        if (root->val == p->val) {
            if (root->right == nullptr) {
                return nullptr;
            } else {
                auto left_most = root->right;
                while (left_most->left) {
                    left_most = left_most->left;
                }
                return left_most;
            }
        } else if (p->val < root->val) {
            auto *f = inorderSuccessor(root->left, p);
            if (f == nullptr) {
                f = root;
            }
            return f;
        } else {
            return inorderSuccessor(root->right, p);
        }
    }
};

int main() {
    TreeNode root(5);
    root.left = new TreeNode(3, 2, 4);
    root.left->left->left = new TreeNode(1);
    root.right = new TreeNode(6);
    cout << Solution().inorderSuccessor(&root, new TreeNode(1)) << endl;
    return 0;
}