#include "QuickSort.h"

int QuickSort::partition(std::vector<int>& list, int left, int right) {
    int pivotValue;
    if(right - left + 1 >= 3) {
        pivotValue = list[left + 2]; // third element as pivot
    } else {
        pivotValue = list[right];    // fall back to the last element if there are fewer than 3 elements
    }
    
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
