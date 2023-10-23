#include <string>
#include <unordered_map>
#include <set>

using namespace std;

// A simple structure to hold Document details
struct Document {
    string name;
    int id;
    int license_limit;
};

class DocumentManager {
private:
    unordered_map<string, int> nameToIdMap;
    unordered_map<int, Document> documents;
    unordered_map<int, int> borrowedCopies;
    unordered_map<int, set<int>> docToPatrons;
    set<int> patrons;

public:
    void addDocument(string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
};
