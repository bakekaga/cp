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

// TOPOLOGICAL SORT IN O(n + m)

int n;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> ord;

void dfs(int cur) {
    vis[cur] = true;
    for (int x : adj[cur]) {
        if (!vis[x]) dfs(x);
    }
    ord.pb(cur);
}

void topoSort() {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());
}