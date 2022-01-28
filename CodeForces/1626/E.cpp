#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int black[MAXN], par[MAXN], val[MAXN], vis[MAXN];
vector<int> adj[MAXN], adj2[MAXN];

int dfs(int cur) {
    for (int node : adj[cur]) {
        if (node != par[cur]) {
            par[node] = cur;
            val[cur]+= dfs(node);
        }
    }
    val[cur]+= black[cur];
    return val[cur];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> black[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    par[0] = -1;
    dfs(0);

    for (int i = 0; i < n; i++) {
        for (int node : adj[i]) {
            if (i == par[node]) {
                if (black[i] || val[0] - val[node] > 1) {
                    adj2[i].pb(node);
                }
            }
            else {
                if (black[i] || val[i] > 1) {
                    adj2[i].pb(node);
                }
            }
        }
    }
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (black[i]) {
            s.push(i);
            vis[i]++;
        }
    }
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        for (int node : adj2[cur]) {
            if (!vis[node]) {
                vis[node]++;
                s.push(node);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << vis[i] << ' ';
    }
    return 0;
}