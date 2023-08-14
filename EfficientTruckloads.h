#include <unordered_map>

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize);

private:
    std::unordered_map<int, std::unordered_map<int, int>> memo;
    int recursiveTruckloads(int numCrates, int loadSize);
};