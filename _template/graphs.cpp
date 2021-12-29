#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double eps = 1e-6;

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