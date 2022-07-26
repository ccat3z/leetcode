/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 *
 * https://leetcode-cn.com/problems/design-skiplist/description/
 *
 * algorithms
 * Hard (62.08%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    20.3K
 * Total Submissions: 29.8K
 * Testcase Example:  '["Skiplist","add","add","add","search","add","search","erase","erase","search"]\n' +
  '[[],[1],[2],[3],[0],[4],[1],[0],[1],[1]]'
 *
 * 不使用任何库函数，设计一个 跳表 。
 * 
 * 跳表 是在 O(log(n))
 * 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。
 * 
 * 例如，一个跳表包含 [30, 40, 50, 60, 70, 90] ，然后增加 80、45 到跳表中，以下图的方式操作：
 * 
 * 
 * Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons
 * 
 * 跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是
 * O(log(n))，空间复杂度是 O(n)。
 * 
 * 了解更多 : https://en.wikipedia.org/wiki/Skip_list
 * 
 * 在本题中，你的设计应该要包含这些函数：
 * 
 * 
 * bool search(int target) : 返回target是否存在于跳表中。
 * void add(int num): 插入一个元素到跳表。
 * bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num
 * ，删除其中任意一个即可。
 * 
 * 
 * 注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入
 * ["Skiplist", "add", "add", "add", "search", "add", "search", "erase",
 * "erase", "search"]
 * [[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
 * 输出
 * [null, null, null, null, false, null, true, false, true, false]
 * 
 * 解释
 * Skiplist skiplist = new Skiplist();
 * skiplist.add(1);
 * skiplist.add(2);
 * skiplist.add(3);
 * skiplist.search(0);   // 返回 false
 * skiplist.add(4);
 * skiplist.search(1);   // 返回 true
 * skiplist.erase(0);    // 返回 false，0 不在跳表中
 * skiplist.erase(1);    // 返回 true
 * skiplist.search(1);   // 返回 false，1 已被擦除
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 <= num, target <= 2 * 10^4
 * 调用search, add,  erase操作次数不大于 5 * 10^4 
 * 
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// @lc code=start
#define SKIP_LIST_LAYER_SIZE 4
class Skiplist {
public:
    class Node;
    class Node {
    public:
        explicit Node(int i) : i(i) {};
        int i;
        Node *next = nullptr;
        Node *down = nullptr;
    };

    Node *layers[SKIP_LIST_LAYER_SIZE];
    int p[SKIP_LIST_LAYER_SIZE];

    Skiplist() {
        std::srand(std::time(nullptr));
        for (int i = 0; i < SKIP_LIST_LAYER_SIZE; i++) {
            layers[i] = new Node(-1);
            if (i != 0) {
                layers[i-1]->down = layers[i];
            }
        }

        p[SKIP_LIST_LAYER_SIZE-1] = 100;
        for (int i = SKIP_LIST_LAYER_SIZE - 2; i >= 0; i--) {
            p[i] = p[i+1] * 0.25;
        }
    }

    inline Node *find_pre(int num, Node *it) {
        for (; it->next != nullptr && it->next->i < num; it = it->next);
        // std::cout << it << std::endl;
        return it;
    }

    inline Node *find_pre(int num, int layer) {
        return find_pre(num, layers[layer]);
    }
    
    bool search(int target) {
        auto *pre = find_pre(target, 0);

        for (;;) {
            if (pre->next && pre->next->i == target) {
                return true;
            } else if (pre->down == nullptr) {
                return false;
            } else {
                pre = find_pre(target, pre->down);
            }
        }

        return false;
    }
    
    void add(int num) {
        add(num, 0, nullptr);
    }

    void add(int num, int layer, Node **upper) {
        if (layer >= SKIP_LIST_LAYER_SIZE) return;

        auto *it = find_pre(num, layer);

        if (upper || (std::rand() % 100) < p[layer]) {
            auto *next = it->next;
            it->next = new Node(num);
            it->next->next = next;
            add(num, layer+1, &it->next->down);

            if (upper) {
                *upper = it->next;
            }
        } else {
            add(num, layer+1, nullptr);
        }
    }
    
    bool erase(int num) {
        auto *pre = find_pre(num, layers[0]);
        bool deleted = false;

        for (;;) {
            if (pre->next && pre->next->i == num) {
                auto *next = pre->next->next;

                delete pre->next;
                pre->next = next;

                deleted = true;
            }
            
            if (pre->down == nullptr) {
                break;
            } else {
                pre = find_pre(num, pre->down);
            }
        }

        return deleted;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end

std::ostream &operator<<(std::ostream &os, Skiplist &list) {
    for (int i = 0; i < SKIP_LIST_LAYER_SIZE; i++) {
        os << list.p[i] << " [";
        for (auto *it = list.layers[i]; it; it = it->next) {
            os << it->i
               << '(' << it << "->" << it->down << ')'
               << ',';
        }
        os << ']' << std::endl;
    }
    return os;
}

int main() {
    Skiplist l;
    l.add(1);
    l.add(1);
    l.add(10);
    l.add(3);
    // for (int i = 0; i < 100; i++) {
    //     l.add(5);
    // }
    std::cout << l << std::endl;

    std::vector<int> deleted = {1, 1, 1, 4};
    for (auto &target : deleted) {
        std::cout << "DEL " << target << ' ' << l.erase(target) << std::endl;
        // std::cout << l << std::endl;
    }

    std::vector<int> search = {10};
    for (auto &target : search) {
        std::cout << "SER " << target << ' ' << l.search(target) << std::endl;
    }

    return 0;
}