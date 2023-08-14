#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    // vector<int> v(n);.
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int moves=0;
    for(int i=1; i<n; i++) {
        moves+=max(1LL*0, arr[i-1]-arr[i]);
        arr[i]=max(arr[i-1], arr[i]);
    }
    
    cout << moves;

    return 1;
}