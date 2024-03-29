/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (52.48%)
 * Likes:    444
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 83.2K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给你一个数组 nums ，请你完成两类查询。
 * 
 * 
 * 其中一类查询要求 更新 数组 nums 下标对应的值
 * 另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
 * 
 * 
 * 实现 NumArray 类：
 * 
 * 
 * NumArray(int[] nums) 用整数数组 nums 初始化对象
 * void update(int index, int val) 将 nums[index] 的值 更新 为 val
 * int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含
 * ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * 输出：
 * [null, 9, null, 8]
 * 
 * 解释：
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * 调用 update 和 sumRange 方法次数不大于 3 * 10^4 
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums) {
        bittree.reserve(nums.size());
        for (auto _ : nums) bittree.push_back(0);

        for (int i = 0; i < nums.size(); ++i) {
            add(i, nums[i]);
        }
    }

    void add(int index, int val) {
        ++index;
        while (index <= nums.size()) {
            bittree[index-1] += val;
            index += index & -index;
        }
    }
    
    void update(int index, int val) {
        add(index, val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sumPrefix(right) - sumPrefix(left - 1);
    }

    int sumPrefix(int index) {
        int res = 0;
        ++index;
        while (index) {
            res += bittree[index-1];
            index -= index & -index;
        }
        return res;
    }

    vector<int> &nums;
    vector<int> bittree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    vector<int> nums{1, 3, 5};
    NumArray na(nums);

    cout << na.nums << ' ' << na.bittree << endl;
    cout << "sumRange(0, 2) = " << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << "sumRange(0, 2) = " << na.sumRange(0, 2) << endl;
    return 0;
}
