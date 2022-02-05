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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> comps, adj(n);
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> curcomp;
        stack<int> dfs;
        dfs.push(i);
        while (!dfs.empty()) {
            int cur = dfs.top();
            dfs.pop();
            if (vis[cur]) continue;
            vis[cur]++;
            curcomp.pb(cur);
            for (int node : adj[cur]) {
                dfs.push(i);
            }
        }
        comps.pb(curcomp);
    }
    return 0;
}