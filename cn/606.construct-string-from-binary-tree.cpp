/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 *
 * https://leetcode-cn.com/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Easy (57.45%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    44.5K
 * Total Submissions: 73.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
 * 
 * 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 二叉树: [1,2,3,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠  /    
 * ⁠ 4     
 * 
 * 输出: "1(2(4))(3)"
 * 
 * 解释: 原本将是“1(2(4)())(3())”，
 * 在你省略所有不必要的空括号对之后，
 * 它将是“1(2(4))(3)”。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 二叉树: [1,2,3,null,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠    \  
 * ⁠     4 
 * 
 * 输出: "1(2()(4))(3)"
 * 
 * 解释: 和第一个示例相似，
 * 除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
 * 
 * 
 */

#include "leetcode.h"
#include "prettyprint.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
typedef leetcode::TreeNode<int> TreeNode;


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
class Solution {
public:
    string tree2str(TreeNode *root) {
        stringstream ss;
        tree2ss(ss, root);
        return ss.str();
    }
private:
    void tree2ss(stringstream &ss, TreeNode *&root) {
        if (!root) return;

        ss << root->val;
        if (!root->left && !root->right) return;

        ss << '(';
        tree2ss(ss, root->left);
        ss << ')';

        if (root->right) {
            ss << '(';
            tree2ss(ss, root->right);
            ss << ')';
        }
    }
};
// @lc code=end

int main() {
    TreeNode tr(1, new TreeNode(2, 4, nullptr), new TreeNode(3, nullptr, 5));
    cout << tr << endl;
    cout << Solution().tree2str(&tr) << endl;
    return 0;
}