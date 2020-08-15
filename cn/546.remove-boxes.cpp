/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 *
 * https://leetcode-cn.com/problems/remove-boxes/description/
 *
 * algorithms
 * Hard (51.13%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 14.8K
 * Testcase Example:  '[1,3,2,2,2,3,4,3,1]\r'
 *
 * 给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
 * 你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k*k
 * 个积分。
 * 当你将所有盒子都去掉之后，求你能获得的最大积分和。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：boxes = [1,3,2,2,2,3,4,3,1]
 * 输出：23
 * 解释：
 * [1, 3, 2, 2, 2, 3, 4, 3, 1] 
 * ----> [1, 3, 3, 4, 3, 1] (3*3=9 分) 
 * ----> [1, 3, 3, 3, 1] (1*1=1 分) 
 * ----> [1, 1] (3*3=9 分) 
 * ----> [] (2*2=4 分)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= boxes.length <= 100
 * 1 <= boxes[i] <= 100
 * 
 * 
 */
// REVIEW

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    Solution () {
        fill(&cache[0][0][0], &cache[99][99][100], 0);
    }
    int removeBoxes(vector<int>& boxes) {
        return removeBoxes(boxes, 0, boxes.size() - 1, 0);
    }
private:
    // 1,3,2,2,2,3,3,4,3,(1)
    //   ^       ^
    //   from:1  end:5   follow boxes[end]:1
    int removeBoxes(vector<int>& boxes, int from, int end, int follow) {
        int &result = cache[from][end][follow];
        if (result != 0) return result;
        cout << from << ' ' << end << ' ' << follow << endl;
        if (from == end) {
            result = (follow + 1) * (follow + 1);
        } else {
            result = removeBoxes(boxes, from, end - 1, 0) + (follow + 1) * (follow + 1);
        }
        for (int i = from; i < end; ++i) {
            if (boxes[i] == boxes[end]) {
                result = max(
                    result,
                    // 1,3,2,2,2,3,3,(4),3,(1)
                    // f i x   x e
                    removeBoxes(boxes, from, i, follow + 1) + (i + 1 != end ? removeBoxes(boxes, i + 1, end - 1, 0) : 0)
                );
            }
        }
        return result;
    }
    int cache[100][100][100];
};
// @lc code=end

int main() {
    vector<vector<int>> cases = {
       {1,3,2,2,2,3,4,3,1}
    };
    for (auto it = cases.begin(); it != cases.end(); ++it) {
        cout << Solution().removeBoxes(*it) << endl;
    }
    return 0;
}
