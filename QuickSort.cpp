#include "QuickSort.h"

void QuickSort::quicksort(std::vector<int>& list, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(list, left, right);
        quicksort(list, left, pivotIndex - 1);
        quicksort(list, pivotIndex + 1, right);
    }
}

int QuickSort::partition(std::vector<int>& list, int left, int right) {
    int pivotValue = list[left + 2]; // third element as pivot
    int i = left, j = right;
    while(i <= j) {
        while(list[i] < pivotValue) i++;
        while(list[j] > pivotValue) j--;
        if(i <= j) {
            std::swap(list[i], list[j]);
            i++;
            j--;
        }
    }
    return i;
}

std::vector<int> QuickSort::sort(const std::vector<int>& list) {
    std::vector<int> result = list;
    quicksort(result, 0, result.size() - 1);
    return result;
}
