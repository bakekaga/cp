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
	vector<int> par, sz, mn, mx;
	DSU(int N) {
		par = vector<int>(N);
		sz = vector<int>(N, 1);
		iota(par.begin(), par.end(), 0);
		mn = par;
		mx = par;
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
			mn[a] = min(mn[a], mn[b]);
			mx[a] = max(mx[a], mx[b]);
		}
	}
	
	bool same_set(int a, int b) {
		return get(a) == get(b);
	}
	
	int size(int v) {
		return sz[get(v)];
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	DSU dsu(n + 1);

	while (m--) {
		string x; int u, v;
		cin >> x >> u;
		if (x == "union") {
			cin >> v;
			dsu.unite(u, v);
		}
		else cout << dsu.mn[dsu.get(u)] << ' ' << dsu.mx[dsu.get(u)] << ' ' << dsu.sz[dsu.get(u)] << '\n';
	}
}