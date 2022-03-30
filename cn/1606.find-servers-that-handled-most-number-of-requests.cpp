/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 *
 * https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/description/
 *
 * algorithms
 * Hard (35.22%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 11.1K
 * Testcase Example:  '3\n[1,2,3,4,5]\n[5,2,3,3,3]'
 *
 * 你有 k 个服务器，编号为 0 到 k-1 ，它们可以同时处理多个请求组。每个服务器有无穷的计算能力但是 不能同时处理超过一个请求
 * 。请求分配到服务器的规则如下：
 * 
 * 
 * 第 i （序号从 0 开始）个请求到达。
 * 如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。
 * 如果第 (i % k) 个服务器空闲，那么对应服务器会处理该请求。
 * 否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。比方说，如果第 i
 * 个服务器在忙，那么会查看第 (i+1) 个服务器，第 (i+2) 个服务器等等。
 * 
 * 
 * 给你一个 严格递增 的正整数数组 arrival ，表示第 i 个任务的到达时间，和另一个数组 load ，其中 load[i] 表示第 i
 * 个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到 最繁忙的服务器 。最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。
 * 
 * 请你返回包含所有 最繁忙服务器 序号的列表，你可以以任意顺序返回这个列表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
 * 输出：[1] 
 * 解释：
 * 所有服务器一开始都是空闲的。
 * 前 3 个请求分别由前 3 台服务器依次处理。
 * 请求 3 进来的时候，服务器 0 被占据，所以它呗安排到下一台空闲的服务器，也就是服务器 1 。
 * 请求 4 进来的时候，由于所有服务器都被占据，该请求被舍弃。
 * 服务器 0 和 2 分别都处理了一个请求，服务器 1 处理了两个请求。所以服务器 1 是最忙的服务器。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
 * 输出：[0]
 * 解释：
 * 前 3 个请求分别被前 3 个服务器处理。
 * 请求 3 进来，由于服务器 0 空闲，它被服务器 0 处理。
 * 服务器 0 处理了两个请求，服务器 1 和 2 分别处理了一个请求。所以服务器 0 是最忙的服务器。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：k = 3, arrival = [1,2,3], load = [10,12,11]
 * 输出：[0,1,2]
 * 解释：每个服务器分别处理了一个请求，所以它们都是最忙的服务器。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
 * 输出：[1]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：k = 1, arrival = [1], load = [1]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * arrival.length == load.length
 * 1 
 * arrival 保证 严格递增 。
 * 
 * 
 */
// REVIEW: https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/solution/zhao-dao-chu-li-zui-duo-qing-qiu-de-fu-w-e0a5/#%E6%96%B9%E6%B3%95%E4%BA%8C%EF%BC%9A%E6%A8%A1%E6%8B%9F-%E5%8F%8C%E4%BC%98%E5%85%88%E9%98%9F%E5%88%97

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <tuple>
#include <set>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        const int size = arrival.size();
        vector<int> count(k, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;

        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.emplace(i);
        }

        for (int i = 0; i < size; ++i) {
            int &current = arrival[i];
            int arra_server = -1;

            while (!free_servers.empty() && free_servers.top().first <= current) {
                available.emplace(free_servers.top().second);
                free_servers.pop();
            }

            if (available.find(i % k) != available.end()) {
                arra_server = i % k;
            } else {
                auto p = available.lower_bound(i % k);
                if (p == available.end()) {
                    p = available.begin();

                    if (p == available.end()) {
                        continue;
                    }
                }
                arra_server = *p;
            }
            
            available.erase(arra_server);
            free_servers.emplace(current + load[i], arra_server);
            count[arra_server]++;
            // cout << "use " << arra_server << ' ' << available << endl;
        }

        vector<int> res;
        if (size == 0) return res;

        // cout << "find top " << k << endl;
        priority_queue<pair<int, int>> busy_servers;
        for (int i = 0; i < k; ++i) {
            busy_servers.emplace(count[i], i);
        }

        int busy_top = busy_servers.top().first;
        while (!busy_servers.empty() && busy_servers.top().first == busy_top) {
            res.push_back(busy_servers.top().second);
            busy_servers.pop();
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<tuple<int, vector<int>, vector<int>, vector<int>>> cases = {
        make_tuple(3, vector<int>{1, 2, 3, 4, 5}, vector<int>{5, 2, 3, 3, 3}, vector<int>{1}),
        make_tuple(3, vector<int>{1, 2, 3, 4}, vector<int>{1, 2, 1, 2}, vector<int>{0}),
        make_tuple(3, vector<int>{1, 2, 3}, vector<int>{10, 12, 11}, vector<int>{0, 1, 2}),
        make_tuple(3, vector<int>{1,2,3,4,8,9,10}, vector<int>{5,2,10,3,1,2,2}, vector<int>{1}),
        make_tuple(2, vector<int>{2,3,4,8}, vector<int>{3,2,4,3}, vector<int>{1}),
    };

    for (auto &c : cases) {
        int &k = get<0>(c);
        vector<int> &arrival = get<1>(c);
        vector<int> &load = get<2>(c);
        vector<int> &res = get<3>(c);
        cout << Solution().busiestServers(k, arrival, load) << '=' << res << " ("
             << k << ' '
             << arrival << ' '
             << load << ')' << endl;
    }
    return 0;
}