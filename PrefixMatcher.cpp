struct BinaryTrieNode {
    BinaryTrieNode* children[2];
    int routerNumber;  // default -1 means no router at this node
    BinaryTrieNode() {
        children[0] = children[1] = nullptr;
        routerNumber = -1;
    }
};

class PrefixMatcher {
private:
    BinaryTrieNode* root;

public:
    PrefixMatcher() {
        root = new BinaryTrieNode();
    }

    void insert(string address, int routerNumber) {
        BinaryTrieNode* node = root;
        for (char c : address) {
            int index = c - '0';
            if (!node->children[index]) {
                node->children[index] = new BinaryTrieNode();
            }
            node = node->children[index];
        }
        node->routerNumber = routerNumber;
    }

    int selectRouter(string networkAddress) {
        BinaryTrieNode* node = root;
        int matchedRouter = -1;  // Default: No matched router
        for (char c : networkAddress) {
            int index = c - '0';
            if (!node->children[index]) break;
            node = node->children[index];
            if (node->routerNumber != -1) {
                matchedRouter = node->routerNumber;
            }
        }
        return matchedRouter;
    }
};
