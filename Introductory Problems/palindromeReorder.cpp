#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for(auto c:s) freq[c-'A']++;

    string half;
    bool oddFound=false;
    char oddChar;
    bool flag=false;
    for(int i=0; i<26; i++) {
        if(freq[i]%2!=0 && oddFound) {
            cout << "NO SOLUTION";
            flag=true;
            break;
        }
        if(freq[i]%2!=0 && !oddFound) {
            oddChar='A'+i;
            oddFound=true;
        }
        if(freq[i]%2==0) {
            for(int j=0; j<freq[i]/2; j++) {
                half+='A'+i;
            }
        }
    }

    if(!flag) {
        if(oddFound) {
            int cnt=freq[oddChar-'A'];
            cnt/=2;
            for(int i=0; i<cnt; i++) half+=oddChar;
        }
        string revHalf=half;
        reverse(revHalf.begin(), revHalf.end());

        string full;
        if(oddFound) full=half+oddChar+revHalf;
        else full=half+revHalf;

        cout << full;
    }

    // return 1;
}