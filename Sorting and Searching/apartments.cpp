#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> b(m);
    for(int i=0; i<m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt=0;
    int i=0, j=0;
    while(i<n && j<m) {
        if(a[i]-k>b[j]) j++;
        else if(a[i]+k<b[j]) i++;
        else i++, j++, cnt++;
    }

    cout << cnt << "\n";

    // return 1;
}