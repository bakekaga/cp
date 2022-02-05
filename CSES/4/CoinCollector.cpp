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
 
vector<int> adj[MAXN], adj_t[MAXN], adj_s[MAXN], root_nodes, ord;
int id[MAXN], roots[MAXN];
ll k[MAXN], sum[MAXN], dp[MAXN];
bool vis[MAXN];
 
void dfs(int cur, int pass, int root = 0) {
    vis[cur] = true;
    vector<int> ad = (pass == 1) ? adj[cur] : adj_t[cur];
    for (int x : ad) {
        if (!vis[x]) dfs(x, pass, root);
    }
 
    ord.pb(cur);
    if (pass == 2) {
        roots[cur] = root;
        sum[root]+= k[cur];
    }
}
 
ll solve(int v) {
    if (dp[v] != 0) return dp[v];
    ll res = 0;
    for (int x : adj_s[v]) res = max(res, solve(x));
    return dp[v] = res + sum[v];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
 
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj_t[b].pb(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 1);
    }
 
    memset(vis, false, sizeof vis);
 
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[ord[i]]) {
            dfs(ord[i], 2, ord[i]);
            root_nodes.pb(ord[i]);
        }
    }
 
    for (int i = 1; i <= n; i++) {
        for (int node : adj[i]) {
            if (roots[i] != roots[node]) {
                adj_s[roots[i]].pb(roots[node]);
            }
        }
    }
 
    ll ans = 0;
    for (int root : root_nodes) {
        ans = max(ans, solve(root));
    }
 
    cout << ans << '\n';
    return 0;
}