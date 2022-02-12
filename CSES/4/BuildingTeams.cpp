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

vector<int> adj[MAXN];
int val[MAXN];
bool impossible;

void dfs(int cur, int id) {
    val[cur] = id;
    for (int node : adj[cur]) {
        if (val[node] == val[cur]) impossible = true;
        if (val[node] == -1) dfs(node, (id + 1) % 2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    memset(val, -1, sizeof val);
    for (int i = 1; i <= n; i++) {
        if (val[i] == -1) {
            dfs(i, 0);
        }
    }

    if (impossible) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 1; i <= n; i++) {
            cout << val[i] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}