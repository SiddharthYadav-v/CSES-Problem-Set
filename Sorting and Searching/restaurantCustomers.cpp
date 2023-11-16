#include<bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> customers;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        customers.push_back({a, b});
    }

    sort(customers.begin(), customers.end());

    int maxCnt=1;
    for(int i=0; i<n; i++) {
        
    }

    // return 1;
}