#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    vector<string> grayCode;
    grayCode.push_back("");
    for(int i=0; i<n; i++) {
        int size=grayCode.size();
        for(int j=size-1; j>=0; j--) {
            grayCode.push_back(grayCode[j]);
        }
        size*=2;
        for(int j=0; j<size; j++) {
            if(j<grayCode.size()/2) {
                grayCode[j]+="0";
            } else {
                grayCode[j]+="1";
            }
        }
    }
    for(int i=0; i<grayCode.size(); i++) {
        cout << grayCode[i] << endl;
    }

    // return 1;
}