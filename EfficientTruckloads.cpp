#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    return recursiveTruckloads(numCrates, loadSize);
}

int EfficientTruckloads::recursiveTruckloads(int numCrates, int loadSize) {
    if (numCrates <= loadSize) return 1;
    
    if (memo[numCrates][loadSize]) return memo[numCrates][loadSize];
    
    int half1 = numCrates / 2;
    int half2 = numCrates - half1;
    
    int result = recursiveTruckloads(half1, loadSize) + recursiveTruckloads(half2, loadSize);
    memo[numCrates][loadSize] = result;
    
    return result;
}