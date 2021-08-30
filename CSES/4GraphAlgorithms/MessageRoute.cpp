#include <bits/stdc++.h>
#define MAXN 100005
#define MOdist 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1), par(n + 1);
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<int> bfs;
    par[1] = INT_MAX;
    bfs.push(1);
    while (!bfs.empty()) {
        int x = bfs.front(); bfs.pop();
        for (auto node : adj[x]) {
            if (!par[node]) {
                bfs.push(node);
                par[node] = x;
                dist[node] = dist[x] + 1;
            }
        }
    }

    if (!par[n]) cout << "IMPOSSIBLE";
    else {
        cout << dist[n] + 1 << '\n';
        vector<int> path; path.pb(n);
        while (path.back() != 1) path.pb(par[path.back()]);
        for (int i = dist[n]; i >= 0; i--) {
            cout << path[i] << ' ';
        }
    }
}