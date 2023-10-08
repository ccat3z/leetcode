#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        max_heap.emplace(price, timestamp);
        min_heap.emplace(price, timestamp);
        time2price[timestamp] = price;

        if (timestamp >= latest) {
            latest = timestamp;
            latest_price = price;
        }
    }
    
    int current() {
        return latest_price;
    }
    
    int maximum() {
        if (max_heap.empty())
            return 0;

        while (!max_heap.empty()) {
            auto & [price, time] = max_heap.top();
            if (time2price[time] == price)
                return price;
            max_heap.pop();
        }

        return 0;
    }
    
    int minimum() {
        if (min_heap.empty())
            return 0;

        while (!min_heap.empty()) {
            auto & [price, time] = min_heap.top();
            if (time2price[time] == price)
                return price;
            min_heap.pop();
        }

        return 0;
    }

    // heap of <price, time>
    std::priority_queue<std::pair<int, int>> max_heap;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;

    std::unordered_map<int, int> time2price;

    int latest = -1;
    int latest_price = 0;
};

#define PRINT(expr) std::cerr << #expr << ": " << expr << std::endl

int main() {
    StockPrice stockPrice;
    stockPrice.update(1, 10);  // 时间戳为 [1] ，对应的股票价格为 [10] 。
    stockPrice.update(2, 5);   // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
    PRINT(stockPrice.current());      // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
    PRINT(stockPrice.maximum());      // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
    stockPrice.update(1, 3);   // 之前时间戳为 1 的价格错误，价格更新为 3 。
                               // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
    PRINT(stockPrice.maximum());      // 返回 5 ，更正后最高价格为 5 。
    stockPrice.update(4, 2);   // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
    PRINT(stockPrice.minimum());      // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
    return 0;
}