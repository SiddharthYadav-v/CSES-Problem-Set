// reference taken from codeforces

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> h(n+1);
    for(int i=0; i<n; i++) cin >> h[i];

    vector<int> s(n+1);
    for(int i=0; i<n; i++) cin >> s[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1));
    dp[0][0]=0;
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=x; i++) dp[0][i]=0;
    int mod=1e9+7;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=x; j++) {
            dp[i][j]=dp[i-1][j];
            if(j>=h[i-1]) dp[i][j]=max(dp[i-1][j-h[i-1]]+s[i-1], dp[i][j]);
            dp[i][j]%=mod;
        }
    }

    cout << dp[n][x] << "\n";

    // return 1;
}