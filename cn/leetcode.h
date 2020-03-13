#ifndef _LEETCODE_H_
#include <iostream>

namespace leetcode {
    template<typename T> struct TreeNode {
        T val;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        TreeNode(T val) : val(val) {};
        TreeNode(T val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) { }
        TreeNode(T val, TreeNode *left) : val(val), left(left) { }
        TreeNode(std::initializer_list<T> tree) : TreeNode(tree.begin(), tree.end()) { }
        TreeNode(const T *begin, const T *end) : TreeNode(*begin) {
            int size = end - begin;

            if (size != 1) {
                if ((size - 1) % 2 != 0) throw "invalid tree";
                int leaf_size = (size - 1) / 2;
                left = new TreeNode(begin + 1, begin + 1 + leaf_size);
                right = new TreeNode(begin + 1 + leaf_size, end);
            }
        }

        ~TreeNode() {
            delete left;
            delete right;
        }
    };

    template<typename T> std::ostream& operator<<(std::ostream& out, const TreeNode<T>* tree) {
        if (tree == nullptr) {
            out << "";
        } else {
            out << *tree;
        }
        return out;
    }

    template<typename T> std::ostream& operator<<(std::ostream& out, const TreeNode<T>& tree) {
        out << '(' << tree.val << ',' << tree.left << ',' << tree.right << ')';

        return out;
    }
}
#endif