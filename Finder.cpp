#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;

    for(size_t i = 0; i < s2.size(); i++) { // start loop index at 0
        size_t found = s1.find(s2.substr(0, i + 1));
        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
        }
    }
    return result;
}



   