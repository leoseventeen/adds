// klargest.cpp
#include <vector>
#include <queue>

int kth_largest(const std::vector<int>& values, int k) {
    // priority_queue by default uses max-heap
    // We need a min-heap to efficiently get kth largest
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    for (int val : values) {
        min_heap.push(val);
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }
    return min_heap.top();
}
