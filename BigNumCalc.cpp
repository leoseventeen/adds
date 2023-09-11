#include "BigNumCalc.h"

bigNumCalc::bigNumCalc() {
    // Constructor body (if any initialization needed)
}

bigNumCalc::~bigNumCalc() {
    // Destructor body (if any cleanup needed)
}

std::list<int> bigNumCalc::buildBigNum(std::string numString) {
    std::list<int> result;
    for (char c : numString) {
        if (isdigit(c)) {
            result.push_back(c - '0');
        }
    }
    return result;
}

std::list<int> bigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    
    int carry = 0;
    
    while(it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        
        if(it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }

        if(it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }

        carry = sum / 10;
        sum %= 10;

        result.push_front(sum);
    }

    return result;
}

std::list<int> bigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    
    int borrow = 0;
    
    while(it1 != num1.rend()) {
        int difference = *it1 - borrow;
        
        if(it2 != num2.rend()) {
            difference -= *it2;
            ++it2;
        }

        if(difference < 0) {
            borrow = 1;
            difference += 10;
        } else {
            borrow = 0;
        }

        result.push_front(difference);
        ++it1;
    }

    // Remove leading zeros
    while(result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> bigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;

    if(num2.size() != 1) {
        // handle error (throw exception or return an empty list)
        return {};
    }

    int multiplier = num2.front();
    int carry = 0;

    for(auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int product = (*it) * multiplier + carry;
        carry = product / 10;
        product %= 10;

        result.push_front(product);
    }

    while(carry) {
        result.push_front(carry % 10);
        carry /= 10;
    }

    return result;
}
