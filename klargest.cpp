// klargest.cpp
#include <vector>
#include <queue>

int kth_largest(const std::vector<int>& values, int k) {
    std::priority_queue<int> pq(values.begin(), values.end());

    for (int i = 1; i < k; ++i) {
        pq.pop();
    }

    return pq.top();
}
