#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) return 1;
    int half1 = numCrates / 2;
    int half2 = numCrates - half1;
    return numTrucks(half1, loadSize) + numTrucks(half2, loadSize);
}