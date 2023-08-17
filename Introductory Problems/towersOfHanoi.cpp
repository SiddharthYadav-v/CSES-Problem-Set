// ref taken from GFG

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    vector<vector<int>> moves;
    function<void(int, int, int, int)> util=[&](int n, int from_rod, int to_rod, int aux_rod)->void {
        if(n==0) return;

        util(n-1, from_rod, aux_rod, to_rod);
        moves.push_back({from_rod, to_rod});
        util(n-1, aux_rod, to_rod, from_rod);         
    };

    util(n, 1, 3, 2);

    cout << moves.size() << endl;
    for(auto &move:moves) {
        cout << move[0] << " " << move[1] << endl;
    }

    // return 1;
}