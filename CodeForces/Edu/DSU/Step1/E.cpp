#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

struct DSU {
	vector<int> par, ans;
	vector<vector<int>> children;
	DSU(int N) {
		par = ans = vector<int>(N, -1);
		children = vector<vector<int>>(N);
		for (int i = 0; i < N; i++) children[i].pb(i);
		iota(par.begin(), par.end(), 0);
	}

	// get representive component (uses path compression)
	int get(int v) {
		if (v == par[v]) return v;
		return par[v] = get(par[v]);
	}

	// union by size
	void unite(int a, int b, int t) {
		a = get(a), b = get(b);
		if (a != b) {
			if (a > b) swap(a, b);
			par[b] = a;
			if (a == 1) {
				for (int x : children[b]) ans[x] = t;
			}
			else {
				if (sz(children[a]) < sz(children[b])) children[a].swap(children[b]);
				for (int i = 0; i < sz(children[b]); i++) children[a].pb(children[b][i]);
			}
		}
	}
};

int adj[MAXN][3][2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> adj[i][1][0] >> adj[i][2][0];
	}
	vector<array<int, 2>> q(m);
	for (int i = 0; i < m; i++) {
		cin >> q[i][0] >> q[i][1];
		adj[q[i][0]][q[i][1]][1]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!adj[i][1][1] && adj[i][1][0] != -1) dsu.unite(i, adj[i][1][0], -1);
		if (!adj[i][2][1] && adj[i][2][0] != -1) dsu.unite(i, adj[i][2][0], -1);
	}
	for (int i = m - 1; i >= 0; i--) {
		dsu.unite(q[i][0], adj[q[i][0]][q[i][1]][0], i);
	}
	for (int i = 1; i <= n; i++) {
		cout << dsu.ans[i] << '\n';
	}
}