#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, x;
    cin >> n >> x;

    vector<int> coinVals(n);
    for(int i=0; i<n; i++) cin >> coinVals[i];

    vector<int> dp(x+1, -1);
    function<int(int, int)> calculateDP=[&](int rem, int cnt)->int {
        if(rem<0) return -1;
        if(rem==0) return 0;

        if(dp[rem]!=-1) return dp[rem];

        int tmp=INT_MAX;
        for(auto val:coinVals) {
            int res=calculateDP(rem-val, cnt+1);
            if(res!=-1) tmp=min(tmp, res+1);
        }

        return dp[rem]=tmp;
    };

    cout << calculateDP(n, 0);

    // return 1;
}