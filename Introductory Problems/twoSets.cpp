#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    // possibility
    int sum=n*(n+1)/2;
    bool isNotPossible=false;
    if(sum%2!=0) {
        isNotPossible=true;
        cout << "NO";
    }

    if(!isNotPossible) {
        cout << "YES" << endl;
        
        vector<int> v1, v2;
        vector<bool> vis(n+1, false);

        int tmp=n, rem=sum/2;
        while(rem>0) {
            if(tmp<=rem) {
                v1.push_back(tmp);
                rem-=tmp;
                vis[tmp]=true;
                tmp--;
            } else break;
        }

        if(rem>0) {
            v1.push_back(rem);
            vis[rem]=true;
        }

        for(int i=1; i<n+1; i++) {
            if(!vis[i]) v2.push_back(i);
        }

        cout << v1.size() << endl;
        for(auto x:v1) cout << x << " ";
        cout << endl;
        cout << v2.size() << endl;
        for(auto x:v2) cout << x << " ";
    }

    // return 1;
}