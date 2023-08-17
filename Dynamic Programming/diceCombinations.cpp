#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    int mod=1e9+7;

    vector<int> dp(n+1, -1);
    function<int(int)> calculateDP=[&](int rem)->int  {
        if(rem<0) return 0;
        if(rem==0) return 1;

        if(dp[rem]!=-1) return dp[rem];

        int tmp=0;
        for(int i=1; i<7; i++) {
            tmp+=(calculateDP(rem-i))%mod;
            tmp%=mod;
        }

        return dp[rem]=tmp;
    };

    calculateDP(n);

    cout << dp[n];

    // return 1;
}