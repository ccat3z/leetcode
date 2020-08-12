/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (34.51%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 30.2K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

// @lc code=start
class Node {
public:
    Node(int begin, int end) {
        this->begin = begin;
        this->end = end;
        this->length = 0;
        this->count = 0;
    };
    int begin;
    int end;
    // max lengths of subseq which ending in [begin..end]
    // [1 3 2 4 => 3 (1 3 4, 1 2 4)
    //   ^   ^
    int length;
    // count of subseq which ending in [begin..end]
    // 1 3 2 4  => 2 (1 3 4, 1 2 4)
    //   ^   ^
    int count;
    Node *left() {
        if (this->_left == nullptr) {
            this->_left = new Node(begin, begin + (end - begin) / 2);
        }
        return this->_left;
    }
    Node *right() {
        if (this->_right == nullptr) {
            this->_right = new Node(begin + (end - begin) / 2 + 1, end);
        }
        return this->_right;
    }
    // query <max length, count> of subseq which ending in [begin..num]
    tuple<int, int> query(int num) {
        if (num >= end) {
            return tuple<int, int>(length, count);
        } else if (num < begin) {
            return tuple<int, int>(0, 0);
        }

        // if num in [begin, end)
        return merge(left()->query(num), right()->query(num));
    }
    tuple<int, int> merge(tuple<int, int> a, tuple<int, int> b) {
        int length_a, count_a, length_b, count_b;
        tie(length_a, count_a) = a;
        tie(length_b, count_b) = b;

        if (length_a == length_b) {
            return tuple<int, int>(length_a, count_a + count_b);
        } else if (length_a > length_b) {
            return a;
        } else {
            return b;
        }
    }
    void push(int num) {
        int l, c;
        tie(l, c) = query(num - 1);
        if (c == 0) c = 1;
        // cout << "insert" << ' ' << num << ' ' << l + 1 << ' ' << c << endl;
        insert(num, l + 1, c);
    }
    friend ostream &operator<<(ostream &ostream, const Node &n);
private:
    Node *_left = nullptr;
    Node *_right = nullptr;
    // insert subseqs end with num
    void insert(int num, int length, int count) {
        if (num < begin || end < num) return;
        tie(this->length, this->count) = merge(
            tuple<int, int>(length, count),
            tuple<int, int>(this->length, this->count)
        );

        if (begin != end) {
            left()->insert(num, length, count);
            right()->insert(num, length, count);
        }
    }
};

ostream &operator<<(ostream &ostream, const Node &n) {
    ostream << "["
        << n.begin << "_" << n.end << ","
        << n.length << ","
        << n.count << ","
        << "(";
    if (n._left != nullptr) ostream << *n._left;
    ostream << ",";
    if (n._right != nullptr) ostream << *n._right;
    ostream << ")]";

    return ostream;
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        auto minmax = minmax_element(nums.begin(), nums.end());
        auto n = Node(*minmax.first, *minmax.second);
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            n.push(*it);
            // cout << n << endl;
        }
        return n.count;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> input = {
        {1,3,5,4,7},
        {2,2,2,2,2},
        {},
        {1},
        {-100,-99,-98,-97,-96,-96}
    };
    for (auto it = input.begin(); it != input.end(); ++it) {
        cout << Solution().findNumberOfLIS(*it) << endl;
    }
}
