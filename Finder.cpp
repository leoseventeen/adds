#include "Finder.h"

    using namespace std;

vector<int> computeLPSArray(string s2) {
    int n = s2.length();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (s2[i] == s2[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> Finder::findSubstrings(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    vector<int> lps = computeLPSArray(s2);
    vector<int> result(n, -1);

    int i = 0, j = 0;
    while (i < m) {
        if (s2[j] == s1[i]) {
            i++;
            j++;
        }

        if (j == n) {
            for (int k = 0; k < j; k++) {
                result[k] = i - j;
            }
            j = lps[j - 1];
        } else if (i < m && s2[j] != s1[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }

    return result;
}



   
