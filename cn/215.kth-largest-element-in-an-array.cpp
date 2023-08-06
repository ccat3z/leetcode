#include "leetcode_helper.h"
#include <type_traits>
#include <vector>

class Solution {
public:
    //    0
    //  1   2
    // 3 4 5 6
    int findKthLargest(std::vector<int>& nums, int k) {
        auto & heap = nums;
        auto heap_size = nums.size();

        for (int i = heap_size / 2 - 1; i >= 0; --i) {
            adjust(heap, heap_size, i);
        }

        while (--k > 0) {
            --heap_size;
            heap[0] = heap[heap_size];
            adjust(heap, heap_size, 0);
        }

        return heap[0];
    }

    void adjust(std::vector<int>& heap, size_t heap_size, int i) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (i >= heap_size) return;
        if (l < heap_size && heap[l] > heap[largest]) {
            largest = l;
        }
        if (r < heap_size && heap[r] > heap[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            adjust(heap, heap_size, largest);
        }
    }

    int _(const std::vector<int>& nums, int k) {
        auto n = nums;
        auto res = findKthLargest(n, k);

        using namespace leetcode;
        std::cerr << n << std::endl;
        return res;
    }
};

int main() {
    LC_D(Solution::_);
    LC_T({3,2,1,5,6,4}, 2, 5);
    LC_T({3,2,3,1,2,4,5,5,6}, 4, 4);

    return 0;
}
