#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for(auto c:s) freq[c-'a']++;
    
    vector<string> perms;
    function<void(string)> genStr=[&](string cur)->void {
        if(cur.size()==s.size()) {
            perms.push_back(cur);
            return;
        }

        for(int i=0; i<26; i++) {
            if(freq[i]>0) {
                freq[i]--;
                genStr(cur+(char)('a'+i));
                freq[i]++;
            }
        }
    };

    genStr("");

    cout << perms.size() << endl;
    for(auto &perm:perms) cout << perm << endl;

    // return 1;
}