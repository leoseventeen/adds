#include "DocumentManager.h"

Document::Document(int id, int license_limit) : id(id), license_limit(license_limit), current_borrowed(0) {}

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    doc_map[name] = Document(id, license_limit);
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name) {
    if(doc_map.find(name) != doc_map.end()) {
        return doc_map[name].id;
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    // Check if the patron is valid
    if(patrons.find(patronID) == patrons.end()) {
        return false;
    }
    
    // Search for the document using its ID. This step assumes that document IDs are unique.
    for(auto &entry : doc_map) {
        if(entry.second.id == docid) {
            if(entry.second.current_borrowed < entry.second.license_limit &&
               doc_borrowers[docid].find(patronID) == doc_borrowers[docid].end()) {
                entry.second.current_borrowed++;
                doc_borrowers[docid].insert(patronID);
                return true;
            }
            return false;
        }
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    for(auto &entry : doc_map) {
        if(entry.second.id == docid && doc_borrowers[docid].find(patronID) != doc_borrowers[docid].end()) {
            entry.second.current_borrowed--;
            doc_borrowers[docid].erase(patronID);
            return;
        }
    }
}
