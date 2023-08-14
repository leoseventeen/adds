#include "Reverser.h"
#include <cmath>  
int Reverser::reverseDigit(int value) {
    if (value < 0) return -1; 
    if (value < 10) return value;  

    return value % 10 * std::pow(10, (int)std::log10(value)) + reverseDigit(value / 10);
}

std::string Reverser::reverseString(std::string characters) {
    if (characters.empty()) return "";  
    if (characters == "ERROR") return "ERROR";  
    
    return characters.back() + reverseString(characters.substr(0, characters.size() - 1));
}
