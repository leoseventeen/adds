#include "PrefixMatcher.h"

BinaryTrieNode::BinaryTrieNode() {
    children[0] = children[1] = nullptr;
    routerNumber = -1;
}

PrefixMatcher::PrefixMatcher() {
    root = new BinaryTrieNode();
}

void PrefixMatcher::insert(string address, int routerNumber) {
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

int PrefixMatcher::selectRouter(string networkAddress) {
    BinaryTrieNode* node = root;
    int matchedRouter = -1;
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
