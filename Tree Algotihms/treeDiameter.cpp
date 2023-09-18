#include<bits/stdc++.h>
using namespace std;

int x, y;

pair<int, int> bfs(int src, vector<vector<int>>& graph) {
    int n=graph.size();
    int d=0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    vector<bool> vis(n, false);
    pair<int, int> u;

    while(!q.empty()) {
        u=q.front();
        vis[u.first]=true;
        q.pop();
        for(int v:graph[u.first]) {
            if(!vis[v]) {
                q.push({v, u.second+1});
            }
        }
    }

    return u;
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

    pair<int, int> end1=bfs(1, graph);
    pair<int, int> end2=bfs(end1.first, graph);
    cout << end2.second << endl;
}