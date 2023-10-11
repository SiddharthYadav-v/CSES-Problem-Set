#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int maxLen=INT_MIN;
    int minShifts=INT_MAX;
    for(int i=0; i<b.size(); i++) {
        int curLen=0;
        int j=0;
        string tmp=b+b;
        while(curLen<a.size() && j<a.size()) {
            if(tmp[i+curLen]!=a[j]) break;
            curLen++, j++;
        }

        if(curLen>maxLen) {
            maxLen=curLen;
            minShifts=i;
        }
    }

    cout << minShifts << "\n";

    // return 1;
}