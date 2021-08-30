#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

// BREADTH-FIRST SEARCH (SHORTEST PATH)

void bfs(int start) {
    vector<vector<int>> adj;
    vector<int> vis;
    vector<int> dist;

    queue<int> bfs;
    dist[start] = 0;
    bfs.push(start);
    while (!bfs.empty()) {
        int cur = bfs.front(); bfs.pop();
        for (auto node : adj[cur]) {
            if (!vis[node]) {
                bfs.push(node);
                vis[node]++;
                dist[node] = dist[cur] + 1;
            }
        }
    }
}