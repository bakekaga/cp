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

struct DSU {
	vector<int> par, sz;
	DSU(int N) {
		par = vector<int>(N);
		sz = vector<int>(N, 1);
		iota(par.begin(), par.end(), 0);
	}

	// get representive component (uses path compression)
	int get(int v) {
		if (v == par[v]) return v;
		return par[v] = get(par[v]);
	}

	// union by size
	void unite(int a, int b) {
		a = get(a), b = get(b);
		if (a != b) {
			if (sz[a] < sz[b]) swap(a, b);
			par[b] = a;
			sz[a]+= sz[b];
		}
	}
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> h(n);
	vector<array<ll, 2>> hh(n);
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		cin >> hh[i][0];
		hh[i][1] = i;
		h[i] = hh[i][0];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[--u].pb(--v);
		adj[v].pb(u);
	}
	int q;
	cin >> q;
	vector<array<ll, 4>> qrs(q);
	for (int i = 0; i < q; i++) {
		cin >> qrs[i][1] >> qrs[i][2] >> qrs[i][0];
		qrs[i][0]+= h[--qrs[i][1]];
		qrs[i][2]--;
		qrs[i][3] = i;
	}
	sort(qrs.begin(), qrs.end());
	sort(hh.begin(), hh.end());

	DSU dsu(n);
	vector<int> out(q);
	int cur = 0;
	for (auto qry : qrs) {
		while (cur < n && hh[cur][0] <= qry[0]) {
			for (auto nbr : adj[hh[cur][1]]) {
				if (h[nbr] <= qry[0]) {
					dsu.unite(hh[cur][1], nbr);
				} 
			}
			cur++;
		}
		if (dsu.same_set(qry[1], qry[2])) {
			out[qry[3]]++;
		}
	}
	for (int ans : out) {
		cout << (ans ? "YES\n" : "NO\n");
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}