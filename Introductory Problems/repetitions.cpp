#include<bits/stdc++.h>
using namespace std;

int main() {
    string dna;
    cin >> dna;

    int maxLen=INT_MIN;

    // building a window
    char c=dna[0];
    int i=0;
    int len=0;
    while(i<dna.size() && dna[i]==c) {
        i++;
        len++;
        maxLen=max(maxLen, len);
    }

    // sliding the window
    while(i<dna.size()) {
        c=dna[i];
        len=0;
        while(i<dna.size() && dna[i]==c) {
            i++;
            len++;
            maxLen=max(maxLen, len);
        }
    }

    cout << maxLen;

    // return 1;
}