#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    int mod=1e9+7;
    vector<int> dp(x+1, -1);
    dp[0]=1;
    for(int i=1; i<=x; i++) {
        dp[i]=0;
        for(int j=0; j<n; j++) {
            if(i-coins[j]>=0) {
                dp[i]+=dp[i-coins[j]]%mod;
                dp[i]%=mod;
            }
        }
    }

    cout << dp[x];

    // return 1;
}