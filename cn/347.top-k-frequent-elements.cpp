/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.62%)
 * Likes:    498
 * Dislikes: 0
 * Total Accepted:    102.1K
 * Total Submissions: 165.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 * 你可以按任意顺序返回答案。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) return vector<int>();
        unordered_map<int, int> o; for (auto &it : nums) o[it]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<tuple<int, int>>> q;

        for (auto &it : o) {
            const int &num = it.first;
            const int &freq = it.second;
            if (q.size() < k) q.emplace(freq, num);
            else {
                if (it.second > q.top().first) {
                    q.pop();
                    q.emplace(freq, num);
                } 
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.emplace_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<vector<int>, int>> inputs = {
        make_tuple(vector<int>({1,1,1,2,2,3}), 2),
        make_tuple(vector<int>({1}), 1),
        make_tuple(vector<int>({5,2,5,3,5,3,1,1,3}), 2),
    };
    for (auto &t : inputs) {
        cout << Solution().topKFrequent(get<0>(t), get<1>(t)) << endl;
    }
}