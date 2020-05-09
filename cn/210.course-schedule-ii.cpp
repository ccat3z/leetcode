/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 *
 * https://leetcode-cn.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (46.51%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 45.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 
 * 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
 * 
 * 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: [0,1]
 * 解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
 * 
 * 示例 2:
 * 
 * 输入: 4, [[1,0],[2,0],[3,1],[3,2]]
 * 输出: [0,1,2,3] or [0,2,1,3]
 * 解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
 * 因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
 * 
 * 
 * 说明:
 * 
 * 
 * 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 
 * 
 * 提示:
 * 
 * 
 * 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
 * 通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
 * 
 * 拓扑排序也可以通过 BFS 完成。
 * 
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

// @lc code=start
class Solution {
private:
    char **deps;
    char *learned;
    vector<int> courses;
    int course_num;
    int *in_stack;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        course_num = numCourses;

        // dfs环路探测
        in_stack = new int[numCourses];
        memset(in_stack, 0, sizeof(int) * numCourses);

        // 课程列表
        courses.reserve(numCourses);

        // 记录入度
        int required[numCourses];
        memset(required, 0, sizeof(int) * numCourses);

        // 初始化边矩阵
        deps = new char*[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            deps[i] = new char[numCourses];
            memset(deps[i], 0, sizeof(char) * numCourses);
        }
        for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it) {
            deps[(*it)[0]][(*it)[1]] = 1;
            ++required[(*it)[1]];
        }

        // 初始化已访问记录
        learned = new char[numCourses];
        memset(learned, 0, sizeof(char) * numCourses);

        // 学习没有被依赖的课程
        for (int i = 0; i < numCourses; ++i) {
            if (required[i] == 0) {
                if (!learn(i)) {
                    return vector<int>();
                }
            }
        }

        // 没学完
        if (courses.size() != course_num) {
            return vector<int>();
        }

        return courses;
    }
    
    bool learn(int c) {
        if (learned[c] == 1) return true;

        in_stack[c] = 1;

        for (int i = 0; i < course_num; ++i) {
            if (deps[c][i] == 1) {
                if (in_stack[i]) {
                    return false;
                }
                learn(i);
            }
        }

        in_stack[c] = 0;
        learned[c] = 1;
        courses.push_back(c);
        return true;
    }
};
// @lc code=end

void print_vector(vector<int> v) {
    cout << '[';
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it;
        if (it != v.end() - 1) {
            cout << ", ";
        }
    }
    cout << ']' << endl;
}

int main() {
    vector<vector<int>> ps;
    ps.push_back(vector<int>({1, 0}));
    print_vector(Solution().findOrder(2, ps));
    ps.push_back(vector<int>({2, 0}));
    ps.push_back(vector<int>({3, 1}));
    ps.push_back(vector<int>({3, 2}));
    print_vector(Solution().findOrder(4, ps));
    ps.push_back(vector<int>({2, 3}));
    print_vector(Solution().findOrder(4, ps));

    vector<vector<int>> ps2;
    ps2.push_back(vector<int>({0, 2}));
    ps2.push_back(vector<int>({1, 2}));
    ps2.push_back(vector<int>({2, 0}));
    print_vector(Solution().findOrder(3, ps2));
}