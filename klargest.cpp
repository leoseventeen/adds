// klargest.cpp
#include <vector>
#include <queue>

int kth_largest(const std::vector<int>& values, int k) {
    std::priority_queue<int> pq(values.begin(), values.end());

    for (int i = 1; i < k; ++i) {
        if (!pq.empty()) {
            pq.pop();
        } else {
            // This will handle the case when k is larger than the size of values
            return -1; // or some other indicator value
        }
    }

    if (!pq.empty()) {
        return pq.top();
    } else {
        return -1; // or some other indicator value
    }
}
