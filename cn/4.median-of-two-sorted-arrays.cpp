/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (37.05%)
 * Likes:    2261
 * Dislikes: 0
 * Total Accepted:    154K
 * Total Submissions: 415.7K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // nums1 [0, i-1] | [i, m - 1], slice: [i-1, i]
        // nums2 [0, j-1] | [j, n - 1], slice: [j-1, j]
        // 2(i + j) = m + n - (odd ? 1) => j = (m + n - (odd ? 1)) / 2 - i
        // i <- (0, m) & j <- (0, n) -> m - (odd ? 1) <= n -> m <= n

        // apply m <= n
        if (nums1.size() > nums2.size()) nums2.swap(nums1);
        int m = nums1.size(), n = nums2.size();

        // init i, j
        const int odd_fix = (m + n) % 2;
        int i_min = 0, i_max = m;
        int i, j;

        for (;;) {
            i = (i_min + i_max) / 2;
            j = (m + n - odd_fix) / 2 - i;
            // cout << i << ' ' << j << endl;
            if (i == 0) {
                if (m == 0) break;
                else if (m == 1) {
                    if (nums1[i] > nums2[j - 1]) break;
                    else i_min = 1;
                } else {
                    break;
                }
            } else if (i == m) {
                break;
            } else if (nums1[i - 1] > nums2[j]) { // j-1 j i-1 i
                // i <-
                i_max = i;
            } else if (nums1[i] < nums2[j - 1]) { // i-1 i j-1 j
                // i ->
                if (i == i_min) {
                    i_min = m;
                } else {
                    i_min = i;
                }
            } else { // ok!
                break;
            }
        }

        int a = max(i == 0 ? -1 : nums1[i - 1], j == 0 ? -1 : nums2[j - 1]);
        int b = min(i == m ? nums2[j] : nums1[i], j == n ? nums1[i] : nums2[j]);
        return odd_fix ? max(a, b) : ((double) (a + b) / 2);
    }
};
// @lc code=end

int main() {
    vector<int> nums1 = {1}, nums2 = {2, 3, 4};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

