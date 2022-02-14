#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

// BREADTH-FIRST SEARCH (SHORTEST PATH ON UNDIRECTED UNWEIGHTED GRAPH IN O(n))

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