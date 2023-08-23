#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> freq(10, 0);
    int tmp=n;
    while(tmp>0) {
        freq[tmp%10]++;
        tmp/=10;
    }

    vector<int> dp(n+1, INT_MAX);
    function<int(int)> calculateDP=[&](int x)->int {
        if(x==0) return 0;

        if(dp[x]!=INT_MAX) return dp[x];

        for(int i=1; i<10; i++) {
            if(freq[i]>0) {
                int tmp=x-i;
                vector<int> newFreq(10, 0);
                while(tmp>0) {
                    newFreq[tmp%10]++;
                    tmp/=10;
                }

                int res=calculateDP(tmp);
                if(res!=INT_MAX) dp[x]=min(dp[x], res+1);
            }
        }

        return dp[x];
    };

    cout << calculateDP(n) << "\n";

    // return 1;
}