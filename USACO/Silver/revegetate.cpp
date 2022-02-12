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

vector<pair<int, int>> adj[MAXN];
int val[MAXN];
bool impossible;

void dfs(int cur, int id) {
    val[cur] = id;
    for (pair<int, int> node : adj[cur]) {
        if (node.second) {
            if (val[node.first] == (val[cur] + 1) % 2) impossible = true;
            id = val[cur];
        }
        else {
            if (val[node.first] == val[cur]) impossible = true;
            id = (val[cur] + 1) % 2;
        }
        if (val[node.first] == -1) {
            dfs(node.first, id);
        }
    }
}

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        int a, b; cin >> a >> b;
        if (c == 'S') {
            adj[a].pb({b, 1});
            adj[b].pb({a, 1});
        }
        else {
            adj[a].pb({b, 0});
            adj[b].pb({a, 0});
        }
    }

    int cnt = 0;
    memset(val, -1, sizeof val);
    for (int i = 1; i <= n; i++) {
        if (val[i] == -1) {
            cnt++;
            dfs(i, 0);
        }
    }

    if (impossible) cout << 0 << '\n';
    else {
        cout << 1;
        for (int i = 0; i < cnt; i++) cout << 0;
        cout << '\n';
    }
    return 0;
}