#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> labyrinth(n);
    for(int i=0; i<n; i++) cin >> labyrinth[i];

    int beginI, beginJ;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(labyrinth[i][j]=='A') {
                beginI=i;
                beginJ=j;
                break;
            } 
        }
    }

    string curPath, minPath;
    function<void(int, int)> explore=[&](int i, int j)->void {
        if(labyrinth[i][j]=='B') {
            if(minPath.size()==0 || curPath.size()<minPath.size()) minPath=curPath;
            return;
        }

        // left
        if(j>0) curPath+='L', explore(i, j-1);
        curPath.pop_back();
        // right
        if(j<m-1) curPath+='R', explore(i, j+1);
        curPath.pop_back();
        // up
        if(i>0) curPath+='U', explore(i-1, j);
        curPath.pop_back();
        // down
        if(i<n-1) curPath+='D', explore(i+1, j);
        curPath.pop_back();
    };

    explore(beginI, beginJ);

    if(minPath.size()==0) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << minPath.size() << "\n";
        cout << minPath << "\n";
    }

    // return 1;
}