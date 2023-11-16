#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> preSum(n+1, 0);
    for(int i=0; i<=n; i++) preSum[i+1]=preSum[i]+nums[i];
    
    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << preSum[b] - preSum[a-1] << endl;
    }
}