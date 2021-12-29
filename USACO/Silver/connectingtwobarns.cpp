#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> sets, adj(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int pos1 = 0, posn;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        stack<int> dfs; dfs.push(i);
        vector<int> comp;
        while (!dfs.empty()) {
            int cur = dfs.top();
            dfs.pop();
            comp.pb(cur);
            vis[cur] = true;
            if (cur == n) posn = sz(sets);
            for (int node : adj[cur]) {
                if (!vis[node]) dfs.push(node);
            }
        }
        sets.pb(comp);
    }

    if (pos1 == posn) {
        cout << 0 << '\n';
        return;
    }

    ll ret = LONG_LONG_MAX;
    sort(sets[pos1].begin(), sets[pos1].end());
    sort(sets[posn].begin(), sets[posn].end());

    for (int i = 0; i < sz(sets); i++) {
        if (i == pos1 || i == posn) continue;
        ll val1min = LONG_LONG_MAX, val2min = LONG_LONG_MAX;
        for (int x : sets[i]) {
            auto val1 = upper_bound(sets[pos1].begin(), sets[pos1].end(), x);
            if (val1 != sets[pos1].end()) val1min = min(val1min, (ll) *val1 - x);
            val1--;
            val1min = min(val1min, (ll) x - *val1);
            
            auto val2 = upper_bound(sets[posn].begin(), sets[posn].end(), x);
            val2min = min(val2min, (ll) *val2 - x);
            if (val2 != sets[posn].begin()) {
                val2--;
                val2min = min(val2min, (ll) x - *val2);
            }
        }
        ret = min(ret, val1min * val1min + val2min * val2min);
    }

    for (int i : sets[pos1]) {
        auto val = upper_bound(sets[posn].begin(), sets[posn].end(), i);
        ret = min(ret, ((ll) *val - i) * (*val - i));
        if (val != sets[posn].begin()) {
            val--;
            ret = min(ret, ((ll) i - *val) * (i - *val));
        }
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}