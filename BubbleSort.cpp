#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(const std::vector<int>& list) {
    std::vector<int> result = list;
    for(std::size_t i = 0; i < result.size(); i++) {
        for(std::size_t j = 0; j < result.size() - i - 1; j++) {
            if(result[j] > result[j + 1]) {
                std::swap(result[j], result[j + 1]);
            }
        }
    }
    return result;
}
