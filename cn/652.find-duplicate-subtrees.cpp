/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 *
 * https://leetcode-cn.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (57.45%)
 * Likes:    541
 * Dislikes: 0
 * Total Accepted:    69.3K
 * Total Submissions: 115.6K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * 给定一棵二叉树 root，返回所有重复的子树。
 * 
 * 对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 * 
 * 如果两棵树具有相同的结构和相同的结点值，则它们是重复的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,null,2,4,null,null,4]
 * 输出：[[2,4],[4]]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root = [2,1,1]
 * 输出：[[1]]
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：root = [2,2,2,3,null,3,null]
 * 输出：[[2,3],[3]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的结点数在[1,10^4]范围内。
 * -200 <= Node.val <= 200
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <utility>
#include <functional>
#include <tuple>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include "leetcode.h"
#include "prettyprint.h"

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
template<>
class std::hash<tuple<int, int, int>> {
public:
    size_t operator()(const tuple<int, int, int> &t) const noexcept {
        auto &[a, b, c] = t;
        auto fn = hash<int>();
        return (fn(a) << 24) ^ (fn(b) << 8) ^ fn(c);
    }
};

class Solution {
public:
    //                  val, lidx, ridx            tree, idx
    unordered_map<tuple<int, int, int>, pair<TreeNode *, int>> seen;
    unordered_set<TreeNode *> res;

    vector<TreeNode *> findDuplicateSubtrees(TreeNode* root) {
        getIdx(root);
        return {res.begin(), res.end()};
    }

    int idx = 0;
    int getIdx(TreeNode *node) {
        if (!node) return -1;

        auto key = make_tuple(node->val, getIdx(node->left), getIdx(node->right));
        auto it = seen.find(key);
        if (it != seen.end()) {
            auto &[tree, idx] = it->second;
            res.emplace(tree);
            return idx;
        } else {
            seen[key] = {node, ++idx};
            return idx;
        }
    }
};
// @lc code=end

int main() {
    vector<pair<TreeNode *, vector<TreeNode *>>> cases = {
        {
            TreeNode::create(1,2,3,4,null,2,4,null,null,4),
            {TreeNode::create(2,4), TreeNode::create(4)}
        }
    };

    for (auto &[root, res] : cases) {
        cout << "# " << root << endl;
        cout << Solution().findDuplicateSubtrees(root) << " == " << res << endl;
    }
    
    return 0;
}
