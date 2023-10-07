#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    string word;  // to store the word at the end node
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};

class Autocomplete {
private:
    TrieNode* root;

    void dfs(TrieNode* node, vector<string>& result) {
        if (node->isEndOfWord) {
            result.push_back(node->word);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                dfs(node->children[i], result);
            }
        }
    }

public:
    Autocomplete() {
        root = new TrieNode();
    }

    void insert(string word) {
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

    vector<string> getSuggestions(string partialWord) {
        vector<string> result;
        TrieNode* node = root;
        for (char c : partialWord) {
            int index = c - 'a';
            if (!node->children[index]) return result;  // if the word does not exist in trie
            node = node->children[index];
        }
        dfs(node, result);
        return result;
    }
};
