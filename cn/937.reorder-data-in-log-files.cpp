/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 *
 * https://leetcode-cn.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (59.02%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    30.7K
 * Total Submissions: 48.6K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]'
 *
 * 给你一个日志数组 logs。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的 标识符 。
 * 
 * 有两种不同类型的日志：
 * 
 * 
 * 字母日志：除标识符之外，所有字均由小写字母组成
 * 数字日志：除标识符之外，所有字均由数字组成
 * 
 * 
 * 请按下述规则将日志重新排序：
 * 
 * 
 * 所有 字母日志 都排在 数字日志 之前。
 * 字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
 * 数字日志 应该保留原来的相对顺序。
 * 
 * 
 * 返回日志的最终顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3
 * art zero"]
 * 输出：["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3
 * 6"]
 * 解释：
 * 字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
 * 数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act
 * zoo"]
 * 输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 3 
 * logs[i] 中，字与字之间都用 单个 空格分隔
 * 题目数据保证 logs[i] 都有一个标识符，并且在标识符之后至少存在一个字
 * 
 * 
 */
#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<pair<string_view, string_view>> abc_logs;
        vector<string_view> num_logs;

        for (auto &log : logs) {
            int tag_size = 0;
            auto log_start = log.begin();
            for (; *log_start != ' '; log_start++) {
                tag_size++;
            }
            log_start++;

            if (find_if(log_start, log.end(), [](const char &it) {
                return '0' <= it && it <= '9';
            }) == log.end()) {
                abc_logs.emplace_back(string_view(log.c_str() + tag_size + 1), string_view(log.c_str(), tag_size));
            } else {
                num_logs.emplace_back(log);
            }
        }
        sort(abc_logs.begin(), abc_logs.end());

        for (auto &log : abc_logs) {
            res.emplace_back(log.second.data());
        }
        for (auto &log : num_logs) {
            res.emplace_back(log);
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<string> logs = {
        "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"
    };
    cout << Solution().reorderLogFiles(logs) << endl;
    return 0;
}