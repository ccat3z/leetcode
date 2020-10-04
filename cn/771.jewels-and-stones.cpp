/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 *
 * https://leetcode-cn.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (83.25%)
 * Likes:    590
 * Dislikes: 0
 * Total Accepted:    115K
 * Total Submissions: 135.9K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 *  给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
 * 
 * J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
 * 
 * 示例 1:
 * 
 * 输入: J = "aA", S = "aAAbbbb"
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: J = "z", S = "ZZ"
 * 输出: 0
 * 
 * 
 * 注意:
 * 
 * 
 * S 和 J 最多含有50个字母。
 * J 中的字符不重复。
 * 
 * 
 */
#include <string>
#include <tuple>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// @lc code=start
class Solution {
public:
    bitset<52> j;
    inline char code(char &c) {
        if (c <= 'Z') {
            return c - 'A' + 26;
        } else {
            return c - 'a';
        }
    }
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (char &c : J) {
            j[code(c)] = 1;
        }
        for (char &c : S) {
            if (j[code(c)]) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<string, string>> inputs = {
        {"aA", "aAAbbbb"},
        {"z", "ZZ"},
    };
    for (auto i : inputs) {
        string J, S;
        tie(J, S) = i;
        cout << Solution().numJewelsInStones(J, S) << endl;
    }
}