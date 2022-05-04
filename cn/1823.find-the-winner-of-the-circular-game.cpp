/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 *
 * https://leetcode-cn.com/problems/find-the-winner-of-the-circular-game/description/
 *
 * algorithms
 * Medium (72.74%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    26.3K
 * Total Submissions: 33.9K
 * Testcase Example:  '5\n2'
 *
 * 共有 n 名小伙伴一起做游戏。小伙伴们围成一圈，按 顺时针顺序 从 1 到 n 编号。确切地说，从第 i 名小伙伴顺时针移动一位会到达第 (i+1)
 * 名小伙伴的位置，其中 1  ，从第 n 名小伙伴顺时针移动一位会回到第 1 名小伙伴的位置。
 * 
 * 游戏遵循如下规则：
 * 
 * 
 * 从第 1 名小伙伴所在位置 开始 。
 * 沿着顺时针方向数 k 名小伙伴，计数时需要 包含 起始时的那位小伙伴。逐个绕圈进行计数，一些小伙伴可能会被数过不止一次。
 * 你数到的最后一名小伙伴需要离开圈子，并视作输掉游戏。
 * 如果圈子中仍然有不止一名小伙伴，从刚刚输掉的小伙伴的 顺时针下一位 小伙伴 开始，回到步骤 2 继续执行。
 * 否则，圈子中最后一名小伙伴赢得游戏。
 * 
 * 
 * 给你参与游戏的小伙伴总数 n ，和一个整数 k ，返回游戏的获胜者。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 5, k = 2
 * 输出：3
 * 解释：游戏运行步骤如下：
 * 1) 从小伙伴 1 开始。
 * 2) 顺时针数 2 名小伙伴，也就是小伙伴 1 和 2 。
 * 3) 小伙伴 2 离开圈子。下一次从小伙伴 3 开始。
 * 4) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 4 。
 * 5) 小伙伴 4 离开圈子。下一次从小伙伴 5 开始。
 * 6) 顺时针数 2 名小伙伴，也就是小伙伴 5 和 1 。
 * 7) 小伙伴 1 离开圈子。下一次从小伙伴 3 开始。
 * 8) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 5 。
 * 9) 小伙伴 5 离开圈子。只剩下小伙伴 3 。所以小伙伴 3 是游戏的获胜者。
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 6, k = 5
 * 输出：1
 * 解释：小伙伴离开圈子的顺序：5、4、6、2、3 。小伙伴 1 是游戏的获胜者。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
#include <iostream>
#include <queue>
using namespace std;
// REVIEW
// https://leetcode-cn.com/problems/find-the-winner-of-the-circular-game/solution/zhao-chu-you-xi-de-huo-sheng-zhe-by-leet-w2jd/
// https://leetcode-cn.com/circle/article/BOoxAL/

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        return findTheWinner_(n, k) + 1;
    }

    int findTheWinner_(int n, int k) {
        if (n == 1) return 0;

        return (findTheWinner_(n - 1, k) + k) % n;
    }
};
// @lc code=end

int main() {
    cout << Solution().findTheWinner(5, 2) << endl;
    cout << Solution().findTheWinner(6, 5) << endl;
    return 0;
}
