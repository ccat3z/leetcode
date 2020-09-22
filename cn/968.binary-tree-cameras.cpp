/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 *
 * https://leetcode-cn.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (39.35%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 14.1K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * 给定一个二叉树，我们在树的节点上安装摄像头。
 * 
 * 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
 * 
 * 计算监控树的所有节点所需的最小摄像头数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[0,0,null,0,0]
 * 输出：1
 * 解释：如图所示，一台摄像头足以监控所有节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[0,0,null,0,null,0,null,null,0]
 * 输出：2
 * 解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数的范围是 [1, 1000]。
 * 每个节点的值都是 0。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
struct tup {
    int includeRoot;
    int coverTree;
    int coverChildren;
};

class Solution {
public:
    struct tup dfs(TreeNode* root) {
        if (root == nullptr) {
            return {INT32_MAX / 2, 0, 0};
        }
        struct tup t;
        struct tup l = dfs(root->left), r = dfs(root->right);
        
        t.includeRoot = l.coverChildren + r.coverChildren + 1;
        t.coverTree = min(t.includeRoot, min(l.includeRoot + r.coverTree, l.coverTree + r.includeRoot));
        t.coverChildren = min(t.coverTree, l.coverTree + r.coverTree);
        return t;
    }
    int minCameraCover(TreeNode* root) {
        return dfs(root).coverTree;
    }
};
// @lc code=end

int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    cout << Solution().minCameraCover(root) << endl;
}