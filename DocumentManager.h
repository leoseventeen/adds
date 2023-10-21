#include <unordered_map>
#include <unordered_set>
#include <string>

class Document {
public:
    int id;
    int license_limit;
    int current_borrowed;
    Document(int id, int license_limit);
};

class DocumentManager {
private:
    std::unordered_map<std::string, Document> doc_map;
    std::unordered_set<int> patrons;
    std::unordered_map<int, std::unordered_set<int>> doc_borrowers;

public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
};
