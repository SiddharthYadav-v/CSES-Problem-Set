#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];

    int minDiff=INT_MAX;
    function<void(int, int, int)> util=[&](int idx, int w1, int w2)->void {
        if(idx==n) {
            minDiff=min(minDiff, abs(w1-w2));
            return;
        }

        util(idx+1, w1+p[idx], w2);
        util(idx+1, w1, w2+p[idx]);
    };    

    util(0, 0, 0);
    cout << minDiff;

    // return 1;
}