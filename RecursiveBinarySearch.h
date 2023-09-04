#pragma once
#include <vector>

class RecursiveBinarySearch {
private:
    bool binarySearch(const std::vector<int>& sortedList, int start, int end, int item);

public:
    bool search(const std::vector<int>& sortedList, int item);
};
