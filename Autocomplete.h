#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    string word;  // to store the word at the end node
    TrieNode();
};

class Autocomplete {
private:
    TrieNode* root;
    void dfs(TrieNode* node, vector<string>& result);

public:
    Autocomplete();
    void insert(string word);
    vector<string> getSuggestions(string partialWord);
};
