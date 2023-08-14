#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n-1);
    for(int i=0; i<n-1; i++) cin >> v[i];

    // edge case
    if(n==2) {
        if(v[0]==1) cout << 2;
        else cout << 1;

        return 1;
    }

    sort(v.begin(), v.end());
    function<int(int, int)> modBS=[&](int l, int r)->int {
        if(l>r) return -1;

        if(r==0) return 1; 
        if(l==n-2) return n;

        int mid=l+(r-l)/2;
        if(v[mid]+2==v[mid+1]) return mid+2;
        else if(v[mid]==mid+1) return modBS(mid+1, r);
        else return modBS(l, mid-1);
    };

    cout << modBS(0, n-2);

    return 1;
}