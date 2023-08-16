#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    int res=0;

    while(n>0) {
        res+=n/5;
        n/=5;
    }

    cout << res;

    // return 1;
}