#include "leetcode_helper.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template <class T>
std::ostream &operator<<(std::ostream &o, const std::vector<T> & vec) {
    o << "[";
    for (const auto & t : vec) {
        o << t << ",";
    }
    o << "]";
    return o;
}

class Solution {
public:
    vector<string> topKFrequent(const vector<string>& words, int k) {
        std::unordered_map<std::string, int> cnt;
        for (const auto & word : words) {
            ++cnt[word];
        }

        MinHeap heap(k);
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            heap.insert({it});
        }

        std::sort(heap.items.begin(), heap.items.end(), std::greater<HeapItem>());

        std::vector<std::string> res;
        for (const auto & item : heap.items) {
            res.emplace_back(item.word());
        }
        return res;
    }

    struct HeapItem {
        std::unordered_map<std::string, int>::const_iterator it;
        // std::string word;
        // int size;

        const std::string &word() const {
            return it->first;
        }

        const int size() const {
            return it->second;
        }

        bool operator<(const HeapItem & other) const {
            if (size() == other.size()) {
                return word() > other.word();
            }

            return size() < other.size();
        }

        bool operator>(const HeapItem & other) const {
            if (size() == other.size()) {
                return word() < other.word();
            }

            return size() > other.size();
        }
    };

    struct MinHeap {
        std::vector<HeapItem> items;
        int size;

        MinHeap(int n) : size(n) {
            items.reserve(n);
        }

        void insert(const HeapItem & item) {
            if (items.size() == size) {
                if (item > items[0]) {
                    items[0] = item;
                    // std::cerr << '#' << items << std::endl;
                    build(0);
                }
            } else if (items.empty()) {
                items.emplace_back(item);
            } else {
                items.emplace_back(item);
                int curr = items.size() - 1;
                while (curr > 0) {
                    int parent = (curr - 1) / 2;

                    if (items[curr] < items[parent]) {
                        std::swap(items[curr], items[parent]);
                    }

                    curr = parent;
                }
            }
            // std::cerr << items << std::endl;
        }

        void build(int idx) {
            if (idx >= items.size()) return;

            int left = (idx + 1) * 2 - 1;
            int right = left + 1;
            int min = idx;

            if (left < items.size() && items[left] < items[min]) {
                min = left;
            }
            if (right < items.size() && items[right] < items[min]) {
                min = right;
            }

            if (min == idx) return;

            // std::cerr << idx << ' ' << left << ' ' << right << ' ' << min << std::endl;
            std::swap(items[min], items[idx]);
            build(left);
            build(right);
        }
    };
};

std::ostream &operator<<(std::ostream &o, const Solution::HeapItem & it) {
    return o << "<" << it.word() << "," << it.size() << ">";
}

int main() {
    LC_D(Solution::topKFrequent);
    LC_T({"i", "love", "leetcode", "i", "love", "coding"}, 2, {"i", "love"});
    LC_T({"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4, {"the", "is", "sunny", "day"});
    LC_T({"i","love","leetcode","i","love","coding"}, 3, {"i","love","coding"});
    LC_T({"aaa", "aa", "a"}, 1, {"a"});
    LC_T({"vbimix","ztj","ztj","vbimix","zgoedv","itnsxvvevu","bftirwsc","nlv","ithxcskb","walxnr","amkjox","ehzbw","ithxcskb","bftirwsc","amkjox","vbimix","ztj","amkjox","itnsxvvevu","ithxcskb","oveunzoevl","bdqinoduvu","tfbpcjj","itnsxvvevu","vbimix","tfbpcjj","rllqmb","iwj","iwj","ithxcskb","ehzbw","ehzbw","bdqinoduvu","vbimix","ithxcskb","ithxcskb","ehzbw","iwj","bdqinoduvu","nlv","tfbpcjj","nlv","ehzbw","ztj","ztj","tfbpcjj","oveunzoevl","itnsxvvevu","amkjox","vbimix","itnsxvvevu","ehzbw","iwj","rllqmb","itnsxvvevu","ehzbw","iwj","tfbpcjj","amkjox","vbimix","itnsxvvevu","amkjox","nlv","tfbpcjj","nlv","ztj","iwj","bftirwsc","bdqinoduvu","zgoedv","ithxcskb","itnsxvvevu","vbimix","walxnr","amkjox","bftirwsc","vbimix","itnsxvvevu","tfbpcjj","bdqinoduvu","ithxcskb","ithxcskb","ztj","bftirwsc","iwj","bftirwsc","tfbpcjj","ehzbw","ehzbw","amkjox","ztj","itnsxvvevu","zgoedv","nlv"}, 14, {"itnsxvvevu","ehzbw","ithxcskb","vbimix","amkjox","tfbpcjj","ztj","iwj","bftirwsc","nlv","bdqinoduvu","zgoedv","oveunzoevl","rllqmb"});
    return 0;
}