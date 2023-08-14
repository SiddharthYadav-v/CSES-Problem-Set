#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    function<void(int)> util=[&](int n)->void {
        cout << n << " ";
        if(n==1) return;
        else if(n%2==0) util(n/2);
        else util(n*3 + 1);
    };

    util(n);

    return 1;
}