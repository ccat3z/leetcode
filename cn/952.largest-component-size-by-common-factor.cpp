/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 *
 * https://leetcode-cn.com/problems/largest-component-size-by-common-factor/description/
 *
 * algorithms
 * Hard (36.71%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 28.4K
 * Testcase Example:  '[4,6,15,35]'
 *
 * 给定一个由不同正整数的组成的非空数组 nums ，考虑下面的图：
 * 
 * 
 * 有 nums.length 个节点，按从 nums[0] 到 nums[nums.length - 1] 标记；
 * 只有当 nums[i] 和 nums[j] 共用一个大于 1 的公因数时，nums[i] 和 nums[j]之间才有一条边。
 * 
 * 
 * 返回 图中最大连通组件的大小 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：nums = [4,6,15,35]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：nums = [20,50,9,63]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：nums = [2,3,6,7,4,12,21,39]
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] <= 10^5
 * nums 中所有值都 不同
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        parent.reserve(max_num + 1);
        rank.reserve(max_num + 1);
        for (int i = 0; i <= max_num; i++) {
            parent.emplace_back(i);
            rank.emplace_back(0);
        }

        for (auto &num : nums) {
            for (int i = 2; i * i <= num; i++) {
                if (num % i != 0) continue;

                merge(num, i);
                merge(num, num / i);
            }
        }

        map<int, int> counter;
        for (auto &num : nums) {
            counter[find(num)]++;
        }

        int max_group = -1;
        for (auto &[k, v] : counter) {
            max_group = max(max_group, v);
        }
        return max_group;
    }
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        while (parent[x] != x)
            x = parent[x];

        return x;
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums = {20,50,9,63};
    cout << Solution().largestComponentSize(nums) << endl;
    return 0;
}