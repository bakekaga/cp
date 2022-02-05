#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

vector<int> adj[MAXN];
int dist[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d1 = 0; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<pair<int, int>> bfs;
    bfs.push(mp(0, -1));
    while (!bfs.empty()) {
        pair<int, int> cur = bfs.front(); bfs.pop();
        for (auto node : adj[cur.first]) {
            if (node != cur.second) {
                bfs.push(mp(node, cur.first));
                d1 = node;
            }
        }
    }
    bfs.push(mp(d1, -1));
    while (!bfs.empty()) {
        pair<int, int> cur = bfs.front(); bfs.pop();
        for (auto node : adj[cur.first]) {
            if (node != cur.second) {
                bfs.push(mp(node, cur.first));
                dist[node] = dist[cur.first] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dist[i]);
    cout << ans << '\n';
}