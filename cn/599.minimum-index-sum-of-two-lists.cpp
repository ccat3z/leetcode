/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 *
 * https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/description/
 *
 * algorithms
 * Easy (52.25%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 66.1K
 * Testcase Example:  '["Shogun","Tapioca Express","Burger King","KFC"]\n' +
  '["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]'
 *
 * 假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
 * 
 * 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 =
 * ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse",
 * "Shogun"]
 * 输出: ["Shogun"]
 * 解释: 他们唯一共同喜爱的餐厅是“Shogun”。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 =
 * ["KFC", "Shogun", "Burger King"]
 * 输出: ["Shogun"]
 * 解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= list1.length, list2.length <= 1000
 * 1 <= list1[i].length, list2[i].length <= 30 
 * list1[i] 和 list2[i] 由空格 ' ' 和英文字母组成。
 * list1 的所有字符串都是 唯一 的。
 * list2 中的所有字符串都是 唯一 的。
 * 
 * 
 */
#include "prettyprint.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> list1_idx;
        for (int i = 0; i < list1.size(); i++) {
            list1_idx[list1[i]] = i;
        }

        int min_idx_sum = 2000;
        int idx_sum;

        for (int j = 0; j < list2.size() && j <= min_idx_sum; j++) {
            auto list1_it = list1_idx.find(list2[j]);
            if (list1_it == list1_idx.end()) {
                continue;
            }

            idx_sum = list1_it->second + j;               
            if (idx_sum > min_idx_sum) {
                continue;
            }

            if (idx_sum < min_idx_sum) {
                min_idx_sum = idx_sum;
                res.clear();
            }
            
            res.emplace_back(list2[j]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<string> list1 = {"Shogun", "S", "Tapioca Express"}, list2 = {"S", "Shogun", "Piatti"};
    cout << Solution().findRestaurant(list1, list2) << endl;
    return 0;
}