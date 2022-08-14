/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 *
 * https://leetcode-cn.com/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (53.13%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 57.2K
 * Testcase Example:  '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计实现双端队列。
 * 
 * 实现 MyCircularDeque 类:
 * 
 * 
 * MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
 * boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
 * boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
 * boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
 * boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
 * int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
 * int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
 * boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
 * boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入
 * ["MyCircularDeque", "insertLast", "insertLast", "insertFront",
 * "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
 * [[3], [1], [2], [3], [4], [], [], [], [4], []]
 * 输出
 * [null, true, true, true, false, 2, true, true, true, 4]
 * 
 * 解释
 * MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
 * circularDeque.insertLast(1);                    // 返回 true
 * circularDeque.insertLast(2);                    // 返回 true
 * circularDeque.insertFront(3);                    // 返回 true
 * circularDeque.insertFront(4);                    // 已经满了，返回 false
 * circularDeque.getRear();                  // 返回 2
 * circularDeque.isFull();                        // 返回 true
 * circularDeque.deleteLast();                    // 返回 true
 * circularDeque.insertFront(4);                    // 返回 true
 * circularDeque.getFront();                // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= 1000
 * 0 <= value <= 1000
 * insertFront, insertLast, deleteFront, deleteLast, getFront, getRear,
 * isEmpty, isFull  调用次数不大于 2000 次
 * 
 * 
 */
#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;

// @lc code=start
class MyCircularDeque {
public:
    MyCircularDeque(int k) : cap(k), data(k, 0) { }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        data[idx(--begin)] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        data[idx(end++)] = value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        ++begin;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        --end;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return data[idx(begin)];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return data[idx(end - 1)];
    }
    
    inline bool isEmpty() {
        return end == begin;
    }
    
    inline bool isFull() {
        return end - begin == cap;
    }

    inline int idx(int i) {
        int idx = i % cap;
        if (idx < 0) {
            idx += cap;
        }
        return idx;
    }

    vector<int> data;
    int begin = 0;
    int end = 0;
    int cap;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

int main() {
    MyCircularDeque* obj = new MyCircularDeque(5);
    cout << obj->insertFront(1) << endl;
    cout << obj->data << ',' << obj->begin << ',' << obj->end << endl;
    cout << obj->insertLast(2) << endl;
    cout << obj->data << ',' << obj->begin << ',' << obj->end << endl;
    cout << obj->deleteFront() << endl;
    cout << obj->data << ',' << obj->begin << ',' << obj->end << endl;
    cout << obj->deleteLast() << endl;
    cout << obj->data << ',' << obj->begin << ',' << obj->end << endl;
    cout << obj->getFront() << endl;
    cout << obj->getRear() << endl;
    cout << obj->isEmpty() << endl;
    cout << obj->isFull() << endl;
    return 0;
}