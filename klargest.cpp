// klargest.cpp
#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    // Using a lambda to create a min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int val : values) {
        minHeap.push(val);
        
        // If heap size grows beyond k, we pop the smallest
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    if (minHeap.size() < k) {
        return -1; // indicating an error as kth largest is not present
    }
    return minHeap.top();  // Returns the kth largest element
}
