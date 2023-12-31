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

    vector<int> dp(x+1, 0);
    for(int i=1; i<=x; i++) {
        dp[i]=INT_MAX;
        for(int j=0; j<n; j++) {
            if(i-coins[j]>=0) {
                dp[i]=min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }

    cout << (dp[x]>=INT_MAX ? -1 : dp[x]);

    // return 1;
}