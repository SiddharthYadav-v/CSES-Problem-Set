#include<bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for(int i=0; i<n-1; i++) {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    
}