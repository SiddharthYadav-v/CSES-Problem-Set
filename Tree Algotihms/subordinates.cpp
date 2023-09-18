#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n+1);
    for(int i=2; i<=n; i++) {
        int par;
        cin >> par;

        tree[par].push_back(i);
    }

    vector<int> cnt(n+1, -1);
    for(int i=1; i<=n; i++) if(tree[i].size()==0) cnt[i]=0;

    function<int(int)> calculateCnt=[&](int cur)->int {
        if(cnt[cur]!=-1) return cnt[cur];

        int tmp=0;
        for(auto nxt:tree[cur]) {
            tmp+=1+calculateCnt(nxt);
        }

        return cnt[cur]=tmp;
    };

    for(int i=1; i<=n; i++) cout << calculateCnt(i) << " ";
    cout << "\n";
}