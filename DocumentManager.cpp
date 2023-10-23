#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
    nameToIdMap[name] = id;
    documents[id] = {name, id, license_limit};
    borrowedCopies[id] = 0;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(string name) {
    if(nameToIdMap.find(name) != nameToIdMap.end()) {
        return nameToIdMap[name];
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if(patrons.find(patronID) == patrons.end()) {
        // Patron not registered
        return false;
    }
    if(borrowedCopies[docid] >= documents[docid].license_limit) {
        // License limit reached
        return false;
    }
    borrowedCopies[docid]++;
    docToPatrons[docid].insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if(docToPatrons[docid].find(patronID) != docToPatrons[docid].end()) {
        borrowedCopies[docid]--;
        docToPatrons[docid].erase(patronID);
    }
}
