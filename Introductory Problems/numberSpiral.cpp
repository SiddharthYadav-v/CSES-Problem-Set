#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;

    vector<vector<int>> tests(t);
    for(int i=0; i<t; i++) {
        int x, y;
        cin >> x >> y;

        tests[i]={x, y};
    }

    for(auto &t:tests) {
        int x=t[0], y=t[1];

        int a=max(x-1, y-1);
        int val=pow(a, 2);
        
        bool flag=(a%2==0);
        if(flag) {
            val+=y+(a+1-x);
        } else {
            val+=x+(a+1-y);
        }

        cout << val << endl;
    }

    // return 1;
}