#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> strs(n);
    for(int i=0; i<n; i++) cin >> strs[i];

    int rooms=0;
    vector<vector<int>> vis(n, vector<int>(m, false));
    function<void(int, int)> explore=[&](int i, int j)->void {
        if(vis[i][j] || strs[i][j]=='#') return;

        vis[i][j]=true;

        // move left
        if(i>0) explore(i-1, j);
        // move right
        if(i<n-1) explore(i+1, j);
        // move down
        if(j<m-1) explore(i, j+1);
        // move up
        if(j>0) explore(i, j-1);  
    };

    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(strs[i][j]=='.' && !vis[i][j]) {
                cnt++;
                explore(i, j);
            }
        }
    }

    cout << cnt << "\n";
}