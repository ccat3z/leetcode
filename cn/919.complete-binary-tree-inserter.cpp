/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 *
 * https://leetcode-cn.com/problems/complete-binary-tree-inserter/description/
 *
 * algorithms
 * Medium (65.43%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 42.9K
 * Testcase Example:  '["CBTInserter","insert","get_root"]\n[[[1]],[2],[]]'
 *
 * 完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
 * 
 * 设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。
 * 
 * 实现 CBTInserter 类:
 * 
 * 
 * CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
 * CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点
 * TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
 * CBTInserter.get_root() 将返回树的头节点。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入
 * ["CBTInserter", "insert", "insert", "get_root"]
 * [[[1, 2]], [3], [4], []]
 * 输出
 * [null, 1, 2, [1, 2, 3, 4]]
 * 
 * 解释
 * CBTInserter cBTInserter = new CBTInserter([1, 2]);
 * cBTInserter.insert(3);  // 返回 1
 * cBTInserter.insert(4);  // 返回 2
 * cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数量范围为 [1, 1000] 
 * 0 <= Node.val <= 5000
 * root 是完全二叉树
 * 0 <= val <= 5000 
 * 每个测试用例最多调用 insert 和 get_root 操作 10^4 次
 * 
 * 
 */
#include "leetcode.h"
#include <iostream>
#include <vector>
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
class CBTInserter {
public:
    vector<TreeNode *> path;
    CBTInserter(TreeNode* root) {
        path.emplace_back(root);
        auto left = left_most();
        if (left == root) return;

        path.pop_back();

        size_t left_dep = path.size();
        TreeNode *a, *b = next(left_dep);
        do {
            a = b;
            b = next(left_dep);
        } while (a != b);
    }

    inline TreeNode *left_most(size_t max_deep = 10000) {
        auto *next = path[path.size() - 1];
        if (next->left == nullptr) return next;

        for (next = next->left; next != nullptr && path.size() < max_deep; next = next->left) {
            path.emplace_back(next);
        }

        return path[path.size() - 1];
    }

    TreeNode *next(size_t max_deep = 10000) {
        auto & cur = path[path.size() - 1];
        if (cur->left == nullptr || cur->right == nullptr) {
            return cur;
        }

        for (;;) {
            if (path.size() == 1) {
                return left_most();
            }

            auto child = path[path.size() - 1];
            auto parent = path[path.size() - 2];
            path.pop_back();

            if (parent->left == child) {
                path.emplace_back(parent->right);
                return left_most(max_deep);
            }
        }
    }
    
    int insert(int val) {
        auto *parent = next();
        if (parent->left == nullptr) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }
        return parent->val;
    }
    
    TreeNode* get_root() {
        return path[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

int main() {
    auto *root = new TreeNode(0);
    // root->left = new TreeNode(1);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(5);

    CBTInserter ins(root);
    cout << ins.insert(6) << endl;
    cout << ins.insert(7) << endl;
    return 0;
}