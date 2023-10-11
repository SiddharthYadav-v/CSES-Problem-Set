#include<bits/stdc++.h>
using namespace std;

int x, y;

int findEnd(int src, vector<vector<int>>& graph) {
    int n=graph.size();
    queue<int> q;
    q.push(src);
    vector<bool> vis(n+1, false);

    int u=src;
    while(!q.empty()) {
        u=q.front();
        vis[u]=true;
        q.pop();
        for(auto nxt:graph[u]) {
            if(!vis[nxt]) q.push(nxt);
        }
    }

    return u;
}

void calculateDsts(vector<vector<int>>& graph, int end1, int end2, vector<int>& dsts) {
    int n=graph.size();
    vector<bool> vis(n+1, false);
    queue<pair<int, int>> q;
    // bfs from end1
    q.push({end1, 0});
    while(!q.empty()) {
        pair<int, int> u=q.front();
        vis[u.first]=true;
        q.pop();
        dsts[u.first]=max(dsts[u.first], u.second);
        
        for(auto nxt:graph[u.first]) {
            if(!vis[nxt]) {
                q.push({nxt, u.second+1});
            }
        }
    }

    // bfs from end2
    for(int i=0; i<vis.size(); i++) vis[i]=false;
    q.push({end2, 0});
    while(!q.empty()) {
        pair<int, int> u=q.front();
        vis[u.first]=true;
        q.pop();
        dsts[u.first]=max(dsts[u.first], u.second);

        for(auto nxt:graph[u.first]) {
            if(!vis[nxt]) {
                q.push({nxt, u.second+1});
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n+1);
    for(int i=0; i<n-1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int end1=findEnd(1, graph);
    int end2=findEnd(end1, graph);

    vector<int> dsts(n+1, INT_MIN);
    calculateDsts(graph, end1, end2, dsts);
    for(int i=1; i<=n; i++) cout << dsts[i] << " ";
    cout << "\n";
}