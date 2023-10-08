#include "Autocomplete.h"

TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
    isEndOfWord = false;
}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

void Autocomplete::insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
    node->word = word;
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
    vector<string> result;
    TrieNode* node = root;
    for (char c : partialWord) {
        int index = c - 'a';
        if (!node->children[index]) return result;
        node = node->children[index];
    }
    dfs(node, result);
    return result;
}

void Autocomplete::dfs(TrieNode* node, vector<string>& result) {
    if (node->isEndOfWord) {
        result.push_back(node->word);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            dfs(node->children[i], result);
        }
    }
}
