#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <iostream>
#include <sstream>

int main() {
    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);
    int num;
    std::vector<int> numbers;
    
    while(iss >> num) numbers.push_back(num);

    QuickSort qs;
    std::vector<int> sortedList = qs.sort(numbers);

    RecursiveBinarySearch rbs;
    std::cout << (rbs.search(sortedList, 1) ? "true" : "false");

    for(int val : sortedList) std::cout << " " << val;
    std::cout << std::endl;

    return 0;
}
