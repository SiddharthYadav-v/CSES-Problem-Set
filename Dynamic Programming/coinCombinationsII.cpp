// reference taken from NeetCode

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    int mod=1e9+7;
    vector<int> dp(x+1, 0);
    dp[0]=1;
    for(int i=n-1; i>=0; i--) {
        vector<int> nextDP(x+1, 0);
        nextDP[0]=1;
        for(int a=1; a<x+1; a++) {
            nextDP[a]=dp[a];
            if(a-coins[i]>=0) {
                nextDP[a]+=nextDP[a-coins[i]];
            }
        }
        dp=nextDP;
    }

    cout << dp[x];

    // return 1;
}