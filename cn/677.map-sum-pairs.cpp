/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 *
 * https://leetcode-cn.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (60.61%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 14K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n' +
  '[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * 实现一个 MapSum 类里的两个方法，insert 和 sum。
 * 
 * 对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。
 * 
 * 对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。
 * 
 * 示例 1:
 * 
 * 输入: insert("apple", 3), 输出: Null
 * 输入: sum("ap"), 输出: 3
 * 输入: insert("app", 2), 输出: Null
 * 输入: sum("ap"), 输出: 5
 * 
 * 
 */
#include <string>
#include <iostream>
#include <tuple>
#include <algorithm>
#include "prettyprint.h"
using namespace std;

// @lc code=start
#define MAX_NODE_SIZE (100)
class MapSum {
public:
    // count, next
    tuple<int, int[26]> node[MAX_NODE_SIZE];
    int max_node = 0;

    MapSum() {

    }

    int find(string key) {
        int at = 0;
        for_each(key.begin(), key.end(), [&](char &c) {
            int &next = get<1>(node[at])[c - 'a'];
            if (next == 0) next = ++max_node;

            at = next;
        });
        int res = get<0>(node[at]);
        int (&next)[26] = get<1>(node[at]);
        for_each(next, next+26, [&](int &i) {
            if (i != 0) res -= get<0>(node[i]);
        });
        return res;
    }
    
    void insert(string key, int val) {
        int at = 0;
        val -= find(key);
        for_each(key.begin(), key.end(), [&](char &c) {
            int &next = get<1>(node[at])[c - 'a'];
            if (next == 0) next = ++max_node;

            at = next;
            get<0>(node[at]) += val;
        });
    }
    
    int sum(string prefix) {
        int at = 0;
        for (auto c = prefix.begin(); c != prefix.end(); ++c) {
            int &next = get<1>(node[at])[*c - 'a'];
            if (next == 0) return 0;

            at = next;
        }
        return get<0>(node[at]);
    }
};
// @lc code=end

int main() {
    MapSum *obj = new MapSum();
    obj->insert("aa",3);
    cout << obj->sum("a") << endl;
    obj->insert("aa",2);
    cout << obj->sum("a") << endl;
}

