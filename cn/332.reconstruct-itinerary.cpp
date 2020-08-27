/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 *
 * https://leetcode-cn.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (38.76%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 43.8K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * 给定一个机票的字符串二维数组 [from,
 * to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从
 * JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
 * 
 * 说明:
 * 
 * 
 * 如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"]
 * 相比就更小，排序更靠前
 * 所有的机场都用三个大写字母表示（机场代码）。
 * 假定所有机票至少存在一种合理的行程。
 * 
 * 
 * 示例 1:
 * 
 * 输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * 输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * 输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * 解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。
 * 
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> res;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> tickets;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for_each(tickets.begin(), tickets.end(), [&](vector<string> &t) {
            this->tickets[t[0]].push(t[1]);
        });
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(const string &start) {
        unordered_multimap<string, string>::iterator it;
        string to;
        auto &ticket = tickets[start];
        while (!ticket.empty()) {
            to = ticket.top();
            ticket.pop();
            dfs(to);
        }
        res.push_back(start);
    }
};
// @lc code=end

int main() {
    vector<vector<vector<string>>> inputs = {
        {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}},
        {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}
    };
    for_each(inputs.begin(), inputs.end(), [&](vector<vector<string>> &i) {
        cout << Solution().findItinerary(i) << endl;
    });
}