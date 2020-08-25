/*
 * @lc app=leetcode.cn id=1125 lang=cpp
 *
 * [1125] 最小的必要团队
 *
 * https://leetcode-cn.com/problems/smallest-sufficient-team/description/
 *
 * algorithms
 * Hard (45.25%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 4K
 * Testcase Example:  '["java","nodejs","reactjs"]\n[["java"],["nodejs"],["nodejs","reactjs"]]'
 *
 * 作为项目经理，你规划了一份需求的技能清单 req_skills，并打算从备选人员名单 people 中选出些人组成一个「必要团队」（ 编号为 i
 * 的备选人员 people[i] 含有一份该备选人员掌握的技能列表）。
 * 
 * 所谓「必要团队」，就是在这个团队中，对于所需求的技能列表 req_skills 中列出的每项技能，团队中至少有一名成员已经掌握。
 * 
 * 我们可以用每个人的编号来表示团队中的成员：例如，团队 team = [0, 1, 3] 表示掌握技能分别为 people[0]，people[1]，和
 * people[3] 的备选人员。
 * 
 * 请你返回 任一 规模最小的必要团队，团队成员用人员编号表示。你可以按任意顺序返回答案，本题保证答案存在。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：req_skills = ["java","nodejs","reactjs"], people =
 * [["java"],["nodejs"],["nodejs","reactjs"]]
 * 输出：[0,2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
 * people =
 * [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= req_skills.length <= 16
 * 1 <= people.length <= 60
 * 1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
 * req_skills 和 people[i] 中的元素分别各不相同
 * req_skills[i][j], people[i][j][k] 都由小写英文字母组成
 * 本题保证「必要团队」一定存在
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <unordered_map>
#include "prettyprint.h"
using namespace std;

// REVIEW:
// @lc code=start
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        uint16_t skills;
        vector<uint16_t> peoples;
        unordered_map<string, int> skill_map;
        for (int i = 0; i < req_skills.size(); ++i) {
            skills |= 1<<i;
            skill_map[req_skills[i]] = i;
        }
        for_each(people.begin(), people.end(), [&](vector<string> &p) {
            uint64_t ts = 0;
            for_each(p.begin(), p.end(), [&](string &s) {
                ts |= 1<<(skill_map[s]);
            });
            peoples.push_back(ts);
        });

        // f(sk, ps:p) = max(f(sk & ~p, ps) + 1, f(sk, ps))
        //        sk == 0 => 0
        // size(ps:p) == 0 => INF(61)
        // val, last_state
        #define INF (61)
        tuple<int, int> dp[skills + 1][people.size()];
        for (int sk = 0; sk <= skills; ++sk) {
            for (int p = 0; p < peoples.size(); ++p) {
                int with_p, without_p;
                int sk_without_p = sk & ~peoples[p];
                if (sk == 0) {
                    without_p = 0;
                    with_p = INF;
                } else {
                    if (p != 0) {
                        with_p = get<0>(dp[sk_without_p][p-1]) + 1;
                        without_p = get<0>(dp[sk][p-1]);
                        if (with_p > INF) with_p = INF;
                    } else {
                        with_p = sk_without_p == 0 ? 1 : INF;
                        without_p = INF;
                    }
                }
                if (with_p < without_p) {
                    dp[sk][p] = make_tuple(with_p, sk_without_p);
                } else {
                    dp[sk][p] = make_tuple(without_p, sk);
                }
                cout << dp[sk][p] << ' ';
            }
            cout << endl;
        }

        vector<int> res(get<0>(dp[skills][peoples.size() - 1]));
        int curSkill = skills, p = peoples.size() - 1;
        for (auto it = res.rbegin(); it != res.rend();) {
            int &nextSkill = get<1>(dp[curSkill][p]);
            if (nextSkill != curSkill) *(it++) = p;
            curSkill = nextSkill;
            --p;
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<string>, vector<vector<string>>>> inputs = {
        make_tuple(vector<string>({"java","nodejs","reactjs"}), vector<vector<string>>({{"java"},{"nodejs"},{"nodejs","reactjs"}})),
        make_tuple(vector<string>({"algorithms","math","java","reactjs","csharp","aws"}), vector<vector<string>>({{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}}))
    };
    for_each(inputs.begin(), inputs.end(), [](tuple<vector<string>, vector<vector<string>>> &t) {
        cout << Solution().smallestSufficientTeam(get<0>(t), get<1>(t)) << endl;
    });
    return 0;
}