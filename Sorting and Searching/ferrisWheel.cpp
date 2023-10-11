#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];

    int cnt=n, sum=0, c=0;
    int i=0, j=n-1;
    while(i<j) {
        if(p[i]+p[j]<=x) cnt--, i++, j--;
        else j--;
    }

    cout << cnt << endl;

    // return 1;
}