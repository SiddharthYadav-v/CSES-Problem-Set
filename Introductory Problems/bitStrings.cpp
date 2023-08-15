#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    int mod=1e9+7;
    int val=1;
    for(int i=0; i<n; i++) {
        val*=2;
        val%=mod;
    }

    cout << val;

    // return 1;
}