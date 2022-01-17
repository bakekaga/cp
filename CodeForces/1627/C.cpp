#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-6;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> out(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].pb(mp(b - 1, i));
        adj[b - 1].pb(mp(a - 1, i));
    }

    int end = -1;
    for (int i = 0; i < n; i++) {
        if (sz(adj[i]) > 2) {
            cout << -1 << '\n';
            return;
        }
        else if (sz(adj[i]) == 1) end = i;
    }
    
    bool good = false;
    stack<pair<pair<int, int>, int>> dfs;
    dfs.push(mp(mp(end, -1), -1));
    while (!dfs.empty()) {
        auto cur = dfs.top();
        dfs.pop();
        for (auto x : adj[cur.first.first]) {
            if (x.first != cur.second) dfs.push(mp(x, cur.first.first));
        }
        good = !good;
        if (cur.first.second == -1) continue;
        if (good) out[cur.first.second] = 2;
        else out[cur.first.second] = 3;
    }
    
    for (int i = 0; i < n - 1; i++) {
        cout << out[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}