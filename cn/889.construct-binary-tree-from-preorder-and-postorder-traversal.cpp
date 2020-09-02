/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (65.91%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 10.2K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
 * 
 * pre 和 post 遍历中的值是不同的正整数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
 * 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ostream &operator<<(ostream &o, const TreeNode &n) {
    o << n.val << ", ";
    if (n.left != nullptr) {
        o << *n.left;
    } 
    if (n.right != nullptr) {
        o << *n.right;
    }
    return o;
}

// @lc code=start

class Solution {
public:
    vector<int> pre;
    vector<int> post;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        this->pre = pre;
        this->post = post;
        return constructFromPrePost(0, pre.size() - 1, 0, post.size() - 1);
    }
    // .a0         .a1
    // 1,2,4,5,3,6,7
    //   ^a0+1
    // 4,5,2,6,7,3,1
    // ^b0 ^l      ^b1
    TreeNode* constructFromPrePost(int a0, int a1, int b0, int b1) {
        int size = a1 - a0 + 1;
        if (size <= 0) return nullptr;
        TreeNode *res = new TreeNode(pre[a0]);
        if (size == 1) return res;

        int l;
        for (l = b0; l <= b1; ++l) {
            if (pre[a0 + 1] == post[l]) {
                break;
            }
        }

        size = l - b0 + 1;
        res->left = constructFromPrePost(a0+1, a0+size, b0, l);
        res->right = constructFromPrePost(a0+size+1, a1, l+1, b1);
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, vector<int>>> inputs = {
        make_tuple(vector<int>({1,2,4,5,3,6,7}), vector<int>({4,5,2,6,7,3,1})),
        make_tuple(vector<int>({1}), vector<int>({1})),
    };
    for_each(inputs.begin(), inputs.end(), [&](tuple<vector<int>, vector<int>> &t) {
        cout << *Solution().constructFromPrePost(get<0>(t), get<1>(t)) << endl;
    });
    return 0;
}

