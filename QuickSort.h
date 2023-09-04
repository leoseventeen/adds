#pragma once
#include "Sort.h"

class QuickSort : public Sort {
private:
    void quicksort(std::vector<int>& list, int left, int right);
    int partition(std::vector<int>& list, int left, int right);

public:
    std::vector<int> sort(const std::vector<int>& list) override;
};
