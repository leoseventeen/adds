#pragma once
#include "Sort.h"

class BubbleSort : public Sort {
public:
    std::vector<int> sort(const std::vector<int>& list) override;
};
