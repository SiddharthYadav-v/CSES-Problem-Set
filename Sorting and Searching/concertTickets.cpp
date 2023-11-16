#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    vector<int> t(m);
    for(int i=0; i<m; i++) cin >> t[i];

    multiset<int, greater<int>> ms;
    for(int i=0; i<n; i++) ms.insert(    h[i]);

    for(int i=0; i<m; i++) {
        auto it=ms.lower_bound(t[i]);
        if(it==ms.end()) cout << -1 << endl;
        else {
            cout << *it << endl;
            ms.erase(it);
        }
    }

    // return 1;
}