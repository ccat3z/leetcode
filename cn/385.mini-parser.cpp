/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 *
 * https://leetcode-cn.com/problems/mini-parser/description/
 *
 * algorithms
 * Medium (42.21%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 40K
 * Testcase Example:  '"324"'
 *
 * 给定一个字符串 s 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果 NestedInteger 。
 * 
 * 列表中的每个元素只可能是整数或整数嵌套列表
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "324",
 * 输出：324
 * 解释：你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "[123,[456,[789]]]",
 * 输出：[123,[456,[789]]]
 * 解释：返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
 * 1. 一个 integer 包含值 123
 * 2. 一个包含两个元素的嵌套列表：
 * ⁠   i.  一个 integer 包含值 456
 * ⁠   ii. 一个包含一个元素的嵌套列表
 * ⁠        a. 一个 integer 包含值 789
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s 由数字、方括号 "[]"、负号 '-' 、逗号 ','组成
 * 用例保证 s 是可解析的 NestedInteger
 * 输入中的所有值的范围是 [-10^6, 10^6]
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger() {};

    // Constructor initializes a single integer.
    NestedInteger(int value): val(value) {};

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) { val = value; };

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) { list.push_back(ni); };

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const { return list; };
    friend ostream &operator<<(ostream &os, const NestedInteger &ni);
private:
    int val = -1;
    vector<NestedInteger> list;
};

ostream &operator<<(ostream &os, const NestedInteger &ni) {
    os << ni.val << ",[";
    for (auto &child : ni.list) {
        os << child << ',';
    }
    os << ']';
    return os;
}


// @lc code=start
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ni;
        int at = 0;
        parseNestedInteger(s, at, ni);
        return ni;
    }

    bool parseNestedInteger(string &s, int &at, NestedInteger &ni) {
        // cout << "parseNestedInteger " << s.substr(at) << endl;
        if (parseList(s, at, ni)) {
            return true;
        }

        int i;
        parseInteger(s, at, i);
        ni.setInteger(i);
        return true;
    }

    bool parseInteger(string &s, int &at, int &res) {
        // cout << "parseInteger " << s.substr(at) << endl;
        res = 0;
        int is_minus = false;
        if (s[at] == '-') {
            is_minus = true;
            ++at;
        } else if (s[at] < '0' || '9' < s[at]) {
            return false;
        }

        while ('0' <= s[at] && s[at] <= '9') {
            res = res*10 + s[at] - '0';
            ++at;
        }
        if (is_minus) res = -res;
        return true;
    }

    bool parseList(string &s, int &at, NestedInteger &ni) {
        // cout << "parseList " << s.substr(at) << endl;
        if (s[at] != '[') return false;
        ++at;

        while (true) {
            if (s[at] == ']') {
                ++at;
                break;
            }
            if (s[at] == ',') ++at;

            NestedInteger next;
            parseNestedInteger(s, at, next);
            ni.add(next);
        }
        return true;
    }
};
// @lc code=end

int main() {
    cout << Solution().deserialize("256") << endl;
    cout << Solution().deserialize("-256") << endl;
    cout << Solution().deserialize("[1]") << endl;
    cout << Solution().deserialize("[1,2]") << endl;
    cout << Solution().deserialize("-3") << endl;
    return 0;
}
