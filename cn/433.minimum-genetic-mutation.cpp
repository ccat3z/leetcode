/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 *
 * https://leetcode-cn.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (53.45%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 57.6K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
 * 
 * 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
 * 
 * 
 * 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
 * 
 * 
 * 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。
 * 
 * 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end
 * 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
 * 
 * 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：start = "AACCGGTT", end = "AAACGGTA", bank =
 * ["AACCGGTA","AACCGCTA","AAACGGTA"]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：start = "AAAAACCC", end = "AACCCCCC", bank =
 * ["AAAACCCC","AAACCCCC","AACCCCCC"]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * start.length == 8
 * end.length == 8
 * 0 <= bank.length <= 10
 * bank[i].length == 8
 * start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
 * 
 * 
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <queue>
#include <cassert>
#include <string_view>
#include <list>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool near(string_view &a, string_view &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) continue;

            ++diff;
            if (diff > 1) return false;
        }
        assert(diff > 0);
        return true;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        int level = 0;

        list<string_view> bankset(bank.begin(), bank.end());
        queue<string_view> path;
        path.push(start);

        while (!path.empty()) {
            int size = path.size();
            level += 1;

            while (size-- > 0) {
                string_view &from = path.front();
                for (auto next = bankset.begin(); next != bankset.end();) {
                    if (*next == from) {
                        bankset.erase(next++);
                    }

                    if (!near(from, *next)) {
                        ++next;
                        continue;
                    }

                    if (*next == end) return level;

                    path.emplace(*next);
                    bankset.erase(next++);
                }
                path.pop();
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    vector<tuple<string, string, vector<string>, int>> tests = {
        {"AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1},
        {"AACCGGTT", "AAACGGTA", {"AACCGGTA","AACCGCTA","AAACGGTA"}, 2},
        {"AAAAACCC", "AACCCCCC", {"AAAACCCC","AAACCCCC","AACCCCCC"}, 3},
        {"AAAAAAAA", "CCCCCCCC", {"AAAAAAAA"}, -1}
    };
    for (auto &[start, end, bank, res] : tests) {
        cout << Solution().minMutation(start, end, bank) << "=" << res << endl;
    }
    return 0;
}