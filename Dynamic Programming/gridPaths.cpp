#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    int mod=1e9+7;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> calculateDP=[&](int i, int j)->int {
        if(i>=n || i<0 || j>=n || j<0 || grid[i][j]=='*') return 0;
        if(i==n-1 && j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=(calculateDP(i+1, j)%mod+calculateDP(i, j+1)%mod)%mod;
    };

    cout << calculateDP(0, 0) << "\n";

    // return 1;
}