#include <vector>
#include <memory>
#include <tuple>

#include "leetcode.h"

using TreeNode = leetcode::TreeNode<int>;

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
  bool evaluateTree(TreeNode *root)
  {
    switch (root->val) {
      case 0:
      case 1:
        return root->val;
      case 2:
        return evaluateTree(root->left) || evaluateTree(root->right);
      case 3:
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
    return false;
  }
};

int main()
{
  std::vector<std::tuple<TreeNode *, bool>> trees = {
      {TreeNode::create(2, 1, 3, null, null, 0, 1), true},
      {TreeNode::create(0), false},
      {TreeNode::create(3,
           3,
           2,
           0,
           0,
           3,
           2,
           null,
           null,
           null,
           null,
           1,
           3,
           1,
           1,
           null,
           null,
           2,
           1,
           null,
           null,
           null,
           null,
           1,
           1,
           null,
           null,
           null,
           null,
           null,
           null),
          false},
  };
  for (const auto &[tree, expect] : trees) {
    std::cout << Solution().evaluateTree(tree) << " = " << expect << ": " << *tree << std::endl;
  }

  return 0;
}