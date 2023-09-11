#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mod=1e9+7;
    vector<int> dp(1e6+1, INT_MAX);

    dp[0]=0;
    for(int i=1; i<10; i++) dp[i]=1;
    for(int i=10; i<=n; i++) {
        int tmp=i;
        while(tmp>0) {
            if(tmp%10!=0) dp[i]=min(dp[i], 1+dp[i-tmp%10]);
            tmp/=10;
        }
    }

    cout << dp[n] << "\n";

    // return 1
}