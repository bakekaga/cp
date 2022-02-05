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

// KOSARAJU'S ALGORITHM (STRONGLY CONNECTED COMPONENTS + CONDENSATION GRAPH IN O(n + m))

int n;
vector<int> adj[MAXN], adj_t[MAXN], ord;
bool vis[MAXN];
int id[MAXN];

// int roots[MAXN];
// vector<int> adj_s[MAXN], root_nodes;

void dfs(int cur, int pass, int num = 0, int root = 0) {
    vis[cur] = true;
    vector<int> ad = (pass == 1) ? adj[cur] : adj_t[cur];
    for (int x : ad) {
        if (!vis[x]) dfs(x, pass, num, root);
    }

    ord.pb(cur);
    if (pass == 2) {
        id[cur] = num;
        // roots[cur] = root;
    }
}

void kosaraju() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 1);
    }

    memset(vis, false, sizeof vis);

    int comps = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[ord[i]]) {
            comps++;
            dfs(ord[i], 2, comps, ord[i]);
            // root_nodes.pb(ord[i]);
        }
    }

    // make condensation graph

    // for (int i = 1; i <= n; i++) {
    //     for (int node : adj[i]) {
    //         if (roots[i] != roots[node]) {
    //             adj_s[roots[i]].pb(roots[node]);
    //         }
    //     }
    // }
}