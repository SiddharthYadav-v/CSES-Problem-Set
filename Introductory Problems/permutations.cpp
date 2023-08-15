#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    // not possible cases
    bool isNotPossible=false;
    if(n>1 && n<4) {
        isNotPossible=true;
        cout << "NO SOLUTION";
    }

    if(!isNotPossible) {
        // even part
        int evenPart=(n%2==0) ? n : (n-1);
        int tmp=2;
        while(tmp<=evenPart) {
            cout << tmp << " ";
            tmp+=2;
        }
        
        // odd part
        int oddPart=(n%2==0) ? (n-1) : n;
        tmp=1;
        while(tmp<=oddPart) {
            cout << tmp << " ";
            tmp+=2;
        }
    }

    // return 1;
}