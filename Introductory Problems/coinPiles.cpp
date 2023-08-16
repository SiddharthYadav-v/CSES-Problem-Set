#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;

    vector<vector<int>> piles(t);
    for(int i=0; i<t; i++) {
        int a, b;
        cin >> a >> b;

        piles[i]={a, b};
    }

    for(auto &pile:piles) {
        int a=pile[0], b=pile[1];

        // solution: x=(2*a-b)/3, y=(-a+2*b)/3
        if((2*a-b)>=0 && (-a+2*b)>=0 && (2*a-b)%3==0 && (-a+2*b)%3==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    // return 1;
}