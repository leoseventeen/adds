#include <string>

using namespace std;

struct BinaryTrieNode {
    BinaryTrieNode* children[2];
    int routerNumber;
    BinaryTrieNode();
};

class PrefixMatcher {
private:
    BinaryTrieNode* root;

public:
    PrefixMatcher();
    void insert(string address, int routerNumber);
    int selectRouter(string networkAddress);
};
