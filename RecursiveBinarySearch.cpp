#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::binarySearch(const std::vector<int>& sortedList, int start, int end, int item) {
    if(start > end) return false;
    int mid = (start + end) / 2;
    if(sortedList[mid] == item) return true;
    if(sortedList[mid] > item) return binarySearch(sortedList, start, mid - 1, item);
    return binarySearch(sortedList, mid + 1, end, item);
}

bool RecursiveBinarySearch::search(const std::vector<int>& sortedList, int item) {
    return binarySearch(sortedList, 0, sortedList.size() - 1, item);
}
